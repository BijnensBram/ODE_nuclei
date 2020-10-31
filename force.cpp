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
double forcef(double sigmaN, double alphaN, double d, double dref, double cN){
	return sigmaN*pow(d/dref,alphaN)*H(cN-d);
}

/* Scalar forces between nuclei and cell side or poles*/
double forceg(double sigma, double M, double alpha, double d, double dref, double c){
	return sigma*M*pow(d/dref,alpha)*H(c-d);
}

/* finite size exclusion */
double finsize(double Qe, double d, double r){
	return Qe*(1/(d*d)-1/(r*r))*H(r-d);
}
