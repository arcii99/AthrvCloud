//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: minimalist
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define G 6.67430e-11

typedef struct {
    double x, y, z;
} Vector3D;

typedef struct {
    Vector3D pos, vel, force;
    double mass;
} Body;

void calculateForce(Body *body1, Body *body2) {
    double dx = body2->pos.x - body1->pos.x;
    double dy = body2->pos.y - body1->pos.y;
    double dz = body2->pos.z - body1->pos.z;
    double dist3 = pow(dx*dx + dy*dy + dz*dz, 1.5);

    double forceMagnitude = G * body1->mass * body2->mass / dist3;

    body1->force.x += dx * forceMagnitude;
    body1->force.y += dy * forceMagnitude;
    body1->force.z += dz * forceMagnitude;

    body2->force.x -= dx * forceMagnitude;
    body2->force.y -= dy * forceMagnitude;
    body2->force.z -= dz * forceMagnitude;
}

void updateBody(Body *body, double deltaTime) {
    body->vel.x += body->force.x / body->mass * deltaTime;
    body->vel.y += body->force.y / body->mass * deltaTime;
    body->vel.z += body->force.z / body->mass * deltaTime;

    body->pos.x += body->vel.x * deltaTime;
    body->pos.y += body->vel.y * deltaTime;
    body->pos.z += body->vel.z * deltaTime;

    body->force.x = 0;
    body->force.y = 0;
    body->force.z = 0;
}

void simulate(Body *bodies, int numBodies, double deltaTime, int numSteps) {
    for (int step = 0; step < numSteps; step++) {
        for (int i = 0; i < numBodies; i++) {
            for (int j = i+1; j < numBodies; j++) {
                calculateForce(&bodies[i], &bodies[j]);
            }
        }

        for (int i = 0; i < numBodies; i++) {
            updateBody(&bodies[i], deltaTime);
        }
    }
}

int main() {
    Body bodies[] = {
        {{   0,    0,    0}, {0, 0, 0}, {0, 0, 0}, 1.989e30}, // sun
        {{-1.5e11,    0,    0}, {0, 30000, 0}, {0, 0, 0}, 5.9742e24}, // earth
        {{-1.5e11+384400000,    0,    0}, {0, 30000+1022, 0}, {0, 0, 0}, 7.342e22} // moon
    };
    int numBodies = sizeof(bodies) / sizeof(Body);

    double deltaTime = 3600;
    int numSteps = 24 * 365 * 5;

    simulate(bodies, numBodies, deltaTime, numSteps);

    for (int i = 0; i < numBodies; i++) {
        printf("Body %d: Pos = (%f, %f, %f), Vel = (%f, %f, %f)\n", i+1, bodies[i].pos.x, bodies[i].pos.y, bodies[i].pos.z, bodies[i].vel.x, bodies[i].vel.y, bodies[i].vel.z);
    }

    return 0;
}