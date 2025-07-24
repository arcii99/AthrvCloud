//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.67408e-11

struct Vector {
    double x, y;
};

struct Body {
    struct Vector pos, vel, force;
    double mass, radius;
};

void initSimulation(struct Body* bodies, int n) {
    for(int i = 0; i < n; i++) {
        double x = (double) rand() / (RAND_MAX / 2) - 1;
        double y = (double) rand() / (RAND_MAX / 2) - 1;
        struct Vector pos = {x, y};
        struct Vector vel = {0, 0};
        struct Vector force = {0, 0};
        double mass = (double) rand() / (RAND_MAX / 1000) + 10;
        double radius = pow(mass, 1/3.0);
        bodies[i] = (struct Body) {pos, vel, force, mass, radius};
    }
}

void updateForces(struct Body* bodies, int n) {
    for(int i = 0; i < n; i++) {
        bodies[i].force.x = 0;
        bodies[i].force.y = 0;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            double dx = bodies[j].pos.x - bodies[i].pos.x;
            double dy = bodies[j].pos.y - bodies[i].pos.y;
            double distance = sqrt(dx*dx + dy*dy);
            if(distance == 0) continue;
            double f = G * bodies[i].mass * bodies[j].mass / (distance*distance);
            bodies[i].force.x += f * dx / distance;
            bodies[i].force.y += f * dy / distance;
        }
    }
}

void updateVelocities(struct Body* bodies, int n, double dt) {
    for(int i = 0; i < n; i++) {
        bodies[i].vel.x += bodies[i].force.x / bodies[i].mass * dt;
        bodies[i].vel.y += bodies[i].force.y / bodies[i].mass * dt;
    }
}

void updatePositions(struct Body* bodies, int n, double dt) {
    for(int i = 0; i < n; i++) {
        bodies[i].pos.x += bodies[i].vel.x * dt;
        bodies[i].pos.y += bodies[i].vel.y * dt;
    }
}

void printBodies(struct Body* bodies, int n) {
    for(int i = 0; i < n; i++) {
        printf("Body %d: x=%f, y=%f, mass=%f, radius=%f\n", i+1, bodies[i].pos.x, bodies[i].pos.y, bodies[i].mass, bodies[i].radius);
    }
}

int main() {
    srand(time(NULL));
    const int n = 5;
    struct Body bodies[n];
    double dt = 0.01;
    int iterations = 1000;
    initSimulation(bodies, n);
    for(int i = 0; i < iterations; i++) {
        updateForces(bodies, n);
        updateVelocities(bodies, n, dt);
        updatePositions(bodies, n, dt);
        if(i == 0 || i == iterations-1) {
            printf("Iteration %d:\n", i+1);
            printBodies(bodies, n);
        }
    }
    return 0;
}