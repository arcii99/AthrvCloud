//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674 * pow(10, -11) // Gravitational Constant
#define MASS_EARTH 5.972 * pow(10, 24) // Mass of Earth
#define MASS_SUN 1.989 * pow(10, 30) // Mass of Sun
#define DIST_EARTH_SUN 149.6 * pow(10, 9) // Distance between Earth and Sun
#define PI 3.14159265358979323846 // Value of PI

typedef struct {
    double x; // x coordinate
    double y; // y coordinate
} Vector2D;

typedef struct {
    Vector2D position; // Position of celestial body
    Vector2D velocity; // Velocity of celestial body
    double mass; // Mass of celestial body
} CelestialBody;

void computeForce(Vector2D* force, CelestialBody* currentBody, CelestialBody* otherBody) {
    Vector2D direction;
    double distance, magnitude;
    direction.x = otherBody->position.x - currentBody->position.x;
    direction.y = otherBody->position.y - currentBody->position.y;
    distance = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
    magnitude = G * currentBody->mass * otherBody->mass / pow(distance, 2);
    force->x = magnitude * direction.x / distance;
    force->y = magnitude * direction.y / distance;
}

void updatePositionVelocity(CelestialBody* body, Vector2D* force, double timeStep) {
    Vector2D acceleration;
    acceleration.x = force->x / body->mass;
    acceleration.y = force->y / body->mass;
    body->velocity.x += acceleration.x * timeStep;
    body->velocity.y += acceleration.y * timeStep;
    body->position.x += body->velocity.x * timeStep;
    body->position.y += body->velocity.y * timeStep;
}

int main() {
    CelestialBody sun = {{0, 0}, {0, 0}, MASS_SUN}; // Sun
    CelestialBody earth = {{DIST_EARTH_SUN, 0}, {0, 29.78 * pow(10, 3)}, MASS_EARTH}; // Earth
    CelestialBody moon = {{DIST_EARTH_SUN + 385000000, 0}, {0, 1022}, 7.342 * pow(10, 22)}; // Moon
    double timeStep = 60 * 60 * 24; // 1 day in seconds
    int numSteps = 365 * 5; // 5 years
    Vector2D forceEarth, forceMoon;

    for (int i = 0; i < numSteps; i++) {
        computeForce(&forceEarth, &earth, &sun);
        computeForce(&forceMoon, &moon, &earth);
        updatePositionVelocity(&earth, &forceEarth, timeStep);
        updatePositionVelocity(&moon, &forceMoon, timeStep);
        printf("Day: %d, Earth: (%e, %e), Moon: (%e, %e)\n", i + 1, earth.position.x, earth.position.y, moon.position.x, moon.position.y);
    }

    return 0;
}