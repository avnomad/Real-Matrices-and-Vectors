#include "Real Matrices and Vectors.h"
using namespace ASL;


TempMatrix ASL::transpose(Matrix A)
{
	register unsigned int c,i;
	register anticast row;
	register anticast p;
	register double *el;
	unsigned int rows,cols;
	TempMatrix B;

	row = A.data;	// set row at the beginning of the first row.
	c = *row.ui++;	// set c to the # of elements in the matrix
	rows = *row.ui++;	// set rows to the # of rows of the matrix
	i = cols = c / rows;	// set i and cols to the # of columns of the matrix
	el = row.d;	// set el to the first element of the first row

	p.v = B.data.v = malloc(2*sizeof(unsigned int) + c*sizeof(double));
	*p.ui++ = c;	// store the # of elements of A in B.
	*p.ui++ = cols;	// store the # of columns of A as the # of rows of B.

 	while(c--)
	{
		*p.d++ = *el;
		if(!--i)
		{
			el = ++row.d;
			i = cols;
			continue;
		}
		el += rows;	// move el to the next element in the row
	}		

	A.data.v = 0;	//prevents the destractor from deallocating A's memory.
	return B;
} // end fuction transpose


TempMatrix ASL::transpose(TempMatrix A)
{
	register unsigned int c,i;
	register anticast row;
	register anticast p;
	register double *el;
	unsigned int rows,cols;
	TempMatrix B;

	row = A.data;	// set row at the beginning of the first row.
	c = *row.ui++;	// set c to the # of elements in the matrix
	rows = *row.ui++;	// set rows to the # of rows of the matrix
	i = cols = c / rows;	// set i and cols to the # of columns of the matrix
	el = row.d;	// set el to the first element of the first row

	p.v = B.data.v = malloc(2*sizeof(unsigned int) + c*sizeof(double));
	*p.ui++ = c;	// store the # of elements of A in B.
	*p.ui++ = cols;	// store the # of columns of A as the # of rows of B.

 	while(c--)
	{
		*p.d++ = *el;
		if(!--i)
		{
			el = ++row.d;
			i = cols;
			continue;
		}
		el += rows;	// move el to the next element in the row
	}		

	free(A.data.v);	// free A's memory.
	return B;
} // end fuction transpose
