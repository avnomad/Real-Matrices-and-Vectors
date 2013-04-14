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

#ifndef REAL_MATRICES_AND_VECTORS_H
#define REAL_MATRICES_AND_VECTORS_H

#include <iostream>
#include <stdlib.h>
#include <math.h>

#include "anticast.h"
#include "utility.h"
#include "colon.h"

namespace ASL
{

#define pi 3.141592653589793238462643383279502884197169399375106
#define e  2.718281828459045235360287471352662497757247093699960

class Matrix;
class TempVector;
class TempMatrix;
class ReferenceList;
class Intermediate1of2;
class Intermediate2of2;
class Intermediate1of1;

class Vector
{
	friend class ReferenceList;
	friend std::ostream &operator << (std::ostream &,Vector);		// operator <<
	friend std::istream &operator >> (std::istream &,Vector);		// operator >>
	friend double polyval(Vector,double);							// polyval
	friend TempVector polyval(Vector,Vector);						//	>>
	friend TempVector polyval(Vector,TempVector);					//	>>
	friend TempVector polyval(TempVector,Vector);					//	>>
	friend TempMatrix polyval(Vector,Matrix);						//	>>
	friend TempMatrix polyval(Vector,TempMatrix);					//	>>
	friend unsigned int size(Vector);								// size
	friend unsigned int length(Vector);								// length
	friend double max(Vector);										// max
	friend double min(Vector);										// min
	friend double sum(Vector);										// sum
	friend double prod(Vector);										// prod
	friend double any(Vector);										// any
	friend double all(Vector);										// all
	friend TempMatrix diag(Vector,int = 0);							// diag
	friend TempMatrix polyvalm(Vector,Matrix);						// polyvalm			//to do-
	friend TempMatrix polyvalm(Vector,TempMatrix);					//	>>				//to do-
	friend TempVector roots(Vector);								// roots			//to do-
	friend TempVector poly(Vector);									// poly				//to do-
	friend TempVector conv(Vector,Vector);							// conv				//to do-
	friend TempVector conv(Vector,TempVector);						//	>>				//to do-
	friend TempVector conv(TempVector,Vector);						//	>>				//to do-
	friend TempVector polyder(Vector);								// polyder			//to do-
	friend TempVector polyint(Vector,double = 0);					// polyint			//to do-
	friend TempMatrix toMatrix(Vector,char = 1);					// toMatrix
	friend TempVector sin(Vector);									// sin
	friend TempVector cos(Vector);									// cos
	friend TempVector tan(Vector);									// tan
	friend TempVector asin(Vector);									// asin
	friend TempVector acos(Vector);									// acos
	friend TempVector atan(Vector);									// atan
	friend TempVector sinh(Vector);									// sinh
	friend TempVector cosh(Vector);									// cosh
	friend TempVector tanh(Vector);									// tanh
	friend TempVector exp(Vector);									// exp
	friend TempVector log(Vector);									// log
	friend TempVector log10(Vector);								// log10
	friend TempVector sqrt(Vector);									// sqrt
	friend TempVector ceil(Vector);									// ceil
	friend TempVector floor(Vector);								// floor
	friend TempVector abs(Vector);									// abs
	friend TempVector operator + (Vector);							// operator + (unary)
	friend TempVector operator - (Vector);							// operator - (unary)
	friend TempVector operator ! (Vector);							// operator !
	friend TempVector operator + (Vector,Vector);					// operator +
	friend TempVector operator + (TempVector,Vector);				//	>>
	friend TempVector operator + (Vector,TempVector);				//	>>
	friend TempVector operator + (Vector,double);					//	>>
	friend TempVector operator + (double,Vector);					//	>>
	friend TempVector operator - (Vector,Vector);					// operator -
	friend TempVector operator - (TempVector,Vector);				//	>>
	friend TempVector operator - (Vector,TempVector);				//	>>
	friend TempVector operator - (Vector,double);					//	>>
	friend TempVector operator - (double,Vector);					//	>>
	friend TempVector operator < (Vector,Vector);					// operator <
	friend TempVector operator < (TempVector,Vector);				//	>>
	friend TempVector operator < (Vector,TempVector);				//	>>
	friend TempVector operator < (Vector,double);					//	>>
	friend TempVector operator < (double,Vector);					//	>>
	friend TempVector operator > (Vector,Vector);					// operator >
	friend TempVector operator > (TempVector,Vector);				//	>>
	friend TempVector operator > (Vector,TempVector);				//	>>
	friend TempVector operator > (Vector,double);					//	>>
	friend TempVector operator > (double,Vector);					//	>>
	friend TempVector operator <= (Vector,Vector);					// operator <=
	friend TempVector operator <= (TempVector,Vector);				//	>>
	friend TempVector operator <= (Vector,TempVector);				//	>>
	friend TempVector operator <= (Vector,double);					//	>>
	friend TempVector operator <= (double,Vector);					//	>>
	friend TempVector operator >= (Vector,Vector);					// operator >=
	friend TempVector operator >= (TempVector,Vector);				//	>>
	friend TempVector operator >= (Vector,TempVector);				//	>>
	friend TempVector operator >= (Vector,double);					//	>>
	friend TempVector operator >= (double,Vector);					//	>>
	friend TempVector operator == (Vector,Vector);					// operator ==
	friend TempVector operator == (TempVector,Vector);				//	>>
	friend TempVector operator == (Vector,TempVector);				//	>>
	friend TempVector operator == (Vector,double);					//	>>
	friend TempVector operator == (double,Vector);					//	>>
	friend TempVector operator != (Vector,Vector);					// operator !=
	friend TempVector operator != (TempVector,Vector);				//	>>
	friend TempVector operator != (Vector,TempVector);				//	>>
	friend TempVector operator != (Vector,double);					//	>>
	friend TempVector operator != (double,Vector);					//	>>
	friend TempVector operator && (Vector,Vector);					// operator &&
	friend TempVector operator && (TempVector,Vector);				//	>>
	friend TempVector operator && (Vector,TempVector);				//	>>
	friend TempVector operator && (Vector,double);					//	>>
	friend TempVector operator && (double,Vector);					//	>>
	friend TempVector operator || (Vector,Vector);					// operator ||
	friend TempVector operator || (TempVector,Vector);				//	>>
	friend TempVector operator || (Vector,TempVector);				//	>>
	friend TempVector operator || (Vector,double);					//	>>
	friend TempVector operator || (double,Vector);					//	>>
	friend TempVector operator & (Vector,Vector);					// operator &
	friend TempVector operator & (TempVector,Vector);				//	>>
	friend TempVector operator & (Vector,TempVector);				//	>>
	friend TempVector operator & (Vector,double);					//	>>
	friend TempVector operator & (double,Vector);					//	>>
	friend TempVector operator | (Vector,Vector);					// operator |
	friend TempVector operator | (TempVector,Vector);				//	>>
	friend TempVector operator | (Vector,TempVector);				//	>>
	friend TempVector operator | (Vector,double);					//	>>
	friend TempVector operator | (double,Vector);					//	>>
	friend TempVector operator *= (Vector,Vector);					// operator *=
	friend TempVector operator *= (TempVector,Vector);				//	>>
	friend TempVector operator *= (Vector,TempVector);				//	>>
	friend TempVector operator *= (Vector,double);					//	>>
	friend TempVector operator *= (double,Vector);					//	>>
	friend TempVector operator /= (Vector,Vector);					// operator /=
	friend TempVector operator /= (TempVector,Vector);				//	>>
	friend TempVector operator /= (Vector,TempVector);				//	>>
	friend TempVector operator /= (Vector,double);					//	>>
	friend TempVector operator /= (double,Vector);					//	>>
	friend double operator * (Vector,Vector);						// operator *
	friend double operator * (TempVector,Vector);					//	>>
	friend double operator * (Vector,TempVector);					//	>>
	friend TempVector operator * (Vector,double);					//	>>
	friend TempVector operator * (double,Vector);					//	>>
	friend TempVector operator / (Vector,Vector);					// operator /
	friend TempVector operator / (TempVector,Vector);				//	>>
	friend TempVector operator / (Vector,TempVector);				//	>>
	friend TempVector operator / (Vector,double);					//	>>
	friend TempVector operator / (double,Vector);					//	>>
	friend TempVector operator ^ (Vector,Vector);					// operator ^
	friend TempVector operator ^ (TempVector,Vector);				//	>>
	friend TempVector operator ^ (Vector,TempVector);				//	>>
	friend TempVector operator ^ (Vector,double);					//	>>
	friend TempVector operator ^ (double,Vector);					//	>>
	friend TempVector operator ^= (Vector,Vector);					// operator ^=
	friend TempVector operator ^= (TempVector,Vector);				//	>>
	friend TempVector operator ^= (Vector,TempVector);				//	>>
	friend TempVector operator ^= (Vector,double);					//	>>
	friend TempVector operator ^= (double,Vector);					//	>>
	friend TempVector operator % (Vector,Vector);					// operator %
	friend TempVector operator % (TempVector,Vector);				//	>>
	friend TempVector operator % (Vector,TempVector);				//	>>
	friend TempVector operator % (Vector,double);					//	>>
	friend TempVector operator % (double,Vector);					//	>>
	friend TempVector max(Vector,Vector);							// max
	friend TempVector max(TempVector,Vector);						//	>>
	friend TempVector max(Vector,TempVector);						//	>>
	friend TempVector max(Vector,double);							//	>>
	friend TempVector max(double,Vector);							//	>>
	friend TempVector min(Vector,Vector);							// min
	friend TempVector min(TempVector,Vector);						//	>>
	friend TempVector min(Vector,TempVector);						//	>>
	friend TempVector min(Vector,double);							//	>>
	friend TempVector min(double,Vector);							//	>>
public:
	Vector();												// default constractor
	~Vector();												// destractor
	void operator = (TempVector);							// assignment operator
	void operator = (Vector);								//			>>
	void operator = (double);								//			>>
	double &operator () (unsigned int);								// operator ()
	ReferenceList operator () (Vector);								//	>>
	ReferenceList operator () (TempVector);							//	>>
	void resize(unsigned int);										// resize
private:
	anticast data;
}; // end class Vector


class TempVector
{
	friend class Vector;
	friend class ReferenceList;
	friend std::ostream &operator << (std::ostream &,TempVector);	// operator <<
	friend TempVector rand(unsigned int);							// rand
	friend TempVector randn(unsigned int);							// randn			//to do
	friend double polyval(TempVector,double);						// polyval
	friend TempVector polyval(Vector,Vector);						//	>>
	friend TempVector polyval(TempVector,Vector);					//	>>
	friend TempVector polyval(Vector,TempVector);					//	>>
	friend TempVector polyval(TempVector,TempVector);				//	>>
	friend TempMatrix polyval(TempVector,Matrix);					//	>>
	friend TempMatrix polyval(TempVector,TempMatrix);				//	>>
	friend TempVector loadv(const char *);							// loadv			//to do
	friend unsigned int size(TempVector);							// size
	friend TempVector size(Matrix);									//	>>
	friend TempVector size(TempMatrix);								//	>>
	friend unsigned int length(TempVector);							// length
	friend double max(Vector);										// max
	friend double max(TempVector);									//	>>
	friend TempVector max(Matrix,unsigned int = 1);					//	>>
	friend TempVector max(TempMatrix,unsigned int = 1);				//	>>
	friend double min(Vector);										// min
	friend double min(TempVector);									//	>>
	friend TempVector min(Matrix,unsigned int = 1);					//	>>
	friend TempVector min(TempMatrix,unsigned int = 1);				//	>>
	friend double sum(Vector);										// sum
	friend double sum(TempVector);									//	>>
	friend TempVector sum(Matrix,char = 1);							//	>>
	friend TempVector sum(TempMatrix,char = 1);						//	>>
	friend double prod(Vector);										// prod
	friend double prod(TempVector);									//	>>
	friend TempVector prod(Matrix,char = 1);						//	>>
	friend TempVector prod(TempMatrix,char = 1);					//	>>
	friend double any(Vector);										// any
	friend double any(TempVector);									//	>>
	friend TempVector any(Matrix,char = 1);							//	>>
	friend TempVector any(TempMatrix,char = 1);						//	>>
	friend double all(Vector);										// all
	friend double all(TempVector);									//	>>
	friend TempVector all(Matrix,char = 1);							//	>>
	friend TempVector all(TempMatrix,char = 1);						//	>>
	friend TempMatrix diag(TempVector,int = 0);						// diag
	friend TempVector diag(Matrix,int = 0);							//	>>
	friend TempVector diag(TempMatrix,int = 0);						//	>>
	friend TempVector linspace(double,double,unsigned int = 100);	// linspace
	friend TempVector logspace(double,double,unsigned int = 50);	// logspace			//to do
	friend TempMatrix polyvalm(TempVector,Matrix);					// polyvalm			//to do-
	friend TempMatrix polyvalm(TempVector,TempMatrix);				//	>>				//to do-
	friend TempVector roots(Vector);								// roots			//to do-
	friend TempVector roots(TempVector);							//	>>				//to do
	friend TempVector poly(Vector);									// poly				//to do-
	friend TempVector poly(TempVector);								//	>>				//to do
	friend TempVector poly(Matrix);									//	>>				//to do-
	friend TempVector poly(TempMatrix);								//	>>				//to do-
	friend TempVector eig(Matrix);									// eig				//to do-
	friend TempVector eig(TempMatrix);								//	>>				//to do-
	friend TempVector conv(Vector,Vector);							// conv				//to do-
	friend TempVector conv(Vector,TempVector);						//	>>				//to do-
	friend TempVector conv(TempVector,Vector);						//	>>				//to do-
	friend TempVector conv(TempVector,TempVector);					//	>>				//to do
	friend TempVector polyder(Vector);								// polyder			//to do-
	friend TempVector polyder(TempVector);							//	>>				//to do
	friend TempVector polyint(Vector,double);						// polyint			//to do-
	friend TempVector polyint(TempVector,double = 0);				//	>>				//to do
	friend TempMatrix toMatrix(TempVector,char = 1);				// toMatrix
	friend TempVector sin(Vector);									// sin
	friend TempVector sin(TempVector);								//	>>
	friend TempVector cos(Vector);									// cos
	friend TempVector cos(TempVector);								//	>>
	friend TempVector tan(Vector);									// tan
	friend TempVector tan(TempVector);								//	>>
	friend TempVector asin(Vector);									// asin
	friend TempVector asin(TempVector);								//	>>
	friend TempVector acos(Vector);									// acos
	friend TempVector acos(TempVector);								//	>>
	friend TempVector atan(Vector);									// atan
	friend TempVector atan(TempVector);								//	>>
	friend TempVector sinh(Vector);									// sinh
	friend TempVector sinh(TempVector);								//	>>
	friend TempVector cosh(Vector);									// cosh
	friend TempVector cosh(TempVector);								//	>>
	friend TempVector tanh(Vector);									// tanh
	friend TempVector tanh(TempVector);								//	>>
	friend TempVector exp(Vector);									// exp
	friend TempVector exp(TempVector);								//	>>
	friend TempVector log(Vector);									// log
	friend TempVector log(TempVector);								//	>>
	friend TempVector log10(Vector);								// log10
	friend TempVector log10(TempVector);							//	>>
	friend TempVector sqrt(Vector);									// sqrt
	friend TempVector sqrt(TempVector);								//	>>
	friend TempVector ceil(Vector);									// ceil
	friend TempVector ceil(TempVector);								//	>>
	friend TempVector floor(Vector);								// floor
	friend TempVector floor(TempVector);							//	>>
	friend TempVector abs(Vector);									// abs
	friend TempVector abs(TempVector);								//	>>
	friend TempVector operator + (Vector);							// operator + (unary)
	friend TempVector operator + (TempVector);						//	>>
	friend TempVector operator - (Vector);							// operator - (unary)
	friend TempVector operator - (TempVector);						//	>>
	friend TempVector operator ! (Vector);							// operator !
	friend TempVector operator ! (TempVector);						//	>>
	friend TempVector operator + (Vector,Vector);					// operator +
	friend TempVector operator + (TempVector,Vector);				//	>>
	friend TempVector operator + (Vector,TempVector);				//	>>
	friend TempVector operator + (TempVector,TempVector);			//	>>
	friend TempVector operator + (Vector,double);					//	>>
	friend TempVector operator + (double,Vector);					//	>>
	friend TempVector operator + (TempVector,double);				//	>>
	friend TempVector operator + (double,TempVector);				//	>>
	friend TempVector operator - (Vector,Vector);					// operator -
	friend TempVector operator - (TempVector,Vector);				//	>>
	friend TempVector operator - (Vector,TempVector);				//	>>
	friend TempVector operator - (TempVector,TempVector);			//	>>
	friend TempVector operator - (Vector,double);					//	>>
	friend TempVector operator - (double,Vector);					//	>>
	friend TempVector operator - (TempVector,double);				//	>>
	friend TempVector operator - (double,TempVector);				//	>>
	friend TempVector operator < (Vector,Vector);					// operator <
	friend TempVector operator < (TempVector,Vector);				//	>>
	friend TempVector operator < (Vector,TempVector);				//	>>
	friend TempVector operator < (TempVector,TempVector);			//	>>
	friend TempVector operator < (Vector,double);					//	>>
	friend TempVector operator < (double,Vector);					//	>>
	friend TempVector operator < (TempVector,double);				//	>>
	friend TempVector operator < (double,TempVector);				//	>>
	friend TempVector operator > (Vector,Vector);					// operator >
	friend TempVector operator > (TempVector,Vector);				//	>>
	friend TempVector operator > (Vector,TempVector);				//	>>
	friend TempVector operator > (TempVector,TempVector);			//	>>
	friend TempVector operator > (Vector,double);					//	>>
	friend TempVector operator > (double,Vector);					//	>>
	friend TempVector operator > (TempVector,double);				//	>>
	friend TempVector operator > (double,TempVector);				//	>>
	friend TempVector operator <= (Vector,Vector);					// operator <=
	friend TempVector operator <= (TempVector,Vector);				//	>>
	friend TempVector operator <= (Vector,TempVector);				//	>>
	friend TempVector operator <= (TempVector,TempVector);			//	>>
	friend TempVector operator <= (Vector,double);					//	>>
	friend TempVector operator <= (double,Vector);					//	>>
	friend TempVector operator <= (TempVector,double);				//	>>
	friend TempVector operator <= (double,TempVector);				//	>>
	friend TempVector operator >= (Vector,Vector);					// operator >=
	friend TempVector operator >= (TempVector,Vector);				//	>>
	friend TempVector operator >= (Vector,TempVector);				//	>>
	friend TempVector operator >= (TempVector,TempVector);			//	>>
	friend TempVector operator >= (Vector,double);					//	>>
	friend TempVector operator >= (double,Vector);					//	>>
	friend TempVector operator >= (TempVector,double);				//	>>
	friend TempVector operator >= (double,TempVector);				//	>>
	friend TempVector operator == (Vector,Vector);					// operator ==
	friend TempVector operator == (TempVector,Vector);				//	>>
	friend TempVector operator == (Vector,TempVector);				//	>>
	friend TempVector operator == (TempVector,TempVector);			//	>>
	friend TempVector operator == (Vector,double);					//	>>
	friend TempVector operator == (double,Vector);					//	>>
	friend TempVector operator == (TempVector,double);				//	>>
	friend TempVector operator == (double,TempVector);				//	>>
	friend TempVector operator != (Vector,Vector);					// operator !=
	friend TempVector operator != (TempVector,Vector);				//	>>
	friend TempVector operator != (Vector,TempVector);				//	>>
	friend TempVector operator != (TempVector,TempVector);			//	>>
	friend TempVector operator != (Vector,double);					//	>>
	friend TempVector operator != (double,Vector);					//	>>
	friend TempVector operator != (TempVector,double);				//	>>
	friend TempVector operator != (double,TempVector);				//	>>
	friend TempVector operator && (Vector,Vector);					// operator &&
	friend TempVector operator && (TempVector,Vector);				//	>>
	friend TempVector operator && (Vector,TempVector);				//	>>
	friend TempVector operator && (TempVector,TempVector);			//	>>
	friend TempVector operator && (Vector,double);					//	>>
	friend TempVector operator && (double,Vector);					//	>>
	friend TempVector operator && (TempVector,double);				//	>>
	friend TempVector operator && (double,TempVector);				//	>>
	friend TempVector operator || (Vector,Vector);					// operator ||
	friend TempVector operator || (TempVector,Vector);				//	>>
	friend TempVector operator || (Vector,TempVector);				//	>>
	friend TempVector operator || (TempVector,TempVector);			//	>>
	friend TempVector operator || (Vector,double);					//	>>
	friend TempVector operator || (double,Vector);					//	>>
	friend TempVector operator || (TempVector,double);				//	>>
	friend TempVector operator || (double,TempVector);				//	>>
	friend TempVector operator & (Vector,Vector);					// operator &
	friend TempVector operator & (TempVector,Vector);				//	>>
	friend TempVector operator & (Vector,TempVector);				//	>>
	friend TempVector operator & (TempVector,TempVector);			//	>>
	friend TempVector operator & (Vector,double);					//	>>
	friend TempVector operator & (double,Vector);					//	>>
	friend TempVector operator & (TempVector,double);				//	>>
	friend TempVector operator & (double,TempVector);				//	>>
	friend TempVector operator | (Vector,Vector);					// operator |
	friend TempVector operator | (TempVector,Vector);				//	>>
	friend TempVector operator | (Vector,TempVector);				//	>>
	friend TempVector operator | (TempVector,TempVector);			//	>>
	friend TempVector operator | (Vector,double);					//	>>
	friend TempVector operator | (double,Vector);					//	>>
	friend TempVector operator | (TempVector,double);				//	>>
	friend TempVector operator | (double,TempVector);				//	>>
	friend TempVector operator *= (Vector,Vector);					// operator *=
	friend TempVector operator *= (TempVector,Vector);				//	>>
	friend TempVector operator *= (Vector,TempVector);				//	>>
	friend TempVector operator *= (TempVector,TempVector);			//	>>
	friend TempVector operator *= (Vector,double);					//	>>
	friend TempVector operator *= (double,Vector);					//	>>
	friend TempVector operator *= (TempVector,double);				//	>>
	friend TempVector operator *= (double,TempVector);				//	>>
	friend TempVector operator /= (Vector,Vector);					// operator /=
	friend TempVector operator /= (TempVector,Vector);				//	>>
	friend TempVector operator /= (Vector,TempVector);				//	>>
	friend TempVector operator /= (TempVector,TempVector);			//	>>
	friend TempVector operator /= (Vector,double);					//	>>
	friend TempVector operator /= (double,Vector);					//	>>
	friend TempVector operator /= (TempVector,double);				//	>>
	friend TempVector operator /= (double,TempVector);				//	>>
	friend double operator * (TempVector,Vector);					// operator *
	friend double operator * (Vector,TempVector);					//	>>
	friend double operator * (TempVector,TempVector);				//	>>
	friend TempVector operator * (Vector,double);					//	>>
	friend TempVector operator * (double,Vector);					//	>>
	friend TempVector operator * (TempVector,double);				//	>>
	friend TempVector operator * (double,TempVector);				//	>>
	friend TempVector operator / (Vector,Vector);					// operator /
	friend TempVector operator / (TempVector,Vector);				//	>>
	friend TempVector operator / (Vector,TempVector);				//	>>
	friend TempVector operator / (TempVector,TempVector);			//	>>
	friend TempVector operator / (Vector,double);					//	>>
	friend TempVector operator / (double,Vector);					//	>>
	friend TempVector operator / (TempVector,double);				//	>>
	friend TempVector operator / (double,TempVector);				//	>>
	friend TempVector operator ^ (Vector,Vector);					// operator ^
	friend TempVector operator ^ (TempVector,Vector);				//	>>
	friend TempVector operator ^ (Vector,TempVector);				//	>>
	friend TempVector operator ^ (TempVector,TempVector);			//	>>
	friend TempVector operator ^ (Vector,double);					//	>>
	friend TempVector operator ^ (double,Vector);					//	>>
	friend TempVector operator ^ (TempVector,double);				//	>>
	friend TempVector operator ^ (double,TempVector);				//	>>
	friend TempVector operator ^= (Vector,Vector);					// operator ^=
	friend TempVector operator ^= (TempVector,Vector);				//	>>
	friend TempVector operator ^= (Vector,TempVector);				//	>>
	friend TempVector operator ^= (TempVector,TempVector);			//	>>
	friend TempVector operator ^= (Vector,double);					//	>>
	friend TempVector operator ^= (double,Vector);					//	>>
	friend TempVector operator ^= (TempVector,double);				//	>>
	friend TempVector operator ^= (double,TempVector);				//	>>
	friend TempVector operator % (Vector,Vector);					// operator %
	friend TempVector operator % (TempVector,Vector);				//	>>
	friend TempVector operator % (Vector,TempVector);				//	>>
	friend TempVector operator % (TempVector,TempVector);			//	>>
	friend TempVector operator % (Vector,double);					//	>>
	friend TempVector operator % (double,Vector);					//	>>
	friend TempVector operator % (TempVector,double);				//	>>
	friend TempVector operator % (double,TempVector);				//	>>
	friend TempVector max(Vector,Vector);							// max
	friend TempVector max(TempVector,Vector);						//	>>
	friend TempVector max(Vector,TempVector);						//	>>
	friend TempVector max(TempVector,TempVector);					//	>>
	friend TempVector max(Vector,double);							//	>>
	friend TempVector max(double,Vector);							//	>>
	friend TempVector max(TempVector,double);						//	>>
	friend TempVector max(double,TempVector);						//	>>
	friend TempVector min(Vector,Vector);							// min
	friend TempVector min(TempVector,Vector);						//	>>
	friend TempVector min(Vector,TempVector);						//	>>
	friend TempVector min(TempVector,TempVector);					//	>>
	friend TempVector min(Vector,double);							//	>>
	friend TempVector min(double,Vector);							//	>>
	friend TempVector min(TempVector,double);						//	>>
	friend TempVector min(double,TempVector);						//	>>
	friend TempVector operator | (Intermediate2of2,double);			// colon
	friend TempVector operator / (Intermediate1of1,double);			//	>>
public:
	double operator ()(unsigned int);								// operator ()
private:
	inline TempVector(){}											// default constracor
	inline TempVector *operator & (){return this;}
	anticast data;
}; // end class TempVector

		/************************************************************************************************
		*																								*
		*   Matrix is internally represented as a pointer to a block of consecutive memory addresses	*
		*   the size of this block should be equal to:													*
		* 				(# of rows)*(# of columns)*sizeof(double) + 2 * sizeof(unsiged int)				*
		*   The first of the sizeof(unsigned int) slots is used to hold the # of elements in the		*
		*   matrix while the second holds the # of rows. These can be used to calculate the # of rows	*
		*   of the matrix if necessary. To obtain better performance with functions that operate the	*
		*   same way as the corresponding matlab functions elements of the same column are placed in	*
		*   consecutive memory addresses with the memory addresses to grow as we move from the top to	*
		*   the bottom of the array. Columns are placed one after the other in the block with the		*
		*   memory addresses of the columns to grow as we move from left to right.						*
		*   This is means that a matrix is stored in memory as it's transpose would be stored if it		*
		*   was stored as a two dimentional array (double A[rows][columns]).							*
		*																								*
		************************************************************************************************/

class Matrix
{
	friend std::ostream &operator << (std::ostream &,Matrix);		// operator <<
	friend std::istream &operator >> (std::istream &,Matrix);		// operator >>
	friend TempMatrix polyval(Vector,Matrix);						// polyval
	friend TempMatrix polyval(TempVector,Matrix);					//	>>
	friend TempVector size(Matrix);									// size
	friend unsigned int size(Matrix,char);							//	>>
	friend unsigned int length(Matrix);								// lenght
	friend TempVector max(Matrix,unsigned int);						// max
	friend TempVector min(Matrix,unsigned int);						// min
	friend TempVector sum(Matrix,char);								// sum
	friend TempVector prod(Matrix,char);							// prod
	friend TempVector any(Matrix,char);								// any
	friend TempVector all(Matrix,char);								// all
	friend TempMatrix transpose(Matrix);							// transpose
	friend TempVector diag(Matrix,int);								// diag
	friend TempMatrix inv(Matrix);									// inv				//to do-
	friend TempMatrix polyvalm(Vector,Matrix);						// polyvalm			//to do-
	friend TempMatrix polyvalm(TempVector,Matrix);					//	>>				//to do-
	friend TempVector poly(Matrix);									// poly				//to do-
	friend TempVector eig(Matrix);									// eig				//to do-
	friend TempMatrix sin(Matrix);									// sin
	friend TempMatrix cos(Matrix);									// cos
	friend TempMatrix tan(Matrix);									// tan
	friend TempMatrix asin(Matrix);									// asin
	friend TempMatrix acos(Matrix);									// acos
	friend TempMatrix atan(Matrix);									// atan
	friend TempMatrix sinh(Matrix);									// sinh
	friend TempMatrix cosh(Matrix);									// cosh
	friend TempMatrix tanh(Matrix);									// tanh
	friend TempMatrix exp(Matrix);									// exp
	friend TempMatrix log(Matrix);									// log
	friend TempMatrix log10(Matrix);								// log10
	friend TempMatrix sqrt(Matrix);									// sqrt
	friend TempMatrix ceil(Matrix);									// ceil
	friend TempMatrix floor(Matrix);								// floor
	friend TempMatrix abs(Matrix);									// abs
	friend TempMatrix operator + (Matrix);							// operator + (unary)
	friend TempMatrix operator - (Matrix);							// operator - (unary)
	friend TempMatrix operator ! (Matrix);							// operator !
	friend TempMatrix operator + (Matrix,Matrix);					// operator +
	friend TempMatrix operator + (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator + (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator + (Matrix,double);					//	>>
	friend TempMatrix operator + (double,Matrix);					//	>>
	friend TempMatrix operator - (Matrix,Matrix);					// operator -
	friend TempMatrix operator - (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator - (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator - (Matrix,double);					//	>>
	friend TempMatrix operator - (double,Matrix);					//	>>
	friend TempMatrix operator < (Matrix,Matrix);					// operator <
	friend TempMatrix operator < (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator < (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator < (Matrix,double);					//	>>
	friend TempMatrix operator < (double,Matrix);					//	>>
	friend TempMatrix operator > (Matrix,Matrix);					// operator >
	friend TempMatrix operator > (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator > (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator > (Matrix,double);					//	>>
	friend TempMatrix operator > (double,Matrix);					//	>>
	friend TempMatrix operator <= (Matrix,Matrix);					// operator <=
	friend TempMatrix operator <= (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator <= (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator <= (Matrix,double);					//	>>
	friend TempMatrix operator <= (double,Matrix);					//	>>
	friend TempMatrix operator >= (Matrix,Matrix);					// operator >=
	friend TempMatrix operator >= (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator >= (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator >= (Matrix,double);					//	>>
	friend TempMatrix operator >= (double,Matrix);					//	>>
	friend TempMatrix operator == (Matrix,Matrix);					// operator ==
	friend TempMatrix operator == (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator == (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator == (Matrix,double);					//	>>
	friend TempMatrix operator == (double,Matrix);					//	>>
	friend TempMatrix operator != (Matrix,Matrix);					// operator !=
	friend TempMatrix operator != (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator != (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator != (Matrix,double);					//	>>
	friend TempMatrix operator != (double,Matrix);					//	>>
	friend TempMatrix operator && (Matrix,Matrix);					// operator &&
	friend TempMatrix operator && (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator && (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator && (Matrix,double);					//	>>
	friend TempMatrix operator && (double,Matrix);					//	>>
	friend TempMatrix operator || (Matrix,Matrix);					// operator ||
	friend TempMatrix operator || (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator || (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator || (Matrix,double);					//	>>
	friend TempMatrix operator || (double,Matrix);					//	>>
	friend TempMatrix operator & (Matrix,Matrix);					// operator &
	friend TempMatrix operator & (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator & (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator & (Matrix,double);					//	>>
	friend TempMatrix operator & (double,Matrix);					//	>>
	friend TempMatrix operator | (Matrix,Matrix);					// operator |
	friend TempMatrix operator | (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator | (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator | (Matrix,double);					//	>>
	friend TempMatrix operator | (double,Matrix);					//	>>
	friend TempMatrix operator *= (Matrix,Matrix);					// operator *=
	friend TempMatrix operator *= (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator *= (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator *= (Matrix,double);					//	>>
	friend TempMatrix operator *= (double,Matrix);					//	>>
	friend TempMatrix operator /= (Matrix,Matrix);					// operator /=
	friend TempMatrix operator /= (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator /= (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator /= (Matrix,double);					//	>>
	friend TempMatrix operator /= (double,Matrix);					//	>>
	friend TempMatrix operator * (Matrix,Matrix);					// operator *
	friend TempMatrix operator * (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator * (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator * (Matrix,double);					//	>>
	friend TempMatrix operator * (double,Matrix);					//	>>
	friend TempMatrix operator / (Matrix,Matrix);					// operator /
	friend TempMatrix operator / (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator / (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator / (Matrix,double);					//	>>
	friend TempMatrix operator / (double,Matrix);					//	>>
	friend TempMatrix operator ^ (Matrix,Matrix);					// operator ^
	friend TempMatrix operator ^ (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator ^ (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator ^ (Matrix,double);					//	>>
	friend TempMatrix operator ^ (double,Matrix);					//	>>
	friend TempMatrix operator ^= (Matrix,Matrix);					// operator ^=
	friend TempMatrix operator ^= (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator ^= (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator ^= (Matrix,double);					//	>>
	friend TempMatrix operator ^= (double,Matrix);					//	>>
	friend TempMatrix operator % (Matrix,Matrix);					// operator %
	friend TempMatrix operator % (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator % (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator % (Matrix,double);					//	>>
	friend TempMatrix operator % (double,Matrix);					//	>>
	friend TempMatrix max(Matrix,Matrix);							// max
	friend TempMatrix max(TempMatrix,Matrix);						//	>>
	friend TempMatrix max(Matrix,TempMatrix);						//	>>
	friend TempMatrix max(Matrix,double);							//	>>
	friend TempMatrix max(double,Matrix);							//	>>
	friend TempMatrix min(Matrix,Matrix);							// min
	friend TempMatrix min(TempMatrix,Matrix);						//	>>
	friend TempMatrix min(Matrix,TempMatrix);						//	>>
	friend TempMatrix min(Matrix,double);							//	>>
	friend TempMatrix min(double,Matrix);							//	>>
	friend inline TempMatrix operator ~ (Matrix A);					// operator ~
public:
	Matrix();											// default constractor
	~Matrix();											// destractor
	void operator = (TempMatrix);						// assignment operator
	void operator = (Matrix);							//		  >>
	void operator = (double);							//		  >>
	double &operator () (unsigned int,unsigned int);				// operator ()
	ReferenceList operator () (Matrix);								//	>>
	ReferenceList operator () (TempMatrix);							//	>>
	void resize(unsigned int,unsigned int);							// resize
private:
	anticast data;
}; // end class Matrix


class TempMatrix
{
	friend class Matrix;
	friend std::ostream &operator << (std::ostream &,TempMatrix);	// operator <<
	friend TempMatrix rand(unsigned int,unsigned int);				// rand
	friend TempMatrix randn(unsigned int,unsigned int);				// randn			//to do
	friend TempMatrix polyval(Vector,Matrix);						// polyval
	friend TempMatrix polyval(TempVector,Matrix);					//	>>
	friend TempMatrix polyval(Vector,TempMatrix);					//	>>
	friend TempMatrix polyval(TempVector,TempMatrix);				//	>>
	friend TempMatrix load(const char *);							// load				//to do
	friend TempVector size(TempMatrix);								// size
	friend unsigned int size(TempMatrix,char);						//	>>
	friend unsigned int length(TempMatrix);							// lenght
	friend TempVector max(TempMatrix,unsigned int);					// max
	friend TempVector min(TempMatrix,unsigned int);					// min
	friend TempVector sum(TempMatrix,char);							// sum
	friend TempVector prod(TempMatrix,char);						// prod
	friend TempVector any(TempMatrix,char);							// any
	friend TempVector all(TempMatrix,char);							// all
	friend TempMatrix transpose(Matrix);							// transpose
	friend TempMatrix transpose(TempMatrix);						//	>>
	friend TempMatrix eye(unsigned int);							// eye
	friend TempMatrix eye(unsigned int,unsigned int);				//	>>
	friend TempMatrix diag(Vector,int);								// diag
	friend TempMatrix diag(TempVector,int);							//	>>
	friend TempVector diag(TempMatrix,int);							//	>>
	friend TempMatrix zeros(unsigned int);							// zeros
	friend TempMatrix zeros(unsigned int,unsigned int);				//	>>
	friend TempMatrix ones(unsigned int);							// ones
	friend TempMatrix ones(unsigned int,unsigned int);				//	>>
	friend TempMatrix inv(Matrix);									// inv				//to do-
	friend TempMatrix inv(TempMatrix);								//	>>				//to do
	friend TempMatrix hilb(unsigned int);							// hilb
	friend TempMatrix hilb(unsigned int,unsigned int);				//	>>
	friend TempMatrix pascal(unsigned int);							// pascal			//to do		//pascal is coloured like a keyword of Visual C++, but  curiously it seems to work!
	friend TempMatrix polyvalm(Vector,Matrix);						// polyvalm			//to do-
	friend TempMatrix polyvalm(TempVector,Matrix);					//	>>				//to do-
	friend TempMatrix polyvalm(Vector,TempMatrix);					//	>>				//to do-
	friend TempMatrix polyvalm(TempVector,TempMatrix);				//	>>				//to do-
	friend TempVector poly(TempMatrix);								// poly				//to do-
	friend TempVector eig(TempMatrix);								// eig				//to do-
	friend TempMatrix toMatrix(Vector,char);						// toMatrix
	friend TempMatrix toMatrix(TempVector,char);					//	>>
	friend TempMatrix sin(Matrix);									// sin
	friend TempMatrix sin(TempMatrix);								//	>>
	friend TempMatrix cos(Matrix);									// cos
	friend TempMatrix cos(TempMatrix);								//	>>
	friend TempMatrix tan(Matrix);									// tan
	friend TempMatrix tan(TempMatrix);								//	>>
	friend TempMatrix asin(Matrix);									// asin
	friend TempMatrix asin(TempMatrix);								//	>>
	friend TempMatrix acos(Matrix);									// acos
	friend TempMatrix acos(TempMatrix);								//	>>
	friend TempMatrix atan(Matrix);									// atan
	friend TempMatrix atan(TempMatrix);								//	>>
	friend TempMatrix sinh(Matrix);									// sinh
	friend TempMatrix sinh(TempMatrix);								//	>>
	friend TempMatrix cosh(Matrix);									// cosh
	friend TempMatrix cosh(TempMatrix);								//	>>
	friend TempMatrix tanh(Matrix);									// tanh
	friend TempMatrix tanh(TempMatrix);								//	>>
	friend TempMatrix exp(Matrix);									// exp
	friend TempMatrix exp(TempMatrix);								//	>>
	friend TempMatrix log(Matrix);									// log
	friend TempMatrix log(TempMatrix);								//	>>
	friend TempMatrix log10(Matrix);								// log10
	friend TempMatrix log10(TempMatrix);							//	>>
	friend TempMatrix sqrt(Matrix);									// sqrt
	friend TempMatrix sqrt(TempMatrix);								//	>>
	friend TempMatrix ceil(Matrix);									// ceil
	friend TempMatrix ceil(TempMatrix);								//	>>
	friend TempMatrix floor(Matrix);								// floor
	friend TempMatrix floor(TempMatrix);							//	>>
	friend TempMatrix abs(Matrix);									// abs
	friend TempMatrix abs(TempMatrix);								//	>>
	friend TempMatrix operator + (Matrix);							// operator + (unary)
	friend TempMatrix operator + (TempMatrix);						//	>>
	friend TempMatrix operator - (Matrix);							// operator - (unary)
	friend TempMatrix operator - (TempMatrix);						//	>>
	friend TempMatrix operator ! (Matrix);							// operator !
	friend TempMatrix operator ! (TempMatrix);						//	>>
	friend TempMatrix operator + (Matrix,Matrix);					// operator +
	friend TempMatrix operator + (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator + (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator + (TempMatrix,TempMatrix);			//	>>
	friend TempMatrix operator + (Matrix,double);					//	>>
	friend TempMatrix operator + (double,Matrix);					//	>>
	friend TempMatrix operator + (TempMatrix,double);				//	>>
	friend TempMatrix operator + (double,TempMatrix);				//	>>
	friend TempMatrix operator - (Matrix,Matrix);					// operator -
	friend TempMatrix operator - (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator - (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator - (TempMatrix,TempMatrix);			//	>>
	friend TempMatrix operator - (Matrix,double);					//	>>
	friend TempMatrix operator - (double,Matrix);					//	>>
	friend TempMatrix operator - (TempMatrix,double);				//	>>
	friend TempMatrix operator - (double,TempMatrix);				//	>>
	friend TempMatrix operator < (Matrix,Matrix);					// operator <
	friend TempMatrix operator < (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator < (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator < (TempMatrix,TempMatrix);			//	>>
	friend TempMatrix operator < (Matrix,double);					//	>>
	friend TempMatrix operator < (double,Matrix);					//	>>
	friend TempMatrix operator < (TempMatrix,double);				//	>>
	friend TempMatrix operator < (double,TempMatrix);				//	>>
	friend TempMatrix operator > (Matrix,Matrix);					// operator >
	friend TempMatrix operator > (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator > (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator > (TempMatrix,TempMatrix);			//	>>
	friend TempMatrix operator > (Matrix,double);					//	>>
	friend TempMatrix operator > (double,Matrix);					//	>>
	friend TempMatrix operator > (TempMatrix,double);				//	>>
	friend TempMatrix operator > (double,TempMatrix);				//	>>
	friend TempMatrix operator <= (Matrix,Matrix);					// operator <=
	friend TempMatrix operator <= (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator <= (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator <= (TempMatrix,TempMatrix);			//	>>
	friend TempMatrix operator <= (Matrix,double);					//	>>
	friend TempMatrix operator <= (double,Matrix);					//	>>
	friend TempMatrix operator <= (TempMatrix,double);				//	>>
	friend TempMatrix operator <= (double,TempMatrix);				//	>>
	friend TempMatrix operator >= (Matrix,Matrix);					// operator >=
	friend TempMatrix operator >= (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator >= (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator >= (TempMatrix,TempMatrix);			//	>>
	friend TempMatrix operator >= (Matrix,double);					//	>>
	friend TempMatrix operator >= (double,Matrix);					//	>>
	friend TempMatrix operator >= (TempMatrix,double);				//	>>
	friend TempMatrix operator >= (double,TempMatrix);				//	>>
	friend TempMatrix operator == (Matrix,Matrix);					// operator ==
	friend TempMatrix operator == (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator == (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator == (TempMatrix,TempMatrix);			//	>>
	friend TempMatrix operator == (Matrix,double);					//	>>
	friend TempMatrix operator == (double,Matrix);					//	>>
	friend TempMatrix operator == (TempMatrix,double);				//	>>
	friend TempMatrix operator == (double,TempMatrix);				//	>>
	friend TempMatrix operator != (Matrix,Matrix);					// operator !=
	friend TempMatrix operator != (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator != (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator != (TempMatrix,TempMatrix);			//	>>
	friend TempMatrix operator != (Matrix,double);					//	>>
	friend TempMatrix operator != (double,Matrix);					//	>>
	friend TempMatrix operator != (TempMatrix,double);				//	>>
	friend TempMatrix operator != (double,TempMatrix);				//	>>
	friend TempMatrix operator && (Matrix,Matrix);					// operator &&
	friend TempMatrix operator && (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator && (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator && (TempMatrix,TempMatrix);			//	>>
	friend TempMatrix operator && (Matrix,double);					//	>>
	friend TempMatrix operator && (double,Matrix);					//	>>
	friend TempMatrix operator && (TempMatrix,double);				//	>>
	friend TempMatrix operator && (double,TempMatrix);				//	>>
	friend TempMatrix operator || (Matrix,Matrix);					// operator ||
	friend TempMatrix operator || (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator || (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator || (TempMatrix,TempMatrix);			//	>>
	friend TempMatrix operator || (Matrix,double);					//	>>
	friend TempMatrix operator || (double,Matrix);					//	>>
	friend TempMatrix operator || (TempMatrix,double);				//	>>
	friend TempMatrix operator || (double,TempMatrix);				//	>>
	friend TempMatrix operator & (Matrix,Matrix);					// operator &
	friend TempMatrix operator & (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator & (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator & (TempMatrix,TempMatrix);			//	>>
	friend TempMatrix operator & (Matrix,double);					//	>>
	friend TempMatrix operator & (double,Matrix);					//	>>
	friend TempMatrix operator & (TempMatrix,double);				//	>>
	friend TempMatrix operator & (double,TempMatrix);				//	>>
	friend TempMatrix operator | (Matrix,Matrix);					// operator |
	friend TempMatrix operator | (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator | (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator | (TempMatrix,TempMatrix);			//	>>
	friend TempMatrix operator | (Matrix,double);					//	>>
	friend TempMatrix operator | (double,Matrix);					//	>>
	friend TempMatrix operator | (TempMatrix,double);				//	>>
	friend TempMatrix operator | (double,TempMatrix);				//	>>
	friend TempMatrix operator *= (Matrix,Matrix);					// operator *=
	friend TempMatrix operator *= (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator *= (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator *= (TempMatrix,TempMatrix);			//	>>
	friend TempMatrix operator *= (Matrix,double);					//	>>
	friend TempMatrix operator *= (double,Matrix);					//	>>
	friend TempMatrix operator *= (TempMatrix,double);				//	>>
	friend TempMatrix operator *= (double,TempMatrix);				//	>>
	friend TempMatrix operator /= (Matrix,Matrix);					// operator /=
	friend TempMatrix operator /= (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator /= (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator /= (TempMatrix,TempMatrix);			//	>>
	friend TempMatrix operator /= (Matrix,double);					//	>>
	friend TempMatrix operator /= (double,Matrix);					//	>>
	friend TempMatrix operator /= (TempMatrix,double);				//	>>
	friend TempMatrix operator /= (double,TempMatrix);				//	>>
	friend TempMatrix operator * (Matrix,Matrix);					// operator *
	friend TempMatrix operator * (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator * (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator * (TempMatrix,TempMatrix);			//	>>
	friend TempMatrix operator * (Matrix,double);					//	>>
	friend TempMatrix operator * (double,Matrix);					//	>>
	friend TempMatrix operator * (TempMatrix,double);				//	>>
	friend TempMatrix operator * (double,TempMatrix);				//	>>
	friend TempMatrix operator / (Matrix,Matrix);					// operator /
	friend TempMatrix operator / (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator / (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator / (TempMatrix,TempMatrix);			//	>>
	friend TempMatrix operator / (Matrix,double);					//	>>
	friend TempMatrix operator / (double,Matrix);					//	>>
	friend TempMatrix operator / (TempMatrix,double);				//	>>
	friend TempMatrix operator / (double,TempMatrix);				//	>>
	friend TempMatrix operator ^ (Matrix,Matrix);					// operator ^
	friend TempMatrix operator ^ (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator ^ (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator ^ (TempMatrix,TempMatrix);			//	>>
	friend TempMatrix operator ^ (Matrix,double);					//	>>
	friend TempMatrix operator ^ (double,Matrix);					//	>>
	friend TempMatrix operator ^ (TempMatrix,double);				//	>>
	friend TempMatrix operator ^ (double,TempMatrix);				//	>>
	friend TempMatrix operator ^= (Matrix,Matrix);					// operator ^=
	friend TempMatrix operator ^= (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator ^= (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator ^= (TempMatrix,TempMatrix);			//	>>
	friend TempMatrix operator ^= (Matrix,double);					//	>>
	friend TempMatrix operator ^= (double,Matrix);					//	>>
	friend TempMatrix operator ^= (TempMatrix,double);				//	>>
	friend TempMatrix operator ^= (double,TempMatrix);				//	>>
	friend TempMatrix operator % (Matrix,Matrix);					// operator %
	friend TempMatrix operator % (TempMatrix,Matrix);				//	>>
	friend TempMatrix operator % (Matrix,TempMatrix);				//	>>
	friend TempMatrix operator % (TempMatrix,TempMatrix);			//	>>
	friend TempMatrix operator % (Matrix,double);					//	>>
	friend TempMatrix operator % (double,Matrix);					//	>>
	friend TempMatrix operator % (TempMatrix,double);				//	>>
	friend TempMatrix operator % (double,TempMatrix);				//	>>
	friend TempMatrix max(Matrix,Matrix);							// max
	friend TempMatrix max(TempMatrix,Matrix);						//	>>
	friend TempMatrix max(Matrix,TempMatrix);						//	>>
	friend TempMatrix max(TempMatrix,TempMatrix);					//	>>
	friend TempMatrix max(Matrix,double);							//	>>
	friend TempMatrix max(double,Matrix);							//	>>
	friend TempMatrix max(TempMatrix,double);						//	>>
	friend TempMatrix max(double,TempMatrix);						//	>>
	friend TempMatrix min(Matrix,Matrix);							// min
	friend TempMatrix min(TempMatrix,Matrix);						//	>>
	friend TempMatrix min(Matrix,TempMatrix);						//	>>
	friend TempMatrix min(TempMatrix,TempMatrix);					//	>>
	friend TempMatrix min(Matrix,double);							//	>>
	friend TempMatrix min(double,Matrix);							//	>>
	friend TempMatrix min(TempMatrix,double);						//	>>
	friend TempMatrix min(double,TempMatrix);						//	>>
	// inlines
	friend inline TempMatrix operator ~ (Matrix A)
	{
		TempMatrix B = transpose(A);
		A.data.v = 0;
		return B;
	}
	friend inline TempMatrix operator ~ (TempMatrix A){return transpose(A);}
public:
	double operator ()(unsigned int,unsigned int);					// operator ()
private:
	inline TempMatrix(){}											// default constracor
	inline TempMatrix *operator & (){return this;}
	anticast data;
}; // end class TempMatrix


void tic();															// tic
void toc(std::ostream &outStream = std::cout);						// toc


class ReferenceList	// no relation with & references. it just "refers" to things.
{				// implemented as a null-terminated list of pointers.
	friend class Vector;
	friend class Matrix;
	friend unsigned int length(ReferenceList r);				// length
public:
	void operator = (double);										// assignment operator
	void operator = (ReferenceList);								//			>>
	void operator = (Vector);										//			>>
	void operator = (TempVector);									//			>>
private:
	inline ReferenceList(){}										// default constracor
	inline ReferenceList *operator & (){return this;}
	double **data;
}; // end class ReferenceList

} // end namespace ASL




// deconv
// residue
// rest of polyder
									/********/
									/* plot */
									/********/


#endif
