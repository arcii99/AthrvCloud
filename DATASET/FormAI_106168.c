//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Linus Torvalds
// The following program is a simple C Planet Gravity Simulation
// inspired by Linus Torvalds style for clean and elegant code.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITATIONAL_CONSTANT 6.67430e-11 // m^3 kg^-1 s^-2

typedef struct {
    double x;
    double y;
    double z;
} Vector3;

typedef struct {
    char name[32];
    double mass;
    Vector3 position;
    Vector3 velocity;
    Vector3 acceleration;
} Body;

void calculate_force(Body* body1, Body* body2, Vector3* force) {
    Vector3 displacement = {
        .x = body2->position.x - body1->position.x,
        .y = body2->position.y - body1->position.y,
        .z = body2->position.z - body1->position.z
    };

    double distance_squared = pow(displacement.x, 2) +
                              pow(displacement.y, 2) +
                              pow(displacement.z, 2);

    double force_magnitude = GRAVITATIONAL_CONSTANT * body1->mass * body2->mass / distance_squared;

    force->x = force_magnitude * displacement.x / sqrt(distance_squared);
    force->y = force_magnitude * displacement.y / sqrt(distance_squared);
    force->z = force_magnitude * displacement.z / sqrt(distance_squared);
}

void update_acceleration(Body* body, Vector3 acceleration) {
    body->acceleration = acceleration;
}

void update_velocity(Body* body, double delta_t) {
    body->velocity.x += body->acceleration.x * delta_t;
    body->velocity.y += body->acceleration.y * delta_t;
    body->velocity.z += body->acceleration.z * delta_t;
}

void update_position(Body* body, double delta_t) {
    body->position.x += body->velocity.x * delta_t;
    body->position.y += body->velocity.y * delta_t;
    body->position.z += body->velocity.z * delta_t;
}

int main() {
    Body earth = {
        .name = "Earth",
        .mass = 5.97e24, // kg
        .position = { .x = 0, .y = 0, .z = 0 }, // m
        .velocity = { .x = 0, .y = 0, .z = 0 }, // m/s
        .acceleration = { .x = 0, .y = 0, .z = 0 } // m/s^2
    };

    Body moon = {
        .name = "Moon",
        .mass = 7.34e22, // kg
        .position = { .x = 384400000, .y = 0, .z = 0 }, // m
        .velocity = { .x = 0, .y = 1022, .z = 0 }, // m/s
        .acceleration = { .x = 0, .y = 0, .z = 0 } // m/s^2
    };

    const double delta_t = 60; // seconds

    for (int i = 0; i < 3600; i++) {
        Vector3 force;

        calculate_force(&earth, &moon, &force);
        update_acceleration(&earth, force);
        update_velocity(&earth, delta_t);
        update_position(&earth, delta_t);

        calculate_force(&moon, &earth, &force);
        update_acceleration(&moon, force);
        update_velocity(&moon, delta_t);
        update_position(&moon, delta_t);

        printf("%d seconds elapsed. Earth pos (%.2f, %.2f, %.2f) Moon pos (%.2f, %.2f, %.2f)\n",
               i * (int) delta_t,
               earth.position.x, earth.position.y, earth.position.z,
               moon.position.x, moon.position.y, moon.position.z);
    }

    return 0;
}