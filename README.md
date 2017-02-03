# ftu
several routines for use with fourier transforms

## Contents
As of now the library contains the routines:  
* `expandR2C`, which expands the output vector of a `R->C` transform  
to the whole field size and
* `shift` and `ishift`, which produces the known "shifted" fields,  
used after and before a fft or ifft respectively.

All of these routines are available in 1d, which entails the suffix `_1d`  
and also in three different precisions (float, double, long double) as well  
as complex numbers. The latter combined with the library prefix `ftu`  
results for example in the prefixes  
* `ftuf_` for the real float library,
* `ftuc_` for the complex double library and
* `ftulc_` for the complex long double library.
