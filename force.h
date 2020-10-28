#ifndef FORCES
#define FORCES

/* heavyside function */
double H(double x);

/* Scalar forces between nuclei */
double forcef(double sigmaN, double alphaN, double d, double dref, double cN);

/* Scalar forces between nuclei and cell side or poles*/
double forceg(double sigma, double M, double alpha, double d, double dref, double c);

/* finite size exclusion */
double finsize(double Qe, double d, double r);

#endif //FORCES
