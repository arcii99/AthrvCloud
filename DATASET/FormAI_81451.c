//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITATIONAL_CONSTANT 6.674e-11

typedef struct {
    double x, y, z; // position
    double vx, vy, vz; // velocity
    double mass;
} Body;

void updateVelocity(Body *a, Body *b, double dt) {
    double dx = b->x - a->x;
    double dy = b->y - a->y;
    double dz = b->z - a->z;

    double distance = sqrt(dx*dx + dy*dy + dz*dz);

    double f = GRAVITATIONAL_CONSTANT * a->mass * b->mass / (distance*distance);

    double fx = f * dx / distance;
    double fy = f * dy / distance;
    double fz = f * dz / distance;

    a->vx += fx / a->mass * dt;
    a->vy += fy / a->mass * dt;
    a->vz += fz / a->mass * dt;

    b->vx -= fx / b->mass * dt;
    b->vy -= fy / b->mass * dt;
    b->vz -= fz / b->mass * dt;
}

void updatePosition(Body *b, double dt) {
    b->x += b->vx * dt;
    b->y += b->vy * dt;
    b->z += b->vz * dt;
}

int main() {
    Body bodies[] = {
        /* x     y       z      vx     vy     vz     mass */
        {  0.0,  1.0,  0.0,    0.0,   0.0,   0.0,   5.97e24 }, // Earth
        {  1.0,  0.0,  0.0,    0.0,   0.0,   0.0,   1.99e30 }, // Sun
        {  0.0,  0.0, -1.0,    0.0,   0.0,   0.0,   7.35e22 }, // Moon
        {  0.0,  1.5,  0.0,  885.0,   0.0,   0.0,   1.0e10 }  // Test particle
    };

    int n = sizeof(bodies) / sizeof(Body);

    double timestep = 0.01;

    double simulation_time = 365 * 24 * 3600; // 1 year

    // Main simulation loop
    for (double t = 0; t < simulation_time; t += timestep) {

        // Update velocities
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                updateVelocity(&bodies[i], &bodies[j], timestep);
            }
        }

        // Update positions
        for (int i = 0; i < n; i++) {
            updatePosition(&bodies[i], timestep);
        }

        // Output positions at regular intervals
        if (fmod(t, 3600*24*30) == 0) {
            printf("Time: %g days\n", t / (3600*24));
            for (int i = 0; i < n; i++) {
                printf("Body %d: x=%g y=%g z=%g\n", i, bodies[i].x, bodies[i].y, bodies[i].z);
            }
            printf("\n");
        }
    }

    return 0;
}