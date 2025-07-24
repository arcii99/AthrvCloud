//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67E-11 // gravitational constant

typedef struct {
    double x;
    double y;
    double z;
} Vector3D;

typedef struct {
    Vector3D position;
    Vector3D velocity;
    double mass;
} Body;

void compute_gravity(Body* a, Body* b, Vector3D* gravity) {
    double distance_squared, force;
    Vector3D direction;

    // calculate distance between two bodies
    direction.x = b->position.x - a->position.x;
    direction.y = b->position.y - a->position.y;
    direction.z = b->position.z - a->position.z;
    distance_squared = direction.x * direction.x + direction.y * direction.y + direction.z * direction.z;

    // calculate force between two bodies
    force = G * a->mass * b->mass / distance_squared;

    // calculate gravity vector
    direction.x /= sqrt(distance_squared);
    direction.y /= sqrt(distance_squared);
    direction.z /= sqrt(distance_squared);
    gravity->x = force * direction.x;
    gravity->y = force * direction.y;
    gravity->z = force * direction.z;
}

void update_body(Body* body, Vector3D* gravity, double dt) {
    // calculate new velocity
    body->velocity.x += gravity->x * dt;
    body->velocity.y += gravity->y * dt;
    body->velocity.z += gravity->z * dt;
    
    // calculate new position
    body->position.x += body->velocity.x * dt;
    body->position.y += body->velocity.y * dt;
    body->position.z += body->velocity.z * dt;
}

int main() {
    Body bodies[3] = {
        {{0, 0, 0}, {0, 0, 0}, 5.97E24}, // Earth
        {{0, 384400000, 0}, {1022, 0, 0}, 7.36E22}, // Moon
        {{149600000000, 0, 0}, {0, 29677, 0}, 1.989E30} // Sun
    };
    Vector3D gravity[3][3];

    // simulate for 1 year
    const double dt = 60; // time step in seconds
    const int num_steps = 365 * 24 * 60 * 60 / dt;
    for (int step = 0; step < num_steps; ++step) {
        // compute gravity for all pairs of bodies
        for (int i = 0; i < 3; ++i) {
            for (int j = i + 1; j < 3; ++j) {
                compute_gravity(&bodies[i], &bodies[j], &gravity[i][j]);
                gravity[j][i].x = -gravity[i][j].x;
                gravity[j][i].y = -gravity[i][j].y;
                gravity[j][i].z = -gravity[i][j].z;
            }
        }

        // update each body based on net gravity
        for (int i = 0; i < 3; ++i) {
            Vector3D net_gravity = {0, 0, 0};
            for (int j = 0; j < 3; ++j) {
                if (i != j) {
                    net_gravity.x += gravity[i][j].x;
                    net_gravity.y += gravity[i][j].y;
                    net_gravity.z += gravity[i][j].z;
                }
            }
            update_body(&bodies[i], &net_gravity, dt);
        }
        
        // print output
        printf("Step %d:\n", step+1);
        for (int i = 0; i < 3; ++i) {
            printf("  Body %d: (%.1f, %.1f, %.1f)\n", i+1, bodies[i].position.x, bodies[i].position.y, bodies[i].position.z);
        }
    }

    return 0;
}