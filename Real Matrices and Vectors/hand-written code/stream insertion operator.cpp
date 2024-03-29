//	Copyright (C) 2008, 2012 Vaptistis Anogeianakis <nomad@cornercase.gr>
/*
 *	This file is part of Real Matrices and Vectors.
 *
 *	Real Matrices and Vectors is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	Real Matrices and Vectors is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with Real Matrices and Vectors.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Real Matrices and Vectors.h"
using namespace ASL;


std::ostream &ASL::operator<< (std::ostream &output,Vector v) // overloaded version 1
{
	unsigned int c;
	
	output<<"\n\n";
	c = *v.data.ui++;
 	while(c--)
		output<<*v.data.d++<<'\t';
	output<<"\n\n";

	v.data.v = 0;	//prevents the destractor from deallocating v's memory.
	return output;
} // end fuction operator << overloaded version 1


std::ostream &ASL::operator << (std::ostream &output,TempVector v) // overloaded version 2
{
	unsigned int c;
	anticast p;

	output<<"\n\n";
	p = v.data;
	c = *p.ui++;
 	while(c--)
		output<<*p.d++<<'\t';
	output<<"\n\n";

	free(v.data.v);
	return output;
} // end fuction operator << overloaded version 2


std::ostream &ASL::operator << (std::ostream &output,Matrix A) // overloaded version 3
{
	register unsigned int c,i;
	register anticast row;
	register double *el;
	unsigned int rows,cols;

	output<<"\n\n";

	row = A.data;
	c = *row.ui++;	// set c to the # of elements in the matrix
	rows = *row.ui++;	// set rows to the # of rows of the matrix
	i = cols = c / rows;	// set i and cols to the # of columns of the matrix
	el = row.d;	// set el to the first element of the first row

 	while(c--)
	{
		output<<*el;
		if(!--i)
		{
			el = ++row.d;
			i = cols;
			output<<"\n\n";
			continue;
		}
		output<<'\t';
		el += rows;	// move el to the next element in the row
	}		

	output<<'\n'<<std:: endl;

	A.data.v = 0;	// prevents the destractor from deallocating A's memory.
	return output;
} // end fuction operator << overloaded version 3


std::ostream &ASL::operator << (std::ostream &output,TempMatrix A) // overloaded version 4
{
	register unsigned int c,i;
	register anticast row;
	register double *el;
	unsigned int rows,cols;

	output<<"\n\n";

	row = A.data;
	c = *row.ui++;	// set c to the # of elements in the matrix
	rows = *row.ui++;	// set rows to the # of rows of the matrix
	i = cols = c / rows;	// set i and cols to the # of columns of the matrix
	el = row.d;	// set el to the first element of the first row

 	while(c--)
	{
		output<<*el;
		if(!--i)
		{
			el = ++row.d;
			i = cols;
			output<<"\n\n";
			continue;
		}
		output<<'\t';
		el += rows;	// move el to the next element in the row
	}		

	output<<'\n'<<std:: endl;

	free(A.data.v);	// free A's memory.
	return output;
} // end fuction operator << overloaded version 4