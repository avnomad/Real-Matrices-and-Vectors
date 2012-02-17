#include "../hand-written code/Real Matrices and Vectors.h"
using namespace ASL;


#pragma region Vector

TempVector ASL::abs(TempVector v)
{
	unsigned int c;
	anticast p;

	p.v = v.data.v;
	c = *p.ui++;
	while(c--)
		*p.d = ::fabs(*p.d),++p.d;

	return v;
} //end of fuction abs


TempVector ASL::abs(Vector v)
{
	unsigned int c;
	anticast p;
	TempVector u;

	c = *v.data.ui++;
	p.v = u.data.v = malloc(sizeof(unsigned int) + c*sizeof(double));
	*p.ui++ = c;
	while(c--)
		*p.d++ = ::fabs(*v.data.d++);

	v.data.v = 0;
	return u;
} //end of fuction abs

#pragma endregion
#pragma region Matrix

TempMatrix ASL::abs(TempMatrix A)
{	/* we will recycle the memory used by A. */
	register unsigned int c;
	register anticast p;

	p.v = A.data.v;
	c = *p.ui++;
	++p.ui;	// skip the # of rows.
	while(c--)
		*p.d = ::fabs(*p.d),++p.d;

	return A;
} //end of fuction abs


TempMatrix ASL::abs(Matrix A)
{
	register unsigned int c;
	register anticast p;
	TempMatrix B;

	c = *A.data.ui++;	// set c to the # of elements in A.
	p.v = B.data.v = malloc(2*sizeof(unsigned int) + c*sizeof(double));
	*p.ui++ = c;	// store the # of elements of A in B.
	*p.ui++ = *A.data.ui++;	// store the # of rows of A in B.
	while(c--)
		*p.d++ = ::fabs(*A.data.d++);

	A.data.v = 0;
	return B;
} //end of fuction abs

#pragma endregion