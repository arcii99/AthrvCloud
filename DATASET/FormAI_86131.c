//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Sherlock Holmes
#include <stdio.h>
#include <math.h>
#define G 6.67430e-11

struct Body {
    double x, y;   // position
    double vx, vy; // velocity
    double fx, fy; // forces
    double m;      // mass
};

void update(struct Body *b, double dt) {
    b->vx += b->fx / b->m * dt;
    b->vy += b->fy / b->m * dt;
    b->x += b->vx * dt;
    b->y += b->vy * dt;
    b->fx = 0;
    b->fy = 0;
}

void add_force(struct Body *b1, struct Body *b2) {
    double dx = b2->x - b1->x;
    double dy = b2->y - b1->y;
    double dist = sqrt(dx * dx + dy * dy);
    double force = G * b1->m * b2->m / (dist * dist);

    b1->fx += force * dx / dist;
    b1->fy += force * dy / dist;
}

int main() {
    const int N = 4; // number of bodies
    struct Body bodies[] = {
        { 0, 0, 0, 0, 1988500e24, }, // Sun
        { -147e9, 0, 0, -30300, 5.97e24, }, // Earth
        { -206e9, 0, 0, -24000, 0.073e24, }, // Mars
        { 0, -778e9, 13100, 0, 1898e24, }, // Jupiter
    };
    const double dt = 86400; // time step (s)
    const double tmax = 11 * 365.25 * 86400; // simulation time (s)

    int t;
    for (t = 0; t < tmax / dt; t++) {
        int i, j;
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (i != j) {
                    add_force(&bodies[i], &bodies[j]);
                }
            }
        }
        for (i = 0; i < N; i++) {
            update(&bodies[i], dt);
        }
        printf("%g %g\n", bodies[1].x, bodies[1].y);
    }

    return 0;
}