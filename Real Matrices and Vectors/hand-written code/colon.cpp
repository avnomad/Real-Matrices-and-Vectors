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

#include "colon.h"

namespace ASL
{

Colon C;
double Colon::a;
double Colon::step;

Intermediate1of2 operator | (Colon,double a)
{
	Intermediate1of2 temp;

	Colon::a = a;
	return temp;
} // end function operator |


Intermediate2of2 operator | (Intermediate1of2,double step)
{
	Intermediate2of2 temp;

	Colon::step = step;
	return temp;
} // end function operator |


TempVector operator | (Intermediate2of2,double b)
{
	register unsigned int c;
	register double x;
	register anticast p;
	TempVector v;

	c = (b - Colon::a) / Colon::step;
	++c;
	p.v = v.data.v = malloc(sizeof(unsigned int) + c*sizeof(double));

	*p.ui++ = c;
	*p.d = x = Colon::a;

	while(--c)
		*++p.d = x += Colon::step;

	return v;
} // end function operator |

Intermediate1of1 operator / (Colon,double a)
{
	Intermediate1of1 temp;

	Colon::a = a;
	return temp;
} // end function operator /


TempVector operator / (Intermediate1of1,double b)
{
	register unsigned int c;
	register double x;
	register anticast p;
	TempVector v;

	c = b - Colon::a;
	++c;
	p.v = v.data.v = malloc(sizeof(unsigned int) + c*sizeof(double));

	*p.ui++ = c;
	*p.d = x = Colon::a;

	while(--c)
		*++p.d = ++x;

	return v;
} // end function operator |

} // end namespace ASL

