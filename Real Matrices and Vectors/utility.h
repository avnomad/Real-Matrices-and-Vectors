#ifndef UTILITY_H
#define UTILITY_H

namespace ASL
{

template<typename ArgType>				//max
inline ArgType max(ArgType x , ArgType y)
{
	return x > y ? x : y;
}


template<typename ArgType>				//min
inline ArgType min(ArgType x , ArgType y)
{
	return x < y ? x : y;
}

}

#endif