//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// define constants
#define PI 3.141592653589793
#define GRAV_CONSTANT 6.674e-11
#define TIME_STEP 3600 // time step in seconds

// define structures
typedef struct {
    double x, y, z; // position
    double vx, vy, vz; // velocity
    double mass;
} Body;

// function prototypes
void simulate(Body*, int, double);
void update_positions(Body*, int, double);
void update_velocities(Body*, int, double);

int main() {
    // initialize sun and planets
    Body sun = {0, 0, 0, 0, 0, 0, 1.9891e30};
    Body mercury = {-2.105e10, 0, 0, 0, 47400, 0, 3.3011e23};
    Body venus = {-1.075e11, 0, 0, 0, 35020, 0, 4.8685e24};
    Body earth = {-1.471e11, 0, 0, 0, 29783, 0, 5.9722e24};
    Body mars = {-2.066e11, 0, 0, 0, 24077, 0, 6.4171e23};
    Body jupiter = {-7.405e11, 0, 0, 0, 13070, 0, 1.8982e27};
    Body saturn = {-1.352e12, 0, 0, 0, 9690, 0, 5.6834e26};
    Body uranus = {-2.741e12, 0, 0, 0, 6810, 0, 8.6810e25};
    Body neptune = {-4.444e12, 0, 0, 0, 5430, 0, 1.0243e26};
    Body pluto = {-5.901e12, 0, 0, 0, 4740, 0, 1.3090e22};

    // put bodies in array
    Body bodies[] = {sun, mercury, venus, earth, mars, jupiter, saturn, uranus, neptune, pluto};

    // simulate for 1 year
    simulate(bodies, 10, 31536000);

    return 0;
}

void simulate(Body* bodies, int n, double time) {
    int time_steps = (int) (time / TIME_STEP);

    // print initial positions
    printf("Initial Positions:\n");
    for (int i = 0; i < n; i++) {
        printf("%f, %f, %f\n", bodies[i].x, bodies[i].y, bodies[i].z);
    }
    printf("\n");

    // simulate each time step
    for (int t = 0; t < time_steps; t++) {
        update_positions(bodies, n, TIME_STEP);
        update_velocities(bodies, n, TIME_STEP);
    }

    // print final positions
    printf("Final Positions:\n");
    for (int i = 0; i < n; i++) {
        printf("%f, %f, %f\n", bodies[i].x, bodies[i].y, bodies[i].z);
    }
}

void update_positions(Body* bodies, int n, double dt) {
    // update positions using current velocities
    for (int i = 0; i < n; i++) {
        bodies[i].x += bodies[i].vx * dt;
        bodies[i].y += bodies[i].vy * dt;
        bodies[i].z += bodies[i].vz * dt;
    }
}

void update_velocities(Body* bodies, int n, double dt) {
    // calculate net force on each body
    for (int i = 0; i < n; i++) {
        double fx = 0, fy = 0, fz = 0;

        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            // calculate distance and force using Newton's law of universal gravitation
            double dx = bodies[j].x - bodies[i].x;
            double dy = bodies[j].y - bodies[i].y;
            double dz = bodies[j].z - bodies[i].z;
            double r = sqrt(dx*dx + dy*dy + dz*dz);
            double f = GRAV_CONSTANT * bodies[i].mass * bodies[j].mass / (r*r);

            fx += f * dx / r;
            fy += f * dy / r;
            fz += f * dz / r;
        }

        // update velocity using net force
        bodies[i].vx += fx / bodies[i].mass * dt;
        bodies[i].vy += fy / bodies[i].mass * dt;
        bodies[i].vz += fz / bodies[i].mass * dt;
    }
}