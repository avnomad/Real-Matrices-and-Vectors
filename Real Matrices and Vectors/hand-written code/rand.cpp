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


TempVector ASL::rand(unsigned int length) // poor implementation. random numbers are integers instead of reals in the interval [0,1). for demonstration purposes only
{
	TempVector v;
	anticast p;

	p.v = v.data.v = malloc(sizeof(unsigned int) + length*sizeof(double)); // allocating memory for the elements of the vector plus it's size.

	*p.ui++ = length;
	while(length--)
		*p.d++ = ::rand();

	return v;
} // end fuction rand


TempMatrix ASL::rand(unsigned int rows,unsigned int cols) // poor implementation. random numbers are integers instead of reals in the interval [0,1). for demonstration purposes only
{
	TempMatrix A;
	register anticast p;
	register unsigned int c;

	c = rows*cols;	// but the # of elements of the matrix in c.
	p.v = A.data.v = malloc(2*sizeof(unsigned int) + c*sizeof(double)); // allocating memory for the elements of the matrix plus it's size.

	*p.ui++ = c;
	*p.ui++ = rows;
	while(c--)
		*p.d++ = ::rand();

	return A;
} // end fuction rand
