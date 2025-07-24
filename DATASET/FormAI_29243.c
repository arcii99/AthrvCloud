//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: recursive
#include <stdio.h>
#include <math.h>

#define G 6.6743e-11  /* Gravitational Constant */
#define TIME_STEP 100 /* Time Step */
#define NUM_BODIES 3  /* Number of Bodies */

/*
 * Body Struct
 * 
 * This struct contains the information of each body
 */
struct Body {
    double mass;    /* Mass of Body */
    double pos[3];  /* Position of Body */
    double vel[3];  /* Velocity of Body */
    double acc[3];  /* Acceleration of Body */
};
typedef struct Body Body;

/*
 * Simulation Function
 * 
 * This function performs a single time step simulation of the gravity system
 * by recursively calling itself with updated position and velocity
 */
void simulate(Body *bodies, double time_step, int idx) {
    int i;
    for (i = 0; i < NUM_BODIES; i++) {
        if (i == idx) continue; /* Skip current body */

        /* Calculate distance, direction, and force between two bodies */
        double dx = bodies[i].pos[0] - bodies[idx].pos[0];
        double dy = bodies[i].pos[1] - bodies[idx].pos[1];
        double dz = bodies[i].pos[2] - bodies[idx].pos[2];
        double dist = sqrt(dx*dx + dy*dy + dz*dz);
        double dir[3] = {dx/dist, dy/dist, dz/dist};
        double f = G * bodies[i].mass * bodies[idx].mass / (dist * dist);

        /* Update acceleration of current body */
        bodies[idx].acc[0] += f * dir[0] / bodies[idx].mass;
        bodies[idx].acc[1] += f * dir[1] / bodies[idx].mass;
        bodies[idx].acc[2] += f * dir[2] / bodies[idx].mass;
    }

    /* Update velocity and position of current body */
    bodies[idx].vel[0] += bodies[idx].acc[0] * time_step;
    bodies[idx].vel[1] += bodies[idx].acc[1] * time_step;
    bodies[idx].vel[2] += bodies[idx].acc[2] * time_step;
    bodies[idx].pos[0] += bodies[idx].vel[0] * time_step;
    bodies[idx].pos[1] += bodies[idx].vel[1] * time_step;
    bodies[idx].pos[2] += bodies[idx].vel[2] * time_step;
    bodies[idx].acc[0] = 0;
    bodies[idx].acc[1] = 0;
    bodies[idx].acc[2] = 0;

    /* Recursively call simulate function for next time step */
    if (idx < NUM_BODIES - 1) {
        simulate(bodies, time_step, idx+1);
    }
}

int main() {
    /* Set up initial values of bodies */
    Body bodies[NUM_BODIES] = {
        {1.0e12, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}},
        {2.0e12, {1.5e11, 0.0, 0.0}, {0.0, 3.28e4, 0.0}, {0.0, 0.0, 0.0}},
        {3.0e12, {0.0, 1.0e12, 0.0}, {-2.94e4, 0.0, 0.0}, {0.0, 0.0, 0.0}}
    };

    /* Simulate the gravity system for 1000 time steps */
    int i, j;
    for (i = 0; i < 1000; i++) {
        for (j = 0; j < NUM_BODIES; j++) {
            simulate(bodies, TIME_STEP, j);
        }
    }

    /* Print out final position and velocity of each body */
    for (i = 0; i < NUM_BODIES; i++) {
        printf("Body %d:\n", i+1);
        printf("\tPosition: %.2f, %.2f, %.2f\n", bodies[i].pos[0], bodies[i].pos[1], bodies[i].pos[2]);
        printf("\tVelocity: %.2f, %.2f, %.2f\n", bodies[i].vel[0], bodies[i].vel[1], bodies[i].vel[2]);
    }

    return 0;
}