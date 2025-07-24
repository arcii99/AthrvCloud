//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: random
#include <stdio.h>
#include <math.h>

#define G 6.67430e-11

typedef struct {
    double x, y, z;
} Vector3;

typedef struct {
    Vector3 pos, vel, acc, force;
    double mass;
} Body;

int main() {
    int i, j, k;
    double dt = 0.1;
    int nsteps = 1000;
    int num_bodies = 3;
    Body bodies[3] = {
        {
            {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, 
            1.99e30
        },
        {
            {149.6e9, 0.0, 0.0}, {0.0, 29.78e3, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, 
            5.97e24
        },
        {
            {227.9e9, 0.0, 0.0}, {0.0, 24.077e3, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, 
            6.39e23
        }
    };
    
    for (i = 0; i < nsteps; i++) {
        for (j = 0; j < num_bodies; j++) {
            bodies[j].force.x = 0.0;
            bodies[j].force.y = 0.0;
            bodies[j].force.z = 0.0;
            for (k = 0; k < num_bodies; k++) {
                if (j != k) {
                    Vector3 r;
                    r.x = bodies[k].pos.x - bodies[j].pos.x;
                    r.y = bodies[k].pos.y - bodies[j].pos.y;
                    r.z = bodies[k].pos.z - bodies[j].pos.z;
                    double dist = sqrt(r.x * r.x + r.y * r.y + r.z * r.z);
                    double mag = G * bodies[j].mass * bodies[k].mass / (dist * dist * dist);
                    bodies[j].force.x += mag * r.x;
                    bodies[j].force.y += mag * r.y;
                    bodies[j].force.z += mag * r.z;
                }
            }
        }
        for (j = 0; j < num_bodies; j++) {
            bodies[j].acc.x = bodies[j].force.x / bodies[j].mass;
            bodies[j].acc.y = bodies[j].force.y / bodies[j].mass;
            bodies[j].acc.z = bodies[j].force.z / bodies[j].mass;
            bodies[j].vel.x += bodies[j].acc.x * dt;
            bodies[j].vel.y += bodies[j].acc.y * dt;
            bodies[j].vel.z += bodies[j].acc.z * dt;
            bodies[j].pos.x += bodies[j].vel.x * dt;
            bodies[j].pos.y += bodies[j].vel.y * dt;
            bodies[j].pos.z += bodies[j].vel.z * dt;
        }
        printf("Step %d:\n", i);
        for (j = 0; j < num_bodies; j++) {
            printf("  Body %d: position = (%e, %e, %e), velocity = (%e, %e, %e)\n", 
                j, bodies[j].pos.x, bodies[j].pos.y, bodies[j].pos.z, bodies[j].vel.x, 
                bodies[j].vel.y, bodies[j].vel.z);
        }
    }
    
    return 0;
}