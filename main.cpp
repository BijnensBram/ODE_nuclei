#include <iostream>
#include <cmath>
#include <random>
#include <fstream>
#include "force.h"
#include "move.h"

int main(int argc, char *argv[]){
	/* defining constants */
	const double alphaN = -1;
	const double alphaS = 1;
	const double alphaP = -1;

	const double sigmaN = 1;
	const double sigmaS = -1;
	const double sigmaP = 1;

	const double cN = 50;
	const double cS = 50;
	const double cP = 50;

	const double MS = 5;
	const double MP = 200;

	const int N = 10;
	const double lx = 250;
	const double ly = 50;
	const double dref = 40;
	const double tmax = 100;
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
	double f;
	double d;
	int j;
	
	for (int i=0; i < N; i++){
		x[i] = initx(rng);
		y[i] = inity(rng);
	}

	/* defining output files */
	std::ofstream File;
	std::string xfilename;
	std::string yfilename;
	xfilename = std::string("xdata_") + argv[1];
	yfilename = std::string("ydata_") + argv[1];

	for (double t =0; t<= tmax; t+=dt){
		for (int i=0; i < N; i++){
			dXdt[i]=0;
			dYdt[i]=0;
			for (int a=1; a<N ; a++){
				/* needs imporvement how to make more efficient? store forces maybe? */
				j = (i+a)%N;
				d = distanced(x[i],y[i],x[j],y[j]);
				xpart = (x[i]-x[j])/d;
				ypart = (y[i]-y[j])/d;
				dXdt[i] += forcef(sigmaN,alphaN,d,dref,cN)*xpart;
				dYdt[i] += forcef(sigmaN,alphaN,d,dref,cN)*ypart;
			}
			dXdt[i] += forceg(sigmaS,MS,alphaS, x[i],dref,cS);
			dXdt[i] += forceg(sigmaS,MS,alphaS, lx-x[i],dref,cS);

			dYdt[i] += forceg(sigmaP,MP,alphaP, y[i],dref,cP);
			dYdt[i] += forceg(sigmaP,MP,alphaP, ly-y[i],dref,cP);
		}
		for (int i=0; i < N; i++){
			x[i] += dXdt[i]*dt;
			y[i] += dYdt[i]*dt;
		}
		File.open(xfilename.c_str(),std::ios_base::app);
		for (int i=0; i < N-1; i++){
			File << x[i] << ";";
		}
		File << x[N-1] << std::endl;
		File.close();
		
		File.open(yfilename.c_str(),std::ios_base::app);
		for (int i=0; i < N-1; i++){
			File << y[i] << ";";
		}
		File << y[N-1] << std::endl;
		File.close();

	}

	return 0;
}
