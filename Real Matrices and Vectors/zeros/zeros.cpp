#include "../Real Matrices and Vectors.h"
using namespace ASL;


TempMatrix ASL::zeros(unsigned int order)
{
	TempMatrix A;
	register unsigned int c;

	c = order*order;
	A.data.v = calloc(1,2*sizeof(unsigned int) + c*sizeof(double));
	*A.data.ui = c;
	*(A.data.ui+1) = order;

	return A;
} // end function zeros



TempMatrix ASL::zeros(unsigned int rows,unsigned int cols)
{
	TempMatrix A;
	register unsigned int c;

	c = rows*cols;
	A.data.v = calloc(1,2*sizeof(unsigned int) + c*sizeof(double));
	*A.data.ui = c;
	*(A.data.ui+1) = rows;

	return A;
} // end function zeros
