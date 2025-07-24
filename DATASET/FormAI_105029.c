//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: systematic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

const int G = 6.67428e-11; // Gravitational constant

struct planet {
    double m; // Mass
    double x; // Position (x, y)
    double y;
    double vx; // Velocity (x, y)
    double vy;
};

int main() {
    // Set up the planets
    struct planet sun = {1.9885e30, 0, 0, 0, 0}; // Sun
    struct planet earth = {5.972e24, 1.496e11, 0, 0, 2.9783e4}; // Earth
    struct planet moon = {7.35e22, 1.496e11 + 3.844e8, 0, 0, 2.9783e4 + 1.022e3}; // Moon

    double t = 0;
    double dt = 3600 * 24; // 1 day in seconds

    // Simulation loop
    while (1) {
        // Calculate distance and force between Earth and Sun
        double dx = earth.x - sun.x;
        double dy = earth.y - sun.y;
        double d = sqrt(dx*dx + dy*dy);
        double F = G * earth.m * sun.m / (d*d);

        // Calculate acceleration and velocity of Earth
        double ax = -F / earth.m * dx / d;
        double ay = -F / earth.m * dy / d;
        earth.vx += ax * dt;
        earth.vy += ay * dt;
        earth.x += earth.vx * dt;
        earth.y += earth.vy * dt;

        // Calculate distance and force between Moon and Earth
        dx = moon.x - earth.x;
        dy = moon.y - earth.y;
        d = sqrt(dx*dx + dy*dy);
        F = G * moon.m * earth.m / (d*d);

        // Calculate acceleration and velocity of Moon
        double axm = -F / moon.m * dx / d;
        double aym = -F / moon.m * dy / d;
        moon.vx += axm * dt;
        moon.vy += aym * dt;
        moon.x += moon.vx * dt;
        moon.y += moon.vy * dt;

        // Print out the positions of the planets
        printf("t = %f, Earth (%f, %f), Moon (%f, %f)\n", t, earth.x, earth.y, moon.x, moon.y);

        t += dt;
    }

    return 0;
}