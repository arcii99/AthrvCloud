//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: all-encompassing
#include <stdio.h>
#include <math.h>

#define GRAVITATIONAL_CONSTANT 6.674e-11 // m^3/kg s^2
#define TIME_STEP 1000 // seconds

typedef struct {
    double x, y, z;
    double vx, vy, vz;
    double mass;
} CelestialBody;

double distance(CelestialBody a, CelestialBody b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double dz = a.z - b.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

void update_velocities(CelestialBody* a, CelestialBody* b) {
    double dist = distance(*a, *b);
    double force = GRAVITATIONAL_CONSTANT * a->mass * b->mass / (dist * dist);
    double ax = force * (b->x - a->x) / dist / a->mass;
    double ay = force * (b->y - a->y) / dist / a->mass;
    double az = force * (b->z - a->z) / dist / a->mass;

    a->vx += ax * TIME_STEP;
    a->vy += ay * TIME_STEP;
    a->vz += az * TIME_STEP;

    b->vx -= ax * TIME_STEP;
    b->vy -= ay * TIME_STEP;
    b->vz -= az * TIME_STEP;
}

void update_positions(CelestialBody* body) {
    body->x += body->vx * TIME_STEP;
    body->y += body->vy * TIME_STEP;
    body->z += body->vz * TIME_STEP;
}

void simulate(CelestialBody bodies[], int num_bodies, int num_steps) {
    for (int step = 0; step < num_steps; ++step) {
        // update velocities
        for (int i = 0; i < num_bodies; ++i) {
            for (int j = i+1; j < num_bodies; ++j) {
                update_velocities(&bodies[i], &bodies[j]);
            }
        }
        // update positions
        for (int i = 0; i < num_bodies; ++i) {
            update_positions(&bodies[i]);
        }
    }
}

int main() {
    CelestialBody sun = {
        .mass = 1.9885e30,
        .x = 0,
        .y = 0,
        .z = 0,
        .vx = 0,
        .vy = 0,
        .vz = 0
    };

    CelestialBody earth = {
        .mass = 5.974e24,
        .x = 149.6e9, // meters from sun
        .y = 0,
        .z = 0,
        .vx = 0,
        .vy = 29.29e3, // meters per second
        .vz = 0
    };
    
    CelestialBody mars = {
        .mass = 6.39e23,
        .x = 227.9e9, // meters from sun
        .y = 0,
        .z = 0,
        .vx = 0,
        .vy = 24.077e3, // meters per second
        .vz = 0
    };

    CelestialBody bodies[] = {sun, earth, mars};
    int num_bodies = sizeof(bodies) / sizeof(CelestialBody);

    simulate(bodies, num_bodies, 365*24*3600/TIME_STEP);
    for (int i = 0; i < num_bodies; ++i) {
        printf("Body %d: (%g, %g, %g)\n", i, bodies[i].x, bodies[i].y, bodies[i].z);
    }
    return 0;
}