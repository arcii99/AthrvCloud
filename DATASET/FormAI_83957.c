//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITATIONAL_CONSTANT 6.6743e-11
#define TIME_STEP 60 * 60 * 24

typedef struct {
    double x;
    double y;
    double z;
} Vector3;

typedef struct {
    Vector3 position;
    Vector3 velocity;
    double mass;
} Body;

Body sun = {
    .position = {0, 0, 0},
    .velocity = {0, 0, 0},
    .mass = 1.989e30
};

Body earth = {
    .position = {-147095000000, 0, 0},
    .velocity = {0, 30290, 0},
    .mass = 5.97e24
};

Vector3 compute_force(Body body1, Body body2) {
    Vector3 distance;
    distance.x = body2.position.x - body1.position.x;
    distance.y = body2.position.y - body1.position.y;
    distance.z = body2.position.z - body1.position.z;

    double magnitude = GRAVITATIONAL_CONSTANT * body1.mass * body2.mass / pow(sqrt(pow(distance.x, 2) + pow(distance.y, 2) + pow(distance.z, 2)), 2);
    Vector3 force;
    force.x = magnitude * distance.x / sqrt(pow(distance.x, 2) + pow(distance.y, 2) + pow(distance.z, 2));
    force.y = magnitude * distance.y / sqrt(pow(distance.x, 2) + pow(distance.y, 2) + pow(distance.z, 2));
    force.z = magnitude * distance.z / sqrt(pow(distance.x, 2) + pow(distance.y, 2) + pow(distance.z, 2));
    return force;
}

void update_velocity(Body* body, Vector3 force) {
    body->velocity.x += force.x / body->mass * TIME_STEP;
    body->velocity.y += force.y / body->mass * TIME_STEP;
    body->velocity.z += force.z / body->mass * TIME_STEP;
}

void update_position(Body* body) {
    body->position.x += body->velocity.x * TIME_STEP;
    body->position.y += body->velocity.y * TIME_STEP;
    body->position.z += body->velocity.z * TIME_STEP;
}

int main() {
    for (int i = 0; i < 365; i++) {
        Vector3 force = compute_force(sun, earth);
        update_velocity(&earth, force);
        update_position(&earth);
        printf("Day %d: Earth position (%lf, %lf, %lf), velocity (%lf, %lf, %lf)\n", i+1, earth.position.x, earth.position.y, earth.position.z, earth.velocity.x, earth.velocity.y, earth.velocity.z);
    }

    return 0;
}