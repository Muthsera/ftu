TYPE* APIprefix(expandR2C_1d)(const TYPE *in, size_t Nx)
{
	if ( in == NULL || Nx < 2 ) return NULL;

	TYPE *out = malloc( Nx * sizeof(*out) );
	APIprefix(expandR2CExt_1d)(out,in,Nx);
	return out;
}


void APIprefix(expandR2CIn_1d)(TYPE *A, size_t Nx)
{
	if ( A == NULL || Nx < 2 ) return;

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


void APIprefix(expandR2CExt_1d)(TYPE *restrict out, const TYPE *restrict in,
		size_t Nx)
{
	if ( out == NULL || in == NULL || Nx < 2 ) return;

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
