//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11    // gravitational constant
#define MAX_BODIES 10     // maximum amount of bodies in system
#define STEPS 50000       // total steps to simulate
#define DELTA_T 100       // time step in seconds
#define WRITE_STEPS 100   // write output every N steps
#define MULTIPLIER 100000

struct body {
    double position[3];
    double velocity[3];
    double acceleration[3];
    double mass;
};

int main() {
    struct body bodies[MAX_BODIES] = {0};
    int num_bodies = 0;

    // add sun
    bodies[num_bodies].position[0] = 0;
    bodies[num_bodies].position[1] = 0;
    bodies[num_bodies].position[2] = 0;
    bodies[num_bodies].velocity[0] = 0;
    bodies[num_bodies].velocity[1] = 0;
    bodies[num_bodies].velocity[2] = 0;
    bodies[num_bodies].mass = 1.989e30;  // mass of sun
    num_bodies++;

    // add earth
    bodies[num_bodies].position[0] = -147095000000;
    bodies[num_bodies].position[1] = 0;
    bodies[num_bodies].position[2] = 0;
    bodies[num_bodies].velocity[0] = 0;
    bodies[num_bodies].velocity[1] = sqrt(G * bodies[0].mass / abs(bodies[num_bodies].position[0]));
    bodies[num_bodies].velocity[2] = 0;
    bodies[num_bodies].mass = 5.972e24;  // mass of earth
    num_bodies++;

    // add moon
    bodies[num_bodies].position[0] = -147095000000 + 384400000;
    bodies[num_bodies].position[1] = 0;
    bodies[num_bodies].position[2] = 0;
    bodies[num_bodies].velocity[0] = 0;
    bodies[num_bodies].velocity[1] = sqrt(G * bodies[1].mass / abs(bodies[num_bodies].position[0] - bodies[1].position[0]));
    bodies[num_bodies].velocity[2] = 0;
    bodies[num_bodies].mass = 7.342e22;  // mass of moon
    num_bodies++;

    printf("Number of bodies: %d\n", num_bodies);

    // simulate motion of bodies
    for (int step = 1; step <= STEPS; step++) {
        // reset accelerations to 0
        for (int i = 0; i < num_bodies; i++) {
            for (int j = 0; j < 3; j++) {
                bodies[i].acceleration[j] = 0;
            }
        }

        // calculate accelerations
        for (int i = 0; i < num_bodies; i++) {
            for (int j = 0; j < num_bodies; j++) {
                if (i == j) {
                    continue;
                }
                double dx = bodies[j].position[0] - bodies[i].position[0];
                double dy = bodies[j].position[1] - bodies[i].position[1];
                double dz = bodies[j].position[2] - bodies[i].position[2];
                double r = sqrt(dx*dx + dy*dy + dz*dz);
                double f = G * bodies[j].mass / (r*r);
                bodies[i].acceleration[0] += f * dx / r;
                bodies[i].acceleration[1] += f * dy / r;
                bodies[i].acceleration[2] += f * dz / r;
            }
        }

        // update velocities and positions based on accelerations
        for (int i = 0; i < num_bodies; i++) {
            for (int j = 0; j < 3; j++) {
                bodies[i].velocity[j] += bodies[i].acceleration[j] * DELTA_T;
                bodies[i].position[j] += bodies[i].velocity[j] * DELTA_T;
            }
        }

        // write output every WRITE_STEPS steps
        if (step % WRITE_STEPS == 0) {
            printf("Step %d:\n", step);
            for (int i = 0; i < num_bodies; i++) {
                printf("Body %d position: %.0f %.0f %.0f\n", i, bodies[i].position[0]/MULTIPLIER, bodies[i].position[1]/MULTIPLIER, bodies[i].position[2]/MULTIPLIER);
            }
            printf("\n");
        }
    }

    return 0;
}