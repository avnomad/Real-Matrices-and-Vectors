//	Copyright (C) 2008, 2012 Vaptistis Anogeianakis <el05208@mail.ntua.gr>
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
