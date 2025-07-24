//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <math.h>

#define NUM_OBJECTS 3
#define G_CONST 6.674e-11

struct Object {
    double x, y, z; // position
    double vx, vy, vz; // velocity
    double mass;
};

struct Force {
    double fx, fy, fz;
};

struct Object objects[NUM_OBJECTS]; // create objects array

int main() {
    // set up initial conditions
    objects[0].x = 0.0; objects[0].y = 0.0; objects[0].z = 0.0;
    objects[0].vx = 0.0; objects[0].vy = 0.0; objects[0].vz = 0.0;
    objects[0].mass = 5.97e24;

    objects[1].x = 6378.0e3; objects[1].y = 0.0; objects[1].z = 0.0;
    objects[1].vx = 0.0; objects[1].vy = 7672.0; objects[1].vz = 0.0;
    objects[1].mass = 150.0e3;

    objects[2].x = 0.0; objects[2].y = 0.0; objects[2].z = 380.0e3;
    objects[2].vx = 1022.0; objects[2].vy = 0.0; objects[2].vz = 0.0;
    objects[2].mass = 500.0;

    // simulate gravity
    double dt = 0.1;
    for (int i = 0; i < 1000; i++) {
        // calculate forces on each object
        struct Force forces[NUM_OBJECTS];
        for (int j = 0; j < NUM_OBJECTS; j++) {
            forces[j].fx = 0.0;
            forces[j].fy = 0.0;
            forces[j].fz = 0.0;
            for (int k = 0; k < NUM_OBJECTS; k++) {
                if (j == k) continue;
                double dx = objects[k].x - objects[j].x;
                double dy = objects[k].y - objects[j].y;
                double dz = objects[k].z - objects[j].z;
                double r = sqrt(dx*dx + dy*dy + dz*dz);
                double f = G_CONST * objects[j].mass * objects[k].mass / (r*r);
                forces[j].fx += f * dx / r;
                forces[j].fy += f * dy / r;
                forces[j].fz += f * dz / r;
            }
        }

        // update positions and velocities
        for (int j = 0; j < NUM_OBJECTS; j++) {
            objects[j].x += objects[j].vx * dt;
            objects[j].y += objects[j].vy * dt;
            objects[j].z += objects[j].vz * dt;

            objects[j].vx += forces[j].fx / objects[j].mass * dt;
            objects[j].vy += forces[j].fy / objects[j].mass * dt;
            objects[j].vz += forces[j].fz / objects[j].mass * dt;
        }

        // output positions of each object
        printf("t = %d:\n", i);
        for (int j = 0; j < NUM_OBJECTS; j++) {
            printf("Object %d: (%.2lf, %.2lf, %.2lf)\n", j, objects[j].x, objects[j].y, objects[j].z);
        }
        printf("\n");
    }

    return 0;
}