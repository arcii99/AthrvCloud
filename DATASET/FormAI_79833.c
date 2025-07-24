//FormAI DATASET v1.0 Category: Physics simulation ; Style: asynchronous
// Asynchronous Physics Simulation Example Program in C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_PARTICLES 10000
#define MASS_RANGE 10
#define POS_RANGE 100
#define VEL_RANGE 10
#define TIME_STEP 0.01
#define NUM_THREADS 4

/* Struct to store data for each particle */
typedef struct {
    double mass;        // Mass of particle
    double pos[3];      // Position vector
    double vel[3];      // Velocity vector
} Particle;

/* Global variables */
Particle particles[NUM_PARTICLES];

/* Function to initialize particles */
void initParticles() {
    for(int i=0; i<NUM_PARTICLES; i++) {
        particles[i].mass = (double)(rand() % MASS_RANGE + 1);
        for(int j=0; j<3; j++) {
            particles[i].pos[j] = (double)(rand() % POS_RANGE + 1);
            particles[i].vel[j] = (double)(rand() % VEL_RANGE + 1);
        }
    }
}

/* Function to update velocity of a particle based on the gravitational force from all other particles */
void* updateVel(void* arg) {
    int id = *(int*)arg;
    int start = (NUM_PARTICLES / NUM_THREADS) * id;
    int end = (id == NUM_THREADS - 1) ? NUM_PARTICLES : (NUM_PARTICLES / NUM_THREADS) * (id + 1);

    for(int i=start; i<end; i++) {
        double force[3] = {0, 0, 0};
        for(int j=0; j<NUM_PARTICLES; j++) {
            if(i == j) continue;
            double dist[3];
            for(int k=0; k<3; k++) {
                dist[k] = particles[j].pos[k] - particles[i].pos[k];
                force[k] += (particles[i].mass * particles[j].mass) / (dist[k] * dist[k]);
            }
        }
        for(int j=0; j<3; j++) {
            particles[i].vel[j] += force[j] * TIME_STEP / particles[i].mass;
        }
    }

    return NULL;
}

/* Main function */
int main() {
    srand(time(NULL));      // Seed random number generator

    initParticles();        // Initialize particles

    pthread_t threads[NUM_THREADS];

    // Create threads to update velocities
    for(int t=0; t<NUM_THREADS; t++) {
        int* id = malloc(sizeof(int));
        *id = t;
        pthread_create(&threads[t], NULL, updateVel, (void*)id);
    }

    // Wait for threads to finish
    for(int t=0; t<NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    // Print final positions and velocities of particles
    for(int i=0; i<NUM_PARTICLES; i++) {
        printf("Particle %d: Position (%f, %f, %f), Velocity (%f, %f, %f)\n", i+1, particles[i].pos[0], particles[i].pos[1], particles[i].pos[2], particles[i].vel[0], particles[i].vel[1], particles[i].vel[2]);
    }

    return 0;
}