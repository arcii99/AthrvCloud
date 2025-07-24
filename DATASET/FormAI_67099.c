//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.67430e-11

typedef struct {
    double x;
    double y;
    double z;
} vector;

typedef struct {
    vector position;
    vector velocity;
    double mass;
} body;

vector gravity(vector a, vector b, double mass_b) {
    double distance = sqrt(pow(b.x-a.x, 2) + pow(b.y-a.y, 2) + pow(b.z-a.z, 2));
    double magnitude = (G * mass_b) / pow(distance, 2);

    return (vector) {magnitude * (b.x-a.x)/distance, magnitude * (b.y-a.y)/distance, magnitude * (b.z-a.z)/distance};
}

void update(body *bodies, int size, double time_delta) {
    int i, j;
    vector forces[size];
    for (i = 0; i < size; i++) {
        for (j = i+1; j < size; j++) {
            vector force = gravity(bodies[i].position, bodies[j].position, bodies[j].mass);
            forces[i].x += force.x;
            forces[i].y += force.y;
            forces[i].z += force.z;
            forces[j].x -= force.x;
            forces[j].y -= force.y;
            forces[j].z -= force.z;
        }
    }

    for (i = 0; i < size; i++) {
        vector acceleration = (vector) {forces[i].x/bodies[i].mass, forces[i].y/bodies[i].mass, forces[i].z/bodies[i].mass};
        bodies[i].velocity.x += acceleration.x * time_delta;
        bodies[i].velocity.y += acceleration.y * time_delta;
        bodies[i].velocity.z += acceleration.z * time_delta;
        bodies[i].position.x += bodies[i].velocity.x * time_delta;
        bodies[i].position.y += bodies[i].velocity.y * time_delta;
        bodies[i].position.z += bodies[i].velocity.z * time_delta;
    }
}

int main() {
    srand(time(NULL)); // set the random seed based on current time
    int size = 5; // number of bodies
    double time_delta = 1.0; // time per iteration

    body bodies[size];
    // initialize the positions, velocities, and masses of the bodies randomly
    for (int i = 0; i < size; i++) {
        bodies[i].position.x = (double)(rand() % 1000 + 1) / 1000;
        bodies[i].position.y = (double)(rand() % 1000 + 1) / 1000;
        bodies[i].position.z = (double)(rand() % 1000 + 1) / 1000;
        bodies[i].velocity.x = (double)(rand() % 10 + 1) / 1000;
        bodies[i].velocity.y = (double)(rand() % 10 + 1) / 1000;
        bodies[i].velocity.z = (double)(rand() % 10 + 1) / 1000;
        bodies[i].mass = (double)(rand() % 1000000 + 1) / 1000000;
    }

    // run the simulation for 100 iterations
    for (int i = 0; i < 100; i++) {
        update(bodies, size, time_delta);
        printf("Iteration %d:\n", i+1);
        for (int j = 0; j < size; j++) {
            printf("Body %d: position(%f, %f, %f) velocity(%f, %f, %f) mass(%f)\n", j+1, bodies[j].position.x, bodies[j].position.y, bodies[j].position.z, bodies[j].velocity.x, bodies[j].velocity.y, bodies[j].velocity.z, bodies[j].mass);
        }
        printf("\n");
    }

    return 0;
}