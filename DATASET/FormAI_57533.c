//FormAI DATASET v1.0 Category: Physics simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_TIME 1000 // Time limit for simulation
#define NUM_PARTICLES 50 // Number of particles in simulation

// Define a particle structure with mass, position and velocity
typedef struct {
    double mass;
    double x_pos, y_pos;
    double x_vel, y_vel;
} Particle;

int main() {
    Particle particles[NUM_PARTICLES]; // Array of particles in simulation
    double time_step = 0.01; // Time step for each iteration
    
    // Initialize particle properties randomly
    for (int i = 0; i < NUM_PARTICLES; i++) {
        particles[i].mass = (rand() % 2000 + 1) / 1000.0; // Random mass between 0.001 and 2.000
        particles[i].x_pos = (rand() % 101) / 10.0; // Random x position between 0 and 10
        particles[i].y_pos = (rand() % 101) / 10.0; // Random y position between 0 and 10
        particles[i].x_vel = (rand() % 21 - 10) / 10.0; // Random x velocity between -1 and 1
        particles[i].y_vel = (rand() % 21 - 10) / 10.0; // Random y velocity between -1 and 1
    }
    
    // Print initial state of simulation
    printf("Initial state:\n");
    for (int i = 0; i < NUM_PARTICLES; i++) {
        printf("Particle %d - Mass: %.3f, Position: (%.1f, %.1f), Velocity: (%.1f, %.1f)\n", i+1, particles[i].mass, particles[i].x_pos, particles[i].y_pos, particles[i].x_vel, particles[i].y_vel);
    }
    
    // Start simulation loop
    for (double t = 0; t < MAX_TIME; t += time_step) {
        // Calculate forces on each particle
        for (int i = 0; i < NUM_PARTICLES; i++) {
            double x_force = 0, y_force = 0;
            for (int j = 0; j < NUM_PARTICLES; j++) {
                if (i != j) {
                    double dx = particles[j].x_pos - particles[i].x_pos;
                    double dy = particles[j].y_pos - particles[i].y_pos;
                    double dist = sqrt(dx*dx + dy*dy);
                    double force = particles[i].mass * particles[j].mass / (dist*dist);
                    x_force += force * dx / dist;
                    y_force += force * dy / dist;
                }
            }
            particles[i].x_vel += x_force / particles[i].mass * time_step;
            particles[i].y_vel += y_force / particles[i].mass * time_step;
        }
        
        // Update positions of each particle
        for (int i = 0; i < NUM_PARTICLES; i++) {
            particles[i].x_pos += particles[i].x_vel * time_step;
            particles[i].y_pos += particles[i].y_vel * time_step;
        }
    }
    
    // Print final state of simulation
    printf("\nFinal state:\n");
    for (int i = 0; i < NUM_PARTICLES; i++) {
        printf("Particle %d - Mass: %.3f, Position: (%.1f, %.1f), Velocity: (%.1f, %.1f)\n", i+1, particles[i].mass, particles[i].x_pos, particles[i].y_pos, particles[i].x_vel, particles[i].y_vel);
    }
    
    return 0;
}