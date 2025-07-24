//FormAI DATASET v1.0 Category: Physics simulation ; Style: intelligent
#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793238

int main() {
    double l, g, theta0, theta, omega, t, dt, tmax;

    // Prompt user for input parameters
    printf("Enter the length of the pendulum (in meters): ");
    scanf("%lf", &l);
    printf("Enter the local acceleration due to gravity (in m/s^2): ");
    scanf("%lf", &g);
    printf("Enter the initial angle (in degrees): ");
    scanf("%lf", &theta0);
    printf("Enter the total simulation time (in seconds): ");
    scanf("%lf", &tmax);
    printf("Enter the time step (in seconds): ");
    scanf("%lf", &dt);

    // Convert angle to radians
    theta = theta0 * PI / 180;

    // Calculate initial angular velocity and time
    omega = 0;
    t = 0;

    // Print column headers for output data
    printf("Time (s)\tAngle (deg)\tAngular Velocity (rad/s)\n");

    // Loop over time steps and calculate the motion of the pendulum
    while (t <= tmax) {
        printf("%.2lf\t\t%.2lf\t\t%.2lf\n", t, theta * 180 / PI, omega);

        // Calculate new angular velocity and angle
        omega += (-g / l) * sin(theta) * dt;
        theta += omega * dt;

        // Update time
        t += dt;
    }

    return 0;
}