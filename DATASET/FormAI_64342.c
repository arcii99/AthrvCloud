//FormAI DATASET v1.0 Category: Physics simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743e-11 // gravitational constant

typedef struct {
    double x;
    double y;
    double z;
} Vector3d;

typedef struct {
    Vector3d position;
    Vector3d velocity;
    Vector3d acceleration;
    double mass;
} Body;

void updateAcceleration(Body* body1, Body* body2) {
    Vector3d direction;
    direction.x = body2->position.x - body1->position.x;
    direction.y = body2->position.y - body1->position.y;
    direction.z = body2->position.z - body1->position.z;
    double distance = sqrt(pow(direction.x, 2) + pow(direction.y, 2) + pow(direction.z, 2));
    double force = G * body1->mass * body2->mass / pow(distance, 2);
    double accelerationMagnitude = force / body1->mass;

    direction.x /= distance;
    direction.y /= distance;
    direction.z /= distance;

    body1->acceleration.x += direction.x * accelerationMagnitude;
    body1->acceleration.y += direction.y * accelerationMagnitude;
    body1->acceleration.z += direction.z * accelerationMagnitude;
}

void updateVelocity(Body* body, double timeStep) {
    body->velocity.x += body->acceleration.x * timeStep;
    body->velocity.y += body->acceleration.y * timeStep;
    body->velocity.z += body->acceleration.z * timeStep;
}

void updatePosition(Body* body, double timeStep) {
    body->position.x += body->velocity.x * timeStep;
    body->position.y += body->velocity.y * timeStep;
    body->position.z += body->velocity.z * timeStep;
}

int main() {
    Body earth = {
        .position = { .x = 0, .y = 0, .z = 0 },
        .velocity = { .x = 0, .y = 0, .z = 0 },
        .acceleration = { .x = 0, .y = 0, .z = 0 },
        .mass = 5.97e24
    };
    Body moon = {
        .position = { .x = 0, .y = 384400000, .z = 0 },
        .velocity = { .x = 1022, .y = 0, .z = 0 },
        .acceleration = { .x = 0, .y = 0, .z = 0 },
        .mass = 7.342e22
    };

    double timeStep = 1000; // seconds
    double endTime = 3600 * 24 * 7 * 4; // simulate 4 weeks

    int numTimeSteps = (int)(endTime / timeStep);
    for (int i = 0; i < numTimeSteps; i++) {
        updateAcceleration(&earth, &moon);
        updateVelocity(&earth, timeStep);
        updatePosition(&earth, timeStep);
        updateAcceleration(&moon, &earth);
        updateVelocity(&moon, timeStep);
        updatePosition(&moon, timeStep);
        printf("Time: %d\tEarth x: %lf\ty: %lf\tMoon x: %lf\ty: %lf\n", i, earth.position.x, earth.position.y, moon.position.x, moon.position.y);
    }

    return 0;
}