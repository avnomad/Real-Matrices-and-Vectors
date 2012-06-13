//	Copyright (C) 2008, 2012 Vaptistis Anogeianakis <el05208@mail.ntua.gr>
/*
 *	This file is part of Real Matrices and Vectors.
 *
 *	Real Matrices and Vectors is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	Real Matrices and Vectors is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with Real Matrices and Vectors.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>

namespace ASL
{
namespace Utility
{


template<typename ArgType>						// max
inline ArgType max(ArgType x , ArgType y)
{
	return x > y ? x : y;
} // end function template max


template<typename ArgType>						// min
inline ArgType min(ArgType x , ArgType y)
{
	return x < y ? x : y;
} // end function template min


template<typename ArgType>						// sum
ArgType sum(ArgType x , ArgType y)
{
	return x+y;
} // end function template sum


template<typename ArgType>						// prod
ArgType prod(ArgType x , ArgType y)
{
	return x*y;
} // end function template prod


template<typename ArgType>						// identity
ArgType identity(ArgType x)
{
	return x;
} // end function template identity


template<typename ArgType>
inline void swap(ArgType &x , ArgType &y)		// swap
{
	ArgType temp;

	temp = x;
	x = y;
	y = temp;
} // end function template swap


} // end namespace Utility
} // end namespace ASL

#endif
