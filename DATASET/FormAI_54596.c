//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: calm
#include <stdio.h>
#include <math.h>

#define G 6.67430e-11 // Gravitational constant
#define AU 149597870700  // Astronomical unit in meters

typedef struct vec { // 3D vector structure
    double x, y, z;
} vec;

typedef struct body { // Body structure containing mass, position, velocity, and acceleration
    double mass;
    vec position, velocity, acceleration;
} body;

void calculate_acceleration(body *bodies, int n) {
    for (int i = 0; i < n; i++) { // Loop through all bodies
        for (int j = 0; j < n; j++) { // Calculate acceleration due to each other body
            if (i != j) { // Avoid calculating acceleration due to itself
                double dx = bodies[j].position.x - bodies[i].position.x;
                double dy = bodies[j].position.y - bodies[i].position.y;
                double dz = bodies[j].position.z - bodies[i].position.z;
                double r = sqrt(dx*dx + dy*dy + dz*dz); // Distance between two bodies
                double f = G * bodies[i].mass * bodies[j].mass / (r*r); // Gravitational force
                vec force = { .x = f*dx/r, .y = f*dy/r, .z = f*dz/r }; // Force vector
                vec acceleration = { .x = force.x / bodies[i].mass, .y = force.y / bodies[i].mass, .z = force.z / bodies[i].mass }; // Acceleration vector
                bodies[i].acceleration.x += acceleration.x; // Add acceleration due to this body
                bodies[i].acceleration.y += acceleration.y;
                bodies[i].acceleration.z += acceleration.z;
            }
        }
    }
}

void update_velocity_and_position(body *bodies, int n, double dt) {
    for (int i = 0; i < n; i++) { // Loop through all bodies
        bodies[i].velocity.x += bodies[i].acceleration.x * dt;
        bodies[i].velocity.y += bodies[i].acceleration.y * dt;
        bodies[i].velocity.z += bodies[i].acceleration.z * dt;
        bodies[i].position.x += bodies[i].velocity.x * dt;
        bodies[i].position.y += bodies[i].velocity.y * dt;
        bodies[i].position.z += bodies[i].velocity.z * dt;
        bodies[i].acceleration.x = 0; // Reset acceleration for next update
        bodies[i].acceleration.y = 0;
        bodies[i].acceleration.z = 0;
    }
}

int main() {
    body sun = { .mass = 1.989e30/AU, .position = { .x = 0, .y = 0, .z = 0 } }; // Sun
    body earth = { .mass = 5.972e24/AU, .position = { .x = 1, .y = 0, .z = 0 }, .velocity = { .x = 0, .y = 2*M_PI, .z = 0 } }; // Earth
    body mars = { .mass = 6.39e23/AU, .position = { .x = 1.52, .y = 0, .z = 0 }, .velocity = { .x = 0, .y = 1.86*M_PI, .z = 0 } }; // Mars
    body venus = { .mass = 4.87e24/AU, .position = { .x = 0.72, .y = 0, .z = 0 }, .velocity = { .x = 0, .y = 2.64*M_PI, .z = 0 } }; // Venus
    body jupiter = { .mass = 1.898e27/AU, .position = { .x = 5.2, .y = 0, .z = 0 }, .velocity = { .x = 0, .y = 1.3*M_PI, .z = 0 } }; // Jupiter
    body saturn = { .mass = 5.683e26/AU, .position = { .x = 9.5, .y = 0, .z = 0 }, .velocity = { .x = 0, .y = 0.96*M_PI, .z = 0 } }; // Saturn

    body bodies[] = {sun, earth, mars, venus, jupiter, saturn}; // Array of bodies
    int n = sizeof(bodies)/sizeof(body); // Number of bodies

    double dt = 86400; // One day in seconds
    int days = 365 * 10; // Simulate 10 years
    for (int i = 0; i < days; i++) {
        calculate_acceleration(bodies, n);
        update_velocity_and_position(bodies, n, dt);
        printf("Day %d - Earth x: %f y: %f z: %f\n", i+1, bodies[1].position.x, bodies[1].position.y, bodies[1].position.z);
    }

    return 0;
}