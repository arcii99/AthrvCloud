//FormAI DATASET v1.0 Category: Physics simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_PARTICLES 1000
#define DELTA_T 0.001

typedef struct {
    float x;
    float y;
    float z;
} Vector3;

typedef struct {
    Vector3 position;
    Vector3 velocity;
    Vector3 acceleration;
    float mass;
} Particle;

Particle particles[NUM_PARTICLES];

void* updateParticle(void* arg) {
    int *index = (int*) arg;
    Particle *current = &particles[*index];
    Vector3 force = {0, 0, 0};

    for (int i = 0; i < NUM_PARTICLES; i++) {
        if (i == *index) continue;

        Particle *other = &particles[i];
        Vector3 direction = {
            other->position.x - current->position.x,
            other->position.y - current->position.y,
            other->position.z - current->position.z
        };
        
        float distance = powf(powf(direction.x, 2) + powf(direction.y, 2) + powf(direction.z, 2), 0.5);
        float magnitude = (current->mass * other->mass) / powf(distance, 2);
        
        force.x += direction.x / distance * magnitude;
        force.y += direction.y / distance * magnitude;
        force.z += direction.z / distance * magnitude;
    }

    Vector3 oldVelocity = current->velocity;

    current->acceleration.x = force.x / current->mass;
    current->acceleration.y = force.y / current->mass;
    current->acceleration.z = force.z / current->mass;

    current->velocity.x += (current->acceleration.x * DELTA_T) / 2;
    current->velocity.y += (current->acceleration.y * DELTA_T) / 2;
    current->velocity.z += (current->acceleration.z * DELTA_T) / 2;

    current->position.x += (oldVelocity.x + current->velocity.x) / 2 * DELTA_T;
    current->position.y += (oldVelocity.y + current->velocity.y) / 2 * DELTA_T;
    current->position.z += (oldVelocity.z + current->velocity.z) / 2 * DELTA_T;

    pthread_exit(NULL);
}

int main() {
    srand(time(0));

    for (int i = 0; i < NUM_PARTICLES; i++) {
        particles[i].position.x = rand() % 1000 - 500;
        particles[i].position.y = rand() % 1000 - 500;
        particles[i].position.z = rand() % 1000 - 500;
        particles[i].velocity.x = 0;
        particles[i].velocity.y = 0;
        particles[i].velocity.z = 0;
        particles[i].mass = rand() % 10 + 1;
    }

    pthread_t threads[NUM_PARTICLES];

    for (int timestep = 0; timestep < 1000; timestep++) {
        for (int i = 0; i < NUM_PARTICLES; i++) {
            pthread_create(&threads[i], NULL, updateParticle, &i);
        }

        for (int i = 0; i < NUM_PARTICLES; i++) {
            pthread_join(threads[i], NULL);
        }

        if (timestep % 10 == 0) {
            // Write output to file every 10 timesteps
            FILE *fp = fopen("output.txt", "a");
            for (int i = 0; i < NUM_PARTICLES; i++) {
                fprintf(fp, "%f,%f,%f\n", particles[i].position.x, particles[i].position.y, particles[i].position.z);
            }
            fclose(fp);
        }
    }

    return 0;
}