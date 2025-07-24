//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743E-11 // gravitational constant

typedef struct {
    double x;
    double y;
} Vector;

typedef struct {
    Vector pos;     // position
    Vector vel;     // velocity
    double mass;    // mass
} Body;

const int numBodies = 3;
Body bodies[] = {
    {{0.0, 0.0}, {0.0, 0.0}, 5.97E24},     // earth
    {{1.0E7, 0.0}, {0.0, 29.8E3}, 2.0E7},  // moon
    {{1.5E11, 0.0}, {0.0, 0.0}, 1.99E30}   // sun
};

void updatePosition(Body *b, double dt) {
    b->pos.x += b->vel.x * dt;
    b->pos.y += b->vel.y * dt;
}

void accelerate(Body *b, Vector force, double dt) {
    Vector a;
    a.x = force.x / b->mass;
    a.y = force.y / b->mass;
    b->vel.x += a.x * dt;
    b->vel.y += a.y * dt;
}

void updateVelocity(Body *b, double dt) {
    Vector force = {0.0, 0.0};
    for (int i = 0; i < numBodies; i++) {
        if (b != &bodies[i]) {
            double dx = bodies[i].pos.x - b->pos.x;
            double dy = bodies[i].pos.y - b->pos.y;
            double dist = sqrt(dx*dx + dy*dy);
            double f = G * b->mass * bodies[i].mass / (dist * dist);
            force.x += f * dx / dist;
            force.y += f * dy / dist;
        }
    }
    accelerate(b, force, dt);
}

void printBody(Body b) {
    printf("Mass: %.2e kg\n", b.mass);
    printf("Position: (%.2e, %.2e) meters\n", b.pos.x, b.pos.y);
    printf("Velocity: (%.2e, %.2e) m/s\n\n", b.vel.x, b.vel.y);
}

int main() {
    double dt = 3600.0;  // time step (1 hour)
    int numSteps = 24*365;  // number of time steps (1 year)
    for (int i = 0; i < numSteps; i++) {
        for (int j = 0; j < numBodies; j++) {
            updateVelocity(&bodies[j], dt);
        }
        for (int j = 0; j < numBodies; j++) {
            updatePosition(&bodies[j], dt);
        }
    }
    printBody(bodies[0]);
    printBody(bodies[1]);
    printBody(bodies[2]);
    return 0;
}