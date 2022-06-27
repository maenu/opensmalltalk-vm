#if !BIT_IDENTICAL_FLOATING_POINT || EMSCRIPTEN
#include "ieee754names.h"

#if !defined(NO_ISNAN) || EMSCRIPTEN

#include "../../third-party/fdlibm/s_isnan.c"

#endif

#endif
