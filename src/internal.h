#ifndef INTERNAL_H_INCLUDED
#define INTERNAL_H_INCLUDED


#include "fft_util.h"
#include "config.h"

#include <stdlib.h>
#include <string.h>
#include <float.h>

#define HIDDEN_CONCAT(x,y) x ## y
#define CONCAT(x,y) HIDDEN_CONCAT(x,y)

#if defined( DOUBLE )
	typedef double PREC;
	#if defined( NO_COMPLEX )
		typedef double TYPE;
		#define PREFIX CONCAT(NAME,_)
		#define XM(func) func
	#elif defined( COMPLEX )
		typedef double _Complex TYPE;
		#define PREFIX CONCAT(NAME,c_)
		#define XM(func) c ## func
	#endif
	#define X(name) CONCAT(PREFIX,name)
	#define FORMAT lf
	#define FLOATING_MAX DBL_MAX
#elif defined( LONG ) || defined( LONG_DOUBLE )
	typedef long double PREC;
	#if defined( NO_COMPLEX )
		typedef long double TYPE;
		#define PREFIX CONCAT(NAME,l_)
		#define XM(func) f ## func ## l
	#elif defined( COMPLEX )
		typedef long double _Complex TYPE;
		#define PREFIX CONCAT(NAME,lc_)
		#define XM(func) c ## func ## l
	#endif
	#define X(name) CONCAT(PREFIX,name)
	#define FORMAT Lf
	#define FLOATING_MAX LDBL_MAX
#elif defined( SINGLE ) || defined( FLOAT )
	typedef float PREC;
	#if defined( NO_COMPLEX )
		typedef float TYPE;
		#define PREFIX CONCAT(NAME,f_)
		#define XM(func) f ## func ## f
	#elif defined( COMPLEX )
		typedef float _Complex TYPE;
		#define PREFIX CONCAT(NAME,fc_)
		#define XM(func) c ## func ## f
	#endif
	#define X(name) CONCAT(PREFIX,name)
	#define FORMAT f
	#define FLOATING_MAX FLOAT_MAX
#endif



#endif /* INTERNAL_H_INCLUDED */
