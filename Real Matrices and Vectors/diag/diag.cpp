#include "../Real Matrices and Vectors.h"
using namespace ASL;


TempVector ASL::diag(Matrix A , int d)
{
	register unsigned int c;
	register anticast p,q;
	TempVector v;
	unsigned int rows;

	q = A.data;	// set q at the beginning of A.
	c = *q.ui++;	// set c to the # of elements of A.
	rows = *q.ui++;	// set rows to the # of rows of A.
	if( d > 0 )
	{
		c = ASL::min(rows , c/rows - d);	// calculate the length of the diagonal.
		q.d += d*rows;	// set q at the beginning of the selected diagonal.
	}
	else
	{
		c = ASL::min(rows + d , c/rows);	// calculate the length of the diagonal.
		q.d -= d;	// set q at the beginning of the selected diagonal.
	}

	p.v = v.data.v = malloc(sizeof(unsigned int) + c*sizeof(double));
	*p.ui++ = c;	// store v's # of elements in v.

	++rows;
	while(c--)
	{
		*p.d++ = *q.d;	// copy elements from selested diagonal of A to v.
		q.d += rows;
	}

	A.data.v = 0; // prevent the destractor from deallocating A's memory.
	return v;
} // end function diag


TempVector ASL::diag(TempMatrix A , int d)
{
	register unsigned int c;
	register anticast p,q;
	TempVector v;
	unsigned int rows;

	q = A.data;	// set q at the beginning of A.
	c = *q.ui++;	// set c to the # of elements of A.
	rows = *q.ui++;	// set rows to the # of rows of A.
	if( d > 0 )
	{
		c = ASL::min(rows , c/rows - d);	// calculate the length of the diagonal.
		q.d += d*rows;	// set q at the beginning of the selected diagonal.
	}
	else
	{
		c = ASL::min(rows + d , c/rows);	// calculate the length of the diagonal.
		q.d -= d;	// set q at the beginning of the selected diagonal.
	}

	p.v = v.data.v = malloc(sizeof(unsigned int) + c*sizeof(double));
	*p.ui++ = c;	// store v's # of elements in v.

	++rows;
	while(c--)
	{
		*p.d++ = *q.d;	// copy elements from selested diagonal of A to v.
		q.d += rows;
	}

	free(A.data.v); // free A's memory.
	return v;
} // end function diag


TempMatrix ASL::diag(Vector v,int d)
{
	register unsigned int c;
	register anticast p,q;
	TempMatrix A;
	unsigned int rows;

	q = v.data;	// set q at the beginning of v.
	rows = *q.ui + ::abs(d);	// set rows to the size of v plus the absolute value of d.
	c = rows*rows;	// set c to rows times rows.

	p.v = A.data.v = calloc(1,2*sizeof(unsigned int) + c*sizeof(double));
	*p.ui++ = c;	// store the # of elements of A.
	*p.ui++ = rows;	// store the # of rows of A.
	if( d > 0 )
		p.d += d*rows;	// set q at the beginning of the selected diagonal.
	else
		p.d -= d;	// set q at the beginning of the selected diagonal.

	c = *q.ui++;	// set c to the # of elements of v.
	++rows;	// increment rows to represent the move needed to advance to the next element of the diagonal.
	while(c--)
	{
		*p.d = *q.d++;
		p.d += rows;
	}

	v.data.v = 0; // prevent the destractor from deallocating v's memory.
	return A;
}


TempMatrix ASL::diag(TempVector v,int d)
{
	register unsigned int c;
	register anticast p,q;
	TempMatrix A;
	unsigned int rows;

	q = v.data;	// set q at the beginning of v.
	rows = *q.ui + ::abs(d);	// set rows to the size of v plus the absolute value of d.
	c = rows*rows;	// set c to rows times rows.

	p.v = A.data.v = calloc(1,2*sizeof(unsigned int) + c*sizeof(double));
	*p.ui++ = c;	// store the # of elements of A.
	*p.ui++ = rows;	// store the # of rows of A.
	if( d > 0 )
		p.d += d*rows;	// set q at the beginning of the selected diagonal.
	else
		p.d -= d;	// set q at the beginning of the selected diagonal.

	c = *q.ui++;	// set c to the # of elements of v.
	++rows;	// increment rows to represent the move needed to advance to the next element of the diagonal.
	while(c--)
	{
		*p.d = *q.d++;
		p.d += rows;
	}

	free(v.data.v); // free v's memory.
	return A;
}

