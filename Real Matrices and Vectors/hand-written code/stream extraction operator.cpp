#include "Real Matrices and Vectors.h"
using namespace ASL;


std::istream &ASL::operator >> (std::istream &input,Vector v)
{
	unsigned int c;

	c = *v.data.ui++;
	while(c--)
		input>>*v.data.d++;

	v.data.v = 0;
	return input;
} // end fuction operator >>


std::istream &ASL::operator >> (std::istream &input,Matrix A)
{
	register unsigned int c,i;
	register anticast row;
	register double *el;
	unsigned int rows,cols;

	row = A.data;
	c = *row.ui++;	// set c to the # of elements in the matrix
	rows = *row.ui++;	// set rows to the # of rows of the matrix
	i = cols = c / rows;	// set i and cols to the # of columns of the matrix
	el = row.d;	// set el to the first element of the first column

 	while(c--)
	{
		input>>*el;
		if(!--i)
		{
			el = ++row.d;	// move both el and row to the begining of the next row.
			i = cols;
			continue;
		}
		el += rows;	// move el to the next element in the row.
	}		

	A.data.v = 0;	//prevents the destractor from deallocating A's memory.
	return input;
} // end fuction operator >>
