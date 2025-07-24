//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.673e-11 // gravitational constant

typedef struct {
    double x, y, z; // position vector
    double vx, vy, vz; // velocity vector
    double fx, fy, fz; // force vector
    double mass; // mass of the planet
} Planet;

void simulate(Planet *planets, int num_planets, double timestep, int num_steps);

int main() {

    // Define the initial state of the planets

    Planet planets[4] = {
        {1e8, 0, 0, 0, 500, 0, 0, 0, 0, 5.97e24}, // Earth
        {0, 1.5e8, 0, -500, 0, 0, 0, 0, 0, 3.3e23}, // Venus
        {0, 0, -1.5e8, 0, 0, 500, 0, 0, 0, 6.4e23}, // Mars
        {0, -1e8, 0, 500, 0, 0, 0, 0, 0, 1.99e30} // Jupiter
    };

    int num_planets = 4;
    double timestep = 1000;
    int num_steps = 10000;

    // Run the simulation

    simulate(planets, num_planets, timestep, num_steps);

    return 0;
}

void simulate(Planet *planets, int num_planets, double timestep, int num_steps) {
    int i, j, k;

    for (i = 0; i < num_steps; i++) {

        // Reset the forces

        for (j = 0; j < num_planets; j++) {
            planets[j].fx = 0;
            planets[j].fy = 0;
            planets[j].fz = 0;
        }

        // Calculate the forces between all pairs of planets

        for (j = 0; j < num_planets; j++) {
            for (k = j+1; k < num_planets; k++) {

                // Calculate the distance between the two planets

                double r = sqrt(pow(planets[j].x - planets[k].x, 2) +
                                pow(planets[j].y - planets[k].y, 2) +
                                pow(planets[j].z - planets[k].z, 2));

                // Calculate the gravitational force

                double f = G * planets[j].mass * planets[k].mass / pow(r, 2);

                // Calculate the force components

                double fx = f * (planets[k].x - planets[j].x) / r;
                double fy = f * (planets[k].y - planets[j].y) / r;
                double fz = f * (planets[k].z - planets[j].z) / r;

                // Add the forces to the planets

                planets[j].fx += fx;
                planets[j].fy += fy;
                planets[j].fz += fz;

                planets[k].fx -= fx;
                planets[k].fy -= fy;
                planets[k].fz -= fz;
            }
        }

        // Update the positions and velocities of the planets

        for (j = 0; j < num_planets; j++) {
            double ax = planets[j].fx / planets[j].mass;
            double ay = planets[j].fy / planets[j].mass;
            double az = planets[j].fz / planets[j].mass;

            planets[j].vx += ax * timestep;
            planets[j].vy += ay * timestep;
            planets[j].vz += az * timestep;

            planets[j].x += planets[j].vx * timestep;
            planets[j].y += planets[j].vy * timestep;
            planets[j].z += planets[j].vz * timestep;
        }

        // Print out the positions of the planets every 100 steps

        if (i % 100 == 0) {
            printf("Step %d:\n", i);
            for (j = 0; j < num_planets; j++) {
                printf("Planet %d: x=%lf, y=%lf, z=%lf\n", j,
                       planets[j].x, planets[j].y, planets[j].z);
            }
        }
    }
}