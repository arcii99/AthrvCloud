//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_PLANETS 5 // Number of planets to simulate
#define MAX_X 100 // Maximum X coordinate of the simulation space 
#define MAX_Y 100 // Maximum Y coordinate of the simulation space 
#define MAX_MASS 2000 // Maximum mass of a planet
#define MIN_MASS 100 // Minimum mass of a planet
#define GRAVITY_CONST 6.674e-11 // Gravitational constant

struct Vector {
    double x;
    double y;
};

struct Planet {
    int id;
    struct Vector pos;
    double mass;
    struct Vector velocity;
};

struct Planet planets[NUM_OF_PLANETS];

void initializePlanets() {
    int i;
    srand(time(NULL));
    for(i = 0; i < NUM_OF_PLANETS; i++) {
        planets[i].id = i;
        planets[i].pos.x = rand() % MAX_X;
        planets[i].pos.y = rand() % MAX_Y;
        planets[i].mass = (rand() % (MAX_MASS - MIN_MASS + 1)) + MIN_MASS;
        planets[i].velocity.x = 0;
        planets[i].velocity.y = 0;
    }
}

void updatePosition(struct Planet* planet, double timeStep) {
    planet->pos.x += planet->velocity.x * timeStep;
    planet->pos.y += planet->velocity.y * timeStep;
}

void updateVelocity(struct Planet* selectedPlanet, struct Planet otherPlanet, double timeStep) {
    double distance = sqrt(pow(selectedPlanet->pos.x - otherPlanet.pos.x, 2) + pow(selectedPlanet->pos.y - otherPlanet.pos.y, 2));
    double magnitude = GRAVITY_CONST * selectedPlanet->mass * otherPlanet.mass / pow(distance, 2);
    struct Vector direction;
    direction.x = (otherPlanet.pos.x - selectedPlanet->pos.x) / distance;
    direction.y = (otherPlanet.pos.y - selectedPlanet->pos.y) / distance;
    struct Vector acceleration;
    acceleration.x = direction.x * magnitude / selectedPlanet->mass;
    acceleration.y = direction.y * magnitude / selectedPlanet->mass;
    selectedPlanet->velocity.x += acceleration.x * timeStep;
    selectedPlanet->velocity.y += acceleration.y * timeStep;
}

void simulate(double timeStep, double duration) {
    int i, j;
    for(i = 0; i < NUM_OF_PLANETS; i++) {
        for(j = 0; j < NUM_OF_PLANETS; j++) {
            if(i != j) {
                updateVelocity(&planets[i], planets[j], timeStep);
            }
        }
    }
    for(i = 0; i < NUM_OF_PLANETS; i++) {
        updatePosition(&planets[i], timeStep);
    }
}

void printPlanets() {
    int i;
    for(i = 0; i < NUM_OF_PLANETS; i++) {
        printf("Planet %d: (%lf, %lf)\n", planets[i].id, planets[i].pos.x, planets[i].pos.y);
    }
}

int main() {
    double timeStep = 0.001;
    double duration = 10;
    initializePlanets();
    int t;
    for(t = 0; t < duration / timeStep; t++) {
        simulate(timeStep, duration);
    }
    printPlanets();
    return 0;
}