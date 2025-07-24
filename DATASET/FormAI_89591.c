//FormAI DATASET v1.0 Category: Physics simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_PARTICLES 10 // number of particles in the simulation
#define PI 3.1415926535f  // constant pi

// struct to represent a particle in the simulation
struct Particle {
    float x;    // position along x-axis
    float y;    // position along y-axis
    float vx;   // velocity along x-axis
    float vy;   // velocity along y-axis
    float m;    // mass of the particle
};

// function to calculate the distance between two particles
float distance(struct Particle p1, struct Particle p2) {
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    // initialize variables
    struct Particle particles[NUM_PARTICLES];
    float dt = 0.1f;    // time step
    float G = 6.674e-11f;   // gravitational constant
    float t = 0.0f;     // current time

    // initialize particles with random positions and velocities
    for (int i = 0; i < NUM_PARTICLES; i++) {
        particles[i].x = (float)rand() / RAND_MAX * 100.0f;
        particles[i].y = (float)rand() / RAND_MAX * 100.0f;
        particles[i].vx = (float)rand() / RAND_MAX * 10.0f;
        particles[i].vy = (float)rand() / RAND_MAX * 10.0f;
        particles[i].m = (float)rand() / RAND_MAX * 100.0f;
    }

    // run simulation for 1000 time steps
    for (int i = 0; i < 1000; i++) {
        // calculate forces between all pairs of particles
        for (int j = 0; j < NUM_PARTICLES; j++) {
            for (int k = j + 1; k < NUM_PARTICLES; k++) {
                float r = distance(particles[j], particles[k]);
                float F = G * particles[j].m * particles[k].m / (r * r);
                float theta = atan2(particles[k].y - particles[j].y, particles[k].x - particles[j].x);
                particles[j].vx += F * cos(theta) / particles[j].m * dt;
                particles[j].vy += F * sin(theta) / particles[j].m * dt;
                particles[k].vx -= F * cos(theta) / particles[k].m * dt;
                particles[k].vy -= F * sin(theta) / particles[k].m * dt;
            }
        }

        // update positions of particles
        for (int j = 0; j < NUM_PARTICLES; j++) {
            particles[j].x += particles[j].vx * dt;
            particles[j].y += particles[j].vy * dt;
        }

        // print current positions of particles every 10 time steps
        if (i % 10 == 0) {
            printf("Time: %f\n", t);
            for (int j = 0; j < NUM_PARTICLES; j++) {
                printf("Particle %d: (%f, %f)\n", j, particles[j].x, particles[j].y);
            }
        }

        // increment time
        t += dt;
    }

    return 0;
}