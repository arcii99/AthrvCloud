//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: all-encompassing
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define G 6.6743e-11 // Gravitational constant

typedef struct { // Structure for a point in 3D space
    double x;
    double y;
    double z;
} point_t;

typedef struct { // Structure for a body in the simulation
    point_t pos; // Position of the body
    point_t vel; // Velocity of the body
    double mass; // Mass of the body
} body_t;

int main() {
    int num_bodies = 2; // Number of bodies in the simulation
    int num_steps = 10000; // Number of simulation steps to run
    double time_step = 1.0; // Length of a simulation time step (in seconds)

    // Initialize the bodies in the simulation
    body_t bodies[num_bodies];
    bodies[0].pos.x = 0.0;
    bodies[0].pos.y = 0.0;
    bodies[0].pos.z = 0.0;
    bodies[0].vel.x = 0.0;
    bodies[0].vel.y = 0.0;
    bodies[0].vel.z = 0.0;
    bodies[0].mass = 1.989e30; // Mass of the Sun

    bodies[1].pos.x = 0.0;
    bodies[1].pos.y = 149.6e9; // Distance from the Sun to Earth
    bodies[1].pos.z = 0.0;
    bodies[1].vel.x = 29.78e3; // Orbital velocity of Earth
    bodies[1].vel.y = 0.0;
    bodies[1].vel.z = 0.0;
    bodies[1].mass = 5.972e24; // Mass of the Earth

    // Run the simulation
    for (int step = 0; step < num_steps; step++) {
        // Update the positions of all bodies using their velocities
        for (int i = 0; i < num_bodies; i++) {
            bodies[i].pos.x += bodies[i].vel.x * time_step;
            bodies[i].pos.y += bodies[i].vel.y * time_step;
            bodies[i].pos.z += bodies[i].vel.z * time_step;
        }

        // Compute the forces on each body due to gravity
        for (int i = 0; i < num_bodies; i++) {
            // Initialize the total force on the body to zero
            double total_force_x = 0.0;
            double total_force_y = 0.0;
            double total_force_z = 0.0;

            for (int j = 0; j < num_bodies; j++) {
                // Skip the body i itself
                if (i == j) {
                    continue;
                }

                // Compute the distance vector between the two bodies
                double dx = bodies[j].pos.x - bodies[i].pos.x;
                double dy = bodies[j].pos.y - bodies[i].pos.y;
                double dz = bodies[j].pos.z - bodies[i].pos.z;

                double r = sqrt(dx*dx + dy*dy + dz*dz); // Compute the distance between the two bodies

                // Compute the gravitational force between the two bodies using the universal law of gravitation
                double f = G * bodies[i].mass * bodies[j].mass / (r*r);

                // Compute the components of the force vector
                double fx = f * dx / r;
                double fy = f * dy / r;
                double fz = f * dz / r;

                // Add the components of the force vector to the total force on the body i
                total_force_x += fx;
                total_force_y += fy;
                total_force_z += fz;
            }

            // Update the velocity of the body due to the total force on the body
            bodies[i].vel.x += total_force_x / bodies[i].mass * time_step;
            bodies[i].vel.y += total_force_y / bodies[i].mass * time_step;
            bodies[i].vel.z += total_force_z / bodies[i].mass * time_step;
        }

        // Print the positions of all bodies at the current time step
        printf("Step %d\n", step);
        for (int i = 0; i < num_bodies; i++) {
            printf("Body %d: (%f, %f, %f)\n", i, bodies[i].pos.x, bodies[i].pos.y, bodies[i].pos.z);
        }
    }

    return 0;
}