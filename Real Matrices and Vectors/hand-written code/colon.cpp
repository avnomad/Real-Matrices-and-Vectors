#include "colon.h"

namespace ASL
{

Colon C;
double Colon::a;
double Colon::step;

Intermediate1of2 operator | (Colon,double a)
{
	Intermediate1of2 temp;

	Colon::a = a;
	return temp;
} // end function operator |


Intermediate2of2 operator | (Intermediate1of2,double step)
{
	Intermediate2of2 temp;

	Colon::step = step;
	return temp;
} // end function operator |


TempVector operator | (Intermediate2of2,double b)
{
	register unsigned int c;
	register double x;
	register anticast p;
	TempVector v;

	c = (b - Colon::a) / Colon::step;
	++c;
	p.v = v.data.v = malloc(sizeof(unsigned int) + c*sizeof(double));

	*p.ui++ = c;
	*p.d = x = Colon::a;

	while(--c)
		*++p.d = x += Colon::step;

	return v;
} // end function operator |

Intermediate1of1 operator / (Colon,double a)
{
	Intermediate1of1 temp;

	Colon::a = a;
	return temp;
} // end function operator /


TempVector operator / (Intermediate1of1,double b)
{
	register unsigned int c;
	register double x;
	register anticast p;
	TempVector v;

	c = b - Colon::a;
	++c;
	p.v = v.data.v = malloc(sizeof(unsigned int) + c*sizeof(double));

	*p.ui++ = c;
	*p.d = x = Colon::a;

	while(--c)
		*++p.d = ++x;

	return v;
} // end function operator |

} // end namespace ASL

