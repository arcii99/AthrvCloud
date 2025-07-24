//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: safe
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define G 6.67408e-11
#define MAX_ITERATIONS 100000
#define DELTA_T 86400

typedef struct {
    double x;
    double y;
    double z;
} vector;

typedef struct {
    double mass;
    vector position;
    vector velocity;
    vector acceleration;
} celestial_body;

void initialize_body(celestial_body* body, double mass, vector position, vector velocity) {
    body->mass = mass;
    body->position = position;
    body->velocity = velocity;
    body->acceleration = (vector){0, 0, 0};
}

void update_acceleration(celestial_body* body, celestial_body* other_body) {
    double distance = sqrt(pow(body->position.x - other_body->position.x, 2) +
                           pow(body->position.y - other_body->position.y, 2) +
                           pow(body->position.z - other_body->position.z, 2));
    double force_magnitude = G * body->mass * other_body->mass / pow(distance, 2);
    vector force_direction = {
        (other_body->position.x - body->position.x) / distance,
        (other_body->position.y - body->position.y) / distance,
        (other_body->position.z - body->position.z) / distance
    };
    vector force = {
        force_magnitude * force_direction.x,
        force_magnitude * force_direction.y,
        force_magnitude * force_direction.z
    };
    body->acceleration.x += force.x / body->mass;
    body->acceleration.y += force.y / body->mass;
    body->acceleration.z += force.z / body->mass;
}

void update_velocity(celestial_body* body, double delta_t) {
    body->velocity.x += body->acceleration.x * delta_t;
    body->velocity.y += body->acceleration.y * delta_t;
    body->velocity.z += body->acceleration.z * delta_t;
}

void update_position(celestial_body* body, double delta_t) {
    body->position.x += body->velocity.x * delta_t;
    body->position.y += body->velocity.y * delta_t;
    body->position.z += body->velocity.z * delta_t;
}

int main() {
    // Initialize celestial bodies
    celestial_body sun, earth, moon;
    initialize_body(&sun, 1.989e30, (vector){0, 0, 0}, (vector){0, 0, 0});
    initialize_body(&earth, 5.972e24, (vector){1.496e11, 0, 0}, (vector){0, 29783, 0});
    initialize_body(&moon, 7.342e22, (vector){1.496e11, 3.633e8, 0}, (vector){-1024, 29783, 0});

    // Run simulation
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        update_acceleration(&earth, &sun);
        update_acceleration(&moon, &sun);
        update_acceleration(&moon, &earth);

        update_velocity(&earth, DELTA_T);
        update_velocity(&moon, DELTA_T);

        update_position(&earth, DELTA_T);
        update_position(&moon, DELTA_T);

        printf("earth: x=%.2f y=%.2f z=%.2f vx=%.2f vy=%.2f vz=%.2f\n",
               earth.position.x, earth.position.y, earth.position.z,
               earth.velocity.x, earth.velocity.y, earth.velocity.z);
        printf("moon: x=%.2f y=%.2f z=%.2f vx=%.2f vy=%.2f vz=%.2f\n",
               moon.position.x, moon.position.y, moon.position.z,
               moon.velocity.x, moon.velocity.y, moon.velocity.z);
    }

    return 0;
}