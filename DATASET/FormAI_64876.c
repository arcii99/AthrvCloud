//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: cheerful
#include <stdio.h>
#include <math.h>

#define GRAVITY 6.67e-11

typedef struct {
    double x, y;
} Vector2D;

typedef struct {
    double mass;
    Vector2D position, velocity, acceleration;
} Planet;

Vector2D getAcceleration(Planet planet, Planet* planets, int numPlanets) {
    Vector2D acceleration = {0, 0};
    for(int i = 0; i < numPlanets; i++) {
        if(&planet == &planets[i]) continue;
        Vector2D distance = {planets[i].position.x - planet.position.x, planets[i].position.y - planet.position.y};
        double magnitude = sqrt(distance.x*distance.x + distance.y*distance.y);
        double force = GRAVITY * planet.mass * planets[i].mass / (magnitude * magnitude);
        acceleration.x += force * distance.x / magnitude / planet.mass;
        acceleration.y += force * distance.y / magnitude / planet.mass;
    }
    return acceleration;
}

void updatePlanet(Planet* planet, Planet* planets, int numPlanets, double timeStep) {
    planet->acceleration = getAcceleration(*planet, planets, numPlanets);
    planet->velocity.x += planet->acceleration.x * timeStep;
    planet->velocity.y += planet->acceleration.y * timeStep;
    planet->position.x += planet->velocity.x * timeStep;
    planet->position.y += planet->velocity.y * timeStep;
}

int main() {
    Planet planets[] = {
        {6e24, {-6.4e6, 0}, {0, -7.5e3}, {0, 0}},
        {7.35e22, {3.84e8, 0}, {0, 1e3}, {0, 0}}
    };
    int numPlanets = sizeof(planets) / sizeof(Planet);
    double timeStep = 1;
    int numTimeSteps = 1000;
    for(int i = 0; i < numTimeSteps; i++) {
        for(int j = 0; j < numPlanets; j++) {
            updatePlanet(&planets[j], planets, numPlanets, timeStep);
        }
        printf("Time: %d seconds\n", i);
        for(int j = 0; j < numPlanets; j++) {
            printf("Planet %d - x:%.2f y:%.2f\n", j, planets[j].position.x, planets[j].position.y);
        }
    }
    return 0;
}