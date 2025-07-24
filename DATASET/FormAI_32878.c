//FormAI DATASET v1.0 Category: Physics simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

int main()
{
    // Input parameters
    float s, a, g = 9.8;
    printf("Enter initial speed (m/s): ");
    scanf("%f", &s);
    printf("Enter angle of projection (degrees): ");
    scanf("%f", &a);

    // Convert angle to radians
    float ar = a * PI / 180;

    // Compute horizontal and vertical components of initial velocity
    float vh = s * cos(ar);
    float vv = s * sin(ar);

    // Simulation parameters
    float dt = 0.1;
    float x = 0, y = 0;
    float vx = vh, vy = vv;

    // Simulation loop
    while (y >= 0)
    {
        // Update x and y positions
        x += vx * dt;
        y += vy * dt;

        // Update velocities
        vx = vh;
        vy = vv - g * dt;

        // Print current position and velocity
        printf("X: %f\tY: %f\tVX: %f\tVY: %f\n", x, y, vx, vy);
    }

    return 0;
}