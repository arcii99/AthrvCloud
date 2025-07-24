//FormAI DATASET v1.0 Category: Physics simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_PARTICLES 10   // Number of particles in the simulation
#define DIMENSIONS 2       // Number of spatial dimensions
#define TIME_STEP 0.01     // Time step for simulation
#define MAX_TIME 10.0      // Maximum time for simulation
#define GRAV_CONST 6.674e-11  // Gravitational constant

typedef struct {
    double position[DIMENSIONS];
    double velocity[DIMENSIONS];
    double mass;
} Particle;

// Function to calculate the force between two particles based on their masses and positions
void calculate_force(Particle *p1, Particle *p2, double *force) {
    double distance_squared = 0;
    for (int i = 0; i < DIMENSIONS; i++) {
        double diff = p2->position[i] - p1->position[i];
        distance_squared += diff * diff;
    }
    double distance = sqrt(distance_squared);
    double magnitude = GRAV_CONST * p1->mass * p2->mass / distance_squared;
    for (int i = 0; i < DIMENSIONS; i++) {
        force[i] = magnitude * (p2->position[i] - p1->position[i]) / distance;
    }
}

int main() {
    Particle particles[NUM_PARTICLES];
    srand(time(NULL));   // Initialize random number generator
    // Set up initial positions, velocities, and masses for particles
    for (int i = 0; i < NUM_PARTICLES; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            particles[i].position[j] = rand() % 100;
            particles[i].velocity[j] = (rand() % 20) - 10;
        }
        particles[i].mass = 1e20 + rand() % (int)(1e24 - 1e20 + 1);
    }
    // Simulate particle motion over time
    double time = 0.0;
    while (time < MAX_TIME) {
        // Calculate forces between each pair of particles
        double forces[NUM_PARTICLES][DIMENSIONS];
        for (int i = 0; i < NUM_PARTICLES; i++) {
            for (int j = i+1; j < NUM_PARTICLES; j++) {
                calculate_force(&particles[i], &particles[j], forces[i]);
                for (int k = 0; k < DIMENSIONS; k++) {
                    forces[j][k] = -forces[i][k];
                }
            }
        }
        // Update positions and velocities of each particle based on forces
        for (int i = 0; i < NUM_PARTICLES; i++) {
            for (int j = 0; j < DIMENSIONS; j++) {
                particles[i].position[j] += particles[i].velocity[j] * TIME_STEP;
                particles[i].velocity[j] += forces[i][j] / particles[i].mass * TIME_STEP;
            }
        }
        time += TIME_STEP;
    }
    // Print final positions, velocities, and masses of particles
    for (int i = 0; i < NUM_PARTICLES; i++) {
        printf("Particle %d:\n", i+1);
        printf("  Position: (%.2f, %.2f)\n", particles[i].position[0], particles[i].position[1]);
        printf("  Velocity: (%.2f, %.2f)\n", particles[i].velocity[0], particles[i].velocity[1]);
        printf("  Mass: %.2e kg\n", particles[i].mass);
    }
    return 0;
}