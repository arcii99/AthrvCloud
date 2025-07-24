//FormAI DATASET v1.0 Category: Physics simulation ; Style: intelligent
#include <stdio.h>
#include <math.h>

int main() {
    double v0 = 5; // initial velocity in meters per second
    double angle = 45; // initial angle in degrees
    double g = 9.81; // gravitational acceleration
    double x, y, t;
    double rad = angle * M_PI / 180; // convert angle to radians

    printf("Projectile Motion Simulation\n\n");
    printf("Initial Velocity: %.2f m/s\n", v0);
    printf("Angle of Projection: %.2f degrees\n", angle);
    printf("Gravitational Acceleration: %.2f m/s^2\n\n", g);

    t = 0;
    x = 0;
    y = 0;

    while (y >= 0) {
        x = v0 * cos(rad) * t;
        y = v0 * sin(rad) * t - 0.5 * g * pow(t, 2);
        printf("Time: %f sec => x: %f m, y: %f m\n", t, x, y);
        t += 0.1;
    }

    printf("\nProjectile reached ground at time: %f sec\n", t);
    printf("Maximum height reached by the projectile: %f m\n", v0 * sin(rad) * v0 * sin(rad) / (2 * g));

    return 0;
}