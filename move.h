#ifndef MOVE
#define MOVE

/* function to calculate distances between nuclei */
double distanced(double x1, double x2, double y1, double y2);

/* function to get max displacement */
double get_max(double maxdx, double maxdy,double mindx, double mindy, double &max);

/* function to update positions */
void update(double &x, double &y, double dxdt, double dydt,double dt,double lx, double ly, double r);

#endif //MOVE
