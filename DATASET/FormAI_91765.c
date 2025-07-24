//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: rigorous
#include <stdio.h>
#include <math.h>

#define G 6.6743 * pow(10, -11) // Gravitational constant
#define TIME_STEPS 1000 // Number of time steps to simulate
#define TIME_STEP_SIZE 86400 // Size of a time step in seconds (1 day)
#define NUM_PLANETS 2 // Number of planets in the simulation

typedef struct {
    char name[20]; // Name of the planet
    double mass; // Mass of the planet in kg
    double x; // x coordinate position in m
    double y; // y coordinate position in m
    double z; // z coordinate position in m
    double vx; // x component of velocity in m/s
    double vy; // y component of velocity in m/s
    double vz; // z component of velocity in m/s
} Planet;

void update_velocity(Planet *p, Planet *other, double time_step) {
    double distance = sqrt(pow(p->x - other->x, 2) + pow(p->y - other->y, 2) + pow(p->z - other->z, 2)); // Distance between the planets
    double force = G * p->mass * other->mass / pow(distance, 2); // Gravitational force between the planets
    double acceleration = force / p->mass; // Acceleration of the planet due to the force
    p->vx += (-1 * distance * acceleration * (p->x - other->x)) / distance; // Update x component of velocity
    p->vy += (-1 * distance * acceleration * (p->y - other->y)) / distance; // Update y component of velocity
    p->vz += (-1 * distance * acceleration * (p->z - other->z)) / distance; // Update z component of velocity
}

void update_position(Planet *p, double time_step) {
    p->x += p->vx * time_step; // Update x position
    p->y += p->vy * time_step; // Update y position
    p->z += p->vz * time_step; // Update z position
}

void simulate(double time_step) {
    Planet planets[NUM_PLANETS] = {
        {"Earth", 5.97 * pow(10, 24), 0, 0, 0, 0, 0, 0}, // Earth
        {"Sun", 1.99 * pow(10, 30), 149.6 * pow(10, 9), 0, 0, 0, 29.29 * pow(10, 3), 0} // Sun
    };
    int i, j, t;
    for (t = 0; t < TIME_STEPS; t++) {
        for (i = 0; i < NUM_PLANETS; i++) {
            for (j = 0; j < NUM_PLANETS; j++) {
                if (j != i) {
                    update_velocity(&planets[i], &planets[j], time_step);
                }
            }
        }
        for (i = 0; i < NUM_PLANETS; i++) {
            update_position(&planets[i], time_step);
        }
    }
    for (i = 0; i < NUM_PLANETS; i++) {
        printf("%s position: (%e, %e, %e)\n", planets[i].name, planets[i].x, planets[i].y, planets[i].z);
        printf("%s velocity: (%e, %e, %e)\n", planets[i].name, planets[i].vx, planets[i].vy, planets[i].vz);
    }
}

int main() {
    simulate(TIME_STEP_SIZE);
    return 0;
}