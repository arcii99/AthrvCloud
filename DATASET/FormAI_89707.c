//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.67e-11

typedef struct {
    double x;
    double y;
    double z;
} Vector;

typedef struct {
    Vector pos;
    Vector vel;
    Vector force;
    double mass;
} Body;

int main() {

    srand(time(NULL));

    const int num_bodies = 5;
    Body bodies[num_bodies];

    // Set up initial conditions for bodies
    bodies[0].pos = (Vector) {0.0, 0.0, 0.0};
    bodies[0].vel = (Vector) {0.0, 0.0, 0.0};
    bodies[0].force = (Vector) {0.0, 0.0, 0.0};
    bodies[0].mass = 1.0e+6;

    bodies[1].pos = (Vector) {1.0e+11, 0.0, 0.0};
    bodies[1].vel = (Vector) {0.0, 3.5e+4, 0.0};
    bodies[1].force = (Vector) {0.0, 0.0, 0.0};
    bodies[1].mass = 1.0e+24;

    bodies[2].pos = (Vector) {0.0, 2.3e+11, 0.0};
    bodies[2].vel = (Vector) {2.0e+4, 0.0, 0.0};
    bodies[2].force = (Vector) {0.0, 0.0, 0.0};
    bodies[2].mass = 5.6e+24;

    bodies[3].pos = (Vector) {0.0, 4.5e+11, 0.0};
    bodies[3].vel = (Vector) {-1.5e+4, 0.0, 0.0};
    bodies[3].force = (Vector) {0.0, 0.0, 0.0};
    bodies[3].mass = 1.0e+24;

    bodies[4].pos = (Vector) {0.0, 0.0, 3.7e+12};
    bodies[4].vel = (Vector) {0.0, 0.0, -2.5e+3};
    bodies[4].force = (Vector) {0.0, 0.0, 0.0};
    bodies[4].mass = 3.0e+23;

    const double dt = 3600.0; // time step
    const double end_time = 3.0e+9; // duration of simulation
    double curr_time = 0.0;

    // Main simulation loop
    while (curr_time < end_time) {

        // Compute forces on bodies
        for (int i = 0; i < num_bodies; i++) {
            bodies[i].force.x = 0.0;
            bodies[i].force.y = 0.0;
            bodies[i].force.z = 0.0;

            for (int j = 0; j < num_bodies; j++) {
                if (i != j) {
                    Vector r;
                    r.x = bodies[j].pos.x - bodies[i].pos.x;
                    r.y = bodies[j].pos.y - bodies[i].pos.y;
                    r.z = bodies[j].pos.z - bodies[i].pos.z;
                    double dist = sqrt(r.x*r.x + r.y*r.y + r.z*r.z);
                    double f = (G * bodies[i].mass * bodies[j].mass) / (dist*dist);
                    bodies[i].force.x += f * r.x / dist;
                    bodies[i].force.y += f * r.y / dist;
                    bodies[i].force.z += f * r.z / dist;
                }
            }
        }

        // Update positions and velocities of bodies using leapfrog integration
        for (int i = 0; i < num_bodies; i++) {
            bodies[i].vel.x += bodies[i].force.x / bodies[i].mass * 0.5 * dt;
            bodies[i].vel.y += bodies[i].force.y / bodies[i].mass * 0.5 * dt;
            bodies[i].vel.z += bodies[i].force.z / bodies[i].mass * 0.5 * dt;

            bodies[i].pos.x += bodies[i].vel.x * dt;
            bodies[i].pos.y += bodies[i].vel.y * dt;
            bodies[i].pos.z += bodies[i].vel.z * dt;

            bodies[i].vel.x += bodies[i].force.x / bodies[i].mass * 0.5 * dt;
            bodies[i].vel.y += bodies[i].force.y / bodies[i].mass * 0.5 * dt;
            bodies[i].vel.z += bodies[i].force.z / bodies[i].mass * 0.5 * dt;
        }

        curr_time += dt;
    }

    // Print final positions and velocities of bodies
    for (int i = 0; i < num_bodies; i++) {
        printf("Body %d:\n", i);
        printf("  position = (%e, %e, %e) meters\n", bodies[i].pos.x, bodies[i].pos.y, bodies[i].pos.z);
        printf("  velocity = (%e, %e, %e) m/s\n", bodies[i].vel.x, bodies[i].vel.y, bodies[i].vel.z);
    }

    return 0;
}