// Calculate force
#include <cmath>
#include <iostream>
#include "myMD.h"

void force(System &sys)
{
	// calculate cutoff conditions, when r > cutoff distance
	const long double rc2 = 3*sys.space; // arbitrary distance
	const long double ec = 4*(pow(rc2, -6) - pow(rc2, -3));
	
	// reset force and energy to zero
	for (int i = 0; i < sys.N; i++)
	{
		sys.fx[i] = 0;
		sys.fy[i] = 0;
	}
	sys.en = 0;

	// calculate force, considering all pairs of atoms
	for (int i = 0; i < sys.N - 1; i++)
	{
		for (int j = i + 1; j < sys.N; j++)
		{
			long double xr = sys.x[i] - sys.x[j];
			long double yr = sys.y[i] - sys.y[j];
			
			// use distance from i to nearest j (periodic boundary conditions)
			xr -= (sys.size+sys.space)*std::round(xr/(sys.size+sys.space));
			yr -= (sys.size+sys.space)*std::round(yr/(sys.size+sys.space));
			long double r2 = xr*xr + yr*yr;
			
			// calculate force component for atoms within cutoff radius
			if (r2 < rc2)
			{
				long double r2i = 1.0/r2;
				long double r6i = pow(r2i, 3);
				long double ff = 48*r2i*r6i*(r6i - 0.5); // Lennard-Jones force
				sys.fx[i] += ff*xr;
				sys.fy[i] += ff*yr;
				sys.fx[j] -= ff*xr;
				sys.fy[j] -= ff*yr;
				sys.en += 4*r6i*(r6i - 1) - ec; // Lennard-Jones potential energy
			}
		}
	}
}
