#include "internal.h"

void X(expandR2C_1d)(TYPE *A, size_t Nx)
{
	size_t Nx2 = Nx/2;
	if ( Nx%2 == 0 ) {
		for (size_t i=1; i<Nx2; i++) {
			A[Nx-i] = conj(A[i]);
		}
	}
	else {
		for (size_t i=1; i<=Nx2; i++) {
			A[Nx-i] = conj(A[i]);
		}
	}
}

void X(expandR2C_ext1d)(TYPE *restrict out, const TYPE *restrict in, size_t Nx)
{
	size_t Nx2 = Nx/2;
	if ( Nx%2 == 0 ) {
		out[0] = in[0];
		for (size_t i=1; i<Nx2; i++) {
			out[i] = in[i];
			out[Nx-i] = conj(in[i]);
		}
		out[Nx2] = in[Nx2];
	}
	else {
		out[0] = in[0];
		for (size_t i=1; i<=Nx2; i++) {
			out[i] = in[i];
			out[Nx-i] = conj(in[i]);
		}
	}
}
