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


double &ASL::Vector::operator ()(unsigned int i) // overloaded version 1
{
	return *((double *)(this->data.ui+1) + i - 1);
} // end function operator () overloaded version 1


double ASL::TempVector::operator ()(unsigned int i) // overloaded version 2
{
	double temp = *((double *)(this->data.ui+1) + i - 1);

	free(this->data.v);
	return temp;
} // end function operator () overloaded version 2


double &ASL::Matrix::operator ()(unsigned int i,unsigned int j) // overloaded version 3
{
	return *((double *)(this->data.ui+2) + (i-1) + *(this->data.ui+1) * (j-1));
} // end function operator () overloaded version 3


double ASL::TempMatrix::operator ()(unsigned int i,unsigned int j) // overloaded version 4
{
	double temp = *((double *)(this->data.ui+2) + (i-1) + *(this->data.ui+1) * (j-1));

	free(this->data.v);
	return temp;
} // end function operator () overloaded version 4


	// vector v should have at least as many elements as the vector pointer to by this.
ReferenceList ASL::Vector::operator () (Vector v) // overloaded version 5
{
	register unsigned int c;
	register anticast driver,source;
	register double **destination;
	ReferenceList r;

	source = this->data;	// set source at the beginning of this.
	driver = v.data;	// set driver at the beginning of v.
	c = *source.ui++;	// set c to the # of elements of this.
	++driver.ui;	// skip the # of elements of v.
	destination = r.data = (double **)malloc((c+1)*sizeof(double *));	// we won't need more memory than this but we may need less...

	while(c--)	// for each element of this.
	{
		if(*driver.d)	// if the current element of v is not zero.
			*destination++ = source.d;	// put a pointer to the corresponding element of this in the list.
		++source.d , ++driver.d;	// move to the next element of v and this.
	}
	*destination = 0;	// designate the end of the list with a null pointer.

/**/v.data.v = 0;	// prevent the distractor from deallocating v's memory.
	return r;
} // end function operator () overloaded version 5


	// vector v should have at least as many elements as the vector pointer to by this.
ReferenceList ASL::Vector::operator () (TempVector v) // overloaded version 6
{
	register unsigned int c;
	register anticast driver,source;
	register double **destination;
	ReferenceList r;

	source = this->data;	// set source at the beginning of this.
	driver = v.data;	// set driver at the beginning of v.
	c = *source.ui++;	// set c to the # of elements of this.
	++driver.ui;	// skip the # of elements of v.
	destination = r.data = (double **)malloc((c+1)*sizeof(double *));	// we won't need more memory than this but we may need less...

	while(c--)	// for each element of this.
	{
		if(*driver.d)	// if the current element of v is not zero.
			*destination++ = source.d;	// put a pointer to the corresponding element of this in the list.
		++source.d , ++driver.d;	// move to the next element of v and this.
	}
	*destination = 0;	// designate the end of the list with a null pointer.

/**/free(v.data.v);	// free v's memory.
	return r;
} // end function operator () overloaded version 6


	// matrix A should have at least as many elements as the matrix pointer to by this.
ReferenceList ASL::Matrix::operator () (Matrix A) // overloaded version 7
{
	register unsigned int c;
	register anticast driver,source;
	register double **destination;
	ReferenceList r;

	source = this->data;	// set source at the beginning of this.
	driver = A.data;	// set driver at the beginning of A.
	c = *source.ui++;	// set c to the # of elements of this.
	++source.ui;	// skip the # of rows of this.
/**/driver.ui += 2;	// skip the # of rows and elements of A.
	destination = r.data = (double **)malloc((c+1)*sizeof(double *));	// we won't need more memory than this but we may need less...

	while(c--)	// for each element of this.
	{
		if(*driver.d)	// if the current element of A is not zero.
			*destination++ = source.d;	// put a pointer to the corresponding element of this in the list.
		++source.d , ++driver.d;	// move to the next element of A and this.
	}
	*destination = 0;	// designate the end of the list with a null pointer.

/**/A.data.v = 0;	// prevent the distractor from deallocating A's memory.
	return r;
} // end function operator () overloaded version 7


ReferenceList ASL::Matrix::operator () (TempMatrix A) // overloaded version 8
{
	register unsigned int c;
	register anticast driver,source;
	register double **destination;
	ReferenceList r;

	source = this->data;	// set source at the beginning of this.
	driver = A.data;	// set driver at the beginning of A.
	c = *source.ui++;	// set c to the # of elements of this.
	++source.ui;	// skip the # of rows of this.
/**/driver.ui += 2;	// skip the # of rows and elements of A.
	destination = r.data = (double **)malloc((c+1)*sizeof(double *));	// we won't need more memory than this but we may need less...

	while(c--)	// for each element of this.
	{
		if(*driver.d)	// if the current element of A is not zero.
			*destination++ = source.d;	// put a pointer to the corresponding element of this in the list.
		++source.d , ++driver.d;	// move to the next element of A and this.
	}
	*destination = 0;	// designate the end of the list with a null pointer.

/**/free(A.data.v);	// free A's memory.
	return r;
} // end function operator () overloaded version 8
