#include "../Real Matrices and Vectors.h"

ASL::Matrix::~Matrix()
{
	free(this->data.v);
} // end ~Matrix destractor
