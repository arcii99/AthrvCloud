//FormAI DATASET v1.0 Category: Physics simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <math.h>

int main()
{
    printf("Welcome to the Physics Simulation Program!\n");

    // constant values
    const double G = 6.67430e-11; // gravitational constant
    const double M = 5.9722e24; // mass of the Earth
    const double R = 6.3788e6; // radius of the Earth

    // initial values
    double h = 1000.0; // altitude of satellite
    double v = 7500.0; // velocity of satellite
    double m = 600.0; // mass of the satellite
    double theta = M_PI / 4; // initial angle

    // calculate initial position and velocity components
    double vx = v * cos(theta);
    double vy = v * sin(theta);
    double x = R + h;
    double y = 0.0;

    // simulation parameters
    const double dt = 1.0; // time step
    const int nsteps = 10000; // number of time steps

    // simulation loop
    for (int i = 0; i < nsteps; i++) {
        // calculate gravitational force
        double Fg = (G * M * m) / pow(x, 2);

        // calculate acceleration
        double ax = (-Fg / m) * cos(theta);
        double ay = (-Fg / m) * sin(theta) - (G * M / pow(x, 2));

        // update velocity components
        vx += ax * dt;
        vy += ay * dt;

        // update position components
        x += vx * dt;
        y += vy * dt;

        // check for collision with Earth
        if (x < R) {
            printf("Collision with Earth at time %d\n", i);
            break;
        }

        // print current position
        if (i % 100 == 0) {
            printf("Position at time %d: (%.2f, %.2f)\n", i, x - R, y);
        }
    }

    printf("Simulation complete.\n");

    return 0;
}