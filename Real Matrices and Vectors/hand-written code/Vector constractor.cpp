#include "Real Matrices and Vectors.h"
using namespace ASL;


ASL::Vector::Vector()
{
	this->data.v = calloc(1,sizeof(unsigned int));
} // end Vector constructor
