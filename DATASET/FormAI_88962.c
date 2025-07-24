//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: expert-level
#include <stdio.h>
#include <math.h>

#define G 6.67430e-11    // Define gravitational constant 'G'

typedef struct {
    double x;
    double y;
    double z;
} Vector3;

typedef struct {
    Vector3 position;
    Vector3 velocity;
    Vector3 acceleration;
    double mass;
} Body;

// Function to calculate the gravitational force between two bodies
Vector3 calculate_gravity_force(Body body_1, Body body_2) {
    Vector3 force;
    double distance;
    Vector3 direction;

    distance = sqrt(pow(body_1.position.x - body_2.position.x, 2) +
                    pow(body_1.position.y - body_2.position.y, 2) +
                    pow(body_1.position.z - body_2.position.z, 2));
    
    direction.x = (body_2.position.x - body_1.position.x) / distance;
    direction.y = (body_2.position.y - body_1.position.y) / distance;
    direction.z = (body_2.position.z - body_1.position.z) / distance;
    
    force.x = G * body_1.mass * body_2.mass / pow(distance, 2) * direction.x;
    force.y = G * body_1.mass * body_2.mass / pow(distance, 2) * direction.y;
    force.z = G * body_1.mass * body_2.mass / pow(distance, 2) * direction.z;
    
    return force;
}

// Function to update the acceleration of a body based on the gravitational forces acting on it
void update_acceleration(Body *body, Body *bodies, int num_bodies) {
    int i;
    Vector3 force;
    
    body->acceleration.x = 0;
    body->acceleration.y = 0;
    body->acceleration.z = 0;
    
    for (i = 0; i < num_bodies; i++) {
        if (body == &bodies[i]) {   // Exclude self
            continue;
        }
        force = calculate_gravity_force(*body, bodies[i]);
        body->acceleration.x += force.x / body->mass;
        body->acceleration.y += force.y / body->mass;
        body->acceleration.z += force.z / body->mass;
    }
}

// Function to update the velocity of a body based on the current acceleration
void update_velocity(Body *body, double time_step) {
    body->velocity.x += body->acceleration.x * time_step;
    body->velocity.y += body->acceleration.y * time_step;
    body->velocity.z += body->acceleration.z * time_step;
}

// Function to update the position of a body based on the current velocity
void update_position(Body *body, double time_step) {
    body->position.x += body->velocity.x * time_step;
    body->position.y += body->velocity.y * time_step;
    body->position.z += body->velocity.z * time_step;
}

int main() {
    // Initialize bodies
    Body earth = {{-1.4710e+11, 0, 0}, {0, -2.9783e+4, 0}, {0, 0, 0}, 5.972e+24};
    Body moon = {{-1.4710e+11, 3.8440e+8, 0}, {1.0220e+3, -2.9493e+4, 0}, {0, 0, 0}, 7.342e+22};
    Body sun = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 1.989e+30};
    int num_bodies = 3;
    Body bodies[] = {earth, moon, sun};

    // Simulation parameters
    double time_step = 60 * 60 * 24;    // Time step of 1 day
    int num_steps = 365;                // 1 year of simulation

    // Simulation loop
    int i, j;
    for (i = 0; i < num_steps; i++) {
        printf("Step %d\n", i+1);
        for (j = 0; j < num_bodies; j++) {
            update_acceleration(&bodies[j], bodies, num_bodies);
            update_velocity(&bodies[j], time_step);
            update_position(&bodies[j], time_step);
            printf("Body %d: %lf %lf %lf\n", j+1, bodies[j].position.x, bodies[j].position.y, bodies[j].position.z);
        }
    }
    
    return 0;
}