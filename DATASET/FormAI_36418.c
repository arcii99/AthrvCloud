//FormAI DATASET v1.0 Category: Physics simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define GRAVITY -9.81 // m/s^2
#define DRAG 0.2
#define WIDTH 100 // m
#define HEIGHT 50 // m
#define DELTA_T 0.1 // s

// Define the particle struct
typedef struct particle {
    float x, y, z;
    float vx, vy, vz;
    float mass;
    int color;
} Particle;

// Define the function to simulate the movement of the particles
void simulate(Particle *p, int n) {
    float fx, fy, fz, ax, ay, az, vrel, drag;
    int i, j;

    // Initialize random number generator
    srand(time(NULL));

    for (i = 0; i < n; i++) {
        // Calculate the sum of forces acting on the particle
        fx = 0;
        fy = GRAVITY * p[i].mass;
        fz = 0;

        for (j = 0; j < n; j++) {
            if (i != j) {
                vrel = sqrt(pow(p[i].vx - p[j].vx, 2) +
                            pow(p[i].vy - p[j].vy, 2) +
                            pow(p[i].vz - p[j].vz, 2));
                drag = DRAG * vrel;

                fx += drag * (p[j].vx - p[i].vx);
                fy += drag * (p[j].vy - p[i].vy);
                fz += drag * (p[j].vz - p[i].vz);
            }
        }

        // Calculate the acceleration of the particle
        ax = fx / p[i].mass;
        ay = fy / p[i].mass;
        az = fz / p[i].mass;

        // Calculate the new velocity of the particle
        p[i].vx += ax * DELTA_T;
        p[i].vy += ay * DELTA_T;
        p[i].vz += az * DELTA_T;

        // Calculate the new position of the particle
        p[i].x += p[i].vx * DELTA_T;
        p[i].y += p[i].vy * DELTA_T;
        p[i].z += p[i].vz * DELTA_T;

        // Handle collisions with the walls
        if (p[i].x < 0) {
            p[i].x = 0;
            p[i].vx = -p[i].vx;
        }
        if (p[i].y < 0) {
            p[i].y = 0;
            p[i].vy = -p[i].vy;
        }
        if (p[i].z < 0) {
            p[i].z = 0;
            p[i].vz = -p[i].vz;
        }
        if (p[i].x > WIDTH) {
            p[i].x = WIDTH;
            p[i].vx = -p[i].vx;
        }
        if (p[i].y > HEIGHT) {
            p[i].y = HEIGHT;
            p[i].vy = -p[i].vy;
        }
    }
}

int main() {
    int i;
    Particle particles[10];

    // Initialize the particles
    for (i = 0; i < 10; i++) {
        particles[i].x = (float) (rand() % WIDTH + 1);
        particles[i].y = (float) (rand() % HEIGHT + 1);
        particles[i].z = 0;
        particles[i].vx = (float) (rand() % 20 - 10);
        particles[i].vy = (float) (rand() % 20 - 10);
        particles[i].vz = (float) (rand() % 20 - 10);
        particles[i].mass = (float) (rand() % 10 + 1) / 10;
        particles[i].color = rand() % 5 + 1;
    }

    // Simulate the movement of the particles
    for (i = 0; i < 100; i++) {
        simulate(particles, 10);
    }

    return 0;
}