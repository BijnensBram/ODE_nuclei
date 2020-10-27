#include <cmath>

/* heavyside function */
double H(double x){
	if (x > 0){
		return 1;
	}else{
		return 0;
	}
}

/* Scalar forces between nuclei */
double forcef(double sigmaN, double alphaN, double d, double dref, double cN,double Qe,double r, double part){
	return part*sigmaN*pow(d/dref,alphaN)*H(cN-d) + part*Qe*(1/(d*d)-1/(4*r*r))*H(2*r-d);
}

/* Scalar forces between nuclei and cell side or poles*/
double forceg(double sigma, double M, double alpha, double d, double dref, double c, double Qe, double r, double part){
	return part*sigma*M*pow(d/dref,alpha) + part*Qe*(1/(d*d)-1/(r*r))*H(2*r-d);
}

