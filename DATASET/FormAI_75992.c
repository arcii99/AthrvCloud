//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: shocked
#include <stdio.h>
#include <math.h>

// define the gravitational constant
#define G 6.67e-11

// define the mass of the planet
#define MASS_PLANET 5.97e24

// define the radius of the planet
#define RADIUS_PLANET 6.37e6

void calculate_acceleration(double x, double y, double *ax, double *ay)
{
    // calculate the distance r from the center of the planet
    double r = sqrt(x * x + y * y);

    // calculate the gravitational acceleration a
    double a = G * MASS_PLANET / (r * r);

    // calculate the angle theta from the x axis
    double theta = atan2(y, x);

    // calculate the x and y components of a
    *ax = -a * sin(theta);
    *ay = a * cos(theta);
}

int main()
{
    // set the initial position and velocity of the object
    double x = 0.0;
    double y = 2.0 * RADIUS_PLANET;
    double vx = 6000.0;
    double vy = 0.0;

    // set the time step and the duration of the simulation
    double dt = 1.0;
    double tmax = 100000.0;

    // simulate the motion of the object
    for (double t = 0.0; t < tmax; t += dt) {
        // calculate the acceleration of the object
        double ax, ay;
        calculate_acceleration(x, y, &ax, &ay);

        // update the velocity of the object
        vx += ax * dt;
        vy += ay * dt;

        // update the position of the object
        x += vx * dt;
        y += vy * dt;

        // check if the object has collided with the planet
        if (sqrt(x * x + y * y) < RADIUS_PLANET) {
            printf("Collision at t=%g\n", t);
            break;
        }
    }

    return 0;
}