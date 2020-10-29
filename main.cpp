#include <iostream>
#include <cmath>
#include <random>
#include <fstream>
#include <algorithm>   
#include "force.h"
#include "move.h"

int main(int argc, char *argv[]){
	/* defining constants */
	const double alphaN = -1;
	const double alphaS = -1;
	const double alphaP = -1;

	const double sigmaN = 1;
	const double sigmaS = 1;
	const double sigmaP = 1;

	const int N = 15;
	const double lx = 250;
	const double ly = 100;
	const double dref = 40;
	const double tmax = 10000;
	const double r = 7;
	const double Qe = 5000;
	
	/* taking user input */
	const double cN = std::stod(argv[2]);
	const double cS = std::stod(argv[3]);
	const double cP = std::stod(argv[4]);

	const double MS = std::stod(argv[5]);
	const double MP = std::stod(argv[6]);

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

	/* random positions */
	for (int i=0; i < N; i++){
		x[i] = initx(rng);
		y[i] = inity(rng);
	}

	/* defining output files */
	std::ofstream File;
	std::string xfilename;
	std::string yfilename;
	xfilename = std::string("data/xdata_") + argv[1] + std::string(".txt");
	yfilename = std::string("data/ydata_") + argv[1] + std::string(".txt");
	
	double t = 0;
	double dt;
	double maxdx;
	double maxdy;
	double mindx;
	double mindy;
	double max;
	while (t<= tmax){
		for (int i=0; i < N; i++){
			dXdt[i]=0;
			dYdt[i]=0;
			for (int a=1; a<N ; a++){
				/* needs imporvement how to make more efficient? store forces maybe? */
				j = (i+a)%N;
				d = distanced(x[i],x[j],y[i],y[j]);
				xpart = (x[i]-x[j])/d;
				ypart = (y[i]-y[j])/d;
				dXdt[i] += forcef(sigmaN,alphaN,d,dref,cN)*xpart;
				dXdt[i] += finsize(Qe,d,2*r)*xpart;
				dYdt[i] += forcef(sigmaN,alphaN,d,dref,cN)*ypart;
				dYdt[i] += finsize(Qe,d,2*r)*ypart;
			}
			dXdt[i] += (x[i])/fabs(x[i])*forceg(sigmaS,MS,alphaS, fabs(x[i]),dref,cS);
			dXdt[i] += (x[i]-lx)/fabs(lx-x[i])*forceg(sigmaS,MS,alphaS, fabs(lx-x[i]),dref,cS);
			dXdt[i] += finsize(Qe,x[i],r);
			dXdt[i] -= finsize(Qe,fabs(lx-x[i]),r);

			dYdt[i] += (y[i])/fabs(y[i])*forceg(sigmaP,MP,alphaP, fabs(y[i]),dref,cP);
			dYdt[i] += (y[i]-ly)/fabs(ly-y[i])*forceg(sigmaP,MP,alphaP, fabs(ly-y[i]),dref,cP);
			dYdt[i] += finsize(Qe,y[i],r);
			dYdt[i] -= finsize(Qe,fabs(ly-y[i]),r);

		}
		
		/* figuring out the biggest force to determine dt such that the movements are not to large */
		maxdx = *std::max_element(dXdt,dXdt+N);
		maxdy = *std::max_element(dYdt,dYdt+N);
		mindx = *std::min_element(dXdt,dXdt+N);
		mindy = *std::min_element(dYdt,dYdt+N);
		
		dt = get_max(maxdx,maxdy,mindx,mindy,max);
		
		/* updateting positions */
		for (int i=0; i < N; i++){
			update(x[i],y[i],dXdt[i],dYdt[i],dt,lx,ly,r);
		}
		/* updating time */
		t +=dt;
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
	return 0;
}
