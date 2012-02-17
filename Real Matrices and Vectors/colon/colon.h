#ifndef COLON_H
#define COLON_H

#include "../Real Matrices and Vectors.h"

namespace ASL
{

class Intermediate1of2;
class Intermediate2of2;
class Intermediate1of1;
class TempVector;

class Colon
{
	friend Intermediate1of2 operator | (Colon,double);
	friend Intermediate2of2 operator | (Intermediate1of2,double);
	friend TempVector operator | (Intermediate2of2,double);
	friend Intermediate1of1 operator / (Colon,double);
	friend TempVector operator / (Intermediate1of1,double);
private:
	static double a;
	static double step;
};


extern Colon C;


class Intermediate1of2
{
	friend Intermediate1of2 operator | (Colon,double);
private:
	inline Intermediate1of2(){}
	inline Intermediate1of2 *operator & (){return this;}
};


class Intermediate2of2
{
	friend Intermediate2of2 operator | (Intermediate1of2,double);
private:
	inline Intermediate2of2(){}
	inline Intermediate2of2 *operator & (){return this;}
};


class Intermediate1of1
{
	friend Intermediate1of1 operator / (Colon,double);
private:
	inline Intermediate1of1(){}
	inline Intermediate1of1 *operator & (){return this;}
};


} // end namespace ASL

#endif
