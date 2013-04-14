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


//y = linspace(a,b) generates a row vector y of 100 points linearly spaced between and including a and b.
//y = linspace(a,b,n) generates a row vector y of n points linearly spaced between and including a and b.
			/*******************************************************************************************/
			/* assumes that n>=2. The first element of the vector will be a and the last b so if a>=b, */
			/* the elements will be in descending order. The last point is always b regardless of	   */
			/* rounding errors.	linspace(a,a,n) works.												   */
			/*******************************************************************************************/

TempVector ASL::linspace(double a,double b,unsigned int n)
{
	TempVector v;
	anticast p;
	double l;

	p.v = v.data.v = malloc(sizeof(unsigned int) + n*sizeof(double));	//allocate memory.

	*p.ui++ = n;
	l = (b-a)/--n;
	*p.d = a;
	while(--n)
		*++p.d = (a += l);
	*++p.d = b;

	return v;
} // end function linspace
