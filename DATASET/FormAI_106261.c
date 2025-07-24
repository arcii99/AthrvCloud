//FormAI DATASET v1.0 Category: Physics simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    printf("Welcome to the physics simulation program\n");

    // user input for initial values
    double x0, y0, v0, theta, t;
    printf("Enter the initial x-position (in meters): ");
    scanf("%lf", &x0);
    printf("Enter the initial y-position (in meters): ");
    scanf("%lf", &y0);
    printf("Enter the initial velocity (in meters per second): ");
    scanf("%lf", &v0);
    printf("Enter the angle of trajectory (in degrees): ");
    scanf("%lf", &theta);
    printf("Enter the time interval (in seconds): ");
    scanf("%lf", &t);

    // convert angle to radians
    double rad = theta * M_PI / 180.0;

    // calculate initial velocity components
    double vx0 = v0 * cos(rad);
    double vy0 = v0 * sin(rad);

    // set acceleration due to gravity
    double g = 9.81;

    // calculate final position after time interval
    double x_final = x0 + vx0 * t;
    double y_final = y0 + vy0 * t - 0.5 * g * pow(t, 2);

    // print final position
    printf("Final position after %.2f seconds is (%.2f, %.2f) meters\n", t, x_final, y_final);

    // loop through time steps and print trajectory
    printf("\nTrajectory of the projectile:\n");
    printf("time (s)\tx-position (m)\ty-position (m)\n");
    for(double i = 0; i <= t; i += 0.1) {
        double x = x0 + vx0 * i;
        double y = y0 + vy0 * i - 0.5 * g * pow(i, 2);
        printf("%.2f\t\t%.2f\t\t%.2f\n", i, x, y);
    }

    return 0;
}