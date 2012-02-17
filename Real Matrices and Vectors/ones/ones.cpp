#include "../Real Matrices and Vectors.h"
using namespace ASL;


TempMatrix ASL::ones(unsigned int order)
{
	TempMatrix A;
	register anticast p;
	register unsigned int c;

	c = order*order;	// but the # of elements in the matrix in c.
	p.v = A.data.v = malloc(2*sizeof(unsigned int) + c*sizeof(double)); // allocating memory for the elements of the matrix plus it's size.

	*p.ui++ = c;	// store the # of elements
	*p.ui++ = order;	// store the # of rows
	while(c--)
		*p.d++ = 1;

	return A;
} // end fuction ones


TempMatrix ASL::ones(unsigned int rows,unsigned int cols)
{
	TempMatrix A;
	register anticast p;
	register unsigned int c;

	c = rows*cols;	// but the # of elements in the matrix in c.
	p.v = A.data.v = malloc(2*sizeof(unsigned int) + c*sizeof(double)); // allocating memory for the elements of the matrix plus it's size.

	*p.ui++ = c;	// store the # of elements
	*p.ui++ = rows;	// store the # of rows
	while(c--)
		*p.d++ = 1;

	return A;
} // end fuction ones
