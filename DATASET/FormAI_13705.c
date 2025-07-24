//FormAI DATASET v1.0 Category: Physics simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G_CONSTANT 6.67430e-11      // gravitational constant in m^3 kg^-1 s^-2
#define TIME_STEP 0.01             // time step used in simulation, in seconds

// Structure to hold each particle's properties
typedef struct {
    double mass;             // mass, in kg
    double position[3];      // position, in m
    double velocity[3];      // velocity, in m/s
    double acceleration[3];  // acceleration, in m/s^2
} Particle;

// Function to calculate the distance between two particles
double calculate_distance(Particle particle1, Particle particle2) {
    double dx = particle1.position[0] - particle2.position[0];
    double dy = particle1.position[1] - particle2.position[1];
    double dz = particle1.position[2] - particle2.position[2];
    return sqrt(dx*dx + dy*dy + dz*dz);
}

// Function to calculate the gravitational force between two particles
double calculate_force(Particle particle1, Particle particle2) {
    double distance = calculate_distance(particle1, particle2);
    double force = G_CONSTANT * particle1.mass * particle2.mass / (distance*distance);
    return force;
}

// Function to update a particle's position and velocity based on its current acceleration
void update_particle(Particle *particle) {
    particle->position[0] += particle->velocity[0] * TIME_STEP + 0.5 * particle->acceleration[0] * TIME_STEP * TIME_STEP;
    particle->position[1] += particle->velocity[1] * TIME_STEP + 0.5 * particle->acceleration[1] * TIME_STEP * TIME_STEP;
    particle->position[2] += particle->velocity[2] * TIME_STEP + 0.5 * particle->acceleration[2] * TIME_STEP * TIME_STEP;
    particle->velocity[0] += particle->acceleration[0] * TIME_STEP;
    particle->velocity[1] += particle->acceleration[1] * TIME_STEP;
    particle->velocity[2] += particle->acceleration[2] * TIME_STEP;
}

int main() {
    // Initialize particles
    Particle particle1 = {1.3e16, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    Particle particle2 = {1.8e16, {1e11, 0, 0}, {0, 3e4, 0}, {0, 0, 0}};

    // Run simulation for 1 year
    double simulation_time = 365.25 * 24 * 60 * 60;
    int num_steps = simulation_time / TIME_STEP;

    for (int i = 0; i < num_steps; i++) {
        // Calculate gravitational forces between particles
        double force12 = calculate_force(particle1, particle2);
        double force21 = calculate_force(particle2, particle1);

        // Calculate acceleration of each particle based on force
        particle1.acceleration[0] = -force12 * (particle1.position[0] - particle2.position[0]) / (particle1.mass * calculate_distance(particle1, particle2));
        particle1.acceleration[1] = -force12 * (particle1.position[1] - particle2.position[1]) / (particle1.mass * calculate_distance(particle1, particle2));
        particle1.acceleration[2] = -force12 * (particle1.position[2] - particle2.position[2]) / (particle1.mass * calculate_distance(particle1, particle2));
        particle2.acceleration[0] = -force21 * (particle2.position[0] - particle1.position[0]) / (particle2.mass * calculate_distance(particle2, particle1));
        particle2.acceleration[1] = -force21 * (particle2.position[1] - particle1.position[1]) / (particle2.mass * calculate_distance(particle2, particle1));
        particle2.acceleration[2] = -force21 * (particle2.position[2] - particle1.position[2]) / (particle2.mass * calculate_distance(particle2, particle1));

        // Update particles' positions and velocities
        update_particle(&particle1);
        update_particle(&particle2);
    }

    // Output final positions and velocities of particles
    printf("Final position and velocity of particle 1:\n");
    printf("(%f, %f, %f)\n", particle1.position[0], particle1.position[1], particle1.position[2]);
    printf("(%f, %f, %f)\n", particle1.velocity[0], particle1.velocity[1], particle1.velocity[2]);
    printf("Final position and velocity of particle 2:\n");
    printf("(%f, %f, %f)\n", particle2.position[0], particle2.position[1], particle2.position[2]);
    printf("(%f, %f, %f)\n", particle2.velocity[0], particle2.velocity[1], particle2.velocity[2]);

    return 0;
}