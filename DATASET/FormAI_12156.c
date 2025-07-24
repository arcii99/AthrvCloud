//FormAI DATASET v1.0 Category: Physics simulation ; Style: energetic
#include <stdio.h>
#include <math.h>

// Define constants
#define GRAVITY 9.81
#define TIME_INTERVAL 0.1

// Define structure to represent a point in the simulation
typedef struct {
    double x;
    double y;
} Point;

// Define structure to represent a particle in the simulation
typedef struct {
    Point position;
    Point velocity;
    double mass;
} Particle;

int main() {
    // Create a particle near the top of a hill
    Particle p = {
        .position = {.x = 0.0, .y = 100.0},
        .velocity = {.x = 10.0, .y = 0.0},
        .mass = 1.0
    };

    // Simulate the particle's motion over 10 seconds
    for (double t = 0.0; t <= 10.0; t += TIME_INTERVAL) {
        // Calculate the forces acting on the particle
        double net_force_y = -p.mass * GRAVITY;
        double net_force_x = 0.0;

        // Update the particle's velocity based on the forces acting on it
        p.velocity.y += (net_force_y * TIME_INTERVAL) / p.mass;
        p.velocity.x += (net_force_x * TIME_INTERVAL) / p.mass;

        // Update the particle's position based on its velocity
        p.position.y += p.velocity.y * TIME_INTERVAL;
        p.position.x += p.velocity.x * TIME_INTERVAL;

        // Print the particle's position and velocity
        printf("Time: %f seconds, Position: (%f, %f), Velocity: (%f, %f)\n", t, p.position.x, p.position.y, p.velocity.x, p.velocity.y);
    }

    return 0;
}