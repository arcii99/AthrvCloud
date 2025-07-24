//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // Gravitational constant
#define DT 0.1 // Time increment

typedef struct {
    double x;
    double y;
} Vector;

typedef struct {
    Vector position;
    Vector velocity;
    Vector acceleration;
    double mass;
} Body;

void update_acceleration(Body *bodies, int num_bodies) {
    for (int i = 0; i < num_bodies; i++) {
        Vector acceleration = {0, 0};
        for (int j = 0; j < num_bodies; j++) {
            if (i != j) {
                Vector r;
                r.x = bodies[j].position.x - bodies[i].position.x;
                r.y = bodies[j].position.y - bodies[i].position.y;
                double dist = sqrt(r.x * r.x + r.y * r.y);
                double force = G * bodies[i].mass * bodies[j].mass / (dist * dist);
                Vector f;
                f.x = force * r.x / dist;
                f.y = force * r.y / dist;
                acceleration.x += f.x / bodies[i].mass;
                acceleration.y += f.y / bodies[i].mass;
            }
        }
        bodies[i].acceleration = acceleration;
    }
}

void update_velocity(Body *bodies, int num_bodies) {
    for (int i = 0; i < num_bodies; i++) {
        bodies[i].velocity.x += bodies[i].acceleration.x * DT;
        bodies[i].velocity.y += bodies[i].acceleration.y * DT;
    }
}

void update_position(Body *bodies, int num_bodies) {
    for (int i = 0; i < num_bodies; i++) {
        bodies[i].position.x += bodies[i].velocity.x * DT;
        bodies[i].position.y += bodies[i].velocity.y * DT;
    }
}

void simulate(Body *bodies, int num_bodies, int num_steps) {
    for (int i = 0; i < num_steps; i++) {
        update_acceleration(bodies, num_bodies);
        update_velocity(bodies, num_bodies);
        update_position(bodies, num_bodies);
    }
}

int main() {
    int num_bodies = 3;
    int num_steps = 1000;
    Body bodies[num_bodies];
    bodies[0].position.x = 0;
    bodies[0].position.y = 0;
    bodies[0].velocity.x = 0;
    bodies[0].velocity.y = 0;
    bodies[0].mass = 5.97e24; // Earth mass
    bodies[1].position.x = 6.4e6; // Distance from Earth center
    bodies[1].position.y = 0;
    bodies[1].velocity.x = 0;
    bodies[1].velocity.y = 7.9e3; // Orbital velocity
    bodies[1].mass = 1000; // Test mass
    bodies[2].position.x = 0;
    bodies[2].position.y = 6.4e6; // Distance from Earth center
    bodies[2].velocity.x = -7.9e3; // Orbital velocity
    bodies[2].velocity.y = 0;
    bodies[2].mass = 1000; // Test mass
    simulate(bodies, num_bodies, num_steps);
    for (int i = 0; i < num_bodies; i++) {
        printf("Body %d position: (%.2f, %.2f)\n", i, bodies[i].position.x, bodies[i].position.y);
    }
    return 0;
}