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

#include <iostream>
using namespace std;

#include "hand-written code/Real Matrices and Vectors.h"
#include <iomanip>
#include <time.h>

using namespace ASL;

int main()
{
	Matrix A,B;
	Vector v,u;
	
	v = linspace(-2,2,9);
	u = linspace(-3,3,9);

	cout<<setprecision(3);

	cout<<v<<u;
	u(u<0) = -(C/1/sum(u<0));
	cout<<v<<u;

	tic();
	toc(cout);
	tic();
	toc();

	cout<<Utility::identity(2.2)<<endl;

	system("PAUSE");
	return 0;
} // end fuction main

/*
	v = linspace(1,4,4);
	A = hilb(5000);

	tic();
	A = polyval(v,A);
	toc();

	532ms optimized vs 723ms matlab		passing to library offers 26.4% reduction of computation time.
*/