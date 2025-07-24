//FormAI DATASET v1.0 Category: Physics simulation ; Style: mind-bending
#include <stdio.h>
#include <math.h>

#define dt 0.01    // time step
#define omega 2.0  // angular frequency
#define k 1.0      // spring constant
#define m 1.0      // mass

int main() {
    double t = 0, x = 1, v = 0, a;  // initial conditions
    int steps = 1000;               // number of time steps

    for (int i = 0; i < steps; i++) {
        a = -k/m*x;               // acceleration from Hooke's Law
        v += a*dt;                // update velocity
        x += v*dt;                // update position
        t += dt;                  // increment time
        printf("%f %f\n", t, x);  // print time and position
    }

    return 0;
}