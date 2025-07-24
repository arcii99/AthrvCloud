//FormAI DATASET v1.0 Category: Physics simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants
#define RADIUS 5.0
#define MASS 10.0
#define DRAG 0.01
#define DT 0.01
#define GRAVITY 9.8

int main()
{
    // Initialize variables
    double x = 0.0;
    double y = RADIUS;
    double vx = 10.0;
    double vy = 0.0;
    double ax = 0.0;
    double ay = 0.0;
    double force_x = 0.0;
    double force_y = 0.0;
    double time = 0.0;

    // Loop until the ball hits the ground
    while (y > 0.0)
    {
        // Calculate drag force
        double v_total = sqrt(vx * vx + vy * vy);
        double drag = DRAG * v_total * v_total;
        force_x = -drag * vx / v_total;
        force_y = -drag * vy / v_total;

        // Calculate gravitational force
        double gravity = MASS * GRAVITY;
        force_y -= gravity;

        // Calculate net force
        ax = force_x / MASS;
        ay = force_y / MASS;

        // Update position and velocity
        x += vx * DT;
        y += vy * DT;
        vx += ax * DT;
        vy += ay * DT;

        // Increment time
        time += DT;

        // Output time and position
        printf("Time: %.2lf, x: %.2lf, y: %.2lf\n", time, x, y);
    }

    printf("The ball hit the ground at time %.2lf seconds.\n", time);

    return 0;
}