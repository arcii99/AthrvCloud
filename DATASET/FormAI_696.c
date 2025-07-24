//FormAI DATASET v1.0 Category: Physics simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Define physical constants
#define GRAVITATIONAL_CONSTANT 6.67430e-11 // m^3/kg/s^2
#define PI 3.14159265359

// Define struct for particle with position, velocity, mass, and radius
typedef struct Particle {
    double mass;
    double radius;
    double position[2]; // x, y
    double velocity[2]; // vx, vy
} Particle;

// Define function for calculating the force between two particles
double calculate_force(Particle particle1, Particle particle2) {
    double distance = sqrt(pow(particle2.position[0]-particle1.position[0], 2) + pow(particle2.position[1]-particle1.position[1], 2));
    double force = GRAVITATIONAL_CONSTANT * particle1.mass * particle2.mass / pow(distance, 2);
    return force;
}

int main() {
    // Define particles
    Particle particle1 = {100000, 10, {0, 0}, {0, 0}};
    Particle particle2 = {1000, 1, {50, 50}, {10, 0}};

    // Define simulation variables
    double time_step = 0.1;
    double simulation_time = 10;
    int steps = (int)(simulation_time / time_step);
    double current_time = 0;
    double acceleration1[2];
    double acceleration2[2];
    double force;

    // Run simulation
    for (int i = 0; i < steps; i++) {
        // Calculate force and acceleration for particle1
        force = calculate_force(particle1, particle2);
        acceleration1[0] = force / particle1.mass * cos(PI/4);
        acceleration1[1] = force / particle1.mass * sin(PI/4);

        // Calculate force and acceleration for particle2
        force = calculate_force(particle2, particle1);
        acceleration2[0] = force / particle2.mass;
        acceleration2[1] = 0;

        // Calculate new velocity and position for each particle
        for (int j = 0; j < 2; j++) {
            particle1.velocity[j] += acceleration1[j] * time_step;
            particle1.position[j] += particle1.velocity[j] * time_step;
            particle2.velocity[j] += acceleration2[j] * time_step;
            particle2.position[j] += particle2.velocity[j] * time_step;
        }

        // Print out current time and positions
        printf("time: %lf\tparticle1 position: (%lf, %lf)\tparticle2 position: (%lf, %lf)\n", current_time, particle1.position[0], particle1.position[1], particle2.position[0], particle2.position[1]);
        current_time += time_step;
    }

    return 0;
}