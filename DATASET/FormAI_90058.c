//FormAI DATASET v1.0 Category: Physics simulation ; Style: detailed
// A physics simulation program to calculate and display trajectories of objects under gravitational force

#include <stdio.h>
#include <math.h>

#define GRAVITY 9.8 // Acceleration due to gravity

int main() {
    double v0, theta, x0, y0, vx0, vy0, t, dt;
    printf("Enter initial velocity (m/s): ");
    scanf("%lf", &v0);
    printf("Enter launch angle (degrees): ");
    scanf("%lf", &theta);
    printf("Enter initial x-position (m): ");
    scanf("%lf", &x0);
    printf("Enter initial y-position (m): ");
    scanf("%lf", &y0);
    printf("Enter time increment (s): ");
    scanf("%lf", &dt);
    
    theta = theta * M_PI / 180.0; // Convert angle from degrees to radians
    vx0 = v0 * cos(theta); // Initial x-velocity
    vy0 = v0 * sin(theta); // Initial y-velocity
    
    double x = x0, y = y0, vx = vx0, vy = vy0;
    while (y >= 0.0) {
        printf("Time: %.2lf s, Height: %.2lf m, Distance: %.2lf m\n", t, y, x);
        t = t + dt;
        x = x0 + vx0 * t; // New x-position
        y = y0 + vy0 * t - 0.5 * GRAVITY * t * t; // New y-position
        vx = vx0; // Constant horizontal velocity
        vy = vy0 - GRAVITY * t; // New vertical velocity
    }
    printf("Total flight time: %.2lf s, Maximum height: %.2lf m, Maximum range: %.2lf m\n", t, y0 + vy0 * vy0 / (2 * GRAVITY), x0 + vx0 * vy0 / GRAVITY);
    return 0;
}