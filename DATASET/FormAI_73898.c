//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define G 6.67384e-11  // Gravitational constant

/*
 * Structures
 */

typedef struct {
    double x, y, z;
} Vector;

typedef struct {
    Vector position, velocity, acceleration;
    double mass;
} Body;

/*
 * Function prototypes
 */

void update_acceleration(Body* body1, const Body* body2);
void update_velocity(Body* body, double time_step);
void update_position(Body* body, double time_step);

/*
 * Main program
 */

int main() {
    // Initialize the solar system
    Body sun = {.mass = 1.9885e30};
    Body earth = {.mass = 5.9742e24, .position = {149.6e9, 0, 0}, .velocity = {0, 29.78e3, 0}};
    Body moon = {.mass = 7.342e22, .position = {149.6e9 + 384.4e6, 0, 0}, .velocity = {0, 29.78e3 + 1.022e3, 0}};

    // Set up simulation parameters
    const double time_step = 3600;
    const int num_steps = 365 * 24;

    // Run the simulation
    for (int i = 0; i < num_steps; i++) {
        update_acceleration(&earth, &sun);
        update_acceleration(&moon, &sun);
        update_acceleration(&moon, &earth);

        update_velocity(&earth, time_step);
        update_velocity(&moon, time_step);

        update_position(&earth, time_step);
        update_position(&moon, time_step);

        printf("Step %d: Earth at (%f, %f, %f), Moon at (%f, %f, %f)\n", i, earth.position.x, earth.position.y, earth.position.z, moon.position.x, moon.position.y, moon.position.z);
    }

    return 0;
}

/*
 * Calculate the gravitational force between two bodies using Newton's law of gravitation.
 * Update the acceleration of body1 based on this force.
 */
void update_acceleration(Body* body1, const Body* body2) {
    const double dist_x = body2->position.x - body1->position.x;
    const double dist_y = body2->position.y - body1->position.y;
    const double dist_z = body2->position.z - body1->position.z;
    const double dist_cu = pow(dist_x, 2) + pow(dist_y, 2) + pow(dist_z, 2);
    const double force_scalar = (G * body1->mass * body2->mass) / dist_cu;
    const double force_x = force_scalar * dist_x;
    const double force_y = force_scalar * dist_y;
    const double force_z = force_scalar * dist_z;
    const double accel_x = force_x / body1->mass;
    const double accel_y = force_y / body1->mass;
    const double accel_z = force_z / body1->mass;

    body1->acceleration.x += accel_x;
    body1->acceleration.y += accel_y;
    body1->acceleration.z += accel_z;
}

/*
 * Update the velocity of a body based on its current acceleration and a time step.
 */
void update_velocity(Body* body, double time_step) {
    body->velocity.x += body->acceleration.x * time_step;
    body->velocity.y += body->acceleration.y * time_step;
    body->velocity.z += body->acceleration.z * time_step;

    body->acceleration.x = 0;
    body->acceleration.y = 0;
    body->acceleration.z = 0;
}

/*
 * Update the position of a body based on its current velocity and a time step.
 */
void update_position(Body* body, double time_step) {
    body->position.x += body->velocity.x * time_step;
    body->position.y += body->velocity.y * time_step;
    body->position.z += body->velocity.z * time_step;
}