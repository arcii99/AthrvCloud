//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DT 0.01 // timestep
#define G 6.6743E-11 // gravitational constant

typedef struct {
    double x, y, z; // position
    double vx, vy, vz; // velocity
    double ax, ay, az; // acceleration
    double mass;
} Body;

Body createBody(double x, double y, double z, double vx, double vy, double vz, double mass) {
    Body body = (Body) {x, y, z, vx, vy, vz, 0, 0, 0, mass};
    return body;
}

double distance(double x1, double y1, double z1, double x2, double y2, double z2) { 
    double dx = x2 - x1;
    double dy = y2 - y1;
    double dz = z2 - z1;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

void calculateAcceleration(Body* body, Body* bodies, int numBodies) {
    double ax = 0, ay = 0, az = 0;

    for (int i = 0; i < numBodies; i++) {
        if (&bodies[i] != body) { // avoid self-interaction
            double r = distance(body->x, body->y, body->z, bodies[i].x, bodies[i].y, bodies[i].z);
            double force = G * body->mass * bodies[i].mass / (r*r*r);
            ax += force * (bodies[i].x - body->x);
            ay += force * (bodies[i].y - body->y);
            az += force * (bodies[i].z - body->z);
        }
    }

    body->ax = ax / body->mass;
    body->ay = ay / body->mass;
    body->az = az / body->mass;
}

void updatePosition(Body* body) {
    body->x += body->vx * DT + 0.5 * body->ax * DT * DT;
    body->y += body->vy * DT + 0.5 * body->ay * DT * DT;
    body->z += body->vz * DT + 0.5 * body->az * DT * DT;
}

void updateVelocity(Body* body) {
    body->vx += body->ax * DT;
    body->vy += body->ay * DT;
    body->vz += body->az * DT;
}

int main() {
    Body bodies[3]; // Create 3 bodies

    bodies[0] = createBody(-1E11, 0, 0, 0, 30000, 0, 5.97E24); // Earth
    bodies[1] = createBody(1E11, 0, 0, 0, -30000, 0, 5.97E24); // Sun
    bodies[2] = createBody(0, 3E8, 0, -30000, 0, 0, 1E3); // Spaceship

    for (int i = 0; i < 10000; i++) { // run for 10000 timesteps
        for (int j = 0; j < 3; j++) { // for each body
            calculateAcceleration(&bodies[j], bodies, 3);
        }
        for (int j = 0; j < 3; j++) { // for each body
            updatePosition(&bodies[j]);
            updateVelocity(&bodies[j]);
        }
    }

    printf("Final position of the spaceship: (%f, %f, %f)\n", bodies[2].x, bodies[2].y, bodies[2].z);

    return 0;
}