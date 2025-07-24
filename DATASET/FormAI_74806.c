//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11 // gravitational constant

struct body {
    double x, y; // position
    double vx, vy; // velocity
    double mass; // mass
};

void update(struct body *b, double dt) {
    b->x += b->vx * dt;
    b->y += b->vy * dt;
}

double distance(struct body *a, struct body *b) {
    double dx = a->x - b->x;
    double dy = a->y - b->y;
    return sqrt(dx*dx + dy*dy);
}

void gravity(struct body *a, struct body *b, double dt) {
    double d = distance(a, b);
    if (d == 0) {
        return;
    }
    double f = G * a->mass * b->mass / (d*d);
    double fx = f * (b->x - a->x) / d;
    double fy = f * (b->y - a->y) / d;
    a->vx += fx / a->mass * dt;
    a->vy += fy / a->mass * dt;
}

int main() {
    int n = 3; // number of bodies
    double dt = 1.0; // time step

    struct body bodies[] = {
        {0.0, 0.0, 0.0, 0.0, 5.97e24}, // earth
        {0.0, 6.3781e6 + 35.0e3, 7800.0, 0.0, 1.0}, // satellite 1
        {0.0, 6.3781e6 + 55.0e3, 4800.0, 0.0, 1.0} // satellite 2
    };

    while (1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    gravity(&bodies[i], &bodies[j], dt);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            update(&bodies[i], dt);
        }
        printf("earth: (%.3f, %.3f)\n", bodies[0].x, bodies[0].y);
        printf("satellite 1: (%.3f, %.3f)\n", bodies[1].x, bodies[1].y);
        printf("satellite 2: (%.3f, %.3f)\n", bodies[2].x, bodies[2].y);
        printf("distance between satellite 1 and 2: %.3f\n", distance(&bodies[1], &bodies[2]));
    }

    return 0;
}