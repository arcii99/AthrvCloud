//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define G 6.67e-11 // gravitational constant

// function to calculate distance between two planets
double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

int main() {
    // define parameters for planet 1
    double x1 = 0.0, y1 = 0.0, mass1 = 6.0e24, vx1 = 0.0, vy1 = 0.0, fx1 = 0.0, fy1 = 0.0;
    // define parameters for planet 2
    double x2 = 15.0e6, y2 = 0.0, mass2 = 7.0e24, vx2 = 0.0, vy2 = 30000.0, fx2 = 0.0, fy2 = 0.0;
    // define time step and simulation time
    double dt = 1000.0, t_max = 86400.0*365.0;

    // simulate the motion of the planets
    for (double t = 0; t <= t_max; t += dt) {
        // calculate distance between the planets
        double r = distance(x1, y1, x2, y2);
        // calculate force between the planets using gravitational law
        double f = G * mass1 * mass2 / (r*r);
        // decompose force into x and y components
        fx1 = f * (x2 - x1) / r;
        fy1 = f * (y2 - y1) / r;
        fx2 = -fx1;
        fy2 = -fy1;
        // update velocities of the planets using the computed forces
        vx1 += fx1/mass1 * dt;
        vy1 += fy1/mass1 * dt;
        vx2 += fx2/mass2 * dt;
        vy2 += fy2/mass2 * dt;
        // update positions of the planets using their current velocities
        x1 += vx1 * dt;
        y1 += vy1 * dt;
        x2 += vx2 * dt;
        y2 += vy2 * dt;
        // print the current positions of the planets
        printf("t = %.0f s: planet 1 at (%.2f, %.2f), planet 2 at (%.2f, %.2f)\n", t, x1, y1, x2, y2);
    }
    return 0;
}