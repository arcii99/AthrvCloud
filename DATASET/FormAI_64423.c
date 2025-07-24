//FormAI DATASET v1.0 Category: Physics simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <pthread.h>

#define NUM_PARTICLES 1000
#define DELTA_T 0.1
#define THREAD_COUNT 4

// particle structure
typedef struct particle_t {
    double x;
    double y;
    double vx;
    double vy;
    double m;
} Particle;

// global variables
Particle particles[NUM_PARTICLES];
pthread_mutex_t lock;

// function prototypes
void *particleCalculation(void *);

int main() {
    int i, j;
    double fx, fy;
    
    // seed random number generator
    srand((unsigned) time(NULL));
    
    // initialize particles
    for (i = 0; i < NUM_PARTICLES; i++) {
        particles[i].x = rand() % 100;
        particles[i].y = rand() % 100;
        particles[i].vx = (rand() % 100) / 10.0;
        particles[i].vy = (rand() % 100) / 10.0;
        particles[i].m = (rand() % 10) + 1;
    }
    
    // create threads
    pthread_t threads[THREAD_COUNT];
    for (i = 0; i < THREAD_COUNT; i++) {
        pthread_create(&threads[i], NULL, particleCalculation, (void *) i);
    }
    
    // join threads
    for (i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // print final positions
    for (i = 0; i < NUM_PARTICLES; i++) {
        printf("Particle %d: (%.2f, %.2f)\n", i, particles[i].x, particles[i].y);
    }
    
    return 0;
}

void *particleCalculation(void *arg) {
    int id = (int) arg;
    double fx, fy, dx, dy, r;
    int i, j;
    
    // calculate particles for this thread
    for (i = id * NUM_PARTICLES / THREAD_COUNT; i < (id + 1) * NUM_PARTICLES / THREAD_COUNT; i++) {
        
        // reset acceleration
        fx = fy = 0;
        
        // calculate acceleration from other particles
        for (j = 0; j < NUM_PARTICLES; j++) {
            if (i == j) continue;
            dx = particles[j].x - particles[i].x;
            dy = particles[j].y - particles[i].y;
            r = sqrt(dx*dx + dy*dy);
            if (r < 1) r = 1;
            fx += dx * particles[j].m / (r*r*r);
            fy += dy * particles[j].m / (r*r*r);
        }
        
        // update velocity and position
        particles[i].vx += fx * DELTA_T / particles[i].m;
        particles[i].vy += fy * DELTA_T / particles[i].m;
        particles[i].x += particles[i].vx * DELTA_T;
        particles[i].y += particles[i].vy * DELTA_T;
    }
    
    // lock mutex and update global particle array
    pthread_mutex_lock(&lock);
    for (i = id * NUM_PARTICLES / THREAD_COUNT; i < (id + 1) * NUM_PARTICLES / THREAD_COUNT; i++) {
        particles[i] = particles[i];
    }
    pthread_mutex_unlock(&lock);
    
    // exit thread
    pthread_exit(NULL);
}