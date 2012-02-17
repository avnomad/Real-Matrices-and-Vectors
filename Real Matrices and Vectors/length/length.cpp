#include "../Real Matrices and Vectors.h"
using namespace ASL;


unsigned int ASL::length(Vector v)
{
	unsigned int c = *v.data.ui;
	v.data.v = 0 ;	// ensure that the memory of the original vector wont be deallocated.
	return c;
} // end fuction length


unsigned int ASL::length(TempVector v)
{
	unsigned int c = *v.data.ui;
	free(v.data.v);	// free the memory occupied by the temporary vector.
	return c;
} // end fuction length


unsigned int ASL::length(Matrix A)
{
	unsigned int c = *(A.data.ui+1); // set c to the # of rows.

	c = ASL::max(c , *A.data.ui / c);

	A.data.v = 0 ;	// ensure that the memory of the original matrix wont be deallocated.
	return c;
} // end fuction length


unsigned int ASL::length(TempMatrix A)
{
	unsigned int c = *(A.data.ui+1); // set c to the # of rows.

	c = ASL::max(c , *A.data.ui / c);

	free(A.data.v);	// free the memory occupied by the temporary matrix.
	return c;
} // end fuction length

		/************************************************************************
		*	due to the way reference list is currently implemented, the time	*
		*	needed to calculate it's length is linear instead of constant.		*
		*	this should not be a problem though as this overloaded version of	*
		*	length is not needed at all: the length can be calculated in other	*
		*	ways.																*
		************************************************************************/

unsigned int ASL::length(ReferenceList r)
{											// 
	register unsigned int c = 0;			//  
	register double **p;

	p = r.data;	// set p at the beginning of r.
	while(*p++)	// as long as you haven't encountered a null pointer.
		++c;	// increment c.

	free(r.data);	// free the memory occupied by the reference list r.
	return c;
} // end fuction length
