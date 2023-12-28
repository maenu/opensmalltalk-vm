/* sqWindows-SDL2.c -- Legacy display API backend using SDL2.
 *
 *   Copyright (C) 2016 by Ronie Salgado
 *   All rights reserved.
 * 
 *   This file is part of Minimalistic Non-Headless Squeak.
 * 
 *   Permission is hereby granted, free of charge, to any person obtaining a
 *   copy of this software and associated documentation files (the "Software"),
 *   to deal in the Software without restriction, including without limitation
 *   the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *   and/or sell copies of the Software, and to permit persons to whom the
 *   Software is furnished to do so, subject to the following conditions:
 * 
 *   The above copyright notice and this permission notice shall be included in
 *   all copies or substantial portions of the Software.
 * 
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *   DEALINGS IN THE SOFTWARE.
 *
 * Author: roniesalg@gmail.com
 */

#include "sq.h"
#include "sqMemoryAccess.h"
#include "sqUnixMain.h"
#include "sqUnixGlobals.h"
#include "sqUnixCharConv.h"
#include "sqTextEncoding.h"
#include "sqaio.h"

#include "SqDisplay.h"

#include <stdio.h>
#include <SDL2/SDL.h>

#include "sqCircularQueue.h"
#include "sqEventCommon.h"
#include "sqUnixEvent.c"		/* see X11 and/or Quartz drivers for examples */

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
# undef EXPORT
# define EXPORT(returnType) static returnType
# define INT_EXT "(i)"
#else
# define INT_EXT "(e)"
#endif

/*** Function Prototypes ***/
EXPORT(const char*) getModuleName(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine *anInterpreter);

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static void * (*firstIndexableField)(sqInt oop);
#if !defined(integerValueOf)
static sqInt (*integerValueOf)(sqInt oop);
#endif
static sqInt (*isBytes)(sqInt oop);
#if !defined(isIntegerObject)
static sqInt (*isIntegerObject)(sqInt objectPointer);
#endif
static sqInt (*isWords)(sqInt oop);
static sqInt (*methodArgumentCount)(void);
static sqInt (*methodReturnBool)(sqInt boolean);
static sqInt (*methodReturnReceiver)(void);
static sqInt (*primitiveFailFor)(sqInt reasonCode);
static sqInt (*stSizeOf)(sqInt oop);
static sqInt (*stackValue)(sqInt offset);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern void * firstIndexableField(sqInt oop);
#if !defined(integerValueOf)
extern sqInt integerValueOf(sqInt oop);
#endif
extern sqInt isBytes(sqInt oop);
#if !defined(isIntegerObject)
extern sqInt isIntegerObject(sqInt objectPointer);
#endif
extern sqInt isWords(sqInt oop);
extern sqInt methodArgumentCount(void);
extern sqInt methodReturnBool(sqInt boolean);
extern sqInt methodReturnReceiver(void);
extern sqInt primitiveFailFor(sqInt reasonCode);
extern sqInt stSizeOf(sqInt oop);
extern sqInt stackValue(sqInt offset);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName = "vm_display_sdl2Plugin vm_display_sdl2Plugin-mle.28 " INT_EXT;

#define trace() fprintf(stderr, "%s:%d %s\n", __FILE__, __LINE__, __FUNCTION__)

extern int getSavedWindowSize();

typedef struct sqSDLEventQueue
{
    sqCircularQueueInfo info;
    SDL_Event elements[SQ_EVENT_QUEUE_SIZE];
} sqSDLEventQueue;

#define sqSDLEventQueueIsEmpty(queue) sqQueueIsEmpty(queue, SQ_EVENT_QUEUE_SIZE)
#define sqSDLEventQueueIsFull(queue) sqQueueIsFull(queue, SQ_EVENT_QUEUE_SIZE)
#define sqSDLEventQueuePush(queue, value) sqQueuePush(queue, SQ_EVENT_QUEUE_SIZE, value)
#define sqSDLEventQueuePopInto(queue, result) sqQueuePopInto(queue, SQ_EVENT_QUEUE_SIZE, result)

static sqInt sqSDL2_processEvents(void);

static sqEventQueue eventQueue;
static sqSDLEventQueue sdlEventQueue;
static sqInt
sqSDL2_getNextSDL2Event(void *buffer, size_t bufferSize)
{
    SDL_Event event;
    size_t copySize;

    /* Retrieve the event from the queue. */
    if(sqSDLEventQueueIsEmpty(sdlEventQueue))
        return false;

    sqSDLEventQueuePopInto(sdlEventQueue, &event);

    /* Copy the event data into the buffer. */
    copySize = sizeof(SDL_Event);
    if(bufferSize < copySize)
        copySize = bufferSize;
    memcpy(buffer, &event, copySize);

    return true;
}

static SDL_Window *window;
static Uint32 windowID;
static SDL_Renderer *windowRenderer;
static SDL_Texture *windowTexture;
static SDL_Cursor *currentCursor;
static int windowTextureWidth;
static int windowTextureHeight;

static int newSDLEvent = 0;
static int newDisplayEvent = 0;

static int mousePositionX = 0;
static int mousePositionY = 0;

static sqInt sdl2InputEventSemaIndex = 0;
static char droppedFileName[FILENAME_MAX];

static SDL_GLContext currentOpenGLContext = 0;
static SDL_Window *currentOpenGLWindow = 0;
static int openglStoreCount = 0;

static void
storeOpenGLState(void)
{
    if(openglStoreCount == 0)
    {
        currentOpenGLContext = SDL_GL_GetCurrentContext();
        currentOpenGLWindow = SDL_GL_GetCurrentWindow();
    }
    ++openglStoreCount;
}


static void
restoreOpenGLState(void)
{
    --openglStoreCount;
    if(openglStoreCount == 0)
    {
        SDL_GL_MakeCurrent(currentOpenGLWindow, currentOpenGLContext);
        currentOpenGLContext = 0;
        currentOpenGLWindow = 0;
    }

    if(openglStoreCount < 0)
        abort();
}

static sqInt
setSDL2InputSemaphoreIndex(sqInt semaIndex)
{
    if (semaIndex == 0)
        success(false);
    else
        sdl2InputEventSemaIndex = semaIndex;
    return true;
}

static void
sdl2SignalInputEvent(void)
{
    if (sdl2InputEventSemaIndex > 0)
        signalSemaphoreWithIndex(sdl2InputEventSemaIndex);
}

static int
convertButton(int button)
{
#ifdef __APPLE__
    // On OS X, swap the middle and right buttons.
    switch(button)
    {
    case SDL_BUTTON_LEFT: return RedButtonBit;
    case SDL_BUTTON_RIGHT: return BlueButtonBit;
    case SDL_BUTTON_MIDDLE: return YellowButtonBit;
    default: return 0;
    }
#else
    switch(button)
    {
        case SDL_BUTTON_LEFT: return RedButtonBit;
        case SDL_BUTTON_MIDDLE: return BlueButtonBit;
        case SDL_BUTTON_RIGHT: return YellowButtonBit;
        default: return 0;
    }
#endif
    return 0;
}

static int
convertModifiers(int state)
{
    int result = 0;
    if(state & KMOD_SHIFT)
        result |= ShiftKeyBit;
    if(state & KMOD_CTRL) /* Alt-gr is received as RCtrl in some cases.*/
        result |= CtrlKeyBit;
    if(state & KMOD_ALT) /* Right alt is used for grammar purposes. */
        result |= OptionKeyBit;
    if(state & KMOD_GUI)
        result |= CommandKeyBit;
    return result;
}

static int
convertSpecialKeySymToCharacter(int symbol)
{
    switch(symbol)
    {
        case SDLK_RETURN: return '\r';
        case SDLK_BACKSPACE: return 8;
        case SDLK_TAB: return '\t';
        case SDLK_HOME: return 1;
        case SDLK_LEFT: return 28;
        case SDLK_UP: return 30;
        case SDLK_RIGHT: return 29;
        case SDLK_DOWN: return 31;
        case SDLK_END: return 4;
        case SDLK_INSERT: return 5;
        case SDLK_PAGEUP: return 11;
        case SDLK_PAGEDOWN: return 12;
        case SDLK_DELETE: return 127;
        default:
            return 0;
    }

}

static int
convertKeySymToCharacter(int symbol)
{
    if(symbol >= 0x400000)
        return 0;
    else
        return symbol;
}

static void
createWindow(sqInt width, sqInt height, sqInt fullscreenFlag)
{
    int flags;
    int actualWindowX, actualWindowY;
    int actualWindowWidth, actualWindowHeight;
    SDL_Rect displayBounds;

    if(window)
        return;

    storeOpenGLState();
#ifdef EMSCRIPTEN
    flags = SDL_WINDOW_SHOWN;
#else
    flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI;
#endif
    if(fullscreenFlag)
        flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;

    modifierState = convertModifiers(SDL_GetModState());
    window = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
    if(!window)
    {
        restoreOpenGLState();
        return;
    }

    if(!fullscreenFlag)
    {
        SDL_GetWindowPosition(window, &actualWindowX, &actualWindowY);
        SDL_GetWindowSize(window, &actualWindowWidth, &actualWindowHeight);
#if SDL_VERSION_ATLEAST(2, 5, 0)
        SDL_GetDisplayUsableBounds(0, &displayBounds);
#else
        SDL_GetDisplayBounds(0, &displayBounds);
#endif
        if(actualWindowWidth + actualWindowX >= displayBounds.w || actualWindowHeight + actualWindowY >= displayBounds.h)
            SDL_MaximizeWindow(window);
    }

    windowID = SDL_GetWindowID(window);
    windowRenderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_PRESENTVSYNC);
    restoreOpenGLState();
}

static int
ensureTextureOfSize(sqInt width, sqInt height)
{
    if(windowTexture && windowTextureWidth == width && windowTextureHeight == height)
        return 0;

    storeOpenGLState();
    if(windowTexture)
        SDL_DestroyTexture(windowTexture);

    windowTexture = SDL_CreateTexture(windowRenderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, width, height);
    windowTextureWidth = width;
    windowTextureHeight = height;
    restoreOpenGLState();
    return 1;
}

static void
presentWindow()
{
    if(!window || !windowRenderer)
        return;

    storeOpenGLState();
    SDL_SetRenderDrawColor(windowRenderer, 0, 0, 0, 0);
    SDL_RenderClear(windowRenderer);

    if(windowTexture)
        SDL_RenderCopy(windowRenderer, windowTexture, NULL, NULL);

    SDL_RenderPresent(windowRenderer);
    restoreOpenGLState();
}

static void
recordSDLEvent(const SDL_Event *rawEvent)
{
    newSDLEvent = 1;
    sqSDLEventQueuePush(sdlEventQueue, *rawEvent);
}

static void
recordEvent(sqEventUnion *event)
{
    newDisplayEvent = 1;
    sqEventQueuePush(eventQueue, *event);
}

static void
recordLowImportanceEvent(sqEventUnion *event)
{
    if(sqEventQueueIsFull(eventQueue))
        return;

    recordEvent(event);
}

static void
recordMouseWheel(int keyCode)
{
    int modifiers = modifierState ^ CtrlKeyBit;

    {
        sqEventUnion event;
        memset(&event, 0, sizeof(event));
        event.key.type = EventTypeKeyboard;
        event.key.pressCode = EventKeyDown;
        event.key.charCode = keyCode;
        event.key.utf32Code = keyCode;
        event.key.modifiers = modifiers;
        recordEvent(&event);
    }

    {
        sqEventUnion event;
        memset(&event, 0, sizeof(event));
        event.key.type = EventTypeKeyboard;
        event.key.pressCode = EventKeyChar;
        event.key.charCode = keyCode;
        event.key.utf32Code = keyCode;
        event.key.modifiers = modifiers;
        recordEvent(&event);
    }

    {
        sqEventUnion event;
        memset(&event, 0, sizeof(event));
        event.key.type = EventTypeKeyboard;
        event.key.pressCode = EventKeyUp;
        event.key.charCode = keyCode;
        event.key.utf32Code = keyCode;
        event.key.modifiers = modifiers;
        recordEvent(&event);
    }
}

static void
handleMouseWheel(const SDL_Event *rawEvent)
{
    if(rawEvent->wheel.windowID != windowID)
    {
        recordSDLEvent(rawEvent);
        return;
    }

    if(rawEvent->wheel.x < 0)
    {
        recordMouseWheel(28);
    }
    else if(rawEvent->wheel.x > 0)
    {
        recordMouseWheel(29);
    }

    if(rawEvent->wheel.y > 0)
    {
        recordMouseWheel(30);
    }
    else if(rawEvent->wheel.y < 0)
    {
        recordMouseWheel(31);
    }
}

static void
handleKeyDown(const SDL_Event *rawEvent)
{
    int character;
    int isSpecial;
    int hasRightAlt;

    hasRightAlt = (rawEvent->key.keysym.mod & KMOD_RALT) != 0;
    modifierState = convertModifiers(rawEvent->key.keysym.mod);
    if(rawEvent->key.windowID != windowID)
    {
        recordSDLEvent(rawEvent);
        return;
    }

    character = convertSpecialKeySymToCharacter(rawEvent->key.keysym.sym);
    isSpecial = character != 0;
    if(!character)
        character = convertKeySymToCharacter(rawEvent->key.keysym.sym);

    {
        sqEventUnion event;
        memset(&event, 0, sizeof(event));
        event.key.type = EventTypeKeyboard;
        event.key.timeStamp = rawEvent->key.timestamp;
        event.key.pressCode = EventKeyDown;
        event.key.charCode = rawEvent->key.keysym.sym;
        event.key.utf32Code = character;
        event.key.modifiers = modifierState;
        recordEvent(&event);
    }

    /* We need to send a key stroke for some special circumstances. */
    if(!isSpecial && (!modifierState || modifierState == ShiftKeyBit || hasRightAlt))
        return;

    if(character && character != 27)
    {
        sqEventUnion event;
        memset(&event, 0, sizeof(event));
        event.key.type = EventTypeKeyboard;
        event.key.timeStamp = rawEvent->key.timestamp;
        event.key.pressCode = EventKeyChar;
        event.key.charCode = character;
        event.key.utf32Code = character;
        event.key.modifiers = modifierState;
        recordEvent(&event);
    }
}

static void
handleKeyUp(const SDL_Event *rawEvent)
{
    modifierState = convertModifiers(rawEvent->key.keysym.mod);
    if(rawEvent->key.windowID != windowID)
    {
        recordSDLEvent(rawEvent);
        return;
    }

    sqEventUnion event;
    memset(&event, 0, sizeof(event));
    event.key.type = EventTypeKeyboard;
    event.key.timeStamp = rawEvent->key.timestamp;
    event.key.pressCode = EventKeyUp;
    event.key.charCode = convertKeySymToCharacter(rawEvent->key.keysym.sym);
    event.key.utf32Code = convertKeySymToCharacter(rawEvent->key.keysym.sym);
    event.key.modifiers = modifierState;
    recordEvent(&event);
}

static void
handleTextInput(const SDL_Event *rawEvent)
{
    int utf32;
    const char *position;

    if(rawEvent->text.windowID != windowID)
    {
        recordSDLEvent(rawEvent);
        return;
    }

    sqEventUnion event;
    memset(&event, 0, sizeof(event));
    event.key.type = EventTypeKeyboard;
    event.key.timeStamp = rawEvent->text.timestamp;
    event.key.pressCode = EventKeyChar;
    event.key.modifiers = modifierState;

    position = rawEvent->text.text;
    while(*position)
    {
        position = sqUTF8ToUTF32Iterate(position, &utf32);
        if(!utf32)
            break;

        event.key.charCode = utf32;
        event.key.utf32Code = utf32;
        recordEvent(&event);
    }
}

static void
handleMouseButtonDown(const SDL_Event *rawEvent)
{
    if(rawEvent->button.windowID != windowID)
    {
        recordSDLEvent(rawEvent);
        return;
    }

    buttonState |= convertButton(rawEvent->button.button);

    sqEventUnion event;
    memset(&event, 0, sizeof(event));
    event.mouse.type = EventTypeMouse;
    event.mouse.timeStamp = rawEvent->button.timestamp;
    event.mouse.x = mousePositionX = rawEvent->button.x;
    event.mouse.y = mousePositionY = rawEvent->button.y;
    event.mouse.buttons = buttonState;
    event.mouse.modifiers = modifierState;
    event.mouse.nrClicks = rawEvent->button.clicks;
    recordEvent(&event);
}

static void
handleMouseButtonUp(const SDL_Event *rawEvent)
{
    if(rawEvent->button.windowID != windowID)
    {
        recordSDLEvent(rawEvent);
        return;
    }

    buttonState &= ~convertButton(rawEvent->button.button);

    sqEventUnion event;
    memset(&event, 0, sizeof(event));
    event.mouse.type = EventTypeMouse;
    event.mouse.timeStamp = rawEvent->button.timestamp;
    event.mouse.x = mousePositionX = rawEvent->button.x;
    event.mouse.y = mousePositionY = rawEvent->button.y;
    event.mouse.buttons = buttonState;
    event.mouse.modifiers = modifierState;
    event.mouse.nrClicks = rawEvent->button.clicks;
    recordEvent(&event);
}

static void
handleMouseMotion(const SDL_Event *rawEvent)
{
    if(rawEvent->motion.windowID != windowID)
    {
        recordSDLEvent(rawEvent);
        return;
    }

    sqEventUnion event;
    memset(&event, 0, sizeof(event));
    event.mouse.type = EventTypeMouse;
    event.mouse.timeStamp = rawEvent->motion.timestamp;
    event.mouse.x = mousePositionX = rawEvent->motion.x;
    event.mouse.y = mousePositionY = rawEvent->motion.y;
    event.mouse.buttons = buttonState;
    event.mouse.modifiers = modifierState;
    recordLowImportanceEvent(&event);
}

static void
handleWindowEvent(const SDL_Event *rawEvent)
{
    if(rawEvent->window.windowID != windowID)
    {
        recordSDLEvent(rawEvent);
        return;
    }

    switch(rawEvent->window.event)
    {
        case SDL_WINDOWEVENT_CLOSE:
        {
            sqEventUnion event;
            memset(&event, 0, sizeof(event));
            event.window.type = EventTypeWindow;
            event.window.timeStamp = rawEvent->window.timestamp;
            event.window.action = WindowEventClose;
            recordEvent(&event);
        }
            break;
        case SDL_WINDOWEVENT_MOVED:
        case SDL_WINDOWEVENT_SIZE_CHANGED:
        case SDL_WINDOWEVENT_RESIZED:
        {
            sqEventUnion event;
            SDL_Rect rect;
            SDL_GetWindowPosition(window, &rect.x, &rect.y);
            SDL_GetRendererOutputSize(windowRenderer, &rect.w, &rect.h);
            memset(&event, 0, sizeof(event));
            event.window.type = EventTypeWindow;
            event.window.timeStamp = rawEvent->window.timestamp;
            event.window.action = WindowEventMetricChange;
            event.window.value1 = rect.x;
            event.window.value2 = rect.y;
            event.window.value3 = rect.x + rect.w;
            event.window.value4 = rect.y + rect.h;
            recordEvent(&event);
        }
            break;
    }
}

static void
handleDropFileEvent(const SDL_Event *rawEvent)
{
    sqEventUnion event;
    strcpy(droppedFileName, rawEvent->drop.file);
    SDL_free(rawEvent->drop.file);

    /* TODO: Support dropping files here or in the image.*/
    {
        event.dnd.type = EventTypeDragDropFiles;
        event.dnd.timeStamp = rawEvent->window.timestamp;
        event.dnd.dragType = SQDragDrop;
        event.dnd.numFiles = 1;
        event.dnd.x = mousePositionX;
        event.dnd.y = mousePositionY;
        event.dnd.modifiers = modifierState;
        recordEvent(&event);
    }
}

static void
handleEvent(const SDL_Event *event)
{
    switch(event->type)
    {
        case SDL_KEYDOWN:
            handleKeyDown(event);
            break;
        case SDL_KEYUP:
            handleKeyUp(event);
            break;
        case SDL_TEXTINPUT:
            handleTextInput(event);
            break;
        case SDL_MOUSEBUTTONDOWN:
            handleMouseButtonDown(event);
            break;
        case SDL_MOUSEBUTTONUP:
            handleMouseButtonUp(event);
            break;
        case SDL_MOUSEMOTION:
            handleMouseMotion(event);
            break;
        case SDL_MOUSEWHEEL:
            handleMouseWheel(event);
            break;
        case SDL_WINDOWEVENT:
            handleWindowEvent(event);
            break;
        case SDL_DROPFILE:
            handleDropFileEvent(event);
            break;
        default:
            /* Record the unhandled SDL events for the image. */
            recordSDLEvent(event);
            break;
    }
}

static int handleEvents(void)
{
    int handled = 0;
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        handleEvent(&event);
        handled = 1;
    }
    if(newDisplayEvent)
        ioSignalInputEvent();
    if(newSDLEvent)
        sdl2SignalInputEvent();
    newDisplayEvent = 0;
    newSDLEvent = 0;
  return handled;
}

static char **display_clipboardGetTypeNames(void)
{
    return 0;
}

static sqInt display_clipboardSize(void)
{
    if(!SDL_HasClipboardText())
        return 0;
    return strlen(SDL_GetClipboardText());
}

static sqInt display_clipboardSizeWithType(char *typeName, int nTypeName)
{
    return display_clipboardSize();
}

static void display_clipboardWriteWithType(char *data, size_t ndata, char *typeName, size_t nTypeName, int isDnd, int isClaiming)
{
    char *buffer = (char*)malloc(ndata + 1);
    memcpy(buffer, data, ndata);
    buffer[ndata] = 0;
    SDL_SetClipboardText(buffer);
    free(buffer);
}

static sqInt display_clipboardWriteFromAt(sqInt count, sqInt byteArrayIndex, sqInt startIndex)
{
    display_clipboardWriteWithType(pointerForOop(byteArrayIndex + startIndex), count, "", 0, 0, 1);
    return 0;
}

static sqInt display_clipboardReadIntoAt(sqInt count, sqInt byteArrayIndex, sqInt startIndex)
{
    sqInt clipSize;
    char *clipboardText = SDL_GetClipboardText();
    if(!clipboardText)
        clipboardText = "";
    clipSize = count;
    if(count < clipSize)
        clipSize = count;
    memcpy(pointerForOop(byteArrayIndex + startIndex), (void *)clipboardText, clipSize);
    return clipSize;
}

static sqInt display_dndOutStart(char *types, int ntypes)	{ return 0; }
static void  display_dndOutSend(char *bytes, int nbytes)	{ return  ; }
/* UNUSED static void  display_dndLaunchFile(char *fileName)	{ return ; }  */
static sqInt display_dndOutAcceptedType(char * buf, int nbuf)	{ return 0; }
static sqInt display_dndReceived(char *fileName)	{ return 0; }


/* SDL2 primitives*/
extern sqInt argumentCountOf(sqInt methodPointer);
extern sqInt failed(void);
extern sqInt pop(sqInt nItems);
extern void popthenPush(sqInt nItems, sqInt oop);
extern sqInt primitiveMethod(void);
extern sqInt stackIntegerValue(sqInt offset);
extern sqInt stackValue(sqInt offset);
extern sqInt trueObject(void);
extern sqInt falseObject(void);
extern void *firstIndexableField(sqInt oop);

static sqInt
primitiveIsVMDisplayUsingSDL2()
{
    popthenPush(1 + (argumentCountOf(primitiveMethod())), trueObject());
    return 0;
}

static sqInt
primitivePollVMSDL2Event()
{
    sqInt bufferOop;
    sqInt size;
    sqInt result;

    bufferOop = stackValue(1);
    size = stackIntegerValue(0);

    result = sqSDL2_getNextSDL2Event(firstIndexableField(bufferOop), size);
    popthenPush(1 + (argumentCountOf(primitiveMethod())), result ? trueObject() : falseObject());

    return 0;
}

static sqInt
primitiveSetVMSDL2Input()
{
    sqInt sema;

    sema = stackIntegerValue(0);
    setSDL2InputSemaphoreIndex(sema);
    if (!(failed())) {
        pop(argumentCountOf(primitiveMethod()));
    }

    return 0;
}

#define XFN(export) {"", #export, (void*)export},
#define XFNDF(export,depth,flags) {"", #export "\000" depth flags, (void*)export},

static void *display_exports[][3]=
        {
                XFNDF(primitiveIsVMDisplayUsingSDL2, "\001","\000")
                XFNDF(primitivePollVMSDL2Event, "\001","\000")
                XFNDF(primitiveSetVMSDL2Input, "\001","\000")
                { 0, 0, 0 }
        };

static void display_winInit(void)
{
    SDL_SetHint(SDL_HINT_NO_SIGNAL_HANDLERS, "1");
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_NOPARACHUTE);
}

static void display_winOpen(int ignored,char **ignored2)
{
    createWindow(640, 480, 0);
}

static void display_winExit(void)
{
    SDL_Quit();
}

static sqInt display_ioFormPrint(sqInt bitsIndex, sqInt width, sqInt height, sqInt depth, double hScale, double vScale, sqInt landscapeFlag)
{
    return 0;
}

static sqInt display_ioBeep(void)
{
  trace();
  return 0;
}

static sqInt display_ioRelinquishProcessorForMicroseconds(sqInt microSeconds)
{
  aioSleepForUsecs(handleEvents() ? 0 : microSeconds);
  return 0;
}

static sqInt display_ioProcessEvents(void)
{
  handleEvents();
  aioPoll(0);
  return 0;
}

static double display_ioScreenScaleFactor(void)
{
    return 1.0;
}

static sqInt display_ioScreenDepth(void)
{
    return 32;
}

static sqInt display_ioScreenSize(void)
{
    int width;
    int height;
    if(!windowRenderer)
        return getSavedWindowSize();
    SDL_GetRendererOutputSize(windowRenderer, &width, &height);
    return height | (width << 16);
}

static sqInt display_ioSetCursorWithMask(sqInt cursorBitsIndex, sqInt cursorMaskIndex, sqInt offsetX, sqInt offsetY)
{
    SDL_Cursor *newCursor;
    Uint8 convertedCursorBits[32];
    Uint8 convertedCursorMask[32];
    int i;

    unsigned int *cursorBits = (unsigned int*)pointerForOop(cursorBitsIndex);
    unsigned int *cursorMask = (unsigned int*)pointerForOop(cursorMaskIndex);

    if (cursorMaskIndex == null)
        cursorMask = cursorBits;

    /* Remove the extra padding */
    for(i = 0; i < 16; ++i)
    {
        convertedCursorBits[i*2 + 0]= (cursorBits[i] >> 24) & 0xFF;
        convertedCursorBits[i*2 + 1]= (cursorBits[i] >> 16) & 0xFF;
        convertedCursorMask[i*2 + 0]= (cursorMask[i] >> 24) & 0xFF;
        convertedCursorMask[i*2 + 1]= (cursorMask[i] >> 16) & 0xFF;
    }

    /* Create and set the new cursor. */
    newCursor = SDL_CreateCursor(convertedCursorBits, convertedCursorMask, 16, 16, -offsetX, -offsetY);
    if(newCursor)
    {
        SDL_SetCursor(newCursor);
        if(currentCursor)
            SDL_FreeCursor(currentCursor);
        currentCursor = newCursor;
    }

    return 0;
}

static sqInt display_ioSetCursorARGB(sqInt cursorBitsIndex, sqInt extentX, sqInt extentY, sqInt offsetX, sqInt offsetY)
{
    return 0;
}

static sqInt display_ioSetFullScreen(sqInt fullScreen)
{
    trace();
    return 0;
}
static sqInt display_ioForceDisplayUpdate(void)
{
    presentWindow();
    return 0;
}

static void
blitRect32(
        int surfaceWidth, int surfaceHeight,
        uint8_t *sourcePixels, int sourcePitch,
        uint8_t *destPixels, int destPitch,
        int copyX, int copyY, int width, int height)
{
    int y;

    if(sourcePitch == destPitch &&
       surfaceWidth == width && surfaceHeight == height && copyX == 0 && copyY == 0)
    {
        memcpy(destPixels, sourcePixels, destPitch*height);
    }
    else if(sourcePitch == destPitch)
    {
        destPixels += copyY*destPitch;
        sourcePixels += copyY*sourcePitch;
        memcpy(destPixels, sourcePixels, destPitch*height);
    }
    else
    {
        int copyPitch = destPitch;
        if(sourcePitch < copyPitch)
            copyPitch = sourcePitch;

        destPixels += copyY*destPitch;
        sourcePixels += copyY*sourcePitch;

        for(y = 0; y < height; ++y)
        {
            memcpy(destPixels, sourcePixels, copyPitch);
            destPixels += destPitch;
            sourcePixels += sourcePitch;
        }
    }
}

static sqInt display_ioShowDisplay(sqInt dispBitsIndex, sqInt width, sqInt height, sqInt depth,
				   sqInt affectedL, sqInt affectedR, sqInt affectedT, sqInt affectedB)
{
    storeOpenGLState();
    if(!window)
        createWindow(width, height, 0);
    SDL_Rect modifiedRect;
    modifiedRect.x = affectedL;
    modifiedRect.y = affectedT;
    modifiedRect.w = affectedR - affectedL;
    modifiedRect.h = affectedB - affectedT;
    /* Make sure the texture has the correct extent. */
    if(ensureTextureOfSize(width, height)) {
        /*If the texture was recreated, we have to upload the whole texture*/
        modifiedRect.x = 0;
        modifiedRect.y = 0;
        modifiedRect.w = width;
        modifiedRect.h = height;
    }
    if(!windowTexture) {
        restoreOpenGLState();
        return 0;
    }
    uint8_t *pixels;
    int pitch;
    if(SDL_LockTexture(windowTexture, NULL, (void**)&pixels, &pitch)) {
        restoreOpenGLState();
        return 0;
    }
    int sourcePitch = windowTextureWidth*4;
    blitRect32(windowTextureWidth, windowTextureHeight,
               (uint8_t*)pointerForOop(dispBitsIndex), sourcePitch,
               pixels, pitch,
               modifiedRect.x, modifiedRect.y, modifiedRect.w, modifiedRect.h
    );
    SDL_UnlockTexture(windowTexture);
    presentWindow();
    restoreOpenGLState();
    return 0;
}

static sqInt display_ioHasDisplayDepth(sqInt i)
{
    return i == 32;
}

static sqInt display_ioSetDisplayMode(sqInt width, sqInt height, sqInt depth, sqInt fullscreenFlag)
{
    if(window)
    {
        storeOpenGLState();
        ioSetWindowWidthHeight(width, height);
        ioSetFullScreen(fullscreenFlag);
        restoreOpenGLState();
        return 0;
    }

    storeOpenGLState();
    createWindow(width, height, fullscreenFlag);
    restoreOpenGLState();
    return 0;
}

static void display_winSetName(char *imageName)
{
    int size = strlen(imageName);
    char *buffer = (char*)malloc(size + 1);
    memcpy(buffer, 0, size);
    buffer[size] = 0;
    SDL_SetWindowTitle(window, buffer);
    free(buffer);
}

static long  display_winImageFind(char *imageName, int size) { return 0; }
static void  display_winImageNotFound(void) {}

static void *display_ioGetDisplay(void)	{ return 0; }
static void *display_ioGetWindow(void)	{ return 0; }

static sqInt display_ioGLinitialise(void) { trace();  return 0; }
static sqInt display_ioGLcreateRenderer(glRenderer *r, sqInt x, sqInt y, sqInt w, sqInt h, sqInt flags) { trace();  return 0; }
static void  display_ioGLdestroyRenderer(glRenderer *r) { trace(); }
static void  display_ioGLswapBuffers(glRenderer *r) { trace(); }
static sqInt display_ioGLmakeCurrentRenderer(glRenderer *r) { trace();  return 0; }
static void  display_ioGLsetBufferRect(glRenderer *r, sqInt x, sqInt y, sqInt w, sqInt h) { trace(); }

static char *display_winSystemName(void)
{
  return "sdl2";
}

static sqInt display_primitivePluginBrowserReady(void)		{ return primitiveFail(); }
static sqInt display_primitivePluginRequestURLStream(void)	{ return primitiveFail(); }
static sqInt display_primitivePluginRequestURL(void)		{ return primitiveFail(); }
static sqInt display_primitivePluginPostURL(void)		{ return primitiveFail(); }
static sqInt display_primitivePluginRequestFileHandle(void)	{ return primitiveFail(); }
static sqInt display_primitivePluginDestroyRequest(void)	{ return primitiveFail(); }
static sqInt display_primitivePluginRequestState(void)		{ return primitiveFail(); }

// Host Windows
static long display_hostWindowClose(long index)                                               { return 0; }
static long display_hostWindowCreate(long w, long h, long x, long y, char *list, long attributeListLength)                                                      { return 0; }
static long display_hostWindowShowDisplay(unsigned *dispBitsIndex, long width, long height, long depth, long affectedL, long affectedR, long affectedT, long affectedB, sqIntptr_t windowIndex)              { return 0; }
static long display_hostWindowGetSize(long windowIndex)                                       { return -1; }
static long display_hostWindowSetSize(long windowIndex, long w, long h)                         { return -1; }
static long display_hostWindowGetPosition(long windowIndex)                                   { return -1; }
static long display_hostWindowSetPosition(long windowIndex, long x, long y)                     { return -1; }
static long display_hostWindowSetTitle(long windowIndex, char *newTitle, long sizeOfTitle)     { return -1; }
static long display_hostWindowCloseAll(void)                                                 { return 0; }

// new stubs for the CogVM
long display_ioSetCursorPositionXY(long x, long y) { return 0; }
long display_ioPositionOfScreenWorkArea (long windowIndex) { return -1; }
long display_ioSizeOfScreenWorkArea (long windowIndex) { return -1; }
void *display_ioGetWindowHandle() { return 0; }
long display_ioPositionOfNativeDisplay(void *windowHandle) { return -1; }
long display_ioSizeOfNativeDisplay(void *windowHandle) { return -1; }
long display_ioPositionOfNativeWindow(void *windowHandle) { return -1; }
long display_ioSizeOfNativeWindow(void *windowHandle) { return -1; }

SqDisplayDefine(sdl2);	/* name must match that in makeInterface() below */


/*** module ***/


static void display_printUsage(void)
{
  printf("\nsdl2 Window <option>s: (none)\n");
  /* otherwise... */
}

static void display_printUsageNotes(void)
{
  trace();
}

static void display_parseEnvironment(void)
{
  trace();
}

static int display_parseArgument(int argc, char **argv)
{
  return 0;	/* arg not recognised */
}

static void *display_makeInterface(void)
{
  return &display_sdl2_itf;		/* name must match that in SqDisplayDefine() above */
}

#include "SqModule.h"

SqModuleDefine(display, sdl2);	/* name must match that in sqUnixMain.c's moduleDescriptions */


/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

/* InterpreterPlugin>>#getModuleName */
EXPORT(const char*)
        getModuleName(void)
{
    return moduleName;
}

/*	Note: This is coded so that it can be run in Squeak. */

/* InterpreterPlugin>>#setInterpreter: */
EXPORT(sqInt)
        setInterpreter(struct VirtualMachine *anInterpreter)
{
    sqInt ok;


    /* This may seem tautological, but in a real plugin it checks that the VM provides
       the version the plugin was compiled against which is the version the plugin expects. */
    interpreterProxy = anInterpreter;
    ok = ((interpreterProxy->majorVersion()) == (VM_PROXY_MAJOR))
         && ((interpreterProxy->minorVersion()) >= (VM_PROXY_MINOR));
    if (ok) {

#if !defined(SQUEAK_BUILTIN_PLUGIN)
        firstIndexableField = interpreterProxy->firstIndexableField;
#if !defined(integerValueOf)
        integerValueOf = interpreterProxy->integerValueOf;
#endif
        isBytes = interpreterProxy->isBytes;
#if !defined(isIntegerObject)
        isIntegerObject = interpreterProxy->isIntegerObject;
#endif
        isWords = interpreterProxy->isWords;
        methodArgumentCount = interpreterProxy->methodArgumentCount;
        methodReturnBool = interpreterProxy->methodReturnBool;
        methodReturnReceiver = interpreterProxy->methodReturnReceiver;
        primitiveFailFor = interpreterProxy->primitiveFailFor;
        stSizeOf = interpreterProxy->stSizeOf;
        stackValue = interpreterProxy->stackValue;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
    }
    return ok;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

static char _m[] = "DESPlugin";
void* DESPlugin_exports[][3] = {
	{(void*)_m, "getModuleName", (void*)getModuleName},
	{(void*)_m, "primitiveDESCookKey\000\001\003", (void*)primitiveDESCookKey},
	{(void*)_m, "primitiveDESPluginAvailable\000\377\001", (void*)primitiveDESPluginAvailable},
	{(void*)_m, "primitiveDESTransform\000\001\001", (void*)primitiveDESTransform},
	{(void*)_m, "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};

#else // ifdef SQ_BUILTIN_PLUGIN