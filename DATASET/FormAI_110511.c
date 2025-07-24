//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4 // Number of threads
#define SIZE 100 // Size of planet array
#define X 0 
#define Y 1
#define Z 2
#define G 6.67430E-11 

double position[SIZE][3]; // Position of planets 
double velocity[SIZE][3]; // Velocity of planets 
double mass[SIZE]; // Mass of planets 
double force[SIZE][3]; // Force on each planet 
double deltaT; // Time step
int numSteps; // Number of simulation steps

pthread_barrier_t barrier; // Barrier for thread syncronization

void simulate(int thread_id) {
    int start = (int) (((double) SIZE / (double) NUM_THREADS) * thread_id);
    int end = (int) (((double) SIZE / (double) NUM_THREADS) * (thread_id + 1));
    for (int step = 0; step < numSteps; step++) {
        for (int i = start; i < end; i++) {
            force[i][X] = 0;
            force[i][Y] = 0;
            force[i][Z] = 0;
            for (int j = 0; j < SIZE; j++) {
                if (i != j) {
                    double r[3];
                    r[X] = position[j][X] - position[i][X];
                    r[Y] = position[j][Y] - position[i][Y];
                    r[Z] = position[j][Z] - position[i][Z];
                    double distance = sqrt(r[X] * r[X] + r[Y] * r[Y] + r[Z] * r[Z]);
                    double f = (G * mass[j] * mass[i]) / (distance * distance);
                    force[i][X] += f * r[X] / distance;
                    force[i][Y] += f * r[Y] / distance;
                    force[i][Z] += f * r[Z] / distance;
                }
            }
        }

        pthread_barrier_wait(&barrier); // Syncronize all threads

        // Update velocity and position for each planet
        for (int i = start; i < end; i++) {
            velocity[i][X] += force[i][X] * deltaT / mass[i];
            velocity[i][Y] += force[i][Y] * deltaT / mass[i];
            velocity[i][Z] += force[i][Z] * deltaT / mass[i];
            position[i][X] += velocity[i][X] * deltaT;
            position[i][Y] += velocity[i][Y] * deltaT;
            position[i][Z] += velocity[i][Z] * deltaT;
        }

        pthread_barrier_wait(&barrier); // Syncronize all threads
    }
}

int main() {
    deltaT = 10.0; // time step
    numSteps = 100; // Number of simulation steps
    
    // initialize planets
    for (int i = 0; i < SIZE; i++) {
        position[i][X] = (double) rand() / (double) RAND_MAX;
        position[i][Y] = (double) rand() / (double) RAND_MAX;
        position[i][Z] = (double) rand() / (double) RAND_MAX;
        velocity[i][X] = (double) rand() / (double) RAND_MAX;
        velocity[i][Y] = (double) rand() / (double) RAND_MAX;
        velocity[i][Z] = (double) rand() / (double) RAND_MAX;
        mass[i] = (double) rand() / (double) RAND_MAX;
    }

    pthread_t threads[NUM_THREADS];
    pthread_barrier_init(&barrier, NULL, NUM_THREADS);

    // Create threads
    for (int t = 0; t < NUM_THREADS; t++) {
        pthread_create(&threads[t], NULL, (void*) &simulate, (void*) t);
    }

    // Wait for threads to complete
    for (int t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    // Print final positions of each planet
    for (int i = 0; i < SIZE; i++) {
        printf("Planet %d: (%f, %f, %f)\n", i+1, position[i][X], position[i][Y], position[i][Z]);
    }

    return 0;
}