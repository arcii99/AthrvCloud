//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.673e-11 // gravitational constant

typedef struct {
    double x, y; // position
    double dx, dy; // velocity
    double mass; // mass
} Body;

// update the velocities and positions of the planets
void update(Body *bodies, int n, double dt) {
    for (int i = 0; i < n; i++) {
        Body *b1 = &bodies[i];
        double fx = 0, fy = 0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                Body *b2 = &bodies[j];
                double dx = b2->x - b1->x;
                double dy = b2->y - b1->y;
                double r = sqrt(dx*dx + dy*dy);
                double f = G * b1->mass * b2->mass / (r*r);
                fx += f*dx/r;
                fy += f*dy/r;
            }
        }
        b1->dx += fx/b1->mass * dt;
        b1->dy += fy/b1->mass * dt;
        b1->x += b1->dx * dt;
        b1->y += b1->dy * dt;
    }
}

int main() {
    int n = 3; // number of planets
    double dt = 1; // time step
    Body *bodies = malloc(n*sizeof(Body));
    if (!bodies) {
        printf("Failed to allocate memory\n");
        exit(1);
    }

    // initialize the planets
    bodies[0].x = 0; bodies[0].y = 0; bodies[0].dx = 0; bodies[0].dy = 0; bodies[0].mass = 5.97e24;
    bodies[1].x = 2e7; bodies[1].y = 0; bodies[1].dx = 0; bodies[1].dy = sqrt(G*bodies[0].mass/2e7); bodies[1].mass = 7.34e22;
    bodies[2].x = 3e7; bodies[2].y = 0; bodies[2].dx = 0; bodies[2].dy = 2*sqrt(G*bodies[0].mass/3e7); bodies[2].mass = 1.99e30;

    // simulate the planets
    for (int i = 0; i < 10; i++) {
        printf("Time step: %d\n", i);
        for (int j = 0; j < n; j++) {
            printf("Planet %d: (%f, %f)\n", j, bodies[j].x, bodies[j].y);
        }
        printf("\n");
        update(bodies, n, dt);
    }

    free(bodies);
    return 0;
}