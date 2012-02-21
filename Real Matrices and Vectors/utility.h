#ifndef UTILITY_H
#define UTILITY_H

namespace ASL
{
namespace Utility
{

void tic();								// tic
void toc();								// toc


template<typename ArgType>				// max
inline ArgType max(ArgType x , ArgType y)
{
	return x > y ? x : y;
} // end function template max


template<typename ArgType>				// min
inline ArgType min(ArgType x , ArgType y)
{
	return x < y ? x : y;
} // end function template min


template<typename ArgType>				// sum
ArgType sum(ArgType x , ArgType y)
{
	return x+y;
} // end function template sum


template<typename ArgType>				// prod
ArgType prod(ArgType x , ArgType y)
{
	return x*y;
} // end function template prod

template<typename ArgType>
ArgType identity(ArgType x)
{
	return x;
}


} // end namespace Utility

} // end namespace ASL

#endif