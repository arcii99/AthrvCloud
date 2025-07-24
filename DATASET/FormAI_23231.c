//FormAI DATASET v1.0 Category: Physics simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * This program simulates the motion of a pendulum, an example of simple harmonic motion.
 * The motion of the pendulum can be described by the differential equation:
 * d^2θ/dt^2 = -g/L * sin(θ)
 * where θ is the angle of displacement of the pendulum from the vertical, t is time,
 * g is the acceleration due to gravity, and L is the length of the pendulum.
 * 
 * We use the Euler-Cromer method to numerically solve the differential equation.
 */

#define PI 3.14159265358979323846
#define G 9.81 // acceleration due to gravity in m/s^2

int main() {
    double L = 1.0; // length of the pendulum in meters
    double theta = PI / 4; // initial displacement of the pendulum in radians
    double omega = 0.0; // initial angular velocity in radians per second
    double dt = 0.01; // time step size in seconds
    double t = 0.0; // initial time in seconds
    double period = 2 * PI * sqrt(L / G); // theoretical period of the pendulum
    bool isForwardSwing = true; // flag to track direction of pendulum swing

    // Print simulation parameters
    printf("Simulation parameters:\n");
    printf("Length of pendulum L = %.2f m\n", L);
    printf("Initial angle theta = %.2f degrees\n", theta * 180 / PI);
    printf("Initial angular velocity omega = %.2f rad/s\n", omega);
    printf("Time step size dt = %.2f s\n", dt);
    printf("Theoretical period T = %.2f s\n\n", period);

    // Write data to file
    FILE *fp;
    fp = fopen("pendulum_data.txt", "w");
    fprintf(fp, "t,theta,omega\n");

    // Perform simulation
    while (t < 5 * period) {
        // Calculate acceleration due to gravity and centripetal force
        double acceleration = -G / L * sin(theta);

        // Update angular velocity using Euler-Cromer method
        omega += acceleration * dt;
        theta += omega * dt;

        // Check if pendulum has swung past vertical
        if (isForwardSwing && theta < 0) {
            isForwardSwing = false;
            period = t * 2; // calculate period
        } else if (!isForwardSwing && theta > 0) {
            isForwardSwing = true;
        }

        // Write data to file
        fprintf(fp, "%.2f,%.4f,%.4f\n", t, theta, omega);

        t += dt; // increment time
    }

    // Close file
    fclose(fp);

    printf("Simulation complete! Data written to pendulum_data.txt.\n");

    return 0;
}