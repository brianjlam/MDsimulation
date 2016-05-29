// MD Simulation, Brian Lam
#include <iostream>
#include <fstream>
#include "myMD.h"
using std::cout;
using std::cin;

void System::makeSystem()
{
	// prompt simulation parameters
	cout << "How long to simulate? ";
	cin >> t_max;
	cout << "Size of timestep? ";
	cin >> delt;
	cout << "Number of particles? Give sqrt(N) ";
	cin >> size;
	cout << "Lattice Spacing? ";
	cin >> space;
	cout << "Initial temperature? ";
	cin >> temp;
	N = size*size;
	x.resize(N);
	y.resize(N);
	xm.resize(N);
	ym.resize(N);
	fx.resize(N);
	fy.resize(N);
}

int main()
{	
	// output stream to MDlog.csv
	std::ofstream outputThermo;
	outputThermo.open("thermolog.csv");
	// create sys containing state of particles in system
	System sys;
	sys.makeSystem();
	init(sys);

	outputThermo << "#tmax" << sys.t_max << "dt" << sys.delt << 
		"size" << sys.size << "latspc" << sys.space << "temp" << sys.temp << "\n";
	outputThermo << "time,temp,KE,PE,total energy\n";


	// simulate from t = 0 to t = t_max
	for (double t = 0; t < sys.t_max; t += sys.delt)
	{
		// calculate force and motion
		force(sys);
		double etot = integrate(sys);
		
		// output results to file
		outputThermo << t << ", ";
		outputThermo << sys.temp << ", ";
		outputThermo << etot - sys.pe << ", ";
		outputThermo << sys.pe << ", ";
		outputThermo << etot << "\n";
	}
}
