//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11  // Gravitational constant

typedef struct {
    double x;
    double y;
    double z;
} vector;

typedef struct {
    char name[20];
    double mass;    // in kilograms
    vector pos;     // in meters
    vector vel;     // in meters per second
    vector acc;     // in meters per second squared
} body;

int main() {

    // Configurable inputs
    const int num_bodies = 4;
    const double time_step = 3600.0; // 1 hour in seconds

    // Create the bodies of the Solar System
    body bodies[num_bodies];
    // Sun
    bodies[0].mass = 1.9885e30;
    sprintf(bodies[0].name, "Sun");
    // Earth
    bodies[1].mass = 5.9722e24;
    sprintf(bodies[1].name, "Earth");
    bodies[1].pos.x = 147e9;
    bodies[1].vel.y = 29.78e3;
    // Moon
    bodies[2].mass = 7.342e22;
    sprintf(bodies[2].name, "Moon");
    bodies[2].pos.x = bodies[1].pos.x;  // same as Earth
    bodies[2].pos.y = 384400e3;
    bodies[2].vel.y = bodies[1].vel.y + 1022;   // relative velocity
    // Mars
    bodies[3].mass = 6.4171e23;
    sprintf(bodies[3].name, "Mars");
    bodies[3].pos.x = 228e9;
    bodies[3].vel.y = 24.077e3;

    // Simulation loop
    for (int t = 0; t < 24*365; t++) {  // 1 year
        printf("Time: %d\n", t);
        // Reset accelerations to zero
        for (int i = 0; i < num_bodies; i++) {
            bodies[i].acc.x = 0;
            bodies[i].acc.y = 0;
            bodies[i].acc.z = 0;
        }
        // Calculate accelerations
        for (int i = 0; i < num_bodies; i++) {
            for (int j = 0; j < num_bodies; j++) {
                if (i != j) {
                    // Distance between bodies
                    double dx = bodies[i].pos.x - bodies[j].pos.x;
                    double dy = bodies[i].pos.y - bodies[j].pos.y;
                    double dz = bodies[i].pos.z - bodies[j].pos.z;
                    double dist = sqrt(dx*dx + dy*dy + dz*dz);
                    // Force between bodies
                    double force = G * bodies[i].mass * bodies[j].mass / (dist*dist);
                    // Acceleration on body i
                    bodies[i].acc.x -= force * dx / dist / bodies[i].mass;
                    bodies[i].acc.y -= force * dy / dist / bodies[i].mass;
                    bodies[i].acc.z -= force * dz / dist / bodies[i].mass;
                }
            }
        }
        // Update positions and velocities
        for (int i = 0; i < num_bodies; i++) {
            // Update velocities
            bodies[i].vel.x += bodies[i].acc.x * time_step;
            bodies[i].vel.y += bodies[i].acc.y * time_step;
            bodies[i].vel.z += bodies[i].acc.z * time_step;
            // Update positions
            bodies[i].pos.x += bodies[i].vel.x * time_step;
            bodies[i].pos.y += bodies[i].vel.y * time_step;
            bodies[i].pos.z += bodies[i].vel.z * time_step;
        }
        // Print out results for Earth
        printf("Earth position: (%.2f, %.2f, %.2f)\n", bodies[1].pos.x, bodies[1].pos.y, bodies[1].pos.z);
    }

    return 0;
}