//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: futuristic
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define G_CONST 6.67430e-11

typedef struct Vector {
    double x;
    double y;
    double z;
} Vector;

typedef struct Body {
    char name[50];
    double mass;
    Vector position;
    Vector velocity;
    Vector acceleration;
} Body;

void update_acceleration(Body *body, Body *other_body, double distance) {
    double magnitude = G_CONST * other_body->mass / pow(distance, 2);
    Vector direction;
    direction.x = (other_body->position.x - body->position.x) / distance;
    direction.y = (other_body->position.y - body->position.y) / distance;
    direction.z = (other_body->position.z - body->position.z) / distance;
    body->acceleration.x += magnitude * direction.x;
    body->acceleration.y += magnitude * direction.y;
    body->acceleration.z += magnitude * direction.z;
}

void update_velocity(Body *body, double time_step) {
    body->velocity.x += body->acceleration.x * time_step;
    body->velocity.y += body->acceleration.y * time_step;
    body->velocity.z += body->acceleration.z * time_step;
}

void update_position(Body *body, double time_step) {
    body->position.x += body->velocity.x * time_step;
    body->position.y += body->velocity.y * time_step;
    body->position.z += body->velocity.z * time_step;
}

int main() {
    Body planet_c;
    strcpy(planet_c.name, "Planet C");
    planet_c.mass = 6.39e23;
    planet_c.position.x = 0;
    planet_c.position.y = 0;
    planet_c.position.z = 0;
    planet_c.velocity.x = 0;
    planet_c.velocity.y = 0;
    planet_c.velocity.z = 0;
    planet_c.acceleration.x = 0;
    planet_c.acceleration.y = 0;
    planet_c.acceleration.z = 0;

    Body sun;
    strcpy(sun.name, "Sun");
    sun.mass = 1.99e30;
    sun.position.x = 1.496e11;
    sun.position.y = 0;
    sun.position.z = 0;
    sun.velocity.x = 0;
    sun.velocity.y = 29783;
    sun.velocity.z = 0;
    sun.acceleration.x = 0;
    sun.acceleration.y = 0;
    sun.acceleration.z = 0;

    double time_step = 86400;
    double simulation_length = 365 * time_step;

    for (double i = 0; i < simulation_length; i += time_step) {
        double distance = sqrt(pow(sun.position.x - planet_c.position.x, 2) + pow(sun.position.y - planet_c.position.y, 2) + pow(sun.position.z - planet_c.position.z, 2));
        update_acceleration(&planet_c, &sun, distance);
        update_velocity(&planet_c, time_step);
        update_position(&planet_c, time_step);
        printf("At time %f:\n", i);
        printf("Planet C is at (%f,%f,%f)\n", planet_c.position.x, planet_c.position.y, planet_c.position.z);
        printf("\n");
    }

    return 0;
}