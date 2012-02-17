#include "../Real Matrices and Vectors.h"
using namespace ASL;


#pragma region Scalar

// polyval(v,x) returns the value of a polynomial of degree n evaluated at x.
// The input argument v is a vector of length n+1 whose elements are the coefficients
// in descending powers of the polynomial to be evaluated.

double ASL::polyval(Vector v,double x)
{
	register double result;
	register unsigned int c;

	c = *v.data.ui++;
	result = *v.data.d;
	while(--c)
		result = result*x + *++v.data.d;

	v.data.v = 0;
	return result;
} // end function polyval


double ASL::polyval(TempVector v,double x)
{
	register double result;
	register unsigned int c;
	register anticast p = v.data;

	c = *v.data.ui++;
	result = *v.data.d;
	while(--c)
		result = result*x + *++v.data.d;

	free(p.v);
	return result;
} // end function polyval


//double polyval(Vector v,double x)				// alternative implementation. the asterisks mark the lines that are the same.
//{												// this implementation should be slightly worse as it does 1 more addition.
//*	double result = 0;							// is postincrementing faster or slower than preincrementing?
//*	register unsigned int c;
//
//*	c = *v.data.ui++;
//*	while(--c)
//		result = (result + *v.data.d++)*x;
//	result += *v.data.d;
//
//*	v.data.v = 0;
//*	return result;
//}

#pragma endregion
#pragma region Vector

TempVector ASL::polyval(Vector polyonym , TempVector v)
{
	register unsigned int c;
	register anticast p;

	p.v = v.data.v;
	c = *p.ui++;
	while(c--)
		*p.d = polyval(polyonym , *p.d),++p.d;

	polyonym.data.v = 0;
	return v;
} //end of fuction polyval


TempVector ASL::polyval(TempVector polyonym , TempVector v)
{
	register unsigned int c;
	register anticast p;
	Vector poly;

	poly = polyonym;

	p.v = v.data.v;
	c = *p.ui++;
	while(c--)
		*p.d = polyval(poly , *p.d),++p.d;

	return v;
} //end of fuction polyval


TempVector ASL::polyval(Vector polyonym , Vector v)
{
	register unsigned int c;
	register anticast p;
	TempVector u;

	c = *v.data.ui++;
	p.v = u.data.v = malloc(sizeof(unsigned int) + c*sizeof(double));
	*p.ui++ = c;
	while(c--)
		*p.d++ = polyval(polyonym , *v.data.d++);

	polyonym.data.v = v.data.v = 0;
	return u;
} //end of fuction polyval


TempVector ASL::polyval(TempVector polyonym , Vector v)
{
	register unsigned int c;
	register anticast p;
	TempVector u;
	Vector poly;

	poly = polyonym;

	c = *v.data.ui++;
	p.v = u.data.v = malloc(sizeof(unsigned int) + c*sizeof(double));
	*p.ui++ = c;
	while(c--)
		*p.d++ = polyval(poly , *v.data.d++);

	v.data.v = 0;
	return u;
} //end of fuction polyval

#pragma endregion
#pragma region Matrix

TempMatrix ASL::polyval(Vector polyonym , TempMatrix A)
{	/* we will recycle the memory used by A. */
	register unsigned int c;
	register anticast p;

	p.v = A.data.v;
	c = *p.ui++;
	++p.ui;	// skip the # of rows.
	while(c--)
		*p.d = polyval(polyonym , *p.d),++p.d;

	polyonym.data.v = 0;
	return A;
} //end of fuction polyval


TempMatrix ASL::polyval(TempVector polyonym , TempMatrix A)
{	/* we will recycle the memory used by A. */
	register unsigned int c;
	register anticast p;
	Vector poly;

	poly = polyonym;

	p.v = A.data.v;
	c = *p.ui++;
	++p.ui;	// skip the # of rows.
	while(c--)
		*p.d = polyval(poly , *p.d),++p.d;

	return A;
} //end of fuction polyval


TempMatrix ASL::polyval(Vector polyonym , Matrix A)
{
	register unsigned int c;
	register anticast p;
	TempMatrix B;

	c = *A.data.ui++;	// set c to the # of elements in A.
	p.v = B.data.v = malloc(2*sizeof(unsigned int) + c*sizeof(double));
	*p.ui++ = c;	// store the # of elements of A in B.
	*p.ui++ = *A.data.ui++;	// store the # of rows of A in B.
	while(c--)
		*p.d++ = polyval(polyonym , *A.data.d++);

	polyonym.data.v = A.data.v = 0;
	return B;
} //end of fuction polyval


TempMatrix ASL::polyval(TempVector polyonym , Matrix A)
{
	register unsigned int c;
	register anticast p;
	TempMatrix B;
	Vector poly;

	poly = polyonym;

	c = *A.data.ui++;	// set c to the # of elements in A.
	p.v = B.data.v = malloc(2*sizeof(unsigned int) + c*sizeof(double));
	*p.ui++ = c;	// store the # of elements of A in B.
	*p.ui++ = *A.data.ui++;	// store the # of rows of A in B.
	while(c--)
		*p.d++ = polyval(poly , *A.data.d++);

	A.data.v = 0;
	return B;
} //end of fuction polyval

#pragma endregion
