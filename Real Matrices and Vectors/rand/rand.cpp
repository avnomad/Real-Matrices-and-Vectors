#include "../Real Matrices and Vectors.h"
using namespace ASL;


TempVector ASL::rand(unsigned int length) // poor implementation. random numbers are integers instead of reals in the interval [0,1). for demonstration purposes only
{
	TempVector v;
	anticast p;

	p.v = v.data.v = malloc(sizeof(unsigned int) + length*sizeof(double)); // allocating memory for the elements of the vector plus it's size.

	*p.ui++ = length;
	while(length--)
		*p.d++ = ::rand();

	return v;
} // end fuction rand


TempMatrix ASL::rand(unsigned int rows,unsigned int cols) // poor implementation. random numbers are integers instead of reals in the interval [0,1). for demonstration purposes only
{
	TempMatrix A;
	register anticast p;
	register unsigned int c;

	c = rows*cols;	// but the # of elements of the matrix in c.
	p.v = A.data.v = malloc(2*sizeof(unsigned int) + c*sizeof(double)); // allocating memory for the elements of the matrix plus it's size.

	*p.ui++ = c;
	*p.ui++ = rows;
	while(c--)
		*p.d++ = ::rand();

	return A;
} // end fuction rand
