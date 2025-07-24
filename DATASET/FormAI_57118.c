//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Constants for gravitational force
const double G = 6.67408e-11; // gravitational constant
const double M = 5.972e24; // mass of Earth

// Struct for a planet
typedef struct {
    char name[50];
    double mass;
    double x, y; // position
    double vx, vy; // velocity
} Planet;

// Calculates the gravitational force between two planets
void calculate_force(Planet *p1, Planet *p2, double *fx, double *fy) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double distance = sqrt(dx*dx + dy*dy);
    double f = G * p1->mass * p2->mass / (distance * distance);
    *fx = f * dx / distance;
    *fy = f * dy / distance;
}

// Updates the position and velocity of a planet based on the net force acting on it
void update_planet(Planet *p, double fx, double fy, double dt) {
    double ax = fx / p->mass;
    double ay = fy / p->mass;
    p->vx += ax * dt;
    p->vy += ay * dt;
    p->x += p->vx * dt;
    p->y += p->vy * dt;
}

int main() {
    // Initialize planets
    Planet earth = {"Earth", M, 0, 0, 0, 0};
    Planet moon = {"Moon", 7.342e22, 3.844e8, 0, 0, 1023};

    // Simulation parameters
    double dt = 1; // time step (in seconds)
    double duration = 365 * 24 * 60 * 60; // simulation duration (1 year)
    int steps = duration / dt; // number of time steps

    // Simulation loop
    for (int i = 0; i < steps; i++) {
        // Calculate gravitational forces
        double fx, fy;
        calculate_force(&earth, &moon, &fx, &fy);

        // Update planet positions and velocities
        update_planet(&earth, fx, fy, dt);
        update_planet(&moon, -fx, -fy, dt);

        // Output positions
        printf("Step %d: %s (%.2e, %.2e), %s (%.2e, %.2e)\n", i+1, earth.name, earth.x, earth.y, moon.name, moon.x, moon.y);
    }

    return 0;
}