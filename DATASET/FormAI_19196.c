//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: recursive
#include <stdio.h>
#include <math.h>

#define G 6.674e-11 // gravitational constant
#define M 5.972e24  // mass of earth
#define T 3600      // simulation time in seconds
#define DT 1        // time step in seconds
#define N T/DT      // number of time steps

typedef struct {
    double x, y;  // position
    double vx, vy; // velocity
    double ax, ay; // acceleration
    double mass;   // mass
} Body;

void calc_gravity(Body *b1, Body *b2) {
    double dx = b2->x - b1->x;
    double dy = b2->y - b1->y;
    double d2 = dx*dx + dy*dy;
    double f = G*b1->mass*b2->mass / d2;
    double fx = f*dx / sqrt(d2);
    double fy = f*dy / sqrt(d2);

    b1->ax += fx/b1->mass;
    b1->ay += fy/b1->mass;
    b2->ax -= fx/b2->mass;
    b2->ay -= fy/b2->mass;
}

void update_body(Body *b) {
    b->vx += b->ax*DT;
    b->vy += b->ay*DT;
    b->x += b->vx*DT;
    b->y += b->vy*DT;
    b->ax = 0;
    b->ay = 0;
}

void simulate(Body *bodies, int n) {
    int i, j;

    // calculate gravitational forces
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            calc_gravity(&bodies[i], &bodies[j]);
        }
    }

    // update positions and velocities
    for (i = 0; i < n; i++) {
        update_body(&bodies[i]);
    }
}

void print_bodies(Body *bodies, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Body %d: x=%.2f y=%.2f vx=%.2f vy=%.2f\n", i, bodies[i].x, bodies[i].y, bodies[i].vx, bodies[i].vy);
    }
}

int main() {
    Body bodies[] = {
        { .x = 0, .y = 0, .vx = 0, .vy = 0, .mass = M },
        { .x = 0, .y = 1000, .vx = 5000, .vy = 0, .mass = 1e4 },
        { .x = 0, .y = -1000, .vx = -5000, .vy = 0, .mass = 1e4 },
        { .x = 1000, .y = 0, .vx = 0, .vy = -5000, .mass = 1e4 },
        { .x = -1000, .y = 0, .vx = 0, .vy = 5000, .mass = 1e4 },
    };

    int n = sizeof(bodies) / sizeof(Body);
    int i;
    for (i = 0; i < N; i++) {
        printf("Step %d:\n", i);
        print_bodies(bodies, n);
        simulate(bodies, n);
    }

    return 0;
}