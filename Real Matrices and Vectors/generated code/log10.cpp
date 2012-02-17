#include "../hand-written code/Real Matrices and Vectors.h"
using namespace ASL;


#pragma region Vector

TempVector ASL::log10(TempVector v)
{
	unsigned int c;
	anticast p;

	p.v = v.data.v;
	c = *p.ui++;
	while(c--)
		*p.d = ::log10(*p.d),++p.d;

	return v;
} //end of fuction log10


TempVector ASL::log10(Vector v)
{
	unsigned int c;
	anticast p;
	TempVector u;

	c = *v.data.ui++;
	p.v = u.data.v = malloc(sizeof(unsigned int) + c*sizeof(double));
	*p.ui++ = c;
	while(c--)
		*p.d++ = ::log10(*v.data.d++);

	v.data.v = 0;
	return u;
} //end of fuction log10

#pragma endregion
#pragma region Matrix

TempMatrix ASL::log10(TempMatrix A)
{	/* we will recycle the memory used by A. */
	register unsigned int c;
	register anticast p;

	p.v = A.data.v;
	c = *p.ui++;
	++p.ui;	// skip the # of rows.
	while(c--)
		*p.d = ::log10(*p.d),++p.d;

	return A;
} //end of fuction log10


TempMatrix ASL::log10(Matrix A)
{
	register unsigned int c;
	register anticast p;
	TempMatrix B;

	c = *A.data.ui++;	// set c to the # of elements in A.
	p.v = B.data.v = malloc(2*sizeof(unsigned int) + c*sizeof(double));
	*p.ui++ = c;	// store the # of elements of A in B.
	*p.ui++ = *A.data.ui++;	// store the # of rows of A in B.
	while(c--)
		*p.d++ = ::log10(*A.data.d++);

	A.data.v = 0;
	return B;
} //end of fuction log10

#pragma endregion
