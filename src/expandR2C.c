#include "../internal.h"


#define TYPE REAL
#define APIprefix X
#include "expandR2C.h"
#undef TYPE
#undef APIprefix


#if ( __STDC_VERSION__ >= 199901L )
#define TYPE COMPL
#define APIprefix XC
#include "expandR2C.h"
#undef TYPE
#undef APIprefix
#endif
