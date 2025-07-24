//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAV_CONST 6.674        // gravitational constant

typedef struct {
    double x, y;                // position
    double vx, vy;              // velocity
    double fx, fy;              // force
    double mass;                // mass
} body;

// function to calculate distance between two bodies
double dist(body a, body b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// function to calculate force between two bodies
void calc_force(body *a, body *b) {
    double r = dist(*a, *b);
    double force = GRAV_CONST * a->mass * b->mass / pow(r, 2);
    a->fx += force * (b->x - a->x) / r;
    a->fy += force * (b->y - a->y) / r;
}

// update body position and velocity based on force and time step
void update_body(body *b, double dt) {
    b->vx += b->fx / b->mass * dt;
    b->vy += b->fy / b->mass * dt;
    b->x += b->vx * dt;
    b->y += b->vy * dt;
}

int main() {
    body bodies[3];             // create 3 bodies

    // initialize positions and masses of bodies
    bodies[0].x = 0;
    bodies[0].y = 0;
    bodies[0].mass = 1e10;

    bodies[1].x = 10;
    bodies[1].y = 0;
    bodies[1].mass = 2e10;

    bodies[2].x = 0;
    bodies[2].y = 10;
    bodies[2].mass = 3e10;

    // initialize velocities
    for (int i = 0; i < 3; i++) {
        bodies[i].vx = 0;
        bodies[i].vy = 0;
    }

    double dt = 0.1;            // time step

    // simulate for 100 time steps
    for (int t = 1; t <= 100; t++) {
        // calculate forces between all pairs of bodies
        for (int i = 0; i < 3; i++) {
            bodies[i].fx = 0;
            bodies[i].fy = 0;
            for (int j = 0; j < 3; j++) {
                if (i != j) {
                    calc_force(&bodies[i], &bodies[j]);
                }
            }
        }
        // update positions and velocities
        for (int i = 0; i < 3; i++) {
            update_body(&bodies[i], dt);
        }
        // print positions of bodies
        printf("t = %d: (%.2lf, %.2lf) (%.2lf, %.2lf) (%.2lf, %.2lf)\n", t, bodies[0].x, bodies[0].y, bodies[1].x, bodies[1].y, bodies[2].x, bodies[2].y);
    }

    return 0;
}