//FormAI DATASET v1.0 Category: Physics simulation ; Style: grateful
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
    double angle, v, vx, vy, t, dt, x, y;

    printf("Enter angle in degrees: ");
    scanf("%lf", &angle);

    printf("Enter initial velocity: ");
    scanf("%lf", &v);

    angle = angle * PI / 180; // Convert angle to radians

    vx = v * cos(angle); // Calculate initial x velocity
    vy = v * sin(angle); // Calculate initial y velocity

    x = y = 0; // Initialize position

    dt = 0.01; // Time step

    // Simulate motion
    while (y >= 0)
    {
        t += dt; // Increment time

        // Calculate new position and velocities
        x = vx * t;
        y = vy * t - 0.5 * 9.81 * t * t;
        vy = vy - 9.81 * dt;

        printf("t=%.2f x=%.2f y=%.2f\n", t, x, y); // Output position
    }

    printf("Time of flight: %.2f s\n", t); // Output time of flight

    return 0;
}