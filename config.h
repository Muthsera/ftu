#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED


/* define macro with project name */
#define NAME ftu


/* set default precision */
#if !defined( DOUBLE ) && !defined( LONG ) && !defined( LONG_DOUBLE ) &&\
	!defined( SINGLE ) && !defined( FLOAT )
#define DOUBLE
#endif

/* set default type: complex or real */
#if !defined( NO_COMPLEX ) && !defined( COMPLEX )
#define NO_COMPLEX
#endif


#endif /* CONFIG_H_INCLUDED */
