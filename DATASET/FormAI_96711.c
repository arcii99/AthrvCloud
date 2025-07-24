//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.6743e-11
#define DELTA_T 86400

typedef struct {
    double x;
    double y;
    double z;
} Vector;

typedef struct {
    Vector position;
    Vector velocity;
    double mass;
} Body;

void update_velocity(Body* body, Vector force, double delta_t) {
    Vector acceleration = {
        force.x / body->mass,
        force.y / body->mass,
        force.z / body->mass
    };
    body->velocity.x += acceleration.x * delta_t;
    body->velocity.y += acceleration.y * delta_t;
    body->velocity.z += acceleration.z * delta_t;
}

void update_position(Body* body, double delta_t) {
    body->position.x += body->velocity.x * delta_t;
    body->position.y += body->velocity.y * delta_t;
    body->position.z += body->velocity.z * delta_t;
}

Vector gravitational_force(Body* body, Body* other_body) {
    double distance =
        sqrt(pow(other_body->position.x - body->position.x, 2) +
             pow(other_body->position.y - body->position.y, 2) +
             pow(other_body->position.z - body->position.z, 2));
    
    double force_magnitude = (G * body->mass * other_body->mass) / pow(distance, 2);

    Vector force = {
        force_magnitude * ((other_body->position.x - body->position.x) / distance),
        force_magnitude * ((other_body->position.y - body->position.y) / distance),
        force_magnitude * ((other_body->position.z - body->position.z) / distance)
    };
    
    return force;
}

void apply_forces(Body* bodies, int num_bodies) {
    for (int i = 0; i < num_bodies; i++) {
        Vector total_force = { 0, 0, 0 };

        for (int j = 0; j < num_bodies; j++) {
            if (i == j) continue;

            Vector force = gravitational_force(&bodies[i], &bodies[j]);
            total_force.x += force.x;
            total_force.y += force.y;
            total_force.z += force.z;
        }

        update_velocity(&bodies[i], total_force, DELTA_T);
    }

    for (int i = 0; i < num_bodies; i++) {
        update_position(&bodies[i], DELTA_T);
    }
}

int main() {
    int num_bodies = 4;
    Body bodies[num_bodies];

    // initialize random number generator
    srand(time(NULL));

    // create sun
    bodies[0].mass = 1.989e30;
    bodies[0].position.x = 0;
    bodies[0].position.y = 0;
    bodies[0].position.z = 0;
    bodies[0].velocity.x = 0;
    bodies[0].velocity.y = 0;
    bodies[0].velocity.z = 0;

    // create earth
    bodies[1].mass = 5.97e24;
    bodies[1].position.x = 1.5e11;
    bodies[1].position.y = 0;
    bodies[1].position.z = 0;
    bodies[1].velocity.x = 0;
    bodies[1].velocity.y = 2.978e4;
    bodies[1].velocity.z = 0;

    // create mars
    bodies[2].mass = 6.39e23;
    bodies[2].position.x = -2.28e11;
    bodies[2].position.y = 0;
    bodies[2].position.z = 0;
    bodies[2].velocity.x = 0;
    bodies[2].velocity.y = -2.407e4;
    bodies[2].velocity.z = 0;

    // create mercury
    bodies[3].mass = 3.30e23;
    bodies[3].position.x = 5.791e10;
    bodies[3].position.y = 0;
    bodies[3].position.z = 0;
    bodies[3].velocity.x = 0;
    bodies[3].velocity.y = 4.74e4;
    bodies[3].velocity.z = 0;

    for (int i = 0; i < 365; i++) {
        apply_forces(bodies, num_bodies);
    }

    printf("Sun Position: (%.2f, %.2f, %.2f)\n", bodies[0].position.x, bodies[0].position.y, bodies[0].position.z);
    printf("Earth Position: (%.2f, %.2f, %.2f)\n", bodies[1].position.x, bodies[1].position.y, bodies[1].position.z);
    printf("Mars Position: (%.2f, %.2f, %.2f)\n", bodies[2].position.x, bodies[2].position.y, bodies[2].position.z);
    printf("Mercury Position: (%.2f, %.2f, %.2f)\n", bodies[3].position.x, bodies[3].position.y, bodies[3].position.z);

    return 0;
}