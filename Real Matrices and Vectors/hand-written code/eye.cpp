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


TempMatrix ASL::eye(unsigned int order)
{
	TempMatrix A;
	register anticast p;
	register unsigned int c;

	c = order*order;
	p.v = A.data.v = calloc(1,2*sizeof(unsigned int) + c*sizeof(double));
	*p.ui++ = c;
	c = *p.ui++ = order;
	*p.d = 1;
	while(--c)
	{
		p.d += order;
		*++p.d = 1;
	}

	return A;
} // end function eye



TempMatrix ASL::eye(unsigned int rows,unsigned int cols)
{
	TempMatrix A;
	register anticast p;
	register unsigned int c;

	c = rows*cols;
	p.v = A.data.v = calloc(1,2*sizeof(unsigned int) + c*sizeof(double));
	*p.ui++ = c;
	*p.ui++ = rows;
	c = ASL::Utility::min(rows,cols);
	*p.d = 1;
	while(--c)
	{
		p.d += rows;
		*++p.d = 1;
	}

	return A;
} // end function eye
