//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

#define G 6.674e-11     // gravitational constant
#define MASS_EARTH 5.972e24     // mass of the Earth
#define RADIUS_EARTH 6.371e6    // radius of the Earth

typedef struct {
    double x;
    double y;
    double z;
} Vector3;

typedef struct {
    Vector3 pos;
    Vector3 vel;
    double mass;
} CelestialBody;

void updateVelocity(CelestialBody *body, Vector3 force, double timeStep) {
    double accelerationMag = sqrt(pow(force.x / body->mass, 2) + pow(force.y / body->mass, 2) + pow(force.z / body->mass, 2));
    Vector3 acceleration = {
        force.x / body->mass,
        force.y / body->mass,
        force.z / body->mass
    };
    body->vel.x += acceleration.x * timeStep;
    body->vel.y += acceleration.y * timeStep;
    body->vel.z += acceleration.z * timeStep;
}

void updatePosition(CelestialBody *body, double timeStep) {
    body->pos.x += body->vel.x * timeStep;
    body->pos.y += body->vel.y * timeStep;
    body->pos.z += body->vel.z * timeStep;
}

Vector3 calculateGravity(CelestialBody *body1, CelestialBody *body2) {
    double distanceMag = sqrt(pow(body1->pos.x - body2->pos.x, 2) + pow(body1->pos.y - body2->pos.y, 2) + pow(body1->pos.z - body2->pos.z, 2));
    Vector3 distance = {
        body2->pos.x - body1->pos.x,
        body2->pos.y - body1->pos.y,
        body2->pos.z - body1->pos.z
    };
    double forceMag = G * body1->mass * body2->mass / pow(distanceMag, 2);
    Vector3 force = {
        forceMag * distance.x / distanceMag,
        forceMag * distance.y / distanceMag,
        forceMag * distance.z / distanceMag
    };
    return force;
}

int main(void) {
    CelestialBody earth = {
        { 0, 0, 0 },
        { 0, 0, 0 },
        MASS_EARTH
    };
    CelestialBody moon = {
        { 384400000, 0, 0 },
        { 0, 1022, 0 },
        7.342e22
    };
    double timeStep = 1.0;  // time step in seconds
    int numSteps = 86400;   // number of steps in one day
    for (int i = 0; i < numSteps; i++) {
        Vector3 gravityForce = calculateGravity(&earth, &moon);
        updateVelocity(&moon, gravityForce, timeStep);
        updatePosition(&moon, timeStep);
        printf("%.2f\t%.2f\t%.2f\n", moon.pos.x, moon.pos.y, moon.pos.z);
    }
    return 0;
}