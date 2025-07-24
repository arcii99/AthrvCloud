//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: mind-bending
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define G 6.674e-11

typedef struct {
    double x;
    double y;
} Vector;

typedef struct {
    Vector pos;
    Vector vel;
    double mass;
} Body;

double distance(Vector p1, Vector p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

Vector force(Body b1, Body b2) {
    Vector f;
    double dist = distance(b1.pos, b2.pos);
    double mag = G * b1.mass * b2.mass / (dist * dist);
    f.x = mag * (b2.pos.x - b1.pos.x) / dist;
    f.y = mag * (b2.pos.y - b1.pos.y) / dist;
    return f;
}

Vector univForce(Body b1, Body* bodies, int numBodies) {
    Vector totalForce = {0, 0};
    for (int i = 0; i < numBodies; i++) {
        if (b1.pos.x != bodies[i].pos.x && b1.pos.y != bodies[i].pos.y) {
            Vector f = force(b1, bodies[i]);
            totalForce.x += f.x;
            totalForce.y += f.y;
        }
    }
    return totalForce;
}

void simulate(Body* bodies, int numBodies, double dt, int steps) {
    for (int t = 0; t < steps; t++) {
        for (int i = 0; i < numBodies; i++) {
            Vector a = univForce(bodies[i], bodies, numBodies);
            bodies[i].vel.x += a.x * dt;
            bodies[i].vel.y += a.y * dt;
            bodies[i].pos.x += bodies[i].vel.x * dt;
            bodies[i].pos.y += bodies[i].vel.y * dt;
        }
        printf("%d: ", t);
        for (int i = 0; i < numBodies; i++) {
            printf("Body %d: (%lf, %lf) ", i, bodies[i].pos.x, bodies[i].pos.y);
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));

    int numBodies = 5;
    Body bodies[numBodies];

    // Sun
    bodies[0].pos.x = 0;
    bodies[0].pos.y = 0;
    bodies[0].vel.x = 0;
    bodies[0].vel.y = 0;
    bodies[0].mass = 1.989e30;

    // Planets
    for (int i = 1; i < numBodies; i++) {
        bodies[i].pos.x = (double) (rand() % 200 - 100) * 1e9;
        bodies[i].pos.y = (double) (rand() % 200 - 100) * 1e9;
        bodies[i].vel.x = (double) (rand() % 10000 - 5000);
        bodies[i].vel.y = (double) (rand() % 10000 - 5000);
        bodies[i].mass = (double) (rand() % 1000) * 1e20;
    }

    double dt = 3600 * 24; // 1 day
    int steps = 365;
    simulate(bodies, numBodies, dt, steps);

    return 0;
}