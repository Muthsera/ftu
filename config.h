#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED


/* define macro with project name */
#define NAME ftu


/* set default precision */
#if !defined( DOUBLE ) && !defined( LONG ) && !defined( LONG_DOUBLE ) &&\
	!defined( SINGLE ) && !defined( FLOAT )
#define DOUBLE
#endif


#endif /* CONFIG_H_INCLUDED */
