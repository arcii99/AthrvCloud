//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11   // Gravitational constant
#define AU 149597870700 // Astronomical unit

typedef struct {
    double x, y;
} vector2d;

typedef struct {
    vector2d pos, vel, acc;
    double mass;
} body;

body sun = { {0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}, 1.9885e30 };
body earth = { {AU, 0.0}, {0.0, 29783.0}, {0.0, 0.0}, 5.975e24 };

int main() {
    double dt = 3600.0;
    int steps = 100000;

    int i;
    for (i = 0; i < steps; i++) {
        vector2d dist = { earth.pos.x - sun.pos.x, earth.pos.y - sun.pos.y };
        double r = sqrt(dist.x * dist.x + dist.y * dist.y);
        double f = G * sun.mass * earth.mass / (r * r);
        double fx = f * dist.x / r;
        double fy = f * dist.y / r;
        earth.acc.x = -fx / earth.mass;
        earth.acc.y = -fy / earth.mass;
        earth.vel.x += earth.acc.x * dt;
        earth.vel.y += earth.acc.y * dt;
        earth.pos.x += earth.vel.x * dt;
        earth.pos.y += earth.vel.y * dt;
        printf("Step %d: Earth Pos (%.6f, %.6f)\n", i+1, earth.pos.x, earth.pos.y);
    }

    return 0;
}