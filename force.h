#ifndef FORCES
#define FORCES

/* Scalar forces between nuclei */
double f(double sigmaN, double alphaN, double d, double dref, double cN);

/* Scalar forces between nuclei and cell side or poles*/
double g(double sigma, double M, double alpha, double d, double dref, double c);

#endif //FORCES
