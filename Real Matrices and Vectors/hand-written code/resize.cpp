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
