//FormAI DATASET v1.0 Category: Physics simulation ; Style: calm
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// We'll use some constants to define the properties of the pendulum
const double g = 9.81; // acceleration due to gravity
const double L = 1.0; // length of the pendulum
const double theta0 = 0.2; // initial angle of the pendulum
const double omega0 = 0.0; // initial angular velocity of the pendulum

int main()
{
    // Set up the initial conditions of the pendulum
    double theta = theta0;
    double omega = omega0;

    // Choose a time step for the simulation
    double dt = 0.01;

    // Iterate over time to simulate the motion of the pendulum
    for (double t = 0.0; t < 10.0; t += dt)
    {
        // Compute the acceleration of the pendulum
        double alpha = -g / L * sin(theta);

        // Update the velocity and position of the pendulum using the Euler method
        omega += alpha * dt;
        theta += omega * dt;

        // Print out the current state of the pendulum
        printf("Time: %f, Angle: %f deg, Velocity: %f m/s\n", t, theta * 180.0 / PI, omega * L);
    }

    return 0;
}