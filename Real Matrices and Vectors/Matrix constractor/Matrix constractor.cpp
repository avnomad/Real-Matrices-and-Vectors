#include "../Real Matrices and Vectors.h"

ASL::Matrix::Matrix()
{
	this->data.v = calloc(2,sizeof(unsigned int));
} // end Matrix constractor
