//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 9.81

typedef struct {
    double x;
    double y;
} Vector2D;

typedef struct {
    Vector2D position;
    Vector2D velocity;
    double mass;
} Planet;

Vector2D calculateGravitationalForce(Planet planet1, Planet planet2) {
    double distance = sqrt(pow((planet1.position.x - planet2.position.x), 2) + pow((planet1.position.y - planet2.position.y), 2));
    double force = G * ((planet1.mass * planet2.mass) / pow(distance, 2));
    Vector2D forceVector;
    forceVector.x = force * ((planet2.position.x - planet1.position.x) / distance);
    forceVector.y = force * ((planet2.position.y - planet1.position.y) / distance);
    return forceVector;
}

void updatePosition(Planet *planet, double timeStep) {
    planet->position.x += planet->velocity.x * timeStep;
    planet->position.y += planet->velocity.y * timeStep;
}

void updateVelocity(Planet *planet, Vector2D acceleration, double timeStep) {
    planet->velocity.x += acceleration.x * timeStep;
    planet->velocity.y += acceleration.y * timeStep;
}

void simulateGravity(Planet *planets, int numPlanets, double timeStep, int numSteps) {
    int i, j, step;
    Vector2D totalAcceleration, force;
    for(step = 0; step < numSteps; step++) {
        for(i = 0; i < numPlanets; i++) {
            totalAcceleration.x = 0;
            totalAcceleration.y = 0;
            for(j = 0; j < numPlanets; j++) {
                if(i != j) {
                    force = calculateGravitationalForce(planets[i], planets[j]);
                    totalAcceleration.x += force.x / planets[i].mass;
                    totalAcceleration.y += force.y / planets[i].mass;
                }
            }
            updateVelocity(&planets[i], totalAcceleration, timeStep);
            updatePosition(&planets[i], timeStep);
        }
    }
}

int main() {
    int numPlanets = 2, numSteps = 1000, i;
    double timeStep = 0.01;

    Planet planets[2] = {
        {.position = {0, 0}, .velocity = {0, 0}, .mass = 10000},
        {.position = {0, 100}, .velocity = {10, 0}, .mass = 1}
    };

    simulateGravity(planets, numPlanets, timeStep, numSteps);

    for(i = 0; i < numPlanets; i++) {
        printf("Planet %d: x = %f, y = %f\n", i, planets[i].position.x, planets[i].position.y);
    }

    return 0;
}