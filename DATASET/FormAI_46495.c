//FormAI DATASET v1.0 Category: Physics simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Define constants
#define G 6.67430e-11
#define SIZE 1000
#define MASS_RANGE 100000

// Define structures
struct vector {
    double x;
    double y;
};

struct particle {
    int id;
    double mass;
    struct vector position;
    struct vector velocity;
};

// Define functions
void simulate(struct particle* particles, int num_particles, double time_step);
void calculate_forces(struct particle* particles, int num_particles, struct vector* forces);
void update_velocities(struct particle* particles, int num_particles, struct vector* forces, double time_step);
void update_positions(struct particle* particles, int num_particles, double time_step);
struct vector calculate_force(struct particle p1, struct particle p2);

// Main function
int main() {
    // Initialize particles
    srand(time(NULL));
    struct particle particles[SIZE];
    for (int i = 0; i < SIZE; i++) {
        particles[i].id = i;
        particles[i].mass = (double) rand() / RAND_MAX * MASS_RANGE;
        particles[i].position.x = (double) rand() / RAND_MAX * SIZE;
        particles[i].position.y = (double) rand() / RAND_MAX * SIZE;
        particles[i].velocity.x = (double) rand() / RAND_MAX * 10 - 5;
        particles[i].velocity.y = (double) rand() / RAND_MAX * 10 - 5;
    }

    // Run simulation
    double time_step = 1;
    for (int i = 0; i < 100; i++) {
        simulate(particles, SIZE, time_step);
    }

    return 0;
}

// Simulate one time step
void simulate(struct particle* particles, int num_particles, double time_step) {
    // Calculate forces
    struct vector forces[num_particles];
    calculate_forces(particles, num_particles, forces);

    // Update velocities and positions
    update_velocities(particles, num_particles, forces, time_step);
    update_positions(particles, num_particles, time_step);
}

// Calculate the forces between particles
void calculate_forces(struct particle* particles, int num_particles, struct vector* forces) {
    for (int i = 0; i < num_particles; i++) {
        struct vector force = {0, 0};
        for (int j = 0; j < num_particles; j++) {
            if (i != j) {
                force = calculate_force(particles[i], particles[j]);
                forces[i].x += force.x;
                forces[i].y += force.y;
            }
        }
    }
}

// Update the velocities of particles
void update_velocities(struct particle* particles, int num_particles, struct vector* forces, double time_step) {
    for (int i = 0; i < num_particles; i++) {
        particles[i].velocity.x += forces[i].x / particles[i].mass * time_step;
        particles[i].velocity.y += forces[i].y / particles[i].mass * time_step;
    }
}

// Update the positions of particles
void update_positions(struct particle* particles, int num_particles, double time_step) {
    for (int i = 0; i < num_particles; i++) {
        particles[i].position.x += particles[i].velocity.x * time_step;
        particles[i].position.y += particles[i].velocity.y * time_step;
    }
}

// Calculate the force between two particles
struct vector calculate_force(struct particle p1, struct particle p2) {
    double distance = sqrt(pow(p1.position.x - p2.position.x, 2) + pow(p1.position.y - p2.position.y, 2));
    double force_magnitude = G * p1.mass * p2.mass / pow(distance, 2);
    double force_x = force_magnitude * (p2.position.x - p1.position.x) / distance;
    double force_y = force_magnitude * (p2.position.y - p1.position.y) / distance;
    struct vector force = {force_x, force_y};
    return force;
}