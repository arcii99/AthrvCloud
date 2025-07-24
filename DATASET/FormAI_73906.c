//FormAI DATASET v1.0 Category: Physics simulation ; Style: Donald Knuth
// This program simulates the motion of two planets in space using basic laws of physics.
// It was inspired by Donald Knuth's principles of simplicity and elegance in programming.

#include <stdio.h>
#include <math.h>

#define G 6.674e-11 // gravitational constant

// planet structure
typedef struct {
    double mass; // in kg
    double x, y; // position in m
    double vx, vy; // velocity in m/s
    double ax, ay; // acceleration in m/s^2
} Planet;

int main() {
    // create two planets
    Planet p1 = {1.0e12, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    Planet p2 = {2.0e12, 1.0e11, 0.0, 0.0, 5000.0, 0.0, 0.0};

    double dt = 1000.0; // time step in seconds
    int num_steps = 100000; // number of time steps
    int i;

    printf("Initial conditions:\n");
    printf("p1: mass = %.2e, position = (%.2e, %.2e), velocity = (%.2e, %.2e)\n", 
        p1.mass, p1.x, p1.y, p1.vx, p1.vy);
    printf("p2: mass = %.2e, position = (%.2e, %.2e), velocity = (%.2e, %.2e)\n", 
        p2.mass, p2.x, p2.y, p2.vx, p2.vy);
    printf("\n");

    for (i = 0; i < num_steps; i++) {
        // calculate distance between planets
        double dx = p2.x - p1.x;
        double dy = p2.y - p1.y;
        double dist = sqrt(dx*dx + dy*dy);

        // calculate gravitational force
        double force = G * p1.mass * p2.mass / (dist*dist);

        // calculate acceleration components
        p1.ax = force / p1.mass * dx / dist;
        p1.ay = force / p1.mass * dy / dist;
        p2.ax = -force / p2.mass * dx / dist;
        p2.ay = -force / p2.mass * dy / dist;

        // update velocities
        p1.vx += p1.ax * dt;
        p1.vy += p1.ay * dt;
        p2.vx += p2.ax * dt;
        p2.vy += p2.ay * dt;

        // update positions
        p1.x += p1.vx * dt;
        p1.y += p1.vy * dt;
        p2.x += p2.vx * dt;
        p2.y += p2.vy * dt;
    }

    printf("Final conditions:\n");
    printf("p1: mass = %.2e, position = (%.2e, %.2e), velocity = (%.2e, %.2e)\n", 
        p1.mass, p1.x, p1.y, p1.vx, p1.vy);
    printf("p2: mass = %.2e, position = (%.2e, %.2e), velocity = (%.2e, %.2e)\n", 
        p2.mass, p2.x, p2.y, p2.vx, p2.vy);
    printf("\n");

    return 0;
}