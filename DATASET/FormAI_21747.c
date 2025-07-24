//FormAI DATASET v1.0 Category: Physics simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Particle Structure
typedef struct Particle {
    double x;  // x-coordinate
    double y;  // y-coordinate
    double vx; // x-velocity
    double vy; // y-velocity
    double ax; // x-acceleration
    double ay; // y-acceleration
    double m;  // mass
} Particle;

// Simulation Constants
const double G = 0.0000000000674; // Gravitational constant
const double DT = 86400;          // Time step (in seconds) i.e., 1 day
const int NUM_PARTICLES = 2;      // Number of particles
const int NUM_STEPS = 365;        // Number of time steps i.e., 1 year

// Function to calculate distance between two particles
double distance(Particle p1, Particle p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Function to update particle's acceleration due to gravity
void updateAcceleration(Particle *p1, Particle *p2) {
    double r = distance(*p1, *p2);
    double force = G * p1->m * p2->m / pow(r, 2);
    p1->ax = force * (p2->x - p1->x) / r / p1->m;
    p1->ay = force * (p2->y - p1->y) / r / p1->m;
}

int main() {
    // Initialize particles
    Particle particles[NUM_PARTICLES];
    particles[0].x = 0;
    particles[0].y = 0;
    particles[0].vx = 0;
    particles[0].vy = 0;
    particles[0].ax = 0;
    particles[0].ay = 0;
    particles[0].m = 5.97 * pow(10, 24); // mass of Earth
    particles[1].x = 384.4 * pow(10, 6);
    particles[1].y = 0;
    particles[1].vx = 0;
    particles[1].vy = 1022;
    particles[1].ax = 0;
    particles[1].ay = 0;
    particles[1].m = 7.34 * pow(10, 22); // mass of Moon

    // Simulate motion
    for (int i = 0; i < NUM_STEPS; i++) {
        // Update particle acceleration due to gravity
        updateAcceleration(&particles[0], &particles[1]);
        updateAcceleration(&particles[1], &particles[0]);

        // Update particle velocity
        particles[0].vx += particles[0].ax * DT;
        particles[0].vy += particles[0].ay * DT;
        particles[1].vx += particles[1].ax * DT;
        particles[1].vy += particles[1].ay * DT;

        // Update particle position
        particles[0].x += particles[0].vx * DT;
        particles[0].y += particles[0].vy * DT;
        particles[1].x += particles[1].vx * DT;
        particles[1].y += particles[1].vy * DT;

        // Print particle positions
        printf("Step %d: Earth (%fm, %fm), Moon (%fm, %fm)\n", i+1, particles[0].x, particles[0].y, particles[1].x, particles[1].y);
    }

    return 0;
}