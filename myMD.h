#ifndef MYMD
#define MYMD
#include <vector>

class System
{
	// create system with attributes size, N, x, y, etc.
	public:
		double t_max;
		int size;
		int N;
		double space;
		double delt;
		double temp;
		long double en;
		std::vector<long double> x;
		std::vector<long double> y;
		std::vector<long double> xm;
		std::vector<long double> ym;
		std::vector<long double> fx;
		std::vector<long double> fy;
		void makeSystem();
};

void init(System &sys);
void force(System &sys);
long double integrate(System &sys);

#endif
