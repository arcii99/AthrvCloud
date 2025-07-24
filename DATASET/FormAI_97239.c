//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: single-threaded
#include <stdio.h>
#include <math.h>

#define G 6.67e-11 // gravitational constant

typedef struct {
    double x;
    double y;
} Vector2d;

typedef struct {
    Vector2d pos;
    Vector2d velocity;
    Vector2d force;
    double mass;
} Body;

// add force from body1 to body2
void addForce(Body* body1, Body* body2) {
    double distance = sqrt(pow((body2->pos.x - body1->pos.x), 2) + pow((body2->pos.y - body1->pos.y), 2));
    double force = (G * body1->mass * body2->mass) / pow(distance, 2);
    body2->force.x -= force * (body2->pos.x - body1->pos.x) / distance;
    body2->force.y -= force * (body2->pos.y - body1->pos.y) / distance;
}

// update position and velocity of a body based on time interval and total force
void updateBody(Body* body, double timeInterval) {
    double accelerationX = body->force.x / body->mass;
    double accelerationY = body->force.y / body->mass;
    body->velocity.x += accelerationX * timeInterval;
    body->velocity.y += accelerationY * timeInterval;
    body->pos.x += body->velocity.x * timeInterval;
    body->pos.y += body->velocity.y * timeInterval;
    body->force.x = 0;
    body->force.y = 0;
}

int main() {
    int numBodies = 5;
    double timeInterval = 0.01;
    int numSteps = 5000;

    Body bodies[numBodies];

    bodies[0] = (Body) {
        .pos = {0, 0},
        .velocity = {0, 0},
        .force = {0, 0},
        .mass = 1.989e30 // mass of the sun
    };

    bodies[1] = (Body) {
        .pos = {1.496e11, 0},
        .velocity = {0, 29783}, // velocity of the earth
        .force = {0, 0},
        .mass = 5.972e24 // mass of the earth
    };

    bodies[2] = (Body) {
        .pos = {2.279e11, 0},
        .velocity = {0, 24130}, // velocity of mars
        .force = {0, 0},
        .mass = 6.39e23 // mass of mars
    };

    bodies[3] = (Body) {
        .pos = {0, 7.781e11},
        .velocity = {12400, 0}, // velocity of jupiter
        .force = {0, 0},
        .mass = 1.898e27 // mass of jupiter
    };

    bodies[4] = (Body) {
        .pos = {0, 1.427e12},
        .velocity = {10400, 0}, // velocity of saturn
        .force = {0, 0},
        .mass = 5.683e26 // mass of saturn
    };

    // simulate the motion of the bodies
    for (int step = 0; step < numSteps; step++) {
        // calculate forces between all pairs of bodies
        for (int i = 0; i < numBodies; i++) {
            for (int j = i + 1; j < numBodies; j++) {
                addForce(&bodies[i], &bodies[j]);
                addForce(&bodies[j], &bodies[i]);
            }
        }

        // update positions and velocities of all bodies
        for (int i = 0; i < numBodies; i++) {
            updateBody(&bodies[i], timeInterval);
        }

        // print positions of all bodies
        for (int i = 0; i < numBodies; i++) {
            printf("%e\t%e\t", bodies[i].pos.x, bodies[i].pos.y);
        }
        printf("\n");
    }

    return 0;
}