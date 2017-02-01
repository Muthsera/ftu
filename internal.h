#ifndef INTERNAL_H_INCLUDED
#define INTERNAL_H_INCLUDED


#include "ftu.h"
#include "config.h"

#include <stdlib.h>
#include <string.h>
#include <complex.h>
#include <float.h>


#define HIDDEN_CONCAT(x,y) x ## y
#define CONCAT(x,y) HIDDEN_CONCAT(x,y)

#if defined( DOUBLE )
	#define PREFIX CONCAT(NAME,_)
	#define CPREFIX CONCAT(NAME,c_)
	#define XM(func) f ## func
	#define XMC(func) c ## func
	#define X(name) CONCAT(PREFIX,name)
	#define XC(name) CONCAT(CPREFIX,name)
	#define FORMAT lf
	#define FLOATING_MAX DBL_MAX
	typedef double PREC;
	typedef double REAL;
	#if ( __STDC_VERSION__ >= 199901L )
	typedef double _Complex COMPL;
	#endif
#elif defined( LONG ) || defined( LONG_DOUBLE )
	#define PREFIX CONCAT(NAME,l_)
	#define CPREFIX CONCAT(NAME,lc_)
	#define XM(func) f ## func ## l
	#define XMC(func) c ## func ## l
	#define X(name) CONCAT(PREFIX,name)
	#define XC(name) CONCAT(CPREFIX,name)
	#define FORMAT Lf
	#define FLOATING_MAX LDBL_MAX
	typedef long double PREC;
	typedef long double REAL;
	#if ( __STDC_VERSION__ >= 199901L )
	typedef long double _Complex COMPL;
	#endif
#elif defined( SINGLE ) || defined( FLOAT )
	#define PREFIX CONCAT(NAME,f_)
	#define CPREFIX CONCAT(NAME,fc_)
	#define XM(func) f ## func ## f
	#define XMC(func) c ## func ## f
	#define X(name) CONCAT(PREFIX,name)
	#define XC(name) CONCAT(CPREFIX,name)
	#define FORMAT f
	#define FLOATING_MAX FLOAT_MAX
	typedef float PREC;
	typedef float REAL;
	#if ( __STDC_VERSION__ >= 199901L )
	typedef float _Complex COMPL;
	#endif
#endif


#endif /* INTERNAL_H_INCLUDED */
