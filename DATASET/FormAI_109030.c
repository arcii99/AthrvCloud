//FormAI DATASET v1.0 Category: Physics simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x = 0.0, y = 0.0, vx = 0.0, vy = 0.0, ax = 0.0, ay = 0.0, dt = 0.01;
    double m = 2.0, g = 9.8, k = 0.05, r = 0.2, rho = 1.0, A = M_PI * r * r;
    int t = 0;

    printf("Medieval Physics Simulation\n\n");

    while (t < 10)
    {
        double v = sqrt(vx * vx + vy * vy);
        double drag = 0.5 * rho * A * k * v * v;
        ax = -drag * vx / (m * v);
        ay = -drag * vy / (m * v) - g;
        
        x += vx * dt + 0.5 * ax * dt * dt;
        y += vy * dt + 0.5 * ay * dt * dt;
        vx += ax * dt;
        vy += ay * dt;

        printf("Time: %.2f s, Position: (%.2f, %.2f) m, Velocity: (%.2f, %.2f) m/s, Acceleration: (%.2f, %.2f) m/s2\n", t * dt, x, y, vx, vy, ax, ay);

        t++;
    }

    printf("\nSimulation ended.\n");

    return 0;
}