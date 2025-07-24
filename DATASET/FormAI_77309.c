//FormAI DATASET v1.0 Category: Physics simulation ; Style: Donald Knuth
#include <stdio.h>
#include <math.h>

int main() {
    double t = 0.0;     // time in seconds
    double dt = 0.01;   // time step in seconds
    double m = 1.0;     // mass in kilograms
    double k = 1.0;     // spring constant in newtons per meter
    double x = 0.1;     // initial displacement in meters
    double v = 0.0;     // initial velocity in meters per second
    double a = 0.0;     // initial acceleration in meters per second squared
    double F = 0.0;     // force in newtons

    printf("Time (s)\tDisplacement (m)\tVelocity (m/s)\tAcceleration (m/s^2)\tForce (N)\n");

    for(int i = 0; i < 1000; i++) {
        // Calculate force using Hooke's Law
        F = -k * x;

        // Calculate acceleration using Newton's second law of motion
        a = F / m;

        // Update velocity using the Euler method
        v += a * dt;

        // Update displacement using the Euler method
        x += v * dt;

        // Output the values
        printf("%f\t%f\t%f\t%f\t%f\n", t, x, v, a, F);

        // Increment time
        t += dt;
    }

    return 0;
}