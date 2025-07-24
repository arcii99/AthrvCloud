//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // Gravitational constant

typedef struct {
    double x;
    double y;
} Vector2D;

typedef struct {
    Vector2D pos;
    Vector2D vel;
    double mass;
} Body;

Vector2D gravitationalForce(Body a, Body b) {
    double distance = sqrt(pow(b.pos.x - a.pos.x, 2) + pow(b.pos.y - a.pos.y, 2));
    double forceMagnitude = G * a.mass * b.mass / pow(distance, 2);
    Vector2D force;
    force.x = forceMagnitude * (b.pos.x - a.pos.x) / distance;
    force.y = forceMagnitude * (b.pos.y - a.pos.y) / distance;
    return force;
}

void simulate(Body bodies[], int numBodies, double timeStep, int numSteps) {
    for(int i = 0; i < numSteps; i++) {
        for(int j = 0; j < numBodies; j++) {
            Vector2D totalForce = {0, 0};
            for(int k = 0; k < numBodies; k++) {
                if(j != k) {
                    Vector2D force = gravitationalForce(bodies[j], bodies[k]);
                    totalForce.x += force.x;
                    totalForce.y += force.y;
                }
            }
            bodies[j].vel.x += totalForce.x * timeStep / bodies[j].mass;
            bodies[j].vel.y += totalForce.y * timeStep / bodies[j].mass;
            bodies[j].pos.x += bodies[j].vel.x * timeStep;
            bodies[j].pos.y += bodies[j].vel.y * timeStep;
        }
    }
}

int main() {
    Body sun = {.pos = {0, 0}, .vel = {0, 0}, .mass = 1.9885e30};
    Body earth = {.pos = {149.6e9, 0}, .vel = {0, 29.78e3}, .mass = 5.97e24};
    Body moon = {.pos = {149.6e9, 3.844e8}, .vel = {-1.023e3, 29.78e3}, .mass = 7.342e22};

    Body bodies[] = {sun, earth, moon};

    int numBodies = sizeof(bodies) / sizeof(Body);
    double timeStep = 60 * 60 * 24; // 1 day
    int numSteps = 365; // 1 year

    simulate(bodies, numBodies, timeStep, numSteps);

    printf("Final positions:\n");
    for(int i = 0; i < numBodies; i++) {
        printf("Body %d: (%.2f, %.2f)\n", i + 1, bodies[i].pos.x, bodies[i].pos.y);
    }

    return 0;
}