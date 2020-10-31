#include <cmath>

/* Scalar forces between nuclei */
double forcef(double sigmaN, double alphaN, double d, double dref, double cN){
	return sigmaN*pow(d/dref,alphaN)*((cN-d)>0);
}

/* Scalar forces between nuclei and cell side or poles*/
double forceg(double sigma, double M, double alpha, double d, double dref, double c){
	return sigma*M*pow(d/dref,alpha)*((c-d)>0);
}

/* finite size exclusion */
double finsize(double Qe, double d, double r){
	return Qe*(1/(d*d)-1/(r*r))*((r-d)>0);
}
