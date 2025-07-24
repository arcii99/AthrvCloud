//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // Gravitational constant
#define SUN_MASS 1.989e30 // Mass of the sun
#define EARTH_MASS 5.972e24 // Mass of the earth
#define DT 3600 // Time step in seconds
#define STEPS 87600 // Number of steps to run simulation
#define AU 149.6e9 // 1 Astronomical Unit in meters

typedef struct vector {
    double x;
    double y;
    double z;
} vector;

typedef struct body {
    char name[20];
    double mass;
    vector position;
    vector velocity;
    vector acceleration;
} body;

vector add_vector(vector a, vector b) {
    vector c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    c.z = a.z + b.z;
    return c;
}

vector scale_vector(vector a, double b) {
    vector c;
    c.x = a.x * b;
    c.y = a.y * b;
    c.z = a.z * b;
    return c;
}

void gravity_step(body *bodies, int n) {
    int i, j;
    double dist, force_mag;
    vector force, direction;

    for (i = 0; i < n; i++) {
        bodies[i].acceleration.x = 0;
        bodies[i].acceleration.y = 0;
        bodies[i].acceleration.z = 0;
        for (j = 0; j < n; j++) {
            if (i != j) {
                // Calculate force between two bodies using Newton's law of universal gravitation
                dist = sqrt(pow(bodies[i].position.x - bodies[j].position.x, 2) + pow(bodies[i].position.y - bodies[j].position.y, 2) + pow(bodies[i].position.z - bodies[j].position.z, 2));
                force_mag = G * bodies[i].mass * bodies[j].mass / pow(dist, 2);
                direction.x = (bodies[j].position.x - bodies[i].position.x) / dist;
                direction.y = (bodies[j].position.y - bodies[i].position.y) / dist;
                direction.z = (bodies[j].position.z - bodies[i].position.z) / dist;
                force = scale_vector(direction, force_mag);

                // Update acceleration of first body
                bodies[i].acceleration = add_vector(bodies[i].acceleration, scale_vector(force, 1 / bodies[i].mass));
            }
        }
    }

    for (i = 0; i < n; i++) {
        // Update velocity and position of each body
        bodies[i].velocity = add_vector(bodies[i].velocity, scale_vector(bodies[i].acceleration, DT));
        bodies[i].position = add_vector(bodies[i].position, scale_vector(bodies[i].velocity, DT));
    }
}

int main() {
    body sun, earth;
    int i;

    // Initialize the sun
    sun.mass = SUN_MASS;
    sun.position.x = 0;
    sun.position.y = 0;
    sun.position.z = 0;
    sun.velocity.x = 0;
    sun.velocity.y = 0;
    sun.velocity.z = 0;
    strcpy(sun.name, "Sun");

    // Initialize the earth
    earth.mass = EARTH_MASS;
    earth.position.x = AU;
    earth.position.y = 0;
    earth.position.z = 0;
    earth.velocity.x = 0;
    earth.velocity.y = 29783;
    earth.velocity.z = 0;
    strcpy(earth.name, "Earth");

    body bodies[2] = {sun, earth};

    for (i = 0; i < STEPS; i++) {
        printf("%d: %s (%.2e, %.2e, %.2e) %s (%.2e, %.2e, %.2e)\n", i, bodies[0].name, bodies[0].position.x, bodies[0].position.y, bodies[0].position.z, bodies[1].name, bodies[1].position.x, bodies[1].position.y, bodies[1].position.z);
        gravity_step(bodies, 2);
    }

    return 0;
}