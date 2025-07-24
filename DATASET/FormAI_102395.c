//FormAI DATASET v1.0 Category: Physics simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PARTICLES 100
#define STEPS 100000
#define K 1.380649e-23
#define TEMP 273.15

int main() {
    double positions[PARTICLES][3], velocities[PARTICLES][3], forces[PARTICLES][3], energy_total = 0.0, temperature, dt = 0.0001, mass = 1.0;
    int i, j, step, dim = 3;

    srand(time(NULL));

    // initialize particle positions and velocities
    for (i = 0; i < PARTICLES; i++) {
        for (j = 0; j < dim; j++) {
            positions[i][j] = (double) rand() / (double) RAND_MAX;
            velocities[i][j] = (0.5 - (double) rand() / (double) RAND_MAX) * 0.1;
        }
    }

    // run simulation
    for (step = 0; step < STEPS; step++) {
        energy_total = 0.0;

        // calculate forces for each particle
        for (i = 0; i < PARTICLES; i++) {
            forces[i][0] = forces[i][1] = forces[i][2] = 0.0;

            // calculate inter-particle forces using Lennard-Jones potential
            for (j = 0; j < PARTICLES; j++) {
                if (j != i) {
                    double r[3], distance, force_magnitude;
                    int k;

                    for (k = 0; k < dim; k++) {
                        r[k] = positions[j][k] - positions[i][k];
                    }

                    distance = sqrt(pow(r[0], 2) + pow(r[1], 2) + pow(r[2], 2));
                    force_magnitude = 24.0 * (2.0 * pow(distance, -13) - pow(distance, -7));

                    for (k = 0; k < dim; k++) {
                        forces[i][k] += force_magnitude * r[k] / distance;
                    }
                }
            }
        }

        // update velocities and positions for each particle
        for (i = 0; i < PARTICLES; i++) {
            double v_new[3], x_new[3];
            int k;

            for (k = 0; k < dim; k++) {
                v_new[k] = velocities[i][k] + forces[i][k] * dt / (2.0 * mass);
                x_new[k] = positions[i][k] + v_new[k] * dt;
            }

            // calculate kinetic and potential energy for the particle
            double energy_particle = 0.0;

            for (k = 0; k < dim; k++) {
                energy_particle += pow(velocities[i][k], 2) * 0.5 * mass;
            }

            energy_particle += energy_total;

            // calculate new temperature of the system
            temperature = energy_total * 2.0 / (K * PARTICLES * dim);

            // apply velocity rescaling to control temperature
            double scaling_factor = sqrt(TEMP / temperature);

            for (k = 0; k < dim; k++) {
                velocities[i][k] *= scaling_factor;
                v_new[k] *= scaling_factor;
            }

            // update position and velocity
            for (k = 0; k < dim; k++) {
                positions[i][k] = x_new[k];
                velocities[i][k] = v_new[k];
            }
        }
    }

    printf("Simulation complete! Final temperature: %lf Kelvin\n", temperature);

    return 0;
}