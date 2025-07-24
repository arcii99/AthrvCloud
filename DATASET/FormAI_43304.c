//FormAI DATASET v1.0 Category: Physics simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    double v, theta, g, t, x, y;
    printf("Enter the velocity (m/s): ");
    scanf("%lf", &v);
    printf("Enter the angle of projection (degrees): ");
    scanf("%lf", &theta);
    printf("Enter the gravitational acceleration (m/s^2): ");
    scanf("%lf", &g);
    printf("Enter the time interval (s): ");
    scanf("%lf", &t);

    // Convert angle from degrees to radians
    theta = theta * PI / 180;

    // Calculate the initial horizontal and vertical velocities
    double vx = v * cos(theta);
    double vy = v * sin(theta);

    // Set initial position to (0, 0)
    x = 0;
    y = 0;

    // Print the initial position
    printf("t = 0 s:\t(%lf, %lf)\n", x, y);

    // Perform simulation for specified time interval
    for(double i = t; i <= 10; i += t) {
        // Calculate the new position and velocity
        x = vx * i;
        y = vy * i - 0.5 * g * i * i;

        // Print the position at current time
        printf("t = %.2lf s:\t(%lf, %lf)\n", i, x, y);
    }

    return 0;
}