//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: scientific
#include <stdio.h>
#include <math.h>

#define G 6.6743e-11  // gravitational constant

typedef struct {
    double x;
    double y;
    double z;
} vector;

typedef struct {
    vector pos;
    vector vel;
    double mass;
} planet;

int main() {
    int num_planets = 3;  // number of planets in simulation
    double delta_t = 3600.0;  // simulation time step in seconds

    // initialize planets
    planet planets[num_planets];
    planets[0].pos.x = 0.0;
    planets[0].pos.y = 0.0;
    planets[0].pos.z = 0.0;
    planets[0].vel.x = 0.0;
    planets[0].vel.y = 0.0;
    planets[0].vel.z = 0.0;
    planets[0].mass = 5.97e24;  // mass of Earth

    planets[1].pos.x = 1.496e11;
    planets[1].pos.y = 0.0;
    planets[1].pos.z = 0.0;
    planets[1].vel.x = 0.0;
    planets[1].vel.y = 29829.0;
    planets[1].vel.z = 0.0;
    planets[1].mass = 1.99e30;  // mass of Sun

    planets[2].pos.x = 2.279e11;
    planets[2].pos.y = 0.0;
    planets[2].pos.z = 0.0;
    planets[2].vel.x = 0.0;
    planets[2].vel.y = 24077.0;
    planets[2].vel.z = 0.0;
    planets[2].mass = 6.39e23;  // mass of Mars

    int i, j, k;
    double force_mag, dist, dist_cubed, accel;
    vector force;
    vector accel_vecs[num_planets];

    // main simulation loop
    for (i = 0; i < 1000; i++) {
        // calculate net acceleration of each planet
        for (j = 0; j < num_planets; j++) {
            accel_vecs[j].x = 0.0;
            accel_vecs[j].y = 0.0;
            accel_vecs[j].z = 0.0;

            for (k = 0; k < num_planets; k++) {
                if (j == k) {
                    continue;
                }

                // calculate force between two planets
                dist = sqrt(pow(planets[k].pos.x - planets[j].pos.x, 2) +
                            pow(planets[k].pos.y - planets[j].pos.y, 2) +
                            pow(planets[k].pos.z - planets[j].pos.z, 2));
                dist_cubed = pow(dist, 3);
                force_mag = G * planets[j].mass * planets[k].mass / dist_cubed;

                force.x = force_mag * (planets[k].pos.x - planets[j].pos.x);
                force.y = force_mag * (planets[k].pos.y - planets[j].pos.y);
                force.z = force_mag * (planets[k].pos.z - planets[j].pos.z);

                accel_vecs[j].x += force.x / planets[j].mass;
                accel_vecs[j].y += force.y / planets[j].mass;
                accel_vecs[j].z += force.z / planets[j].mass;
            }
        }

        // update positions and velocities of planets
        for (j = 0; j < num_planets; j++) {
            planets[j].pos.x += planets[j].vel.x * delta_t;
            planets[j].pos.y += planets[j].vel.y * delta_t;
            planets[j].pos.z += planets[j].vel.z * delta_t;

            planets[j].vel.x += accel_vecs[j].x * delta_t;
            planets[j].vel.y += accel_vecs[j].y * delta_t;
            planets[j].vel.z += accel_vecs[j].z * delta_t;
        }

        // print positions of Earth and Mars every 1000 seconds
        if (i % 1000 == 0) {
            printf("Position of Earth after %d seconds: (%g, %g, %g)\n", i,
                   planets[0].pos.x, planets[0].pos.y, planets[0].pos.z);
            printf("Position of Mars after %d seconds: (%g, %g, %g)\n", i,
                   planets[2].pos.x, planets[2].pos.y, planets[2].pos.z);
        }
    }

    return 0;
}