//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: systematic
#include <stdio.h>
#include <math.h>
#define GRAVITATIONAL_CONSTANT 6.674 * pow(10, -11)

typedef struct {
    double x, y;
} Vector2;

typedef struct {
    Vector2 position;
    Vector2 velocity;
    double mass;
} Body;

int main() {
    Body planetA, planetB;

    planetA.mass = 5.972 * pow(10, 24);
    planetA.position.x = 0;
    planetA.position.y = 0;
    planetA.velocity.x = 0;
    planetA.velocity.y = 0;

    planetB.mass = 6.39 * pow(10, 23);
    planetB.position.x = 3.84 * pow(10, 8);
    planetB.position.y = 0;
    planetB.velocity.x = 0;
    planetB.velocity.y = 1022;

    double timeStep = 10;
    double timeElapsed = 0;

    while (timeElapsed < 86400 * 365) {
        Vector2 distanceVector;
        double distance;
        double accelerationA, accelerationB;
        Vector2 direction;

        distanceVector.x = planetB.position.x - planetA.position.x;
        distanceVector.y = planetB.position.y - planetA.position.y;
        distance = sqrt(pow(distanceVector.x, 2) + pow(distanceVector.y, 2));
        direction.x = distanceVector.x / distance;
        direction.y = distanceVector.y / distance;

        accelerationA = (GRAVITATIONAL_CONSTANT * planetB.mass) / pow(distance, 2);
        accelerationB = (GRAVITATIONAL_CONSTANT * planetA.mass) / pow(distance, 2);

        planetA.velocity.x += accelerationA * direction.x * timeStep;
        planetA.velocity.y += accelerationA * direction.y * timeStep;
        planetB.velocity.x -= accelerationB * direction.x * timeStep;
        planetB.velocity.y -= accelerationB * direction.y * timeStep;

        planetA.position.x += planetA.velocity.x * timeStep;
        planetA.position.y += planetA.velocity.y * timeStep;
        planetB.position.x += planetB.velocity.x * timeStep;
        planetB.position.y += planetB.velocity.y * timeStep;

        timeElapsed += timeStep;
    }

    printf("Position of Planet A after one year: (%lf, %lf)\n", planetA.position.x, planetA.position.y);
    printf("Position of Planet B after one year: (%lf, %lf)\n", planetB.position.x, planetB.position.y);

    return 0;
}