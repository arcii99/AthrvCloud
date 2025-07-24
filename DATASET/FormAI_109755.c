//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11   // gravitational constant

typedef struct {
    double x, y;         // position
    double vx, vy;       // velocity
    double fx, fy;       // force
    double mass;         // mass
} Body;

void init(Body* bodies, int n) {
    for (int i=0; i<n; i++) {
        bodies[i].x = rand() / (double) RAND_MAX * 10;
        bodies[i].y = rand() / (double) RAND_MAX * 10;
        bodies[i].vx = rand() / (double) RAND_MAX * 0.1;
        bodies[i].vy = rand() / (double) RAND_MAX * 0.1;
        bodies[i].fx = 0;
        bodies[i].fy = 0;
        bodies[i].mass = rand() / (double) RAND_MAX * 10;
    }
}

void calculate_force(Body* bodies, int n) {
    for (int i=0; i<n; i++) {
        bodies[i].fx = 0;
        bodies[i].fy = 0;
        for (int j=0; j<n; j++) {
            if (i != j) {
                double dx = bodies[j].x - bodies[i].x;
                double dy = bodies[j].y - bodies[i].y;
                double distance = sqrt(dx*dx + dy*dy);
                double force = G * bodies[i].mass * bodies[j].mass / (distance * distance);
                double fx = force * dx / distance;
                double fy = force * dy / distance;
                bodies[i].fx += fx;
                bodies[i].fy += fy;
            }
        }
    }
}

void update_body(Body* body, double dt) {
    body->vx += body->fx / body->mass * dt;
    body->vy += body->fy / body->mass * dt;
    body->x += body->vx * dt;
    body->y += body->vy * dt;
}

void update(Body* bodies, int n, double dt) {
    for (int i=0; i<n; i++) {
        update_body(&bodies[i], dt);
    }
}

int main() {
    const int n = 3;
    const double dt = 0.01;
    Body bodies[n];
    init(bodies, n);
    for (int i=0; i<1000; i++) {
        calculate_force(bodies, n);
        update(bodies, n, dt);
        for (int j=0; j<n; j++) {
            printf("Body %d: position = (%f, %f), velocity = (%f, %f)\n",
                j, bodies[j].x, bodies[j].y, bodies[j].vx, bodies[j].vy);
        }
        printf("-------------------------------------------\n");
    }
    return 0;
}