//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11 // Universal gravitational constant

typedef struct Vector3D {
    double x;
    double y;
    double z;
} Vector3D;

typedef struct Planet {
    char name[20];
    double mass;
    Vector3D position;
    Vector3D velocity;
    Vector3D acceleration;
} Planet;

Vector3D calculateGravity(Planet a, Planet b) {
    Vector3D direction;
    direction.x = b.position.x - a.position.x;
    direction.y = b.position.y - a.position.y;
    direction.z = b.position.z - a.position.z;

    double distance = sqrt(pow(direction.x, 2) + pow(direction.y, 2) + pow(direction.z, 2));
    double factor = G * a.mass * b.mass / pow(distance, 3);

    Vector3D gravity;
    gravity.x = factor * direction.x;
    gravity.y = factor * direction.y;
    gravity.z = factor * direction.z;
    return gravity;
}

void updatePlanet(Planet* planet, double timeStep) {
    planet->velocity.x += planet->acceleration.x * timeStep;
    planet->velocity.y += planet->acceleration.y * timeStep;
    planet->velocity.z += planet->acceleration.z * timeStep;

    planet->position.x += planet->velocity.x * timeStep;
    planet->position.y += planet->velocity.y * timeStep;
    planet->position.z += planet->velocity.z * timeStep;
}

int main() {
    Planet sun = {"Sun", 1.9885e30, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    Planet earth = {"Earth", 5.9736e24, {147e9, 0, 0}, {0, 30300, 0}, {0, 0, 0}};

    double timeStep = 86400; // 1 day in seconds

    for (int i = 0; i < 365 * 10; i++) { // 10 years
        Vector3D force = calculateGravity(sun, earth);
        earth.acceleration.x = force.x / earth.mass;
        earth.acceleration.y = force.y / earth.mass;
        earth.acceleration.z = force.z / earth.mass;

        updatePlanet(&earth, timeStep);

        printf("%s (x,y,z) = (%f,%f,%f)\n", earth.name, earth.position.x, earth.position.y, earth.position.z);
    }

    return 0;
}