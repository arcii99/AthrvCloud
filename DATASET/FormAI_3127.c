//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11 // gravitational constant

typedef struct {
    double x;
    double y;
    double z;
} Vector3D;

typedef struct {
    Vector3D position;
    Vector3D velocity;
    double mass;
} Body;

void update_velocity(Body * body, Vector3D acceleration, double time_step) {
    body->velocity.x += acceleration.x * time_step;
    body->velocity.y += acceleration.y * time_step;
    body->velocity.z += acceleration.z * time_step;
}

void update_position(Body * body, double time_step) {
    body->position.x += body->velocity.x * time_step;
    body->position.y += body->velocity.y * time_step;
    body->position.z += body->velocity.z * time_step;
}

Vector3D calculate_acceleration(Body * body, Body * other_body) {
    double distance = sqrt(pow(body->position.x - other_body->position.x, 2) + pow(body->position.y - other_body->position.y, 2) + pow(body->position.z - other_body->position.z, 2));
    double force = G * body->mass * other_body->mass / pow(distance, 2);
    Vector3D unit_vector;
    unit_vector.x = (other_body->position.x - body->position.x) / distance;
    unit_vector.y = (other_body->position.y - body->position.y) / distance;
    unit_vector.z = (other_body->position.z - body->position.z) / distance;
    Vector3D acceleration;
    acceleration.x = force / body->mass * unit_vector.x;
    acceleration.y = force / body->mass * unit_vector.y;
    acceleration.z = force / body->mass * unit_vector.z;
    return acceleration;
}

int main() {
    Body sun = { {0, 0, 0}, {0, 0, 0}, 1.989e30 };
    Body earth = { {1.496e11, 0, 0}, {0, 2.978e4, 0}, 5.972e24 };
    Body moon = { {1.496e11 + 3.844e8, 0, 0}, {0, 2.978e4 + 1.022e3, 0}, 7.342e22 };
    double time_step = 1.0; // seconds
    int num_steps = 365 * 24 * 3600 / time_step;
    for (int i = 0; i < num_steps; i++) {
        Vector3D sun_earth_acceleration = calculate_acceleration(&sun, &earth);
        Vector3D sun_moon_acceleration = calculate_acceleration(&sun, &moon);
        Vector3D earth_sun_acceleration = calculate_acceleration(&earth, &sun);
        Vector3D earth_moon_acceleration = calculate_acceleration(&earth, &moon);
        Vector3D moon_sun_acceleration = calculate_acceleration(&moon, &sun);
        Vector3D moon_earth_acceleration = calculate_acceleration(&moon, &earth);
        update_velocity(&sun, sun_earth_acceleration, time_step);
        update_velocity(&sun, sun_moon_acceleration, time_step);
        update_velocity(&earth, earth_sun_acceleration, time_step);
        update_velocity(&earth, earth_moon_acceleration, time_step);
        update_velocity(&moon, moon_sun_acceleration, time_step);
        update_velocity(&moon, moon_earth_acceleration, time_step);
        update_position(&sun, time_step);
        update_position(&earth, time_step);
        update_position(&moon, time_step);
        printf("Step %d:\n", i+1);
        printf("Sun: (%lf, %lf, %lf)\n", sun.position.x, sun.position.y, sun.position.z);
        printf("Earth: (%lf, %lf, %lf)\n", earth.position.x, earth.position.y, earth.position.z);
        printf("Moon: (%lf, %lf, %lf)\n", moon.position.x, moon.position.y, moon.position.z);
    }
    return 0;
}