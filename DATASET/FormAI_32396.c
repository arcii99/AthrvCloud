//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double G = 6.67430e-11;

/*
 * Structure representing a planet
 */
struct Planet {
    double mass;
    double x, y, z;
    double vx, vy, vz;
    double fx, fy, fz;
};

/*
 * Calculate the gravitational force between two planets
 */
void calculate_gravity(struct Planet *p1, struct Planet *p2) {
    double dx = p1->x - p2->x;
    double dy = p1->y - p2->y;
    double dz = p1->z - p2->z;
    double dist = sqrt(dx*dx + dy*dy + dz*dz);
    double F = G * p1->mass * p2->mass / (dist*dist*dist);
    p1->fx -= F * dx;
    p1->fy -= F * dy;
    p1->fz -= F * dz;
    p2->fx += F * dx;
    p2->fy += F * dy;
    p2->fz += F * dz;
}

/*
 * Update the position and velocity of a planet
 */
void update(struct Planet *p, double dt) {
    p->vx += p->fx / p->mass * dt;
    p->vy += p->fy / p->mass * dt;
    p->vz += p->fz / p->mass * dt;
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
    p->fx = 0;
    p->fy = 0;
    p->fz = 0;
}

/*
 * Simulate the gravity between planets over time
 */
void simulate(struct Planet *planets, int num_planets, double dt, int steps) {
    for (int s = 0; s < steps; s++) {
        for (int i = 0; i < num_planets; i++) {
            for (int j = i + 1; j < num_planets; j++) {
                calculate_gravity(&planets[i], &planets[j]);
            }
        }
        for (int i = 0; i < num_planets; i++) {
            update(&planets[i], dt);
        }
    }
}

int main() {
    // Initialize the planets
    struct Planet planets[] = {
        {5.97e24, 0, 0, 0, 0, 0, 0, 0, 0, 0},   // Earth
        {7.34e22, 385000000, 0, 0, 0, 1022, 0, 0, 0, 0}   // Moon
    };
    int num_planets = 2;

    // Simulate the gravity between the planets for one hour
    double dt = 60;   // seconds
    int steps_per_hour = 3600 / dt;
    int steps = 24 * steps_per_hour;
    simulate(planets, num_planets, dt, steps);

    // Print the final positions of the planets
    for (int i = 0; i < num_planets; i++) {
        printf("Planet %d: (%.0f, %.0f, %.0f)\n", i+1, planets[i].x, planets[i].y, planets[i].z);
    }

    return 0;
}