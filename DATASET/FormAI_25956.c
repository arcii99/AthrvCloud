//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: authentic
#include <stdio.h>
#include <math.h>

#define G_CONSTANT 6.67430e-11 // Universal Gravitational Constant
#define TIME_STEP 86400.0 // Time step (in seconds)

struct Vector3D {
    double x;
    double y;
    double z;
};

struct CelestialObject {
    char name[20];
    double mass; // Mass in kilograms
    double radius; // Radius in meters
    struct Vector3D position;
    struct Vector3D velocity;
    struct Vector3D force;
};

void calculate_force(struct CelestialObject *body1, struct CelestialObject *body2) {
    double dx = body2->position.x - body1->position.x;
    double dy = body2->position.y - body1->position.y;
    double dz = body2->position.z - body1->position.z;
    double distance = sqrt(pow(dx, 2) + pow(dy, 2) + pow(dz, 2));
    double force_mag = (G_CONSTANT * body1->mass * body2->mass) / pow(distance, 2);
    body1->force.x += force_mag * dx / distance;
    body1->force.y += force_mag * dy / distance;
    body1->force.z += force_mag * dz / distance;
}

void update_velocity(struct CelestialObject *body) {
    double acceleration_x = body->force.x / body->mass;
    double acceleration_y = body->force.y / body->mass;
    double acceleration_z = body->force.z / body->mass;
    body->velocity.x += acceleration_x * TIME_STEP;
    body->velocity.y += acceleration_y * TIME_STEP;
    body->velocity.z += acceleration_z * TIME_STEP;
}

void update_position(struct CelestialObject *body) {
    body->position.x += body->velocity.x * TIME_STEP;
    body->position.y += body->velocity.y * TIME_STEP;
    body->position.z += body->velocity.z * TIME_STEP;
}

int main() {
    struct CelestialObject earth = {"Earth", 5.972e24, 6.371e6,
                                    {0.0, 0.0, 0.0},
                                    {0.0, 0.0, 0.0},
                                    {0.0, 0.0, 0.0}};
    struct CelestialObject moon = {"Moon", 7.342e22, 1.737e6,
                                   {3.844e8, 0.0, 0.0},
                                   {0.0, 1022.0, 0.0},
                                   {0.0, 0.0, 0.0}};
    double time = 0.0;
    double end_time = 365.25 * 24 * 60 * 60; // One year in seconds
    while (time < end_time) {
        // Calculate forces
        earth.force.x = 0.0;
        earth.force.y = 0.0;
        earth.force.z = 0.0;
        calculate_force(&earth, &moon);
        calculate_force(&moon, &earth);
        // Update velocities
        update_velocity(&earth);
        update_velocity(&moon);
        // Update positions
        update_position(&earth);
        update_position(&moon);
        // Print positions
        printf("Time: %.0f seconds\n", time);
        printf("%s position: (%.0f, %.0f, %.0f) meters\n", earth.name, earth.position.x, earth.position.y, earth.position.z);
        printf("%s position: (%.0f, %.0f, %.0f) meters\n\n", moon.name, moon.position.x, moon.position.y, moon.position.z);
        // Increment time
        time += TIME_STEP;
    }
    return 0;
}