#ifndef FTU_H_INCLUDED
#define FTU_H_INCLUDED


/* ###############################
 * define macros for name mangling
 * ############################### */

#define NAME ftu

#define HIDDEN_CONCAT(x,y) x ## y
#define CONCAT(x,y) HIDDEN_CONCAT(x,y)

#define MANGLE_FLOAT(name) CONCAT( CONCAT(NAME,f_), name )
#define MANGLE_DOUBLE(name) CONCAT( CONCAT(NAME,_), name )
#define MANGLE_LONG(name) CONCAT( CONCAT(NAME,l_), name )

#define MANGLE_FLOAT_COMPLEX(name) CONCAT( CONCAT(NAME,fc_), name )
#define MANGLE_DOUBLE_COMPLEX(name) CONCAT( CONCAT(NAME,c_), name )
#define MANGLE_LONG_COMPLEX(name) CONCAT( CONCAT(NAME,lc_), name )


/* ##############################################
 * define macro to automatically declare function
 * prototypes with correct data types
 * ############################################## */

#include <stdlib.h>

#define DEFINE_API(X,PREC,TYPE) \
\
TYPE* X(shift_1d)(const TYPE*, size_t); \
void X(shiftIn_1d)(TYPE*, size_t); \
void X(shiftExt_1d)(TYPE *restrict, const TYPE *restrict, size_t); \
\
TYPE* X(ishift_1d)(const TYPE*, size_t); \
void X(ishiftIn_1d)(TYPE*, size_t); \
void X(ishiftExt_1d)(TYPE *restrict, const TYPE *restrict, size_t); \
\
TYPE* X(expandR2C_1d)(const TYPE*, size_t); \
void X(expandR2CIn_1d)(TYPE*, size_t); \
void X(expandR2CExt_1d)(TYPE *restrict, const TYPE *restrict, size_t); \
\


/* #############################################
 * prototype declarations for several data types
 * ############################################# */

DEFINE_API( MANGLE_FLOAT, float, float )
DEFINE_API( MANGLE_DOUBLE, double, double )
DEFINE_API( MANGLE_LONG, long double, long double )

/* Check for C99 or above for complex numbers */
#if ( __STDC_VERSION__ >= 199901L )
DEFINE_API( MANGLE_FLOAT_COMPLEX, float, float _Complex )
DEFINE_API( MANGLE_DOUBLE_COMPLEX, double, double _Complex )
DEFINE_API( MANGLE_LONG_COMPLEX, long double, long double _Complex )
#endif


/* ###############
 * clean up macros
 * ############### */

#undef NAME
#undef HIDDEN_CONCAT
#undef CONCAT
#undef DEFINE_API

#undef MANGLE_FLOAT
#undef MANGLE_DOUBLE
#undef MANGLE_LONG

#undef MANGLE_FLOAT_COMPLEX
#undef MANGLE_DOUBLE_COMPLEX
#undef MANGLE_LONG_COMPLEX


#endif /* FTU_H_INCLUDED */
