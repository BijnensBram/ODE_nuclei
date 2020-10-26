#ifndef MOVE
#define MOVE

/* function to calculate distances between nuclei */
double d(double x1, double x2, double y1, double y2);

/* function to calculate direction of the force */
void directionpart(double &xpart, double &ypart, double x1, double x2, double y1, double y2);

/* function to calculate dxdt */
void dXdt(double &dxdt, double xpart, double ypart, double f, double gs, double gp);

#endif //MOVE
