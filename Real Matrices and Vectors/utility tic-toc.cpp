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


void toc(std::ostream &outStream)
{
	outStream<<"\nThe elapsed time equals "<<(clock() - startingTime) / (CLOCKS_PER_SEC/1000.0)<<"ms."<<std::endl;
}


} // end namespace Utility
} // end namespace ASL
