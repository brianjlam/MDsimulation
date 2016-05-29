// init routine for MDsim
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include "myMD.h"

void init(System &sys)
{
	double sumvx = 0, sumvy = 0, sumv2 = 0;
	double vx [sys.N], vy [sys.N];
	std::srand(std::time(0));
	for (int i = 0; i < sys.N; i++)
	{
		sys.x[i] = sys.space*(i % sys.size + 1);
		sys.y[i] = sys.space*(i/3 + 1);
		vx[i] = (std::rand() % 10000)/ 10000 - 0.5;
		vy[i] = (std::rand() % 10000)/ 10000 - 0.5;
		sumvx += vx[i];
		sumvy += vy[i];
		sumv2 += vx[i]*vx[i] + vy[i]*vy[i];
	}
	sumvx /= sys.N;
	sumvy /= sys.N;
	sumv2 /= sys.N;
	double fs = std::sqrt(2*sys.temp/sumv2);
	std::cout << fs;
	for (int i = 0; i < sys.N; i++)
	{
		vx[i] = (vx[i] - sumvx)*fs;
		vy[i] = (vy[i] - sumvy)*fs;
		sys.xm[i] = sys.x[i] - vx[i]*sys.delt;
		sys.ym[i] = sys.y[i] - vy[i]*sys.delt;
	}
}
