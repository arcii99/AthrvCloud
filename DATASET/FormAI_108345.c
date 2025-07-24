//FormAI DATASET v1.0 Category: Physics simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11 // gravitational constant
#define DELTA_T 10 // time step
#define NUM_ITERS 100 // number of iterations to run

typedef struct {
    double x;
    double y;
    double z;
} Vec3;

typedef struct {
    Vec3 position;
    Vec3 velocity;
    double mass;
} Body;

void simulate(Body* bodies, int num_bodies) {
    int i, j, t;
    Vec3 acceleration, pos_diff;
    double distance, force, force_x, force_y, force_z;

    for (t = 0; t < NUM_ITERS; t++) {
        // update positions based on velocities
        for (i = 0; i < num_bodies; i++) {
            bodies[i].position.x += bodies[i].velocity.x * DELTA_T;
            bodies[i].position.y += bodies[i].velocity.y * DELTA_T;
            bodies[i].position.z += bodies[i].velocity.z * DELTA_T;
        }

        // calculate new velocities based on gravitational forces
        for (i = 0; i < num_bodies; i++) {
            acceleration.x = acceleration.y = acceleration.z = 0;

            for (j = 0; j < num_bodies; j++) {
                if (i != j) {
                    pos_diff.x = bodies[j].position.x - bodies[i].position.x;
                    pos_diff.y = bodies[j].position.y - bodies[i].position.y;
                    pos_diff.z = bodies[j].position.z - bodies[i].position.z;

                    distance = sqrt(pos_diff.x * pos_diff.x +
                                    pos_diff.y * pos_diff.y +
                                    pos_diff.z * pos_diff.z);

                    force = G * bodies[i].mass * bodies[j].mass / (distance * distance);

                    force_x = force * pos_diff.x / distance;
                    force_y = force * pos_diff.y / distance;
                    force_z = force * pos_diff.z / distance;

                    acceleration.x += force_x / bodies[i].mass;
                    acceleration.y += force_y / bodies[i].mass;
                    acceleration.z += force_z / bodies[i].mass;
                }
            }

            bodies[i].velocity.x += acceleration.x * DELTA_T;
            bodies[i].velocity.y += acceleration.y * DELTA_T;
            bodies[i].velocity.z += acceleration.z * DELTA_T;
        }
    }
}

int main() {
    Body bodies[] = {
        {
            {0, 0, 0},
            {0, 0, 0},
            5.97e24 // mass of the Earth
        },
        {
            {6.371e6, 0, 0},
            {0, 7.91e3, 0},
            59.7e3 // mass of the ISS
        }
    };

    int num_bodies = sizeof(bodies) / sizeof(Body);
    simulate(bodies, num_bodies);

    printf("Final positions and velocities:\n");
    for (int i = 0; i < num_bodies; i++) {
        printf("Body %d:\n", i + 1);
        printf("Position: (%lf, %lf, %lf)\n", bodies[i].position.x, bodies[i].position.y, bodies[i].position.z);
        printf("Velocity: (%lf, %lf, %lf)\n", bodies[i].velocity.x, bodies[i].velocity.y, bodies[i].velocity.z);
    }

    return 0;
}