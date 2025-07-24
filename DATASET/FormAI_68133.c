//FormAI DATASET v1.0 Category: Physics simulation ; Style: scientific
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define GRAV_CONST 6.67430e-11 // gravitational constant in m^3 kg^-1 s^-2

typedef struct {
    double x; // position in meters
    double y;
    double z;
} Vec3;

typedef struct {
    Vec3 pos; // position in meters
    Vec3 vel; // velocity in meters per second
    Vec3 accel; // acceleration in meters per second squared
    double mass; // mass in kilograms
} Body;

// calculate the force of gravity between two bodies
void calcGravity(Body* a, Body* b, Vec3* force) {
    Vec3 distVec;
    distVec.x = b->pos.x - a->pos.x;
    distVec.y = b->pos.y - a->pos.y;
    distVec.z = b->pos.z - a->pos.z;
    double distSquared = pow(distVec.x, 2) + pow(distVec.y, 2) + pow(distVec.z, 2);
    double forceMag = (GRAV_CONST * a->mass * b->mass) / distSquared;
    force->x = forceMag * distVec.x / sqrt(distSquared);
    force->y = forceMag * distVec.y / sqrt(distSquared);
    force->z = forceMag * distVec.z / sqrt(distSquared);
}

// update the velocity and position of a body based on its acceleration
void updateBody(Body* body, double timestep) {
    body->vel.x += body->accel.x * timestep;
    body->vel.y += body->accel.y * timestep;
    body->vel.z += body->accel.z * timestep;
    body->pos.x += body->vel.x * timestep;
    body->pos.y += body->vel.y * timestep;
    body->pos.z += body->vel.z * timestep;
}

int main() {
    int numBodies = 3;
    Body bodies[numBodies];

    // set up initial conditions for the bodies
    bodies[0].mass = 5.97e24; // mass of the Earth
    bodies[0].pos.x = 0;
    bodies[0].pos.y = 0;
    bodies[0].pos.z = 0;
    bodies[0].vel.x = 0;
    bodies[0].vel.y = 0;
    bodies[0].vel.z = 0;
    bodies[1].mass = 7.35e22; // mass of the Moon
    bodies[1].pos.x = 3.84e8;
    bodies[1].pos.y = 0;
    bodies[1].pos.z = 0;
    bodies[1].vel.x = 0;
    bodies[1].vel.y = 1022; // velocity of the Moon around the Earth
    bodies[1].vel.z = 0;
    bodies[2].mass = 10; // arbitrary mass for test purposes
    bodies[2].pos.x = 1e7;
    bodies[2].pos.y = 0;
    bodies[2].pos.z = 0;
    bodies[2].vel.x = 0;
    bodies[2].vel.y = 0;
    bodies[2].vel.z = 0;

    double timestep = 3600; // one hour in seconds
    int numSteps = 24; // simulate for one day
    int i, j, k;
    Vec3 force;

    for (i = 0; i < numSteps; i++) {
        // calculate the net force on each body
        for (j = 0; j < numBodies; j++) {
            bodies[j].accel.x = 0;
            bodies[j].accel.y = 0;
            bodies[j].accel.z = 0;
            for (k = 0; k < numBodies; k++) {
                if (k != j) {
                    calcGravity(&bodies[j], &bodies[k], &force);
                    bodies[j].accel.x += force.x / bodies[j].mass;
                    bodies[j].accel.y += force.y / bodies[j].mass;
                    bodies[j].accel.z += force.z / bodies[j].mass;
                }
            }
        }
        // update the positions and velocities of the bodies
        for (j = 0; j < numBodies; j++) {
            updateBody(&bodies[j], timestep);
        }
    }

    // print the final positions and velocities of the bodies
    printf("Final positions and velocities:\n");
    for (i = 0; i < numBodies; i++) {
        printf("Body %d:\n", i + 1);
        printf("Position: (%.2f, %.2f, %.2f) m\n", bodies[i].pos.x, bodies[i].pos.y, bodies[i].pos.z);
        printf("Velocity: (%.2f, %.2f, %.2f) m/s\n", bodies[i].vel.x, bodies[i].vel.y, bodies[i].vel.z);
    }

    return 0;
}