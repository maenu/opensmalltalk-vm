/*
 * Break-pointer debugging facilities for the StackInterpreter VM.
 * Edit this to install various debugging traps.  In a production
 * VM this header should define only the assert macros and empty
 * sendBreakpointclassTag and bytecodeDispatchDebugHook macros.
 */

#include "sqAssert.h"

#if !defined(VMBIGENDIAN)
# error "sqConfig.h does not define VMBIGENDIAN"
#elif !((VMBIGENDIAN == 1) || (VMBIGENDIAN == 0))
# error "sqConfig.h does not define VMBIGENDIAN as either 1 or 0"
#endif

/*
 * various definitions of the sendBreakpointclassTag macro for break-pointing at
 * specific sends.
 */
#if STACKVM
# define warnSendBreak() do { \
		suppressHeartbeatFlag = 1; \
		warning("send breakpoint (heartbeat suppressed)"); \
	} while (0)
# define warnMNUBreak() do { \
		suppressHeartbeatFlag = 1; \
		warning("MNU breakpoint (heartbeat suppressed)"); \
	} while (0)
#else
# define warnSendBreak() warning("send breakpoint")
# define warnMNUBreak() warning("MNU breakpoint")
#endif

#if PRODUCTION && !SENDTRACE /* default for no send breakpoint. */
# define sendBreakpointclassTag(sel, len, classTag) 0
# define mnuBreakpointreceiver(sel, len, rcvr) 0

#elif SENDTRACE /* send tracing.  */
# define sendBreakpointclassTag(sel, len, classTag) do { \
	if (sendTrace) \
		printf("%.*s\n", (int)(len), (char *)(sel)); \
} while (0)
# define mnuBreakpointreceiver(sel, len, rcvr) 0

#elif 0 /* send trace/byte count.  */
# define sendBreakpointclassTag(sel, len, classTag) do { \
	if (sendTrace) \
		printf("%u %.*s\n", GIV(byteCount), (int)(len), (char *)(sel)); \
} while (0)
# define mnuBreakpointreceiver(sel, len, rcvr) 0

#else /* breakpoint for assert and debug configurations. */
# define sendBreakpointclassTag(sel, len, classTag) do { \
	if ((len) == breakSelectorLength \
	 && !strncmp((char *)(sel), breakSelector, breakSelectorLength)) { \
		warnSendBreak(); \
		if (0) sendTrace = 1; \
	} \
	if (sendTrace) \
		printf("%.*s\n", (int)(len), (char *)(sel)); \
} while (0)
# define mnuBreakpointreceiver(sel, len, rcvr) do { \
	if ((len) == -breakSelectorLength \
	 && !strncmp((char *)(sel), breakSelector, -breakSelectorLength)) { \
		warnMNUBreak(); \
		if (0) sendTrace = 1; \
	} \
} while (0)

#endif

/*
 * various definitions of the bytecodeDispatchDebugHook macro for
 * debugging code at the bytecode dispatch switch.
 */
#if STACKVM
# define ValidInstructionPointerCheck() \
	validInstructionPointerinMethodframePointer((usqInt)localIP, GIV(method), localFP)
#else
# define ValidInstructionPointerCheck() \
	(GIV(method) == iframeMethod(localFP) \
	 && validInstructionPointerinMethod((usqInt)localIP, GIV(method)))
#endif
				 
# define bytecodeDispatchDebugHook() 0
