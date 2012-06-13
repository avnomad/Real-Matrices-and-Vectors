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


unsigned int ASL::size(Vector v)
{
	unsigned int c = *v.data.ui;
	v.data.v = 0 ;	// ensure that the memory of the original vector wont be deallocated.
	return c;
} // end fuction size


unsigned int ASL::size(TempVector v)
{
	unsigned int c = *v.data.ui;
	free(v.data.v);	// free the memory occupied by the temporary vector.
	return c;
} // end fuction size


TempVector ASL::size(Matrix A)
{
	TempVector v;
	anticast p;

	p.v = v.data.v = malloc(sizeof(unsigned int) + 2*sizeof(double));
	*p.ui++ = 2;
	*p.d++ = *(A.data.ui+1);
	*p.d = *A.data.ui / *(A.data.ui+1);

	A.data.v = 0 ;	// ensure that the memory of the original matrix wont be deallocated.
	return v;
} // end fuction size


TempVector ASL::size(TempMatrix A)
{
	TempVector v;
	anticast p;

	p.v = v.data.v = malloc(sizeof(unsigned int) + 2*sizeof(double));
	*p.ui++ = 2;
	*p.d++ = *(A.data.ui+1);
	*p.d = *A.data.ui / *(A.data.ui+1);

	free(A.data.v);	// free the memory occupied by the temporary matrix.
	return v;
} // end fuction size


unsigned int ASL::size(Matrix A , char dim)
{
	unsigned int c;

	if(dim == 1)
		c = *(A.data.ui+1);
	else
		c = *A.data.ui / *(A.data.ui+1);

	A.data.v = 0 ;	// prevent the memory of the original matrix from being deallocated.
	return c;
} // end fuction size


unsigned int ASL::size(TempMatrix A , char dim)
{
	unsigned int c;

	if(dim == 1)
		c = *(A.data.ui+1);
	else
		c = *A.data.ui / *(A.data.ui+1);

	free(A.data.v);	// free the memory occupied by the temporary matrix.
	return c;
} // end fuction size