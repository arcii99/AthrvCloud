//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11 // gravitational constant

struct Vector {
    double x;
    double y;
    double z;
};

struct Body {
    struct Vector position;
    struct Vector velocity;
    struct Vector acceleration;
    double mass;
};

// function to calculate gravitational force between two bodies
void calculateForce(struct Body *body1, struct Body *body2) {
    double distance = sqrt(pow(body1->position.x - body2->position.x, 2) + 
                           pow(body1->position.y - body2->position.y, 2) + 
                           pow(body1->position.z - body2->position.z, 2)); 
    
    double force = (G * body1->mass * body2->mass) / pow(distance, 2);
    
    // calculate the components of the force vector
    double fx = force * (body2->position.x - body1->position.x) / distance;
    double fy = force * (body2->position.y - body1->position.y) / distance;
    double fz = force * (body2->position.z - body1->position.z) / distance;
    
    // update the acceleration vectors of both bodies
    body1->acceleration.x += fx / body1->mass;
    body1->acceleration.y += fy / body1->mass;
    body1->acceleration.z += fz / body1->mass;
    
    body2->acceleration.x -= fx / body2->mass;
    body2->acceleration.y -= fy / body2->mass;
    body2->acceleration.z -= fz / body2->mass;
}

// function to update the position and velocity of a body based on its acceleration
void updateBody(struct Body *body, double timeStep) {
    // update velocity
    body->velocity.x += body->acceleration.x * timeStep;
    body->velocity.y += body->acceleration.y * timeStep;
    body->velocity.z += body->acceleration.z * timeStep;
    
    // update position
    body->position.x += body->velocity.x * timeStep;
    body->position.y += body->velocity.y * timeStep;
    body->position.z += body->velocity.z * timeStep;
    
    // reset acceleration for next iteration
    body->acceleration.x = 0;
    body->acceleration.y = 0;
    body->acceleration.z = 0;
}

int main() {
    // initialize bodies
    struct Body sun = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 1.989e30}; // mass of the Sun
    struct Body earth = {{-147.09e9, 0, 0}, {0, 30.29e3, 0}, {0, 0, 0}, 5.972e24}; // mass of the Earth
    struct Body moon = {{-147.1e9, 0, 0}, {0, 30.29e3 + 1.022e3, 0}, {0, 0, 0}, 7.342e22}; // mass of the Moon
    
    // simulation parameters
    double timeStep = 60 * 60 * 24; // 1 day in seconds
    double simulationTime = 365.25 * 24 * 60 * 60; // 1 year in seconds
    
    // run simulation
    for (double t = 0; t < simulationTime; t += timeStep) {
        // calculate gravitational force between bodies
        calculateForce(&sun, &earth);
        calculateForce(&sun, &moon);
        calculateForce(&earth, &moon);
        
        // update positions and velocities
        updateBody(&sun, timeStep);
        updateBody(&earth, timeStep);
        updateBody(&moon, timeStep);
        
        // output positions of the bodies
        printf("Sun: (%f, %f, %f)\n", sun.position.x, sun.position.y, sun.position.z);
        printf("Earth: (%f, %f, %f)\n", earth.position.x, earth.position.y, earth.position.z);
        printf("Moon: (%f, %f, %f)\n", moon.position.x, moon.position.y, moon.position.z);
    }
    
    return 0;
}