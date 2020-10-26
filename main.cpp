#include <iostream>
#include <cmath>
#include <random>
#include "force.h"

int main(int argc, char *argv[]){
	/* defining constants */
	const double alphaN = 1;
	const double alphaS = 1;
	const double alphaP = 1;

	const double cN = 40e-6;
	const double cS = 40e-6;
	const double cP = 40e-6;

	const double MS = 1;
	const double MP = 1;

	const int N = 10;
	const double lx = 50e-6;
	const double ly = 50e-6;
	const double tmax = 10;
	const double dt = 0.001;
	
	/* random number generators */ 
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_real_distribution<double> initx(0,lx);
	std::uniform_real_distribution<double> inity(0,ly);

	/* Initialisation */
	double x[N];
	double y[N];
	double dXdt[N];
	double dYdt[N];
	double xpart;
	double ypart;
	
	for (int i=0; i < N; i++){
		x[i] = initx(rng);
		y[i] = inity(rng);
	}

	for (double t =0; t<= tmax; t+=dt)

	return 0;
}
