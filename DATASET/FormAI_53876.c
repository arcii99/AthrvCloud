//FormAI DATASET v1.0 Category: Physics simulation ; Style: future-proof
#include <stdio.h>
#include <math.h>

// Constants
#define G 6.6743e-11     // Gravitational constant
#define DT 60            // Time step for simulation
#define STEPS 100000     // Number of steps to simulate

// Structures
typedef struct {
    double x, y;
} Vector;

typedef struct {
    double mass, radius;
    Vector pos, vel, accel;
} Body;

// Function prototypes
void update_acceleration(int n, Body *bodies);
void update_velocity(int n, Body *bodies);
void update_position(int n, Body *bodies);

// Main function
int main() {
    // Initialize bodies
    Body bodies[3] = {
        { 1000, 50, { 100, 100 }, { 0, 0 }, { 0, 0 } },
        { 2000, 75, { 500, 500 }, { 0, 0 }, { 0, 0 } },
        { 3000, 100, { 800, 200 }, { 0, 0 }, { 0, 0 } }
    };

    // Simulation loop
    for (int step = 0; step < STEPS; step++) {
        update_acceleration(3, bodies);
        update_velocity(3, bodies);
        update_position(3, bodies);
    }

    return 0;
}

// Compute acceleration of each body
void update_acceleration(int n, Body *bodies) {
    for (int i = 0; i < n; i++) {
        bodies[i].accel.x = 0;
        bodies[i].accel.y = 0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                Vector r;
                r.x = bodies[j].pos.x - bodies[i].pos.x;
                r.y = bodies[j].pos.y - bodies[i].pos.y;
                double distance = sqrt(r.x*r.x + r.y*r.y);

                double force = G * bodies[i].mass * bodies[j].mass / (distance*distance);
                double fx = force * r.x / distance;
                double fy = force * r.y / distance;

                bodies[i].accel.x += fx / bodies[i].mass;
                bodies[i].accel.y += fy / bodies[i].mass;
            }
        }
    }
}

// Update velocity of each body
void update_velocity(int n, Body *bodies) {
    for (int i = 0; i < n; i++) {
        bodies[i].vel.x += bodies[i].accel.x * DT;
        bodies[i].vel.y += bodies[i].accel.y * DT;
    }
}

// Update position of each body
void update_position(int n, Body *bodies) {
    for (int i = 0; i < n; i++) {
        bodies[i].pos.x += bodies[i].vel.x * DT;
        bodies[i].pos.y += bodies[i].vel.y * DT;
    }
}