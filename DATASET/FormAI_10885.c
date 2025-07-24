//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Physical constants
#define G 6.6743e-11 // Gravitational constant
#define M_SUN 1.989e30 // Mass of the sun

// Structure to hold info about each body
typedef struct {
    double x, y; // Position
    double vx, vy; // Velocity
    double ax, ay; // Acceleration
    double mass; // Mass
} Body;

// Function to calculate distance between two bodies
double distance(Body a, Body b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    // Set up the simulation
    const int n = 9; // Number of bodies
    Body bodies[n]; // Array to hold the bodies

    // Initialize the bodies
    bodies[0] = (Body) {.x = 0, .y = 0, .vx = 0, .vy = 0, .ax = 0, .ay = 0, .mass = M_SUN}; // Sun
    bodies[1] = (Body) {.x = 69.8e9, .y = 0, .vx = 0, .vy = 35*1000, .ax = 0, .ay = 0, .mass = 3.3e23}; // Mercury
    bodies[2] = (Body) {.x = 108.9e9, .y = 0, .vx = 0, .vy = 24.1*1000, .ax = 0, .ay = 0, .mass = 4.9e24}; // Venus
    bodies[3] = (Body) {.x = 152.1e9, .y = 0, .vx = 0, .vy = 29.3*1000, .ax = 0, .ay = 0, .mass = 6e24}; // Earth
    bodies[4] = (Body) {.x = 249.2e9, .y = 0, .vx = 0, .vy = 21.9*1000, .ax = 0, .ay = 0, .mass = 6.6e23}; // Mars
    bodies[5] = (Body) {.x = 816.6e9, .y = 0, .vx = 0, .vy = 12.4*1000, .ax = 0, .ay = 0, .mass = 1.9e27}; // Jupiter
    bodies[6] = (Body) {.x = 1514.5e9, .y = 0, .vx = 0, .vy = 9.6*1000, .ax = 0, .ay = 0, .mass = 5.7e26}; // Saturn
    bodies[7] = (Body) {.x = 3003.6e9, .y = 0, .vx = 0, .vy = 6.8*1000, .ax = 0, .ay = 0, .mass = 8.8e25}; // Uranus
    bodies[8] = (Body) {.x = 4545.7e9, .y = 0, .vx = 0, .vy = 5.4*1000, .ax = 0, .ay = 0, .mass = 1.03e26}; // Neptune

    // Set up parameters for the simulation
    const double dt = 3600; // Time step in seconds
    const double tmax = 31.5e6 * 24 * 3600; // Maximum time in seconds
    double t = 0; // Current time

    // Run the simulation
    while (t < tmax) {
        // Calculate forces on each body
        for (int i = 0; i < n; i++) {
            Body a = bodies[i]; // Body a
            double ax = 0, ay = 0; // Total acceleration on body a
            for (int j = 0; j < n; j++) {
                if (i == j) continue; // Don't calculate force on self
                Body b = bodies[j]; // Body b
                double d = distance(a, b); // Distance between a and b
                double f = G * a.mass * b.mass / (d*d); // Gravitational force between a and b
                ax += f * (b.x - a.x) / d / a.mass; // x component of acceleration on a
                ay += f * (b.y - a.y) / d / a.mass; // y component of acceleration on a
            }
            bodies[i].ax = ax; // Set x component of acceleration on a
            bodies[i].ay = ay; // Set y component of acceleration on a
        }

        // Update positions and velocities of each body
        for (int i = 0; i < n; i++) {
            Body *b = &bodies[i]; // Body i
            b->vx += b->ax * dt; // Update x component of velocity
            b->vy += b->ay * dt; // Update y component of velocity
            b->x += b->vx * dt; // Update x position
            b->y += b->vy * dt; // Update y position
        }

        t += dt; // Increment time
    }

    // Print out the final positions of each body
    printf("Final positions:\n");
    for (int i = 0; i < n; i++) {
        Body b = bodies[i];
        printf("%d: (%g, %g)\n", i, b.x, b.y);
    }

    return 0;
}