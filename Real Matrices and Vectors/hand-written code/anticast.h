#ifndef ANTICAST_H
#define ANTICAST_H

namespace ASL
{

union anticast	//ISO C++ forbids this, ISO C++ forbids that... fuck C++!! Long live C!
{
	void *v;
	unsigned int *ui;
	double *d;
}; //end of union anticast

} // end namespace ASL
#endif
