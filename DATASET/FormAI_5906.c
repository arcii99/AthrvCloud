//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIM 3   // number of dimensions
#define G 6.67430e-11   // gravitational constant

typedef struct {
    double x[DIM];  // position vector
    double v[DIM];  // velocity vector
    double a[DIM];  // acceleration vector
    double m;       // mass
} Body;

void update_acceleration(Body *p, Body *others, int n) {
    int i, j;
    double r, f;

    for (i = 0; i < DIM; i++) {
        p->a[i] = 0;
    }

    for (i = 0; i < n; i++) {
        if (p != &others[i]) {
            r = 0;
            for (j = 0; j < DIM; j++) {
                r += pow(others[i].x[j] - p->x[j], 2);
            }
            r = sqrt(r);
            f = G * p->m * others[i].m / pow(r, 2);
            for (j = 0; j < DIM; j++) {
                p->a[j] += f * (others[i].x[j] - p->x[j]) / r;
            }
        }
    }
}

void update_velocity(Body *p, double dt) {
    int i;
    for (i = 0; i < DIM; i++) {
        p->v[i] += p->a[i] * dt;
    }
}

void update_position(Body *p, double dt) {
    int i;
    for (i = 0; i < DIM; i++) {
        p->x[i] += p->v[i] * dt;
    }
}

int main() {
    // initialize bodies
    Body bodies[4] = {
        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 5.97e24},
        {{6.3781e6, 0, 0}, {0, 7.9e3, 0}, {0, 0, 0}, 5.97e24},
        {{6.3781e6, 0, 3.57864e7}, {-7.9e3, 0, 0}, {0, 0, 0}, 5.97e24},
        {{6.3781e6, 3.57864e7, 0}, {0, -7.9e3, 0}, {0, 0, 0}, 5.97e24}
    };
    int n = sizeof(bodies) / sizeof(bodies[0]);

    // simulation parameters
    double dt = 1;
    int steps = 100;

    // simulate
    int i, j;
    for (i = 0; i < steps; i++) {
        for (j = 0; j < n; j++) {
            update_acceleration(&bodies[j], bodies, n);
        }
        for (j = 0; j < n; j++) {
            update_velocity(&bodies[j], dt);
        }
        for (j = 0; j < n; j++) {
            update_position(&bodies[j], dt);
        }
    }

    return 0;
}