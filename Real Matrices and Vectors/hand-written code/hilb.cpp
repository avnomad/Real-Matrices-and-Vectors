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


TempMatrix ASL::hilb(unsigned int order)
{
	TempMatrix A;
	register anticast p;
	register double *q;
	register unsigned int c,i,n;
	double x;

	c = order*order;	// but the # of elements in the matrix in c.
	p.v = A.data.v = malloc(2*sizeof(unsigned int) + c*sizeof(double)); // allocating memory for the elements of the matrix plus it's size.

	*p.ui++ = c;	// store the # of elements
	*p.ui++ = order;	// store the # of rows
	
	c = 0;
	i = 2;
	*p.d = 1.0;
	while(++c != order)
	{
		*(q = ++p.d) = x = 1.0/i;
		++i;
		n = c;
		while(n--)
		{
			*(q += order-1) = x;
		}
	}											//times to compute hilb(5000):
	while(--c)									//with Microsoft C++ compiler (Native):
	{											//Debug: 422ms	Release: 344ms	Optimized: 281ms
		*(q = p.d += order) = x = 1.0/i;
		++i;									//with Microsoft C++ compiler (Managed):
		n = c;									//Debug: 390ms or 375	Release: 329ms	Optimized: 328ms
		while(--n)
		{										//with gcc 390ms 390 or 375 optimized
			*(q += order-1) = x;
		}
	}

	return A;
} // end fuction hilb


TempMatrix ASL::hilb(unsigned int rows,unsigned int cols)	// to do: upgrade algorith to the one used by hilb(ui). (if possible)
{
	TempMatrix A;
	register anticast p;
	register unsigned int c;
	unsigned int i,l;
	register unsigned int temp = rows-1;

	c = rows*cols;	// but the # of elements in the matrix in c.
	p.v = A.data.v = malloc(2*sizeof(unsigned int) + c*sizeof(double)); // allocating memory for the elements of the matrix plus it's size.

	*p.ui++ = c;	// store the # of elements
	*p.ui++ = rows;	// store the # of rows
	i = 0;
	l = rows;
	while(c--)
	{
		*p.d++ = 1.0/++i;
		if(!--l)
		{
			l = rows;
			i -= temp;
		}
	}

	return A;
} // end fuction hilb


/*TempMatrix ASL::hilb(unsigned int order)
{
	TempMatrix A;
	register anticast p;
	register unsigned int c;
	unsigned int i,l;
	register unsigned int temp = order-1;
	c = order*order;	// but the # of elements in the matrix in c.
	p.v = A.data.v = malloc(2*sizeof(unsigned int) + c*sizeof(double)); // allocating memory for the elements of the matrix plus it's size.

	*p.ui++ = c;	// store the # of elements
	*p.ui++ = order;	// store the # of rows
	i = 0;
	l = order;
	while(c--)
	{
		*p.d++ = 1.0/++i;
		if(!--l)
		{
			l = order;
			i -= temp;
		}
	}

	return A;
} // end fuction hilb*/				//563ms to compute hilb(5000)
