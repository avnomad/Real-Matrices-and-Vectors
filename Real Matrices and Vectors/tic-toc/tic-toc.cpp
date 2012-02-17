#include "../Real Matrices and Vectors.h"

#include <time.h>

static clock_t startingTime;

void ASL::tic(void)
{
	startingTime = ::clock();
}

void ASL::toc(void)
{
	std::cout<<"\nThe elapsed time equals "<<(clock() - startingTime) / (CLOCKS_PER_SEC/1000.0)<<"ms."<<std::endl;
}
