#include "internal.h"

void X(ishift_1d)(TYPE *A, size_t Nx)
{
	size_t Nx2 = Nx/2;
	TYPE temp;
	if ( Nx%2 == 0 ) {
		for (size_t i=0; i<Nx2; i++) {
			temp = A[i];
			A[i] = A[Nx2+i];
			A[Nx2+i] = temp;
		}
	}
	else {
		temp = A[Nx2];
		for (size_t i=Nx2; i>0; i--) {
			A[i] = A[Nx2+i];
			A[Nx2+i] = A[i-1];
		}
		A[0] = temp;
	}
}

void X(ishift_ext1d)(TYPE *restrict out, const TYPE *restrict in, size_t Nx)
{
	size_t Nx2 = Nx/2;
	if ( Nx%2 == 0 ) {
		memcpy( out, in+Nx2, Nx2*sizeof(TYPE) );
		memcpy( out+Nx2, in, Nx2*sizeof(TYPE) );
	}
	else {
		memcpy( out, in+Nx2, (Nx2+1)*sizeof(TYPE) );
		memcpy( out+(Nx2+1), in, Nx2*sizeof(TYPE) );
	}
}
