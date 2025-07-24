//FormAI DATASET v1.0 Category: Physics simulation ; Style: single-threaded
#include <stdio.h>
#include <math.h>
#define pi 3.141592

int main() {
    double dt = 0.1; // time step
    double tmax = 10.0; // maximum simulation time
    double m = 1.0; // mass of particle
    double k = 1.0; // spring constant
    double b = 0.2; // damping coefficient
    double x = 0.5; // initial position
    double v = 0.0; // initial velocity
    double a = -k*x/m - b*v/m; // initial acceleration
    
    // Run simulation
    double t;
    for (t=0.0; t<=tmax; t+=dt) {
        printf("%f,%f\n", t, x); // output time and position
        x += v*dt; // update position
        v += a*dt; // update velocity
        a = -k*x/m - b*v/m; // calculate acceleration
    }
    
    return 0;
}