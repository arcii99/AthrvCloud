//FormAI DATASET v1.0 Category: Physics simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PARTICLES 1000

struct Vector3 {
    float x, y, z;
};

struct Particle {
    float mass;
    struct Vector3 position;
    struct Vector3 velocity;
};

struct Simulation {
    struct Particle particles[MAX_PARTICLES];
    int count;
};

float rand_float(float min, float max) {
    return min + (max - min) * ((float)rand() / RAND_MAX);
}

void initialize_simulation(struct Simulation * sim) {
    sim->count = 0;
    srand((unsigned int)time(NULL));
    for (int i = 0; i < MAX_PARTICLES; i++) {
        if (rand() % 2) {
            sim->particles[sim->count].mass = rand_float(1.0, 10.0);
            sim->particles[sim->count].position.x = rand_float(-10.0, 10.0);
            sim->particles[sim->count].position.y = rand_float(-10.0, 10.0);
            sim->particles[sim->count].position.z = rand_float(-10.0, 10.0);
            sim->particles[sim->count].velocity.x = rand_float(-1.0, 1.0);
            sim->particles[sim->count].velocity.y = rand_float(-1.0, 1.0);
            sim->particles[sim->count].velocity.z = rand_float(-1.0, 1.0);
            sim->count++;
        }
    }
}

void update_simulation(struct Simulation * sim, float delta_time) {
    for (int i = 0; i < sim->count; i++) {
        for (int j = i+1; j < sim->count; j++) {
            struct Vector3 direction = {
                sim->particles[j].position.x - sim->particles[i].position.x,
                sim->particles[j].position.y - sim->particles[i].position.y,
                sim->particles[j].position.z - sim->particles[i].position.z,
            };
            float distance_squared = direction.x*direction.x + direction.y*direction.y + direction.z*direction.z;
            float force_magnitude = sim->particles[i].mass * sim->particles[j].mass / distance_squared;
            float force_x = force_magnitude * direction.x / distance_squared;
            float force_y = force_magnitude * direction.y / distance_squared;
            float force_z = force_magnitude * direction.z / distance_squared;
            sim->particles[i].velocity.x += delta_time * force_x / sim->particles[i].mass;
            sim->particles[j].velocity.x -= delta_time * force_x / sim->particles[j].mass;
            sim->particles[i].velocity.y += delta_time * force_y / sim->particles[i].mass;
            sim->particles[j].velocity.y -= delta_time * force_y / sim->particles[j].mass;
            sim->particles[i].velocity.z += delta_time * force_z / sim->particles[i].mass;
            sim->particles[j].velocity.z -= delta_time * force_z / sim->particles[j].mass;
        }
    }
    for (int i = 0; i < sim->count; i++) {
        sim->particles[i].position.x += delta_time * sim->particles[i].velocity.x;
        sim->particles[i].position.y += delta_time * sim->particles[i].velocity.y;
        sim->particles[i].position.z += delta_time * sim->particles[i].velocity.z;
    }
}

int main() {
    struct Simulation sim;
    initialize_simulation(&sim);
    for (int i = 0; i < 100; i++) {
        update_simulation(&sim, 0.1);
        for (int j = 0; j < sim.count; j++) {
            printf("%f, %f, %f\n", sim.particles[j].position.x, sim.particles[j].position.y, sim.particles[j].position.z);
        }
    }
    return 0;
}