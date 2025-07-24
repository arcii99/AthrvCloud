//FormAI DATASET v1.0 Category: Physics simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 50

typedef struct {
    float x, y, z;
} Vector;

typedef struct {
    Vector position;
    Vector velocity;
    Vector acceleration;
    float mass;
} Particle;

void init_particles(Particle particles[]) {
    for (int i = 0; i < SIZE; i++) {
        particles[i].position.x = rand() % 100;
        particles[i].position.y = rand() % 100;
        particles[i].position.z = rand() % 100;

        particles[i].velocity.x = 0;
        particles[i].velocity.y = 0;
        particles[i].velocity.z = 0;

        particles[i].acceleration.x = 0;
        particles[i].acceleration.y = 0;
        particles[i].acceleration.z = 0;

        particles[i].mass = 1 + (rand() % 10);
    }
}

void calculate_forces(Particle particles[]) {
    for (int i = 0; i < SIZE; i++) {
        particles[i].acceleration.x = 0;
        particles[i].acceleration.y = 0;
        particles[i].acceleration.z = 0;

        for (int j = 0; j < SIZE; j++) {
            if (i != j) {
                float distance = sqrt(pow(particles[j].position.x - particles[i].position.x, 2) 
                        + pow(particles[j].position.y - particles[i].position.y, 2)
                        + pow(particles[j].position.z - particles[i].position.z, 2));

                float force = particles[j].mass / pow(distance, 2);

                particles[i].acceleration.x += force * (particles[j].position.x - particles[i].position.x) / distance;
                particles[i].acceleration.y += force * (particles[j].position.y - particles[i].position.y) / distance;
                particles[i].acceleration.z += force * (particles[j].position.z - particles[i].position.z) / distance;
            }
        }
    }
}

void update_particles(Particle particles[], float dt) {
    for (int i = 0; i < SIZE; i++) {
        particles[i].position.x += particles[i].velocity.x * dt + 0.5 * particles[i].acceleration.x * pow(dt, 2);
        particles[i].position.y += particles[i].velocity.y * dt + 0.5 * particles[i].acceleration.y * pow(dt, 2);
        particles[i].position.z += particles[i].velocity.z * dt + 0.5 * particles[i].acceleration.z * pow(dt, 2);

        particles[i].velocity.x += particles[i].acceleration.x * dt;
        particles[i].velocity.y += particles[i].acceleration.y * dt;
        particles[i].velocity.z += particles[i].acceleration.z * dt;
    }
}

int main() {
    srand(time(NULL));

    Particle particles[SIZE];

    init_particles(particles);

    float time_step = 0.01;

    printf("Initial positions:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("(%f, %f, %f)\n", particles[i].position.x, particles[i].position.y, particles[i].position.z);
    }

    for (int i = 0; i < 1000; i++) {
        calculate_forces(particles);
        update_particles(particles, time_step);
    }

    printf("\nFinal positions:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("(%f, %f, %f)\n", particles[i].position.x, particles[i].position.y, particles[i].position.z);
    }

    return 0;
}