#include "../Real Matrices and Vectors.h"
using namespace ASL;



// vectors v and u are assumed to be of the same size.
TempVector ASL::max(Vector v, Vector u)	// overloaded version 1
{
	TempVector w;
	unsigned int c;
	anticast p;

	c = *v.data.ui++;
	++u.data.ui;
	p.v = w.data.v = malloc(sizeof(unsigned int) + c*sizeof(double));
	*p.ui++ = c;
	while(c--)
		*p.d++ = ASL::Utility::max(*v.data.d++ , *u.data.d) , ++u.data.d;

	v.data.v = u.data.v = 0;
	return w;
} // end function max overloaded version 1


// vectors v and u are assumed to be of the same size.
TempVector ASL::max(TempVector v, Vector u)	// overloaded version 2
{
	unsigned int c;
	anticast p;

	p = v.data;
	c = *p.ui++;
	++u.data.ui;

	while(c--)
		*p.d = ASL::Utility::max(*p.d , *u.data.d) , ++p.d , ++u.data.d;

	u.data.v = 0;
	return v;
} // end function max overloaded version 2


// vectors v and u are assumed to be of the same size.
TempVector ASL::max(Vector u, TempVector v)	// overloaded version 3
{
	unsigned int c;
	anticast p;

	p = v.data;
	c = *p.ui++;
	++u.data.ui;

	while(c--)
		*p.d = ASL::Utility::max(*u.data.d++ , *p.d) , ++p.d;

	u.data.v = 0;
	return v;
} // end function max overloaded version 3


// vectors v and u are assumed to be of the same size.
TempVector ASL::max(TempVector v, TempVector u)	// overloaded version 4
{
	unsigned int c;
	anticast p,q;

	p = v.data;
	q = u.data;
	c = *p.ui++;
	++q.ui;

	while(c--)
		*p.d = ASL::Utility::max(*p.d , *q.d) , ++p.d , ++q.d;

	free(u.data.v);
	return v;
} // end function max overloaded version 4


TempVector ASL::max(double x, Vector v)	// overloaded version 5
{
	unsigned int c;
	TempVector u;
	anticast p;

	c = *v.data.ui++;	// get the size of v.
	p.v = u.data.v = malloc(sizeof(unsigned int) + c*sizeof(double));	// allocate memory for a new TempVector of that size.
	*p.ui++ = c;		// save the size of the new TempVector.

	while(c--)		// for each element of v.
		*p.d++ = ASL::Utility::max(x , *v.data.d) , ++v.data.d;

	v.data.v = 0;	// prevents the destractor from deallocating v's memory.
	return u;
} // end function max overloaded version 5


TempVector ASL::max(Vector v, double x)	// overloaded version 6
{
	unsigned int c;
	TempVector u;
	anticast p;

	c = *v.data.ui++;	// get the size of v.
	p.v = u.data.v = malloc(sizeof(unsigned int) + c*sizeof(double));	// allocate memory for a new TempVector of that size.
	*p.ui++ = c;		// save the size of the new TempVector.

	while(c--)		// for each element of v.
		*p.d++ = ASL::Utility::max(*v.data.d++ , x);

	v.data.v = 0;	// prevents the destractor from deallocating v's memory.
	return u;
} // end function max overloaded version 6


TempVector ASL::max(double x, TempVector v)	// overloaded version 7
{	/* we will recycle the memory used by v. */
	unsigned int c;
	anticast p;

	p = v.data;		// set p to point at the begining of v.
	c = *p.ui++;	// get the size of v.

	while(c--)		// for each element of v.
		*p.d = ASL::Utility::max(x , *p.d) , ++p.d;

	return v;
} // end function max overloaded version 7


TempVector ASL::max(TempVector v, double x)	// overloaded version 8
{	/* we will recycle the memory used by v. */
	unsigned int c;
	anticast p;

	p = v.data;		// set p to point at the begining of v.
	c = *p.ui++;	// get the size of v.

	while(c--)		// for each element of v.
		*p.d = ASL::Utility::max(*p.d , x) , ++p.d;

	return v;
} // end function max overloaded version 8


// matrices A and B are assumed to be of the same size.
TempMatrix ASL::max(Matrix A, Matrix B)	// overloaded version 9
{
	register unsigned int c;
	register anticast p;
	TempMatrix C;

	c = *A.data.ui++;	// set c to the # of elements of A.
	++B.data.ui;	// skip the # of elements of B.
	p.v = C.data.v = malloc(2*sizeof(unsigned int) + c*sizeof(double));
	*p.ui++ = c;	// store the # of elements of A in C.
	*p.ui++ = *A.data.ui++;	// store the # of rows of A in C.
	++B.data.ui;	// skip the # of rows of B.

	while(c--)
		*p.d++ = ASL::Utility::max(*A.data.d++ , *B.data.d) , ++B.data.d;

	A.data.v = B.data.v = 0;	// prevent the destractor from deallocating A's and B's memory.
	return C;
} // end function max overloaded version 9


// matrices A and B are assumed to be of the same size.
TempMatrix ASL::max(TempMatrix A, Matrix B)	// overloaded version 10
{	/* we will recycle the memory used by A. */
	register unsigned int c;
	register anticast p;

	p = A.data;		// set p at the begining of A.
	c = *p.ui++;	// set c to the # of elements of A.
	++B.data.ui;	// skip the # of elements of B.
	++p.ui , ++B.data.ui;	// skip the # of rows of A and B.

	while(c--)
		*p.d = ASL::Utility::max(*p.d , *B.data.d) , ++p.d , ++B.data.d;

	B.data.v = 0;	// prevent the destractor from deallocating B's memory.
	return A;
} // end function max overloaded version 10


// matrices A and B are assumed to be of the same size.
TempMatrix ASL::max(Matrix B, TempMatrix A)	// overloaded version 11
{	/* we will recycle the memory used by A. */
	register unsigned int c;
	register anticast p;

	p = A.data;		// set p at the begining of A.
	c = *p.ui++;	// set c to the # of elements of A.
	++B.data.ui;	// skip the # of elements of B.
	++p.ui , ++B.data.ui;	// skip the # of rows of A and B.

	while(c--)
		*p.d = ASL::Utility::max(*B.data.d++ , *p.d) , ++p.d;

	B.data.v = 0;
	return A;
} // end function max overloaded version 11


// matrices A and B are assumed to be of the same size.
TempMatrix ASL::max(TempMatrix A, TempMatrix B)	// overloaded version 12
{	/* we will recycle the memory used by A. */
	register unsigned int c;
	register anticast p,q;

	p = A.data;		// set p at the begining of A.
	q = B.data;		// set q at the begining of B.
	c = *p.ui++;	// set c to the # of elements of A.
	++q.ui;	// skip the # of elements of B.
	++p.ui , ++q.ui;	// skip the # of rows of A and B.

	while(c--)
		*p.d = ASL::Utility::max(*p.d , *q.d) , ++p.d , ++q.d;

	free(B.data.v);	// free the memory occupied by the temporary matric B.
	return A;
} // end function max overloaded version 12


TempMatrix ASL::max(double x, Matrix A)	// overloaded version 13
{
	register unsigned int c;
	register anticast p;
	TempMatrix B;

	c = *A.data.ui++;	// set c to the # of elements of A.
	p.v = B.data.v = malloc(2*sizeof(unsigned int) + c*sizeof(double));	// allocate memory for a new TempMatrix of that many elements.
	*p.ui++ = c;	// store the # of elements of A in B.
	*p.ui++ = *A.data.ui++;	// store the # of rows of A in B.

	while(c--)		// for each element of A.
		*p.d++ = ASL::Utility::max(x , *A.data.d) , ++A.data.d;

	A.data.v = 0;	// prevents the destractor from deallocating A's memory.
	return B;
} // end function max overloaded version 13


TempMatrix ASL::max(Matrix A, double x)	// overloaded version 14
{
	register unsigned int c;
	TempMatrix B;
	register anticast p;

	c = *A.data.ui++;	// set c to the # of elements of A.
	p.v = B.data.v = malloc(2*sizeof(unsigned int) + c*sizeof(double));	// allocate memory for a new TempMatrix of that many elements.
	*p.ui++ = c;	// store the # of elements of A in B.
	*p.ui++ = *A.data.ui++;	// store the # of rows of A in B.

	while(c--)		// for each element of A.
		*p.d++ = ASL::Utility::max(*A.data.d++ , x);

	A.data.v = 0;	// prevents the destractor from deallocating A's memory.
	return B;
} // end function max overloaded version 14


TempMatrix ASL::max(double x, TempMatrix A)	// overloaded version 15
{	/* we will recycle the memory used by A. */
	register unsigned int c;
	register anticast p;

	p = A.data;		// set p to point at the begining of A.
	c = *p.ui++;	// set c to the # of elements of A.
	++p.ui;	// skip the # of rows of A.

	while(c--)		// for each element of A.
		*p.d = ASL::Utility::max(x , *p.d) , ++p.d;

	return A;
} // end function max overloaded version 15


TempMatrix ASL::max(TempMatrix A, double x)	// overloaded version 16
{	/* we will recycle the memory used by A. */
	register unsigned int c;
	register anticast p;

	p = A.data;		// set p to point at the begining of A.
	c = *p.ui++;	// set c to the # of elements of A.
	++p.ui;	// skip the # of rows of A.

	while(c--)		// for each element of A.
		*p.d = ASL::Utility::max(*p.d , x) , ++p.d;

	return A;
} // end function max overloaded version 16


// doesn't work on vectors with 0 elements.
double ASL::max(Vector v) // overloaded version 17
{
	register unsigned int c;
	register anticast p;
	register double accumulator;

	p = v.data;	// set p at the beginning of v.
	c = *p.ui++;	// set c to the # of elements of v.

	accumulator = *p.d;
	while(--c)
		accumulator = ASL::Utility::max(accumulator , *++p.d);

	v.data.v = 0;	// prevent the destractor from deallocating v's memory.
	return accumulator;
} // end function max overloaded version 17


// doesn't work on vectors with 0 elements.
double ASL::max(TempVector v) // overloaded version 18
{
	register unsigned int c;
	register anticast p;
	register double accumulator;

	p = v.data;	// set p at the beginning of v.
	c = *p.ui++;	// set c to the # of elements of v.

	accumulator = *p.d;
	while(--c)
		accumulator = ASL::Utility::max(accumulator , *++p.d);

	free(v.data.v);	// free v's memory.
	return accumulator;
} // end function max overloaded version 18


// doesn't work on matrices with 0 elements.
TempVector ASL::max(Matrix A , unsigned int dim) // overloaded version 19
{
	register unsigned int reduceDimention,c;
	register anticast source,destination;
	register double accumulator;
	unsigned int otherDimention;
	TempVector v;

	source = A.data;	// set source at the first element of the first column of A.
	reduceDimention = *source.ui++;	// set reduceDimention to the # of elements of A.

	if(dim == 1)
	{
			// calculate dimentions and prepare A.
		otherDimention = reduceDimention / *source.ui;	// set otherDimention to the # of columns of A.
		reduceDimention = *source.ui++;	// set reduceDimantion to the # of rows of A.
			// prepare v.
		destination.v = v.data.v = malloc(sizeof(unsigned int) + otherDimention*sizeof(double));	// allocate memory for v.
		*destination.ui++ = otherDimention;	// store the # of elements of v in v.
			// perform the actual computation.
		while(otherDimention--)	// for each column of A.
		{
			c = reduceDimention;	// set c to the # of rows of A.
			accumulator = *source.d;	// initialize accumulator with the first element of the current column.
			while(--c)	// reduce the current column
				accumulator = ASL::Utility::max(accumulator , *++source.d);
			*destination.d++ = accumulator;	// store the result from reducing this column in v.
			++source.d;	// move the the next column.
		} // end outer while
	}
	else
	{
			// calculate dimentions and prepare A.
		reduceDimention = reduceDimention / *source.ui;	// set reduceDimention to the # of columns of A.
		otherDimention = *source.ui++;	// set otherDimantion to the # of rows of A.
			// prepare v.
		destination.v = v.data.v = malloc(sizeof(unsigned int) + otherDimention*sizeof(double));	// allocate memory for v.
		*destination.ui++ = otherDimention;	// store the # of elements of v in v.
			// perform the actual computation.
		unsigned int rows = otherDimention;	// keep the # of rows of A in rows.
		double *row = source.d;	// set row to the beginning of the first row.

		while(otherDimention--)	// for each row of A.
		{
			c = reduceDimention;	// set c to the # of columns of A.
			accumulator = *source.d;	// initialize accumulator with the first element of the current row.
			while(--c)	// reduce the current row
				accumulator = ASL::Utility::max(accumulator , *(source.d += rows));
			*destination.d++ = accumulator;	// store the result from reducing this row in v.
			source.d = ++row;	// move the the next row.
		} // end outer while
	}

	A.data.v = 0;	// prevent the destractor from deallocating A's memory.
	return v;
} // end function max overloaded version 19


// doesn't work on matrices with 0 elements.
TempVector ASL::max(TempMatrix A , unsigned int dim) // overloaded version 20
{
	register unsigned int reduceDimention,c;
	register anticast source,destination;
	register double accumulator;
	unsigned int otherDimention;
	TempVector v;

	source = A.data;	// set source at the first element of the first column of A.
	reduceDimention = *source.ui++;	// set reduceDimention to the # of elements of A.

	if(dim == 1)
	{
			// calculate dimentions and prepare A.
		otherDimention = reduceDimention / *source.ui;	// set otherDimention to the # of columns of A.
		reduceDimention = *source.ui++;	// set reduceDimantion to the # of rows of A.
			// prepare v.
		destination.v = v.data.v = malloc(sizeof(unsigned int) + otherDimention*sizeof(double));	// allocate memory for v.
		*destination.ui++ = otherDimention;	// store the # of elements of v in v.
			// perform the actual computation.
		while(otherDimention--)	// for each column of A.
		{
			c = reduceDimention;	// set c to the # of rows of A.
			accumulator = *source.d;	// initialize accumulator with the first element of the current column.
			while(--c)	// reduce the current column
				accumulator = ASL::Utility::max(accumulator , *++source.d);
			*destination.d++ = accumulator;	// store the result from reducing this column in v.
			++source.d;	// move the the next column.
		} // end outer while
	}
	else
	{
			// calculate dimentions and prepare A.
		reduceDimention = reduceDimention / *source.ui;	// set reduceDimention to the # of columns of A.
		otherDimention = *source.ui++;	// set otherDimantion to the # of rows of A.
			// prepare v.
		destination.v = v.data.v = malloc(sizeof(unsigned int) + otherDimention*sizeof(double));	// allocate memory for v.
		*destination.ui++ = otherDimention;	// store the # of elements of v in v.
			// perform the actual computation.
		unsigned int rows = otherDimention;	// keep the # of rows of A in rows.
		double *row = source.d;	// set row to the beginning of the first row.

		while(otherDimention--)	// for each row of A.
		{
			c = reduceDimention;	// set c to the # of columns of A.
			accumulator = *source.d;	// initialize accumulator with the first element of the current row.
			while(--c)	// reduce the current row
				accumulator = ASL::Utility::max(accumulator , *(source.d += rows));
			*destination.d++ = accumulator;	// store the result from reducing this row in v.
			source.d = ++row;	// move the the next row.
		} // end outer while
	}

	free(A.data.v);	// free A's memory.
	return v;
} // end function max overloaded version 20

