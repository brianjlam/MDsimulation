#ifndef MYMD
#define MYMD
#include <vector>
using std::vector;

class System
{
	// create system with attributes size, N, x, y, etc.
	public:
		double t_max = 1;
		int size = 7;
		int N;
		double space = 2;
		double delt = 0.01;
		double temp = 1;
		long double pe;
		vector<long double> x;
		vector<long double> y;
		vector<long double> xm;
		vector<long double> ym;
		vector<long double> fx;
		vector<long double> fy;
		void makeSystem();
};

void init(System &sys);
void force(System &sys);
long double integrate(System &sys);

#endif
