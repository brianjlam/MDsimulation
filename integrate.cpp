// Integrate motion
#include "myMD.h"

long double integrate(System &sys)  
{
	long double sumv2 = 0;
	
	// Move atoms based on Verlet algorithm
	for (int i = 0; i < sys.N; i++)
	{
		// Taylor approximation of new location
		long double xx = 2*sys.x[i] - sys.xm[i] + sys.fx[i]*sys.delt*sys.delt;
		long double yy = 2*sys.y[i] - sys.ym[i] + sys.fy[i]*sys.delt*sys.delt;
		long double vx = (xx - sys.xm[i])/(2*sys.delt);
		long double vy = (yy - sys.ym[i])/(2*sys.delt);
		sumv2 += vx*vx + vy*vy;
		
		// Update current and previous locations
		sys.xm[i] = sys.x[i];
		sys.ym[i] = sys.y[i];
		sys.x[i] = xx;
		sys.y[i] = yy;
	}
	sys.temp = 0.5*sumv2/sys.N;
	// Sum P.E. and K.E.
	long double etot = (sys.pe + 0.5*sumv2)/sys.N;
	return etot;
}
