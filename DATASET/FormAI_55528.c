//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: scientific
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define G 6.6743e-11 // Gravitational constant

typedef struct {
    double x, y; // position
    double vx, vy; // velocity
    double ax, ay; // acceleration
    double m; // mass
} body;

body initBody(double x, double y, double vx, double vy, double m) {
    body b = {x, y, vx, vy, 0, 0, m};
    return b;
}

void updateBody(body *b, double dt) {
    b->vx += b->ax * dt;
    b->vy += b->ay * dt;
    b->x += b->vx * dt + 0.5 * b->ax * dt * dt;
    b->y += b->vy * dt + 0.5 * b->ay * dt * dt;
}

double distance(body *b1, body *b2) {
    double dx = b1->x - b2->x;
    double dy = b1->y - b2->y;
    return sqrt(dx * dx + dy * dy);
}

void addForce(body *b1, body *b2) {
    double d = distance(b1, b2);
    double f = G * b1->m * b2->m / (d * d);
    double fx = f * (b2->x - b1->x) / d;
    double fy = f * (b2->y - b1->y) / d;
    b1->ax += fx / b1->m;
    b1->ay += fy / b1->m;
}

void simulate(body *bodies, int n, double dt, int timesteps) {
    for (int t=0; t<timesteps; t++) {
        // reset accelerations
        for (int i=0; i<n; i++) {
            bodies[i].ax = 0;
            bodies[i].ay = 0;
        }
        // calculate forces
        for (int i=0; i<n; i++) {
            for (int j=0; j<i; j++) { // avoid double counting
                addForce(&bodies[i], &bodies[j]);
                addForce(&bodies[j], &bodies[i]);
            }
        }
        // update positions and velocities
        for (int i=0; i<n; i++) {
            updateBody(&bodies[i], dt);
        }
    }
}

int main() {
    int n = 4; // number of bodies
    body bodies[n];

    // initialize bodies
    bodies[0] = initBody(0, 0, 0, 0, 1.989e30); // sun
    bodies[1] = initBody(57.91e9, 0, 0, 47.87e3, 3.3011e23); // mercury
    bodies[2] = initBody(108.2e9, 0, 0, 35.02e3, 4.869e24); // venus
    bodies[3] = initBody(149.6e9, 0, 0, 29.78e3, 5.9742e24); // earth

    // simulate the solar system for one year
    double dt = 3600.0; // time step size (1 hour)
    int timesteps = 365 * 24; // number of time steps (1 year)
    simulate(bodies, n, dt, timesteps);

    // print final positions and velocities
    for (int i=0; i<n; i++) {
        printf("body #%d: x=%e, y=%e, vx=%e, vy=%e\n", i, bodies[i].x, bodies[i].y, bodies[i].vx, bodies[i].vy);
    }

    return 0;
}