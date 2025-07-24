//FormAI DATASET v1.0 Category: Physics simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.674e-11             // gravitational constant
#define TIME_STEP 0.1           // simulation time step
#define NUM_BODIES 3            // number of bodies in simulation

typedef struct Body {           // body struct
    double mass;
    double position[3];
    double velocity[3];
} Body;

void update_acceleration(Body *body, Body *others) {
    double dx, dy, dz, r_cube, r, fx, fy, fz, f;
    for (int i=0; i<NUM_BODIES; i++) {
        if (body == &others[i]) continue;  // skip self-interaction
        dx = others[i].position[0] - body->position[0];
        dy = others[i].position[1] - body->position[1];
        dz = others[i].position[2] - body->position[2];
        r_cube = pow(dx,2) + pow(dy,2) + pow(dz,2);  // distance^3
        r = sqrt(r_cube);   // distance
        f = G * body->mass * others[i].mass / r_cube;
        fx = f * dx / r;    // force components
        fy = f * dy / r;
        fz = f * dz / r;
        body->velocity[0] += fx / body->mass * TIME_STEP;  // update velocity
        body->velocity[1] += fy / body->mass * TIME_STEP;
        body->velocity[2] += fz / body->mass * TIME_STEP;
    }
}

void update_position(Body *body) {
    body->position[0] += body->velocity[0] * TIME_STEP;  // update position
    body->position[1] += body->velocity[1] * TIME_STEP;
    body->position[2] += body->velocity[2] * TIME_STEP;
}

int main() {
    Body bodies[NUM_BODIES] = {
        {5.97e24, {0, 0, 0}, {0, 0, 0}},    // earth
        {7.34e22, {384400000, 0, 0}, {0, 1022, 0}},   // moon
        {1000, {-1000000, 0, 0}, {0, 9947, 0}}       // asteroid
    };

    for (int i=0; i<500; i++) {     // simulate for 50 seconds
        for (int j=0; j<NUM_BODIES; j++) {
            update_acceleration(&bodies[j], bodies);  // compute acceleration
        }
        for (int j=0; j<NUM_BODIES; j++) {
            update_position(&bodies[j]);    // update position
        }
        printf("EARTH: %f %f %f\n", bodies[0].position[0], bodies[0].position[1], bodies[0].position[2]);
        printf("MOON: %f %f %f\n", bodies[1].position[0], bodies[1].position[1], bodies[1].position[2]);
        printf("ASTEROID: %f %f %f\n", bodies[2].position[0], bodies[2].position[1], bodies[2].position[2]);
    }

    return 0;
}