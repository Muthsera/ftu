#ifndef FFT_UTIL_H_INCLUDED
#define FFT_UTIL_H_INCLUDED


#include <stdlib.h>


#define fftutil_VERSION 1.0
#define CONCAT(x,y) x ## y


#define DEFINE_API(X,PREC,TYPE) \
\
void X(shift_1d)(TYPE *A, size_t Nx); \
void X(shift_ext1d)(TYPE *restrict out, const TYPE *restrict in, size_t Nx); \
void X(ishift_1d)(TYPE *A, size_t Nx); \
void X(ishift_ext1d)(TYPE *restrict out, const TYPE *restrict in, size_t Nx); \
void X(expandR2C_1d)(TYPE *A, size_t Nx); \
void X(expandR2C_ext1d)(TYPE *restrict out, const TYPE *restrict in, size_t Nx); \
\


#define MANGLE_FLOAT(name) CONCAT(fftutilf_,name)
#define MANGLE_DOUBLE(name) CONCAT(fftutil_,name)
#define MANGLE_LONG_DOUBLE(name) CONCAT(fftutill_,name)
DEFINE_API( MANGLE_FLOAT, float, float )
DEFINE_API( MANGLE_DOUBLE, double, double )
DEFINE_API( MANGLE_LONG_DOUBLE, long double, long double )
#undef MANGLE_FLOAT
#undef MANGLE_DOUBLE
#undef MANGLE_LONG_DOUBLE

/* Check for C99 or above for complex numbers */
#if ( __STDC_VERSION__ >= 199901L )
#define MANGLE_FLOAT_COMPLEX(name) CONCAT(fftutilfc_,name)
#define MANGLE_DOUBLE_COMPLEX(name) CONCAT(fftutilc_,name)
#define MANGLE_LONG_DOUBLE_COMPLEX(name) CONCAT(fftutillc_,name)
DEFINE_API( MANGLE_FLOAT_COMPLEX, float, float _Complex )
DEFINE_API( MANGLE_DOUBLE_COMPLEX, double, double _Complex )
DEFINE_API( MANGLE_LONG_DOUBLE_COMPLEX, long double, long double _Complex )
#undef MANGLE_FLOAT_COMPLEX
#undef MANGLE_DOUBLE_COMPLEX
#undef MANGLE_LONG_DOUBLE_COMPLEX
#endif


#undef DEFINE_API
#undef CONCAT


#endif /* FFT_UTIL_H_INCLUDED */
