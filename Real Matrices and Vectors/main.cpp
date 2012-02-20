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