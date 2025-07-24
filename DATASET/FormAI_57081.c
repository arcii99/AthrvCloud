//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846
#define GRAV_CONST 6.67430e-11

struct Vector {
    double x, y, z;
};

struct Body {
    char *name;
    double mass;
    struct Vector position, velocity, acceleration;
};

int num_bodies = 3;

struct Body bodies[] = {
    {"Sun", 1.989e+30, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {"Earth", 5.972e+24, {1.496e+11, 0, 0}, {0, 2.9783e+4, 0}, {0, 0, 0}},
    {"Moon", 7.342e+22, {1.496e+11 + 3.844e+8, 0, 0}, {0, 2.9783e+4 + 1.023e+3, 0}, {0, 0, 0}}
};

void updateBody(struct Body *body, double dt) {
    struct Vector force = {0, 0, 0};
    for (int i = 0; i < num_bodies; ++i) {
        if (body == &bodies[i]) continue;
        // calculate distance vector between the two bodies
        struct Vector distance = {
            bodies[i].position.x - body->position.x,
            bodies[i].position.y - body->position.y,
            bodies[i].position.z - body->position.z
        };
        // calculate magnitude of the distance vector
        double r = sqrt(pow(distance.x, 2) + pow(distance.y, 2) + pow(distance.z, 2));
        // calculate force between the two bodies
        double f = (GRAV_CONST * body->mass * bodies[i].mass) / pow(r, 2);
        // calculate force vector
        struct Vector fVec = {
            f * distance.x / r,
            f * distance.y / r,
            f * distance.z / r
        };
        // add force vector to total force
        force.x += fVec.x;
        force.y += fVec.y;
        force.z += fVec.z;
    }
    // calculate acceleration vector
    struct Vector acceleration = {
        force.x / body->mass,
        force.y / body->mass,
        force.z / body->mass
    };
    // update velocity vector
    body->velocity.x += acceleration.x * dt;
    body->velocity.y += acceleration.y * dt;
    body->velocity.z += acceleration.z * dt;
    // update position vector
    body->position.x += body->velocity.x * dt;
    body->position.y += body->velocity.y * dt;
    body->position.z += body->velocity.z * dt;
}

void update(double dt) {
    for (int i = 0; i < num_bodies; ++i) {
        updateBody(&bodies[i], dt);
    }
}

void printBody(struct Body body) {
    printf("%s:\n", body.name);
    printf("  Mass: %e kg\n", body.mass);
    printf("  Position: (%.2f, %.2f, %.2f)\n", body.position.x, body.position.y, body.position.z);
    printf("  Velocity: (%.2f, %.2f, %.2f)\n", body.velocity.x, body.velocity.y, body.velocity.z);
    printf("  Acceleration: (%.2f, %.2f, %.2f)\n", body.acceleration.x, body.acceleration.y, body.acceleration.z);
}

void printAllBodies() {
    for (int i = 0; i < num_bodies; ++i) {
        printBody(bodies[i]);
    }
}

int main() {
    double dt = 86400; // 1 day in seconds
    double endTime = 365 * 24 * 60 * 60; // 1 year in seconds
    for (int i = 0; i < num_bodies; ++i) {
        bodies[i].acceleration = (struct Vector){0, 0, 0};
    }
    for (double time = 0; time < endTime; time += dt) {
        update(dt);
    }
    printAllBodies();
    return 0;
}