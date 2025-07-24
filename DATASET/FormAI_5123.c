//FormAI DATASET v1.0 Category: Physics simulation ; Style: calm
#include <stdio.h>
#include <math.h>

int main()
{
    double h = 0.01; // time step
    double t = 0; // initial time
    double g = 9.81; // acceleration due to gravity
    double m = 0.1; // mass of the ball
    double k = 0.1; // air resistance coefficient
    double v = 10; // initial velocity
    double x = 0; // initial position
    double a, f, dx, dv;

    printf("Time(s)\tPosition(m)\tVelocity(m/s)\n");

    while (x >= 0) // while the ball is still in the air
    {
        // calculate forces
        f = m * g - k * v * v;
        a = f / m;

        // update position and velocity
        dx = v * h;
        dv = a * h;
        x += dx;
        v += dv;

        // print results
        printf("%.2f\t%.2f\t\t%.2f\n", t, x, v);

        // increment time
        t += h;
    }

    return 0;
}