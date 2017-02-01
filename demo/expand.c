#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

#include <fftw3.h>
#include "../ftu.h"


int main()
{
	size_t N = 10;
	double *fft_in = fftw_alloc_real(N);
	double _Complex *fft_out = fftw_alloc_complex(N);
	fftw_plan p = fftw_plan_dft_r2c_1d(N,fft_in,fft_out,FFTW_ESTIMATE);

	for (size_t i=0; i<N; i++) {
		fft_in[i] = i+1;
	}
	fftw_execute(p);

	double _Complex *out = ftuc_expandR2C_1d(fft_out,N);
	double _Complex *out_ext = malloc( N*sizeof(*out_ext) );
	ftuc_expandR2CExt_1d(out_ext,fft_out,N);
	ftuc_expandR2CIn_1d(fft_out,N);
	ftuc_shiftIn_1d(out,N);
	ftuc_shiftIn_1d(out_ext,N);
	ftuc_shiftIn_1d(fft_out,N);

	printf("New:\n");
	for (size_t i=0; i<N; i++) {
		printf("% lf %+lfi\n",creal(out[i]),cimag(out[i]));
	}
	printf("\nExt:\n");
	for (size_t i=0; i<N; i++) {
		printf("% lf %+lfi\n",creal(out_ext[i]),cimag(out_ext[i]));
	}
	printf("\nIn:\n");
	for (size_t i=0; i<N; i++) {
		printf("% lf %+lfi\n",creal(fft_out[i]),cimag(fft_out[i]));
	}

	fftw_free(fft_in);
	fftw_free(fft_out);
	free(out);
	free(out_ext);
	fftw_destroy_plan(p);

	return 0;
}
