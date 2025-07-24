//FormAI DATASET v1.0 Category: Physics simulation ; Style: calm
#include <stdio.h>
#include <math.h>

#define GRAVITY 9.81 // m/s^2, acceleration due to gravity
#define DT 0.01 // s, time step

int main() {
    double v0, theta, x0, y0; // initial velocity, angle, and position
    printf("Enter the initial velocity in m/s: ");
    scanf("%lf", &v0);
    printf("Enter the angle in degrees: ");
    scanf("%lf", &theta);
    printf("Enter the initial x position in m: ");
    scanf("%lf", &x0);
    printf("Enter the initial y position in m: ");
    scanf("%lf", &y0);

    // convert angle from degrees to radians
    theta = theta * M_PI / 180;

    double vx0 = v0 * cos(theta); // initial x velocity
    double vy0 = v0 * sin(theta); // initial y velocity
    double t = 0; // s, time
    double x = x0; // m, x position
    double y = y0; // m, y position
    double vx = vx0; // m/s, x velocity
    double vy = vy0; // m/s, y velocity

    while (y >= 0) { // projectile is above ground
        // update velocity and position
        double ax = 0; // m/s^2, x acceleration (no horizontal forces)
        double ay = -GRAVITY; // m/s^2, y acceleration due to gravity
        vx += ax * DT;
        vy += ay * DT;
        x += vx * DT;
        y += vy * DT;

        // print current position and time
        printf("Time: %.2lf s, Position: (%.2lf, %.2lf)\n", t, x, y);

        t += DT; // move time forward by time step
    }

    // print final time and distance traveled
    printf("Total time: %.2lf s\n", t);
    printf("Total distance traveled: %.2lf m\n", x - x0);

    return 0;
}