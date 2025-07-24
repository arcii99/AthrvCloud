//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Claude Shannon
#include <stdio.h>
#include <math.h>

#define G 6.674e-11 // Universal gravitational constant

struct Body {
    double mass; // In kg
    double pos[3]; // Position array, in m
    double vel[3]; // Velocity array, in m/s
};

void compute_forces(struct Body *bodies, int num_bodies, double dt) {
    double forces[num_bodies][3];
    for (int i = 0; i < num_bodies; i++) {
        // Initialize forces array to 0
        for (int j = 0; j < 3; j++) {
            forces[i][j] = 0;
        }
        // Compute gravitational forces between this body and all others
        for (int j = 0; j < num_bodies; j++) {
            if (j == i) {
                continue;
            }
            double r[3];
            for (int k = 0; k < 3; k++) {
                r[k] = bodies[j].pos[k] - bodies[i].pos[k];
            }
            double dist = sqrt(r[0]*r[0] + r[1]*r[1] + r[2]*r[2]);
            double f_mag = G*bodies[i].mass*bodies[j].mass / (dist*dist);
            for (int k = 0; k < 3; k++) {
                forces[i][k] += f_mag * r[k] / dist;
            }
        }
    }
    // Update positions and velocities
    for (int i = 0; i < num_bodies; i++) {
        for (int j = 0; j < 3; j++) {
            bodies[i].pos[j] += bodies[i].vel[j] * dt;
            bodies[i].vel[j] += forces[i][j] / bodies[i].mass * dt;
        }
    }
}

int main() {
    // Set up solar system
    struct Body sun = {1.989e30, {0, 0, 0}, {0, 0, 0}};
    struct Body earth = {5.972e24, {1.496e11, 0, 0}, {0, 2.978e4, 0}};
    struct Body moon = {7.342e22, {1.496e11 + 3.844e8, 0, 0}, {0, 2.978e4 + 1.022e3, 0}};
    struct Body mars = {6.39e23, {2.279e11, 0, 0}, {0, 2.407e4, 0}};
    struct Body venus = {4.867e24, {1.08e11, 0, 0}, {0, 3.502e4, 0}};
    struct Body bodies[] = {sun, earth, moon, mars, venus};
    int num_bodies = sizeof(bodies) / sizeof(struct Body);

    // Run simulation
    double dt = 86400; // One day timestep
    int num_steps = 365; // One year
    for (int step = 0; step < num_steps; step++) {
        compute_forces(bodies, num_bodies, dt);
    }

    // Print final positions of bodies
    printf("Final positions:\n");
    for (int i = 0; i < num_bodies; i++) {
        printf("Body %d: (%.3e, %.3e, %.3e)\n", i+1, bodies[i].pos[0], bodies[i].pos[1], bodies[i].pos[2]);
    }
    return 0;
}