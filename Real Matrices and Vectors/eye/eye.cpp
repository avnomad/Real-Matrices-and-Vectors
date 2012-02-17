#include "../Real Matrices and Vectors.h"
using namespace ASL;


TempMatrix ASL::eye(unsigned int order)
{
	TempMatrix A;
	register anticast p;
	register unsigned int c;

	c = order*order;
	p.v = A.data.v = calloc(1,2*sizeof(unsigned int) + c*sizeof(double));
	*p.ui++ = c;
	c = *p.ui++ = order;
	*p.d = 1;
	while(--c)
	{
		p.d += order;
		*++p.d = 1;
	}

	return A;
} // end function eye



TempMatrix ASL::eye(unsigned int rows,unsigned int cols)
{
	TempMatrix A;
	register anticast p;
	register unsigned int c;

	c = rows*cols;
	p.v = A.data.v = calloc(1,2*sizeof(unsigned int) + c*sizeof(double));
	*p.ui++ = c;
	*p.ui++ = rows;
	c = ASL::Utility::min(rows,cols);
	*p.d = 1;
	while(--c)
	{
		p.d += rows;
		*++p.d = 1;
	}

	return A;
} // end function eye
