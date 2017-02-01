#include "../internal.h"


#define TYPE REAL
#define APIprefix X
#include "ishift.h"
#undef TYPE
#undef APIprefix


#if ( __STDC_VERSION__ >= 199901L )
#define TYPE COMPL
#define APIprefix XC
#include "ishift.h"
#undef TYPE
#undef APIprefix
#endif
