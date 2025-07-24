//FormAI DATASET v1.0 Category: Physics simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define THREADS 4
#define G 6.6743e-11
#define TIME_INTERVAL 0.1
#define ITERATIONS 10000
#define PARTICLE_COUNT 100

typedef struct {
    double x, y, z;
    double vx, vy, vz;
    double mass;
} Particle;

typedef struct {
    int i, j;
} Pair;

Particle particles[PARTICLE_COUNT];
pthread_t threads[THREADS];

int currentIteration = 0;
int maxIterations = ITERATIONS;

Pair pairs[PARTICLE_COUNT * (PARTICLE_COUNT - 1) / 2];

double calculateDistance(Particle p1, Particle p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    double dz = p1.z - p2.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

void *calculateForces(void *threadID) {
    int tid = *((int *) threadID);

    for (int i = tid; i < PARTICLE_COUNT * (PARTICLE_COUNT - 1) / 2; i += THREADS) {
        int p1 = pairs[i].i;
        int p2 = pairs[i].j;
        double distance = calculateDistance(particles[p1], particles[p2]);
        double force = G * particles[p1].mass * particles[p2].mass / (distance * distance);

        double dx = particles[p2].x - particles[p1].x;
        double dy = particles[p2].y - particles[p1].y;
        double dz = particles[p2].z - particles[p1].z;
        double d = sqrt(dx * dx + dy * dy + dz * dz);

        particles[p1].vx += force * dx / d * TIME_INTERVAL / particles[p1].mass;
        particles[p1].vy += force * dy / d * TIME_INTERVAL / particles[p1].mass;
        particles[p1].vz += force * dz / d * TIME_INTERVAL / particles[p1].mass;

        particles[p2].vx -= force * dx / d * TIME_INTERVAL / particles[p2].mass;
        particles[p2].vy -= force * dy / d * TIME_INTERVAL / particles[p2].mass;
        particles[p2].vz -= force * dz / d * TIME_INTERVAL / particles[p2].mass;
    }

    return NULL;
}

void calculateForcesMT() {
    for (int i = 0; i < THREADS; i++) {
        pthread_create(&threads[i], NULL, calculateForces, &i);
    }

    for (int i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
}

void calculateForcesST() {
    for (int i = 0; i < PARTICLE_COUNT; i++) {
        for (int j = i + 1; j < PARTICLE_COUNT; j++) {
            double distance = calculateDistance(particles[i], particles[j]);
            double force = G * particles[i].mass * particles[j].mass / (distance * distance);

            double dx = particles[j].x - particles[i].x;
            double dy = particles[j].y - particles[i].y;
            double dz = particles[j].z - particles[i].z;
            double d = sqrt(dx * dx + dy * dy + dz * dz);

            particles[i].vx += force * dx / d * TIME_INTERVAL / particles[i].mass;
            particles[j].vx -= force * dx / d * TIME_INTERVAL / particles[j].mass;

            particles[i].vy += force * dy / d * TIME_INTERVAL / particles[i].mass;
            particles[j].vy -= force * dy / d * TIME_INTERVAL / particles[j].mass;

            particles[i].vz += force * dz / d * TIME_INTERVAL / particles[i].mass;
            particles[j].vz -= force * dz / d * TIME_INTERVAL / particles[j].mass;
        }
    }
}

void updatePositions() {
    for (int i = 0; i < PARTICLE_COUNT; i++) {
        particles[i].x += particles[i].vx * TIME_INTERVAL;
        particles[i].y += particles[i].vy * TIME_INTERVAL;
        particles[i].z += particles[i].vz * TIME_INTERVAL;
    }
}

void printParticles() {
    printf("\n");
    for (int i = 0; i < PARTICLE_COUNT; i++) {
        printf("%.2f %.2f %.2f\n", particles[i].x, particles[i].y, particles[i].z);
    }
}

void generatePairs() {
    int index = 0;
    for (int i = 0; i < PARTICLE_COUNT; i++) {
        for (int j = i + 1; j < PARTICLE_COUNT; j++) {
            pairs[index].i = i;
            pairs[index].j = j;
            index++;
        }
    }
}

int main() {
    for (int i = 0; i < PARTICLE_COUNT; i++) {
        particles[i].x = i;
        particles[i].y = i * 2;
        particles[i].z = 0;
        particles[i].vx = 0;
        particles[i].vy = 0;
        particles[i].vz = 0;
        particles[i].mass = rand() % 10;
    }

    generatePairs();

    while (currentIteration < maxIterations) {
        calculateForcesMT();
        updatePositions();
        currentIteration++;
    }

    printParticles();

    return 0;
}