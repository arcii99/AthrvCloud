//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743015e-11 // gravitational constant

struct Vector {
   double x, y, z;
};

typedef struct Vector Vector;

struct Body {
   Vector pos;    // position
   Vector vel;    // velocity
   Vector force;  // force
   double mass;   // mass
};

typedef struct Body Body;

void compute_forces(Body *bodies, int n) {
    // for each body
    for (int i = 0; i < n; i++) {
        bodies[i].force.x = 0.0;
        bodies[i].force.y = 0.0;
        bodies[i].force.z = 0.0;

        // for each other body
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }

            Vector r;
            r.x = bodies[j].pos.x - bodies[i].pos.x;
            r.y = bodies[j].pos.y - bodies[i].pos.y;
            r.z = bodies[j].pos.z - bodies[i].pos.z;

            double distance = sqrt(r.x * r.x + r.y * r.y + r.z * r.z);

            double force = G * bodies[i].mass * bodies[j].mass / (distance * distance);

            bodies[i].force.x += force * (r.x / distance);
            bodies[i].force.y += force * (r.y / distance);
            bodies[i].force.z += force * (r.z / distance);
        }
    }
}

void update_positions(Body *bodies, int n, double dt) {
    for (int i = 0; i < n; i++) {
        // update position using velocity
        bodies[i].pos.x += bodies[i].vel.x * dt;
        bodies[i].pos.y += bodies[i].vel.y * dt;
        bodies[i].pos.z += bodies[i].vel.z * dt;

        // reset force for next update
        bodies[i].force.x = 0.0;
        bodies[i].force.y = 0.0;
        bodies[i].force.z = 0.0;
    }
}

void update_velocities(Body *bodies, int n, double dt) {
    for (int i = 0; i < n; i++) {
        // update velocity using force
        bodies[i].vel.x += bodies[i].force.x * dt / bodies[i].mass;
        bodies[i].vel.y += bodies[i].force.y * dt / bodies[i].mass;
        bodies[i].vel.z += bodies[i].force.z * dt / bodies[i].mass;
    }
}

int main() {
    Body bodies[] = {
        { { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 }, 1.0 },
        { { 1.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 }, 1.0 },
        { { 0.0, 1.0, 0.0 }, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 }, 1.0 },
        { { 0.0, 0.0, 1.0 }, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 }, 1.0 }
    };
    int n = sizeof(bodies) / sizeof(Body);
    double dt = 0.01;
    int steps = 1000;

    // simulate gravity for steps iterations
    for (int i = 0; i < steps; i++) {
        compute_forces(bodies, n);
        update_positions(bodies, n, dt);
        update_velocities(bodies, n, dt);
    }

    // print final positions
    for (int i = 0; i < n; i++) {
        printf("Body %d: (%f, %f, %f)\n", i, bodies[i].pos.x, bodies[i].pos.y, bodies[i].pos.z);
    }

    return 0;
}