#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#include <fftw3.h>
#include "../src/fftutil.h"


int main(void)
{
	size_t N = 1024;
	double _Complex *yin = fftw_alloc_complex(N);
	double _Complex *yout = fftw_alloc_complex(N);
	fftw_plan plan = fftw_plan_dft_1d(N,yin,yout,FFTW_FORWARD,FFTW_ESTIMATE);

	for (size_t i=0; i<N; i++) {
		yin[i] = 0.005*i * sin(0.15*i);
	}
	fftw_execute(plan);
	fftutilc_shift_1d(yout,N);

	fftw_destroy_plan(plan);
	fftw_free(yin);
	fftw_free(yout);
	return 0;
}
