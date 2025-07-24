//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: systematic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define G 6.67430e-11 //Gravitational constant

typedef struct {
    double x, y;
} Vector;

typedef struct {
    double mass;
    Vector position;
    Vector velocity;
} Body;

Body sun = {
        .mass = 1.9885e30,
        .position = {.x = 0, .y = 0},
        .velocity = {.x = 0, .y = 0}
}; //initialize the sun as a global Body

Body planets[] = {
        {
                .mass = 3.3011e23,
                .position = {.x = 0 , .y = 5.79e10},
                .velocity = {.x = -47000, .y = 0}
        },
        {
                .mass = 4.8675e24,
                .position = {.x = 0, .y = 1.082e11},
                .velocity = {.x = -35000, .y = 0}
        },
        {
                .mass = 5.9722e24,
                .position = {.x = 0, .y = 1.496e11},
                .velocity = {.x = -30000, .y = 0}
        },
        {
                .mass = 6.4171e23,
                .position = {.x = 0, .y = 2.279e11},
                .velocity = {.x = -24000, .y = 0}
        }
}; //initialize planets as an array of Bodies

const int numPlanets = sizeof(planets) / sizeof(Body); //calculate number of planets

Vector calculateForce(Body b, Body a) {
    double distance = sqrt(pow(b.position.x - a.position.x, 2) + pow(b.position.y - a.position.y, 2));
    double force = (G * a.mass * b.mass) / pow(distance, 2);
    Vector direction = {.x = (a.position.x - b.position.x) / distance, .y = (a.position.y - b.position.y) / distance};
    return (Vector) {.x = force * direction.x, .y = force * direction.y};
}//helper function to calculate gravitational force between two bodies

void updateVelocity(Body *bodies, double timeStep) {
    for (int i = 0; i < numPlanets; i++) {
        Vector force = {.x = 0, .y = 0};
        for (int j = 0; j < numPlanets; j++) {
            if (i != j) {
                force.x += calculateForce(bodies[i], bodies[j]).x;
                force.y += calculateForce(bodies[i], bodies[j]).y;
            }
        }
        bodies[i].velocity.x += force.x * timeStep / bodies[i].mass;
        bodies[i].velocity.y += force.y * timeStep / bodies[i].mass;
    }
}//function to update the velocity of each planet based on gravitational forces

void updatePosition(Body *bodies, double timeStep) {
    for (int i = 0; i < numPlanets; i++) {
        bodies[i].position.x += bodies[i].velocity.x * timeStep;
        bodies[i].position.y += bodies[i].velocity.y * timeStep;
    }
}//function to update the position of each planet based on their velocities

void printBody(Body body) {
    printf("Mass: %g\n", body.mass);
    printf("Position: (%g, %g)\n", body.position.x, body.position.y);
    printf("Velocity: (%g, %g)\n", body.velocity.x, body.velocity.y);
}//helper function to print a Body object

void printSystem(Body *bodies) {
    for (int i = 0; i < numPlanets; i++) {
        printf("Body %d:\n", i+1);
        printBody(bodies[i]);
        printf("\n");
    }
}//function to print the entire Solar System

int main() {
    double timeStep = 60; //time step in seconds
    int numTimeSteps = 365 * 24 * 60 * 60 / timeStep; //one year's worth of time steps
    printf("Initial Solar System:\n\n");
    printSystem(planets);
    printf("Simulating Solar System for %d time steps...\n\n", numTimeSteps);
    for (int i = 0; i < numTimeSteps; i++) {
        updateVelocity(planets, timeStep);
        updatePosition(planets, timeStep);
    }
    printf("Final Solar System:\n\n");
    printSystem(planets);
    return 0;
}