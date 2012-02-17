#include "../Real Matrices and Vectors.h"
using namespace ASL;


#pragma region Vector

TempVector ASL::asin(TempVector v)
{
	unsigned int c;
	anticast p;

	p.v = v.data.v;
	c = *p.ui++;
	while(c--)
		*p.d = ::asin(*p.d),++p.d;

	return v;
} //end of fuction asin


TempVector ASL::asin(Vector v)
{
	unsigned int c;
	anticast p;
	TempVector u;

	c = *v.data.ui++;
	p.v = u.data.v = malloc(sizeof(unsigned int) + c*sizeof(double));
	*p.ui++ = c;
	while(c--)
		*p.d++ = ::asin(*v.data.d++);

	v.data.v = 0;
	return u;
} //end of fuction asin

#pragma endregion
#pragma region Matrix

TempMatrix ASL::asin(TempMatrix A)
{	/* we will recycle the memory used by A. */
	register unsigned int c;
	register anticast p;

	p.v = A.data.v;
	c = *p.ui++;
	++p.ui;	// skip the # of rows.
	while(c--)
		*p.d = ::asin(*p.d),++p.d;

	return A;
} //end of fuction asin


TempMatrix ASL::asin(Matrix A)
{
	register unsigned int c;
	register anticast p;
	TempMatrix B;

	c = *A.data.ui++;	// set c to the # of elements in A.
	p.v = B.data.v = malloc(2*sizeof(unsigned int) + c*sizeof(double));
	*p.ui++ = c;	// store the # of elements of A in B.
	*p.ui++ = *A.data.ui++;	// store the # of rows of A in B.
	while(c--)
		*p.d++ = ::asin(*A.data.d++);

	A.data.v = 0;
	return B;
} //end of fuction asin

#pragma endregion
