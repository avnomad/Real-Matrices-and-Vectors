#include "Real Matrices and Vectors.h"
using namespace ASL;


TempMatrix ASL::toMatrix(Vector v , char dim)
{
	register unsigned int c;
	register anticast p;
	TempMatrix X;

	c = *v.data.ui++;	// set c to the # of elements of v.
	p.v = X.data.v = malloc(2*sizeof(unsigned int) + c*sizeof(double));	// allocate memory for the TempMatrix X.
	*p.ui++ = c;	// store v's # of elements in X.

	if(dim == 1)	// column vector.
		*p.ui++ = c;
	else			// row vector.
		*p.ui++ = 1;

	while(c--)
		*p.d++ = *v.data.d++;

	v.data.v = 0;	// prevents the destractor from deallocating v's memory.
	return X;
}

TempMatrix ASL::toMatrix(TempVector v , char dim)
{
	register unsigned int c;
	register anticast p,q;
	TempMatrix X;

	q = v.data;	// set q at the beginning of v.
	c = *q.ui++;	// set c to the # of elements of v.
	p.v = X.data.v = malloc(2*sizeof(unsigned int) + c*sizeof(double));	// allocate memory for the TempMatrix X.
	*p.ui++ = c;	// store v's # of elements in X.

	if(dim == 1)	// column vector.
		*p.ui++ = c;
	else			// row vector.
		*p.ui++ = 1;

	while(c--)
		*p.d++ = *q.d++;

	free(v.data.v);	// free v's memory.
	return X;
}
