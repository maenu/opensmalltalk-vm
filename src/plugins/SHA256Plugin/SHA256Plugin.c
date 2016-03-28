/* Smalltalk from Squeak4.5 with VMMaker 4.15.5 translated as C source on 27 March 2016 9:51:56 pm */
/* Automatically generated by
	SmartSyntaxPluginCodeGenerator VMMaker-dtl.379 uuid: 08564677-5e9d-48d5-a63c-b53bd85489f3
   from
	SHA256Plugin * CryptographyPlugins-rww.10 uuid: 8beefa4e-8411-4385-93ed-1c5d66481465
 */
static char __buildInfo[] = "SHA256Plugin * CryptographyPlugins-rww.10 uuid: 8beefa4e-8411-4385-93ed-1c5d66481465 " __DATE__ ;




#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
/*  The virtual machine proxy definition */
#include "sqVirtualMachine.h"
/* Configuration options */
#include "sqConfig.h"
/* Platform specific definitions */
#include "sqPlatformSpecific.h"

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
#undef EXPORT
// was #undef EXPORT(returnType) but screws NorCroft cc
#define EXPORT(returnType) static returnType
#endif

#include "sqMemoryAccess.h"


/*** Constants ***/

/*** Function Prototypes ***/
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static sqInt halt(void);
#pragma export on
EXPORT(sqInt) primitiveFinalHashFromState(void);
EXPORT(sqInt) primitiveInitializeState(void);
EXPORT(sqInt) primitivePluginAvailable(void);
EXPORT(sqInt) primitiveProcessBufferWithState(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
#pragma export off
/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static unsigned int k[] = {
1116352408, 1899447441, 3049323471U, 3921009573U, 961987163, 1508970993, 2453635748U, 2870763221U, 3624381080U, 310598401, 607225278, 1426881987, 1925078388, 2162078206U, 2614888103U, 3248222580U, 
3835390401U, 4022224774U, 264347078, 604807628, 770255983, 1249150122, 1555081692, 1996064986, 2554220882U, 2821834349U, 2952996808U, 3210313671U, 3336571891U, 3584528711U, 113926993, 338241895, 
666307205, 773529912, 1294757372, 1396182291, 1695183700, 1986661051, 2177026350U, 2456956037U, 2730485921U, 2820302411U, 3259730800U, 3345764771U, 3516065817U, 3600352804U, 4094571909U, 275423344, 
430227734, 506948616, 659060556, 883997877, 958139571, 1322822218, 1537002063, 1747873779, 1955562222, 2024104815, 2227730452U, 2361852424U, 2428436474U, 2756734187U, 3204031479U, 3329325298U};
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"SHA256Plugin 27 March 2016 (i)"
#else
	"SHA256Plugin 27 March 2016 (e)"
#endif
;
static sqInt simulator;
static unsigned int swap[] = {
3, 2, 1, 0};



/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

EXPORT(const char*) getModuleName(void) {
	return moduleName;
}

static sqInt halt(void) {
	;
	return null;
}

EXPORT(sqInt) primitiveFinalHashFromState(void) {
	char *x;
	char *s;
	unsigned int i;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(1)));
	x = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(1))));
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	s = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	/* begin copy:into:count: */
	for (i = 0; i <= ((4 * 8) - 1); i += 4) {
		x[i] = (s[i + (swap[0])]);
		x[i + 1] = (s[i + (swap[1])]);
		x[i + 2] = (s[i + (swap[2])]);
		x[i + 3] = (s[i + (swap[3])]);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(2);
	return null;
}

EXPORT(sqInt) primitiveInitializeState(void) {
	char *state;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	state = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	/* begin sha256InitializeState: */
	(((unsigned int*) state))[0] = 1779033703;
	(((unsigned int*) state))[1] = 3144134277U;
	(((unsigned int*) state))[2] = 1013904242;
	(((unsigned int*) state))[3] = 2773480762U;
	(((unsigned int*) state))[4] = 1359893119;
	(((unsigned int*) state))[5] = 2600822924U;
	(((unsigned int*) state))[6] = 528734635;
	(((unsigned int*) state))[7] = 1541459225;
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}

EXPORT(sqInt) primitivePluginAvailable(void) {
	sqInt _return_value;

	_return_value = (1? interpreterProxy->trueObject(): interpreterProxy->falseObject());
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}

EXPORT(sqInt) primitiveProcessBufferWithState(void) {
	char *buffer;
	char *state;
	unsigned int t2;
	unsigned int a;
	unsigned int i;
	unsigned int t1;
	unsigned int h;
	unsigned int g;
	unsigned int maj;
	unsigned int ch;
	unsigned int f;
	unsigned int w[64];
	unsigned int e;
	unsigned int s1;
	unsigned int d;
	unsigned int s0;
	unsigned int c;
	unsigned int b;
	unsigned int i1;
	unsigned int s11;
	unsigned int s01;
	unsigned int i2;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(1)));
	buffer = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(1))));
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	state = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	/* begin sha256ProcessBuffer:withState: */
	/* begin copy:into:count: */
	for (i1 = 0; i1 <= ((4 * 16) - 1); i1 += 4) {
		(((char*) w))[i1] = ((((char*) (((unsigned int*) buffer))))[i1 + (swap[0])]);
		(((char*) w))[i1 + 1] = ((((char*) (((unsigned int*) buffer))))[i1 + (swap[1])]);
		(((char*) w))[i1 + 2] = ((((char*) (((unsigned int*) buffer))))[i1 + (swap[2])]);
		(((char*) w))[i1 + 3] = ((((char*) (((unsigned int*) buffer))))[i1 + (swap[3])]);
	}
	/* begin expand: */
	for (i2 = 16; i2 <= 0x3F; i2 += 1) {
		s01 = ((((usqInt) (w[i2 - 15])) >> 7) | ((w[i2 - 15]) << (32 - 7))) ^ (((((usqInt) (w[i2 - 15])) >> 18) | ((w[i2 - 15]) << (32 - 18))) ^ (((usqInt) (w[i2 - 15])) >> 3));
		s11 = ((((usqInt) (w[i2 - 2])) >> 17) | ((w[i2 - 2]) << (32 - 17))) ^ (((((usqInt) (w[i2 - 2])) >> 19) | ((w[i2 - 2]) << (32 - 19))) ^ (((usqInt) (w[i2 - 2])) >> 10));
		w[i2] = (((s01 + s11) + (w[i2 - 16])) + (w[i2 - 7]));
	}
	a = (((unsigned int*) state))[0];
	b = (((unsigned int*) state))[1];
	c = (((unsigned int*) state))[2];
	d = (((unsigned int*) state))[3];
	e = (((unsigned int*) state))[4];
	f = (((unsigned int*) state))[5];
	g = (((unsigned int*) state))[6];
	h = (((unsigned int*) state))[7];
	for (i = 0; i <= 0x3F; i += 1) {
		s0 = ((((usqInt) a) >> 2) | (a << (32 - 2))) ^ (((((usqInt) a) >> 13) | (a << (32 - 13))) ^ ((((usqInt) a) >> 22) | (a << (32 - 22))));
		maj = (a & b) ^ ((a & c) ^ (b & c));
		t2 = s0 + maj;
		s1 = ((((usqInt) e) >> 6) | (e << (32 - 6))) ^ (((((usqInt) e) >> 11) | (e << (32 - 11))) ^ ((((usqInt) e) >> 25) | (e << (32 - 25))));
		ch = (e & f) ^ ((~e) & g);
		t1 = (((h + s1) + ch) + (k[i])) + (w[i]);
		h = g;
		g = f;
		f = e;
		e = d + t1;
		d = c;
		c = b;
		b = a;
		a = t1 + t2;
	}
	(((unsigned int*) state))[0] = (((((unsigned int*) state))[0]) + a);
	(((unsigned int*) state))[1] = (((((unsigned int*) state))[1]) + b);
	(((unsigned int*) state))[2] = (((((unsigned int*) state))[2]) + c);
	(((unsigned int*) state))[3] = (((((unsigned int*) state))[3]) + d);
	(((unsigned int*) state))[4] = (((((unsigned int*) state))[4]) + e);
	(((unsigned int*) state))[5] = (((((unsigned int*) state))[5]) + f);
	(((unsigned int*) state))[6] = (((((unsigned int*) state))[6]) + g);
	(((unsigned int*) state))[7] = (((((unsigned int*) state))[7]) + h);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(2);
	return null;
}


/*	Note: This is coded so that is can be run from Squeak. */

EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter) {
	sqInt ok;

	interpreterProxy = anInterpreter;
	ok = interpreterProxy->majorVersion() == VM_PROXY_MAJOR;
	if (ok == 0) {
		return 0;
	}
	ok = interpreterProxy->minorVersion() >= VM_PROXY_MINOR;
	return ok;
}


#ifdef SQUEAK_BUILTIN_PLUGIN


void* SHA256Plugin_exports[][3] = {
	{"SHA256Plugin", "primitiveFinalHashFromState", (void*)primitiveFinalHashFromState},
	{"SHA256Plugin", "setInterpreter", (void*)setInterpreter},
	{"SHA256Plugin", "primitivePluginAvailable", (void*)primitivePluginAvailable},
	{"SHA256Plugin", "primitiveInitializeState", (void*)primitiveInitializeState},
	{"SHA256Plugin", "primitiveProcessBufferWithState", (void*)primitiveProcessBufferWithState},
	{"SHA256Plugin", "getModuleName", (void*)getModuleName},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

