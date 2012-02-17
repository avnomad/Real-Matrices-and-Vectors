#include "utility.h"
#include <ctime>
#include <iostream>

namespace ASL
{
namespace Utility
{


static clock_t startingTime;


void tic(void)
{
	startingTime = ::clock();
}


void toc(void)
{
	std::cout<<"\nThe elapsed time equals "<<(clock() - startingTime) / (CLOCKS_PER_SEC/1000.0)<<"ms."<<std::endl;
}


} // end namespace Utility
} // end namespace ASL