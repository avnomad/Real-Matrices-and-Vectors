//	Copyright (C) 2008, 2012 Vaptistis Anogeianakis <nomad@cornercase.gr>
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

//#include "Real Matrices and Vectors.h"
#include <ctime>
#include <iostream>

namespace ASL
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


} // end namespace ASL
