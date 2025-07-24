//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define G 6.673 * pow(10, -11) // universal gravitation constant

typedef struct {
    double x;
    double y;
    double z;
} vector_t;

typedef struct {
    vector_t position;
    vector_t velocity;
    double mass;
} celestial_body_t;

void simulate(celestial_body_t *bodies, int count, double time_step, int steps) {
    int i, j, k;
    vector_t force, r;
    double distance, magnitude, acceleration;
    vector_t *forces = malloc(sizeof(vector_t) * count);

    for (i = 0; i < steps; i++) {
        for (j = 0; j < count; j++) {
            force.x = force.y = force.z = 0;

            for (k = 0; k < count; k++) {
                if (j == k) continue;

                r.x = bodies[k].position.x - bodies[j].position.x;
                r.y = bodies[k].position.y - bodies[j].position.y;
                r.z = bodies[k].position.z - bodies[j].position.z;

                distance = sqrt(pow(r.x, 2) + pow(r.y, 2) + pow(r.z, 2));
                magnitude = (G * bodies[j].mass * bodies[k].mass) / pow(distance, 2);
                acceleration = magnitude / bodies[j].mass;

                force.x += (r.x / distance) * acceleration;
                force.y += (r.y / distance) * acceleration;
                force.z += (r.z / distance) * acceleration;

            }

            forces[j] = force;
        }

        for (j = 0; j < count; j++) {
            bodies[j].velocity.x += forces[j].x * time_step;
            bodies[j].velocity.y += forces[j].y * time_step;
            bodies[j].velocity.z += forces[j].z * time_step;

            bodies[j].position.x += bodies[j].velocity.x * time_step;
            bodies[j].position.y += bodies[j].velocity.y * time_step;
            bodies[j].position.z += bodies[j].velocity.z * time_step;
        }

        // output positions
        printf("Step %03d: ", i);
        for (j = 0; j < count; j++) {
            printf("%lf,%lf,%lf ", bodies[j].position.x, bodies[j].position.y, bodies[j].position.z);
        }
        printf("\n");
    }

    free(forces);
}

int main() {
    celestial_body_t bodies[] = {
        {{0, 0, 0}, {0, 0, 0}, 5.97*pow(10, 24)},  // Earth
        {{0, 0, 10}, {1, 0, 0}, 100},             // Test Body 1
        {{2, 0, 0}, {0, 0, -1}, 500}              // Test Body 2
    };

    simulate(bodies, 3, 0.1, 50);

    return 0;
}