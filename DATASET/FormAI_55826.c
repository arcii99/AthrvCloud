//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: accurate
#include <stdio.h>
#include <math.h>

#define G 6.67408e-11 // Gravitational constant
#define SUN_MASS 1.989e30 // Mass of the Sun

#define BASE_DISTANCE 8.0e11 // Average distance of Earth to Sun
#define BASE_VELOCITY sqrt(G * SUN_MASS / BASE_DISTANCE) // Velocity at Earth's orbit

#define YEAR 365.25 * 86400 // Length of a year in seconds
#define INTERVAL 3000 // Simulation interval in seconds

typedef struct {
    double mass;
    double position[3];
    double velocity[3];
    double force[3];
} Body;

// Calculate Euclidean distance between two points in 3D space
double distance(Body a, Body b) {
    return sqrt(pow(a.position[0] - b.position[0], 2) + pow(a.position[1] - b.position[1], 2) + pow(a.position[2] - b.position[2], 2));
}

// Calculate gravitational force between two bodies
void calculateForce(Body *a, Body *b) {
    double f = G * a->mass * b->mass / pow(distance(*a, *b), 2);
    for (int i = 0; i < 3; i++) {
        a->force[i] += f * (b->position[i] - a->position[i]) / distance(*a, *b);
        b->force[i] -= f * (b->position[i] - a->position[i]) / distance(*a, *b);
    }
}

// Update velocity and position of a body
void update(Body *b, double t) {
    for (int i = 0; i < 3; i++) {
        b->velocity[i] += b->force[i] / b->mass * t;
        b->position[i] += b->velocity[i] * t;
        b->force[i] = 0.0;
    }
}

int main() {
    // Initialize solar system bodies
    Body sun = {
        .mass = SUN_MASS,
        .position = {0.0, 0.0, 0.0},
        .velocity = {0.0, 0.0, 0.0},
        .force = {0.0, 0.0, 0.0}
    };
    Body earth = {
        .mass = 5.972e24,
        .position = {BASE_DISTANCE, 0.0, 0.0},
        .velocity = {0.0, BASE_VELOCITY, 0.0},
        .force = {0.0, 0.0, 0.0}
    };
    Body moon = {
        .mass = 7.342e22,
        .position = {BASE_DISTANCE + 3.844e8, 0.0, 0.0},
        .velocity = {0.0, BASE_VELOCITY + 1.022e3, 0.0},
        .force = {0.0, 0.0, 0.0}
    };

    // Simulation loop
    for (double t = 0; t < 10.0 * YEAR; t += INTERVAL) {
        calculateForce(&sun, &earth);
        calculateForce(&sun, &moon);
        calculateForce(&earth, &moon);
        update(&sun, INTERVAL);
        update(&earth, INTERVAL);
        update(&moon, INTERVAL);
        printf("%.2f,%.4f,%.4f,%.4f,%.4f,%.4f,%.4f,%.4f,%.4f,%.4f,%.4f,%.4f\n", t / YEAR, earth.position[0] / BASE_DISTANCE, earth.position[1] / BASE_DISTANCE, earth.position[2] / BASE_DISTANCE, moon.position[0] / BASE_DISTANCE, moon.position[1] / BASE_DISTANCE, moon.position[2] / BASE_DISTANCE, earth.velocity[0] / BASE_VELOCITY, earth.velocity[1] / BASE_VELOCITY, earth.velocity[2] / BASE_VELOCITY, moon.velocity[0] / BASE_VELOCITY, moon.velocity[1] / BASE_VELOCITY, moon.velocity[2] / BASE_VELOCITY);
    }

    return 0;
}