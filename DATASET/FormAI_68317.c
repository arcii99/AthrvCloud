//FormAI DATASET v1.0 Category: Physics simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double dt = 0.001; // time step
    double tmax = 10; // simulation time
    double t = 0; // current time
    double k = 1; // spring constant
    double m = 1; // mass
    double x = 0; // position
    double v = 1; // velocity

    while (t < tmax) {
        double a = -k * x / m; // calculate acceleration
        v += a * dt; // update velocity
        x += v * dt; // update position
        t += dt; // update time

        printf("t = %f, x = %f\n", t, x);
    }

    return 0;
}