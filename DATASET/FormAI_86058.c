//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define GRAV_CONSTANT 6.67428e-11
#define TIME_STEP 0.01

typedef struct {
    double x;
    double y;
} Vector2;

typedef struct {
    Vector2 position;
    Vector2 velocity;
    double mass;
} Body;

typedef struct {
    Body** bodies;
    int num_bodies;
    double radius;
    double timestep;
} Simulation;

Vector2 calculate_gravitational_force(Body* a, Body* b) {
    double distance_squared = pow(a->position.x - b->position.x, 2) + pow(a->position.y - b->position.y, 2);
    double force_magnitude = (GRAV_CONSTANT * a->mass * b->mass) / distance_squared;
    double distance = sqrt(distance_squared);
    Vector2 force_direction = { (b->position.x - a->position.x) / distance, (b->position.y - a->position.y) / distance };
    return (Vector2) { force_direction.x * force_magnitude, force_direction.y * force_magnitude };
}

void* calculate_forces(void* arg) {
    Body** bodies = ((Simulation*)arg)->bodies;
    int num_bodies = ((Simulation*)arg)->num_bodies;
    double radius = ((Simulation*)arg)->radius;
    double timestep = ((Simulation*)arg)->timestep;

    for (int i = 0; i < num_bodies; i++) {
        Vector2 net_force = { 0, 0 };

        for (int j = 0; j < num_bodies; j++) {
            if (i == j) continue;

            Vector2 force = calculate_gravitational_force(bodies[i], bodies[j]);
            net_force.x += force.x;
            net_force.y += force.y;
        }

        Vector2 acceleration = { net_force.x / bodies[i]->mass, net_force.y / bodies[i]->mass };
        Vector2 new_velocity = { bodies[i]->velocity.x + (acceleration.x * timestep), bodies[i]->velocity.y + (acceleration.y * timestep) };
        Vector2 new_position = { bodies[i]->position.x + (new_velocity.x * timestep), bodies[i]->position.y + (new_velocity.y * timestep) };

        // Reflect bodies off the walls of the simulation boundary
        if (new_position.x < -radius || new_position.x > radius) {
            new_velocity.x = -new_velocity.x;
            new_position.x = new_position.x < 0 ? -radius : radius;
        }

        if (new_position.y < -radius || new_position.y > radius) {
            new_velocity.y = -new_velocity.y;
            new_position.y = new_position.y < 0 ? -radius : radius;
        }

        bodies[i]->velocity = new_velocity;
        bodies[i]->position = new_position;
    }

    pthread_exit(NULL);
}

int main() {
    // Create bodies with random positions and velocities
    Body bodies[4] = {
        { { -10, 0 }, { 10, 0 }, 50 },
        { { 10, 0 }, { -10, 0 }, 50 },
        { { 0, -10 }, { 0, 10 }, 50 },
        { { 0, 10 }, { 0, -10 }, 50 }
    };

    Simulation simulation = { bodies, 4, 20, TIME_STEP };

    // Run the simulation for 100 timesteps
    for (int i = 0; i < 100; i++) {
        // Create threads to calculate forces for each body
        pthread_t threads[4];
        for (int j = 0; j < 4; j++) {
            pthread_create(&threads[j], NULL, calculate_forces, (void*)&simulation);
        }

        // Join threads when they finish
        for (int j = 0; j < 4; j++) {
            pthread_join(threads[j], NULL);
        }

        // Print the position of each body after this timestep
        for (int j = 0; j < 4; j++) {
            printf("Body %d: x=%f, y=%f\n", j, bodies[j].position.x, bodies[j].position.y);
        }

        printf("\n");
    }

    return 0;
}