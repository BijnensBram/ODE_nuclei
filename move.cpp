#include <cmath>

/* function to calculate distances between nuclei */
double distanced(double x1, double x2, double y1, double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

/* function to get max displacement */
double get_max(double maxdx, double maxdy,double mindx, double mindy, double &max){
	if (maxdx > maxdy && maxdx > fabs(mindx) && maxdx > fabs(mindy)){
		max = maxdx;
	}else if (maxdy > maxdx && maxdy > fabs(mindx) && maxdy > fabs(mindy)){
		max = maxdy;
	}else if (fabs(mindx) > fabs(mindy) && fabs(mindx) > maxdx && fabs(mindx) > maxdy){
		max = fabs(mindx);
	}else {
		max = fabs(mindy);
	}
	/* choosing dt variable such that simulations are faster if forces are small */
	if (max == 0){
		return 0.01;
	} else {
		return 0.01/max;
	}
}

/* function to update positions */
void update(double &x, double &y, double dxdt, double dydt,double dt,double lx, double ly, double r){
	/* updating position */
	x += dxdt*dt;
	y += dydt*dt;
}
