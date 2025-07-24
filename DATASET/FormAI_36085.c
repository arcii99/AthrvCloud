//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67e-11  // gravitational constant
#define TIMESTEP 0.0001 // time step for simulation
#define MAX_TIME 100 // maximum simulation time
#define NUM_PLANETS 3 // number of planets in simulation

typedef struct {
    double x, y, z; // position
    double vx, vy, vz; // velocity
    double mass; // mass
} Planet;

double calc_distance(Planet *p1, Planet *p2) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;

    return sqrt(dx*dx + dy*dy + dz*dz);
}

void update_positions(Planet *planets) {
    int i, j;

    for (i = 0; i < NUM_PLANETS; i++) {
        planets[i].x += planets[i].vx * TIMESTEP;
        planets[i].y += planets[i].vy * TIMESTEP;
        planets[i].z += planets[i].vz * TIMESTEP;
    }
}

void update_velocities(Planet *planets) {
    int i, j;

    for (i = 0; i < NUM_PLANETS; i++) {
        double ax = 0;
        double ay = 0;
        double az = 0;

        for (j = 0; j < NUM_PLANETS; j++) {
            if (i != j) {
                double dist = calc_distance(&planets[i], &planets[j]);
                double F = G * planets[i].mass * planets[j].mass / (dist*dist);

                ax += F * (planets[j].x - planets[i].x) / dist;
                ay += F * (planets[j].y - planets[i].y) / dist;
                az += F * (planets[j].z - planets[i].z) / dist;
            }
        }

        planets[i].vx += ax * TIMESTEP;
        planets[i].vy += ay * TIMESTEP;
        planets[i].vz += az * TIMESTEP;
    }
}

int main() {
    Planet planets[NUM_PLANETS] = {
        {0, 0, 0, 0, 0, 0, 1e5}, // planet 1
        {10, 0, 0, 0, 500, 0, 1e5}, // planet 2
        {0, 10, 0, -500, 0, 0, 1e5} // planet 3
    };

    double time = 0;

    while (time < MAX_TIME) {
        update_positions(planets);
        update_velocities(planets);

        printf("Time: %f\n", time);
        for (int i = 0; i < NUM_PLANETS; i++) {
            printf("Planet %d: position (%f, %f, %f) velocity (%f, %f, %f)\n", i+1, planets[i].x, planets[i].y, planets[i].z, planets[i].vx, planets[i].vy, planets[i].vz);
        }

        time += TIMESTEP;
    }

    return 0;
}