#include "../Real Matrices and Vectors.h"
using namespace ASL;


ASL::Vector::~Vector()
{
	free(this->data.v);
} // end Vector destractor
