//FormAI DATASET v1.0 Category: Physics simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_PARTICLES 100
#define GRAV_CONST 6.6743e-11
#define SIM_TIME 10.0
#define TIMESTEP 0.01

typedef struct {
    double x;
    double y;
    double z;
} vector_t;

typedef struct {
    vector_t position;
    vector_t velocity;
    double mass;
} particle_t;

vector_t calculate_gravity(particle_t *particle1, particle_t *particle2) {
    double distance = sqrt(pow(particle1->position.x - particle2->position.x, 2) + pow(particle1->position.y - particle2->position.y, 2) + pow(particle1->position.z - particle2->position.z, 2));
    double force_magnitude = GRAV_CONST * particle1->mass * particle2->mass / pow(distance, 2);

    vector_t force;
    force.x = force_magnitude * (particle2->position.x - particle1->position.x) / distance;
    force.y = force_magnitude * (particle2->position.y - particle1->position.y) / distance;
    force.z = force_magnitude * (particle2->position.z - particle1->position.z) / distance;

    return force;
}

void update_particle(particle_t *particle, vector_t *net_force, double timestep) {
    vector_t acceleration;
    acceleration.x = net_force->x / particle->mass;
    acceleration.y = net_force->y / particle->mass;
    acceleration.z = net_force->z / particle->mass;

    particle->position.x += particle->velocity.x * timestep + 0.5 * acceleration.x * pow(timestep, 2);
    particle->position.y += particle->velocity.y * timestep + 0.5 * acceleration.y * pow(timestep, 2);
    particle->position.z += particle->velocity.z * timestep + 0.5 * acceleration.z * pow(timestep, 2);

    particle->velocity.x += acceleration.x * timestep;
    particle->velocity.y += acceleration.y * timestep;
    particle->velocity.z += acceleration.z * timestep;
}

int main() {
    particle_t particles[NUM_PARTICLES];

    // Initialize particles with random positions, velocities, and masses
    for (int i = 0; i < NUM_PARTICLES; i++) {
        particles[i].position.x = rand() / (double)RAND_MAX;
        particles[i].position.y = rand() / (double)RAND_MAX;
        particles[i].position.z = rand() / (double)RAND_MAX;

        particles[i].velocity.x = rand() / (double)RAND_MAX;
        particles[i].velocity.y = rand() / (double)RAND_MAX;
        particles[i].velocity.z = rand() / (double)RAND_MAX;

        particles[i].mass = rand() / (double)RAND_MAX;
    }

    // Run simulation
    double current_time = 0;
    while (current_time < SIM_TIME) {
        for (int i = 0; i < NUM_PARTICLES; i++) {
            vector_t net_force;
            net_force.x = net_force.y = net_force.z = 0;

            for (int j = 0; j < NUM_PARTICLES; j++) {
                if (i != j) {
                    vector_t gravity = calculate_gravity(&particles[i], &particles[j]);
                    net_force.x += gravity.x;
                    net_force.y += gravity.y;
                    net_force.z += gravity.z;
                }
            }

            update_particle(&particles[i], &net_force, TIMESTEP);
        }

        current_time += TIMESTEP;
    }

    // Print final positions of particles
    for (int i = 0; i < NUM_PARTICLES; i++) {
        printf("Particle %d: (%f, %f, %f)\n", i, particles[i].position.x, particles[i].position.y, particles[i].position.z);
    }

    return 0;
}