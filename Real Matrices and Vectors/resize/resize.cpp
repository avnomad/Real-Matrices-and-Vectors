#include "../Real Matrices and Vectors.h"
using namespace ASL;


/************************************************************************************************/
/*																								*/
/*  changes the size of the Vector object for which it is invoked to newSize.					*/
/*  the contents of the object remain intact to the minimum of the two sizes (old and new).		*/
/*  if the new size is greater than the old the redundant slots should contain garbage.			*/
/*																								*/
/************************************************************************************************/


void ASL::Vector::resize(unsigned int newSize)
{
	this->data.v = realloc(this->data.v , sizeof(unsigned int) + newSize*sizeof(double));
	*this->data.ui = newSize;
} // end fuction resize


/************************************************************************************************/
/*																								*/
/*  changes the size of the Matrix object for which it is invoked to rows x cols.				*/
/*  the contents of the object remain intact to the minimum of the two sizes (old and new),		*/
/*  but may be distributed differently among columns if the # of rows is changed.				*/
/*  in any case the order in which the elements appear reading from top to bottom and from		*/
/*  left to right remains the same.																*/
/*  if the new size is greater than the old the redundant slots should contain garbage.			*/
/*																								*/
/************************************************************************************************/


void ASL::Matrix::resize(unsigned int rows,unsigned int cols)
{
	this->data.v = realloc(this->data.v , 2*sizeof(unsigned int) + (cols *= rows)*sizeof(double));
	*this->data.ui = cols;
	*(this->data.ui+1) = rows;
} // end fuction resize
