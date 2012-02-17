#include "../Real Matrices and Vectors.h"
using namespace ASL;


#pragma region Vector

void ASL::Vector::operator = (TempVector v) // overloaded version 1
{
	free(this->data.v);
	this->data = v.data;
} // end fuction operator = overloaded version 1


// the assignment of the type A=A is considered an error and should not apear in code using this library.
void ASL::Vector::operator = (Vector v) // overloaded version 2
{
	unsigned int c;
	anticast p;

	free(this->data.v);
	c = *v.data.ui++;
	p.v = this->data.v = malloc(sizeof(unsigned int) + c*sizeof(double));
	*p.ui++ = c;

	while(c--)
		*p.d++ = *v.data.d++;
	
	v.data.v = 0;
} // end fuction operator = overloaded version 2


// sets all the elements of an existing vector to x. Does not change it's size;
void ASL::Vector::operator = (double x) // overloaded version 3
{
	unsigned int c;
	anticast p;

	p.v = this->data.v;
	c = *p.ui++;
	while(c--)
		*p.d++ = x;
} // end fuction operator = overloaded version 3

#pragma endregion
#pragma region Matrix

void ASL::Matrix::operator = (TempMatrix A) // overloaded version 4
{
	free(this->data.v);
	this->data = A.data;
} // end fuction operator = overloaded version 4


// the assignment of the type A=A is considered an error and should not apear in code using this library.
void ASL::Matrix::operator = (Matrix A) // overloaded version 5
{
	register unsigned int c;
	register anticast p;

	free(this->data.v);

	c = *A.data.ui++;
	p.v = this->data.v = malloc(2*sizeof(unsigned int) + c*sizeof(double));
	*p.ui++ = c;
	*p.ui++ = *A.data.ui++;

	while(c--)
		*p.d++ = *A.data.d++;
	
	A.data.v = 0;
} // end fuction operator = overloaded version 5


// sets all the elements of an existing Matrix to x. Does not change it's size;
void ASL::Matrix::operator = (double x) // overloaded version 6
{
	register unsigned int c;
	register anticast p;

	p.v = this->data.v;
	c = *p.ui++;
	++p.ui;
	while(c--)
		*p.d++ = x;
} // end fuction operator = overloaded version 6

#pragma endregion
#pragma region ReferenceList

void ASL::ReferenceList::operator = (double x) // overloaded version 7
{
	register double **p;

	p = this->data;	// set p at the beginning of the list.
	while(*p)	// as long as you haven't encountered a null pointer.
		**p++ = x;

	free(this->data);	// free the memory occupied by this list.
} // end fuction operator = overloaded version 7


	// the reference list r should have at least as many elements as the reference list pointed to by this.
void ASL::ReferenceList::operator = (ReferenceList r) // overloaded version 8
{
	register double **destination , **source;

	source = r.data;	// set source at the beginning of r.
	destination = this->data;	// set destination at the beginning of this.

	while(*destination)	// as long as you haven't encountered a null pointer in this.
		**destination++ = **source++;

	free(r.data);	// free the memory occupied by list r.
	free(this->data);	// free the memory occupied by this list.
} // end fuction operator = overloaded version 8


	// the vector v should have at least as many elements as the reference list pointed to by this.
void ASL::ReferenceList::operator = (Vector v) // overloaded version 9
{
	register double **destination;
	register anticast source;

	source = v.data;	// set source at the beginning of v.
	++source.ui;	// skip the # of elements of v.
	destination = this->data;	// set destination at the beginning of this.

	while(*destination)	// as long as you haven't encountered a null pointer in this.
		**destination++ = *source.d++;

/**/v.data.v = 0;	// prevent the destractor from deallocating the memory occupied by vector v.
	free(this->data);	// free the memory occupied by this list.
} // end fuction operator = overloaded version 9


	// the temporary vector v should have at least as many elements as the reference list pointed to by this.
void ASL::ReferenceList::operator = (TempVector v) // overloaded version 10
{
	register double **destination;
	register anticast source;

	source = v.data;	// set source at the beginning of v.
	++source.ui;	// skip the # of elements of v.
	destination = this->data;	// set destination at the beginning of this.

	while(*destination)	// as long as you haven't encountered a null pointer in this.
		**destination++ = *source.d++;

/**/free(v.data.v);	// free the memory occupied by vector v.
	free(this->data);	// free the memory occupied by this list.
} // end fuction operator = overloaded version 10

#pragma endregion
