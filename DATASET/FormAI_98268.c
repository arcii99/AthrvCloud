//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: complete
#include <stdio.h>
#include <math.h>

#define GRAVITATIONAL_CONST 6.674e-11

typedef struct {
    double x;
    double y;
    double z;
} vector;

typedef struct {
    vector position;
    double mass;
    vector velocity;
    vector force;
} body;

void calculate_force(body* body1, body* body2) {
    vector direction;
    double distance, magnitude1, magnitude2, force_magnitude;

    direction.x = body2->position.x - body1->position.x;
    direction.y = body2->position.y - body1->position.y;
    direction.z = body2->position.z - body1->position.z;

    distance = sqrt(pow(direction.x, 2) + pow(direction.y, 2) + pow(direction.z, 2));

    magnitude1 = GRAVITATIONAL_CONST * body1->mass * body2->mass / pow(distance, 2);
    magnitude2 = GRAVITATIONAL_CONST * body2->mass * body1->mass / pow(distance, 2);
    force_magnitude = fmin(magnitude1, magnitude2);

    body1->force.x += force_magnitude * direction.x / distance;
    body1->force.y += force_magnitude * direction.y / distance;
    body1->force.z += force_magnitude * direction.z / distance;

    body2->force.x -= force_magnitude * direction.x / distance;
    body2->force.y -= force_magnitude * direction.y / distance;
    body2->force.z -= force_magnitude * direction.z / distance;
}

void update_velocity(body* body_ptr, double time_step) {
    body_ptr->velocity.x += body_ptr->force.x / body_ptr->mass * time_step;
    body_ptr->velocity.y += body_ptr->force.y / body_ptr->mass * time_step;
    body_ptr->velocity.z += body_ptr->force.z / body_ptr->mass * time_step;
}

void update_position(body* body_ptr, double time_step) {
    body_ptr->position.x += body_ptr->velocity.x * time_step;
    body_ptr->position.y += body_ptr->velocity.y * time_step;
    body_ptr->position.z += body_ptr->velocity.z * time_step;
}

int main() {
    body earth = {
        .position = {0, 0, 0},
        .mass = 5.97e24,
        .velocity = {0, 0, 0},
        .force = {0, 0, 0}
    };
    body moon = {
        .position = {384400000, 0, 0},
        .mass = 7.35e22,
        .velocity = {0, 1022, 0},
        .force = {0, 0, 0}
    };

    double time_step = 3600;

    calculate_force(&earth, &moon);
    update_velocity(&earth, time_step);
    update_velocity(&moon, time_step);
    update_position(&earth, time_step);
    update_position(&moon, time_step);

    printf("Position of Earth: (%f, %f, %f)\n", earth.position.x, earth.position.y, earth.position.z);
    printf("Position of Moon: (%f, %f, %f)\n", moon.position.x, moon.position.y, moon.position.z);

    return 0;
}