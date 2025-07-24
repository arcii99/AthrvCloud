//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: expert-level
#include <stdio.h>
#include <math.h>

#define G 6.674E-11 // gravitational constant
#define NUM_BODIES 3 // number of bodies in the system

struct body {
    double mass;
    double x[3]; // position vector
    double v[3]; // velocity vector
};

void update_positions(struct body bodies[]) {
    int i, j;
    for (i=0; i<NUM_BODIES; i++) {
        for (j=0; j<3; j++) {
            bodies[i].x[j] += bodies[i].v[j];
        }
    }
}

void update_velocities(struct body bodies[], double dt) {
    int i, j, k;
    double distance, force, acceleration;
    double direction[3];
    for (i=0; i<NUM_BODIES; i++) {
        for (j=i+1; j<NUM_BODIES; j++) {
            distance = 0.0;
            for (k=0; k<3; k++) {
                direction[k] = bodies[j].x[k] - bodies[i].x[k];
                distance += direction[k] * direction[k];
            }
            distance = sqrt(distance);
            force = G * bodies[i].mass * bodies[j].mass / (distance * distance);
            for (k=0; k<3; k++) {
                acceleration = force / bodies[i].mass * direction[k];
                bodies[i].v[k] += acceleration * dt;
                bodies[j].v[k] -= acceleration * dt;
            }
        }
    }
}

void print_system(struct body bodies[]) {
    int i, j;
    for (i=0; i<NUM_BODIES; i++) {
        printf("Body %d: m=%f, x=(%f,%f,%f), v=(%f,%f,%f)\n", i+1,
            bodies[i].mass, bodies[i].x[0], bodies[i].x[1], bodies[i].x[2],
            bodies[i].v[0], bodies[i].v[1], bodies[i].v[2]);
    }
}

int main() {
    double dt = 0.01; // time step
    int t, num_steps = 100; // number of simulation steps
    struct body bodies[NUM_BODIES] = {
        { 5.97E24, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 } }, // earth
        { 1.99E30, { 1.5E11, 0.0, 0.0 }, { 0.0, 3.0E4, 0.0 } }, // sun
        { 3.30E23, { 1.5E11, 4.0E8, 0.0 }, { -1.0E3, 3.5E4, 0.0 } } // mars
    };
    for (t=0; t<num_steps; t++) {
        printf("Step %d:\n", t);
        print_system(bodies);
        update_velocities(bodies, dt);
        update_positions(bodies);
    }
    return 0;
}