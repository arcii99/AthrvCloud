//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_PLANETS 10 // Maximum number of planets
#define GRAVITY 6.67430e-11 // Gravitational constant

typedef struct {
    double x;
    double y;
} Vector2D; // Vector2D struct

typedef struct {
    char name[20];
    double mass;
    double radius;
    Vector2D position;
    Vector2D velocity;
} Planet; // Planet struct

void setPlanet(Planet *planet, char name[20], double mass, double radius, double x, double y, double vx, double vy) {
    // Set planet properties
    planet->mass = mass;
    planet->radius = radius;
    planet->position.x = x;
    planet->position.y = y;
    planet->velocity.x = vx;
    planet->velocity.y = vy;
    strncpy(planet->name, name, sizeof(planet->name));
}

Vector2D calculateGravity(Planet *planet1, Planet *planet2) {
    // Calculate gravity vector
    double distance = sqrt(pow((planet2->position.x - planet1->position.x), 2) + pow((planet2->position.y - planet1->position.y), 2));
    double force = GRAVITY * ((planet1->mass * planet2->mass) / pow(distance, 2));
    Vector2D direction = {(planet2->position.x - planet1->position.x) / distance, (planet2->position.y - planet1->position.y) / distance};
    return (Vector2D) {force * direction.x, force * direction.y};
}

void simulatePlanets(Planet *planets, int numPlanets, double dt) {
    // Simulate planets for one time step
    Vector2D forces[numPlanets];
    for (int i = 0; i < numPlanets; i++) {
        Vector2D totalForce = {0.0, 0.0};
        for (int j = 0; j < numPlanets; j++) {
            if (i != j) {
                Vector2D gravity = calculateGravity(&planets[i], &planets[j]);
                totalForce.x += gravity.x;
                totalForce.y += gravity.y;
            }
        }
        forces[i] = totalForce;
    }
    for (int i = 0; i < numPlanets; i++) {
        Vector2D acceleration = {forces[i].x / planets[i].mass, forces[i].y / planets[i].mass};
        planets[i].velocity.x += acceleration.x * dt;
        planets[i].velocity.y += acceleration.y * dt;
        planets[i].position.x += planets[i].velocity.x * dt;
        planets[i].position.y += planets[i].velocity.y * dt;
    }
}

void printPlanet(Planet *planet) {
    // Print planet properties
    printf("Planet %s:\n", planet->name);
    printf("Mass: %f kg\n", planet->mass);
    printf("Radius: %f m\n", planet->radius);
    printf("Position: (%f, %f) m\n", planet->position.x, planet->position.y);
    printf("Velocity: (%f, %f) m/s\n", planet->velocity.x, planet->velocity.y);
}

int main() {
    srand(time(0));
    Planet planets[MAX_PLANETS];
    int numPlanets = 3;
    setPlanet(&planets[0], "Earth", 5.972e24, 6.371e6, 0.0, 0.0, 0.0, 0.0);
    setPlanet(&planets[1], "Mars", 6.39e23, 3.39e6, 2.067e11, 0.0, 0.0, 24000.0);
    setPlanet(&planets[2], "Jupiter", 1.898e27, 6.9911e7, 7.78e11, 0.0, 0.0, 13000.0);
    double dt = 3600;
    int numSteps = 1000;
    for (int step = 0; step < numSteps; step++) {
        printf("Step %d:\n", step);
        for (int i = 0; i < numPlanets; i++) {
            printPlanet(&planets[i]);
        }
        simulatePlanets(planets, numPlanets, dt);
    }
    return 0;
}