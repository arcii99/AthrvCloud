//FormAI DATASET v1.0 Category: Physics simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITY 9.8

struct Particle {
    float position[3];
    float velocity[3];
    float acceleration[3];
    float mass;
};

typedef struct Particle Particle;

void update_particle(Particle *particle, float delta_time) {
    int i;
    for (i = 0; i < 3; i++) {
        particle->position[i] += particle->velocity[i] * delta_time;
        particle->velocity[i] += particle->acceleration[i] * delta_time;
    }
}

void add_gravity(Particle *particle) {
    particle->acceleration[1] -= GRAVITY * particle->mass;
}

void print_particle(Particle *particle) {
    int i;
    printf("Position: ");
    for (i = 0; i < 3; i++) {
        printf("%.2f ", particle->position[i]);
    }
    printf("\n");
}

int main() {
    Particle p1 = {{0, 0, 0}, {5, 5, 5}, {0, 0, 0}, 10.0};
    float delta_time = 0.05;
    int i;
    for (i = 0; i < 10; i++) {
        add_gravity(&p1);
        update_particle(&p1, delta_time);
        print_particle(&p1);
    }
    return 0;
}