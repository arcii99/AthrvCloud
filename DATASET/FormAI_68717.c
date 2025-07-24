//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: realistic
#include <stdio.h>
#include <math.h>

#define G 6.6742e-11 // Gravitational constant

typedef struct {
    double x, y; // Coordinates
    double vx, vy; // Velocities
    double mass; // Mass
} Body;

Body sun = {0, 0, 0, 0, 1.989e30}; // The sun
Body earth = {1.496e11, 0, 0, 29783, 5.972e24}; // The earth
Body moon = {1.496e11 + 384400000, 0, 0, 3074, 7.342e22}; // The moon

int main() {
    double dt = 1; // Time step
    double t = 0; // Current time
    double x, y, r, fx, fy, ax, ay;
    int steps = 365 * 24 * 60 * 60 / dt; // Number of simulation steps per year

    for (int i = 0; i < steps; i++) {
        // Compute the distance between the earth and the sun
        x = earth.x - sun.x;
        y = earth.y - sun.y;
        r = sqrt(x * x + y * y);

        // Compute the gravitational force between the earth and the sun
        fx = -G * sun.mass * earth.mass / (r * r) * x / r;
        fy = -G * sun.mass * earth.mass / (r * r) * y / r;

        // Update the earth's acceleration
        ax = fx / earth.mass;
        ay = fy / earth.mass;

        // Update the earth's velocity and position
        earth.vx += ax * dt;
        earth.vy += ay * dt;
        earth.x += earth.vx * dt;
        earth.y += earth.vy * dt;

        // Compute the distance between the moon and the earth
        x = moon.x - earth.x;
        y = moon.y - earth.y;
        r = sqrt(x * x + y * y);

        // Compute the gravitational force between the moon and the earth
        fx = -G * moon.mass * earth.mass / (r * r) * x / r;
        fy = -G * moon.mass * earth.mass / (r * r) * y / r;

        // Update the moon's acceleration
        ax = fx / moon.mass;
        ay = fy / moon.mass;

        // Update the moon's velocity and position
        moon.vx += ax * dt;
        moon.vy += ay * dt;
        moon.x += moon.vx * dt;
        moon.y += moon.vy * dt;

        t += dt;
    }

    printf("After one year:\n");
    printf("The earth is at (%.2f, %.2f) with velocity (%.2f, %.2f)\n", earth.x, earth.y, earth.vx, earth.vy);
    printf("The moon is at (%.2f, %.2f) with velocity (%.2f, %.2f)\n", moon.x, moon.y, moon.vx, moon.vy);

    return 0;
}