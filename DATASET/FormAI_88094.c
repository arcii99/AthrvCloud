//FormAI DATASET v1.0 Category: Physics simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11 // gravitational constant
#define TIMESTEP 0.01 // simulation time step

typedef struct {
    double x, y; // position
    double vx, vy; // velocity
    double ax, ay; // acceleration
    double mass; // mass
} Particle;

void update_particles(Particle particles[], int n) {
    int i, j;
    double dx, dy, r, fx, fy;

    // reset accelerations
    for (i = 0; i < n; i++) {
        particles[i].ax = 0.0;
        particles[i].ay = 0.0;
    }

    // calculate pairwise forces
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            dx = particles[i].x - particles[j].x;
            dy = particles[i].y - particles[j].y;
            r = sqrt(dx*dx + dy*dy); // distance between particles
            fx = -G * particles[i].mass * particles[j].mass / (r*r*r) * dx; // force in x direction
            fy = -G * particles[i].mass * particles[j].mass / (r*r*r) * dy; // force in y direction
            particles[i].ax += fx / particles[i].mass;
            particles[i].ay += fy / particles[i].mass;
            particles[j].ax -= fx / particles[j].mass;
            particles[j].ay -= fy / particles[j].mass;
        }
    }

    // update velocities and positions
    for (i = 0; i < n; i++) {
        particles[i].vx += particles[i].ax * TIMESTEP;
        particles[i].vy += particles[i].ay * TIMESTEP;
        particles[i].x += particles[i].vx * TIMESTEP;
        particles[i].y += particles[i].vy * TIMESTEP;
    }
}

int main() {
    int n = 100; // number of particles
    Particle particles[n];
    int i;

    // initialize particles randomly
    srand(12345);
    for (i = 0; i < n; i++) {
        particles[i].x = rand() / (double)RAND_MAX * 10.0 - 5.0;
        particles[i].y = rand() / (double)RAND_MAX * 10.0 - 5.0;
        particles[i].vx = rand() / (double)RAND_MAX * 1.0 - 0.5;
        particles[i].vy = rand() / (double)RAND_MAX * 1.0 - 0.5;
        particles[i].mass = rand() / (double)RAND_MAX * 0.1 + 0.1;
    }

    // simulate particles
    for (i = 0; i < 10000; i++) {
        update_particles(particles, n);
    }

    // print final positions
    for (i = 0; i < n; i++) {
        printf("%f %f\n", particles[i].x, particles[i].y);
    }

    return 0;
}