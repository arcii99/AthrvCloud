//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743e-11 // gravitational constant

typedef struct {
    double x, y;
} Vector2D;

typedef struct {
    Vector2D pos; // position
    Vector2D vel; // velocity
    Vector2D force; // force
    double mass;
} Body;

int main() {
    // Body data
    Body sun = {.pos = {0, 0}, .vel = {0, 0}, .force = {0, 0}, .mass = 1.9885e30};
    Body earth = {.pos = {147.09e9, 0}, .vel = {0, 30300}, .force = {0, 0}, .mass = 5.9724e24};
    // Variables
    const double dt = 86400; // 1 day
    const int steps = 365 * 10; // simulate 10 years
    double d; // distance
    Vector2D dir; // direction
    int i, j, step;
    // Simulation loop
    for (step = 0; step < steps; step++) {
        // Zero out forces
        sun.force.x = sun.force.y = 0;
        earth.force.x = earth.force.y = 0;
        // Compute forces
        // Sun-Earth
        d = sqrt(pow(earth.pos.x - sun.pos.x, 2) + pow(earth.pos.y - sun.pos.y, 2));
        dir.x = (earth.pos.x - sun.pos.x) / d;
        dir.y = (earth.pos.y - sun.pos.y) / d;
        sun.force.x += G * sun.mass * earth.mass * dir.x / pow(d, 2);
        sun.force.y += G * sun.mass * earth.mass * dir.y / pow(d, 2);
        earth.force.x += -sun.force.x;
        earth.force.y += -sun.force.y;
        // Update velocities
        sun.vel.x += sun.force.x / sun.mass * dt;
        sun.vel.y += sun.force.y / sun.mass * dt;
        earth.vel.x += earth.force.x / earth.mass * dt;
        earth.vel.y += earth.force.y / earth.mass * dt;
        // Update positions
        sun.pos.x += sun.vel.x * dt;
        sun.pos.y += sun.vel.y * dt;
        earth.pos.x += earth.vel.x * dt;
        earth.pos.y += earth.vel.y * dt;
        // Print results
        printf("step: %d\tsun: (%e, %e)\tearth: (%e, %e)\n", step, sun.pos.x, sun.pos.y, earth.pos.x, earth.pos.y);
    }
    return 0;
}