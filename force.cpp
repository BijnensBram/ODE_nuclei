#include <cmath>

/* Scalar forces between nuclei */
double f(double sigmaN, double alphaN, double d, double dref, double cN){
	if ((cN-d)>0){
		return sigmaN*pow(d/dref,alphaN);
	}else{
		return 0;
	}
}

/* Scalar forces between nuclei and cell side or poles*/
double g(double sigma, double M, double alpha, double d, double dref, double c){
	if ((c-d)>0){
		return sigma*M*pow(d/dref,alpha);
	}else{
		return 0;
	}
}
