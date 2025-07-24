//FormAI DATASET v1.0 Category: Physics simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define dt 0.01     // time step size
#define G 6.674e-11 // gravitational constant

struct Body {
    double x, y;     // position
    double vx, vy;   // velocity
    double fx, fy;   // forces
    double mass;     // mass
};

void compute_forces(struct Body* bodies, int n) {
    for (int i = 0; i < n; i++) {
        bodies[i].fx = 0;
        bodies[i].fy = 0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                double dx = bodies[j].x - bodies[i].x;
                double dy = bodies[j].y - bodies[i].y;
                double r = sqrt(dx*dx + dy*dy);
                double f = G * bodies[i].mass * bodies[j].mass / (r*r);
                bodies[i].fx += f * dx / r;
                bodies[i].fy += f * dy / r;
            }
        }
    }
}

void update_velocities(struct Body* bodies, int n) {
    for (int i = 0; i < n; i++) {
        bodies[i].vx += bodies[i].fx / bodies[i].mass * dt;
        bodies[i].vy += bodies[i].fy / bodies[i].mass * dt;
    }
}

void update_positions(struct Body* bodies, int n) {
    for (int i = 0; i < n; i++) {
        bodies[i].x += bodies[i].vx * dt;
        bodies[i].y += bodies[i].vy * dt;
    }
}

void print_bodies(struct Body* bodies, int n) {
    printf("%4s  %10s  %10s  %10s  %10s\n", "idx", "x", "y", "vx", "vy");
    for (int i = 0; i < n; i++) {
        printf("%4d  %10.2e  %10.2e  %10.2e  %10.2e\n", i, bodies[i].x, bodies[i].y, bodies[i].vx, bodies[i].vy);
    }
}

int main() {
    struct Body bodies[] = {
        { 1.0,  0.0,  0.0,  2.0 * M_PI, 1.0 },   // first body (1 kg) in circular orbit
        { 0.0,  0.0,  0.0,  0.0, 10.0 }         // second body (10 kg) at rest
    };
    int n = sizeof(bodies) / sizeof(bodies[0]);
    int steps = 10000;

    printf("Initial state:\n");
    print_bodies(bodies, n);

    for (int i = 0; i < steps; i++) {
        compute_forces(bodies, n);
        update_velocities(bodies, n);
        update_positions(bodies, n);
    }

    printf("Final state:\n");
    print_bodies(bodies, n);

    return EXIT_SUCCESS;
}