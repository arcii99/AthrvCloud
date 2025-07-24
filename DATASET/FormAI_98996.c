//FormAI DATASET v1.0 Category: Physics simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define DELTA_T 0.01 // Time step size
#define MASS 1.0 // Mass of particle
#define NUM_PARTICLES 10 // Number of particles in simulation
#define BOUNDARY 10.0 // Size of boundary

typedef struct Vector {
    double x;
    double y;
} Vector;

typedef struct Particle {
    Vector pos; // Position
    Vector vel; // Velocity
} Particle;

void update_position(Particle *p) {
    p->pos.x += p->vel.x * DELTA_T;
    p->pos.y += p->vel.y * DELTA_T;
}

void update_velocity(Particle *p, Vector force) {
    p->vel.x += force.x * DELTA_T / MASS;
    p->vel.y += force.y * DELTA_T / MASS;
}

Vector calculate_force(Vector a, Vector b) {
    double r = sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
    Vector force;
    force.x = -(a.x - b.x) / r;
    force.y = -(a.y - b.y) / r;
    return force;
}

void check_boundary(Particle *p) {
    if (p->pos.x > BOUNDARY) p->pos.x = BOUNDARY;
    if (p->pos.x < -BOUNDARY) p->pos.x = -BOUNDARY;
    if (p->pos.y > BOUNDARY) p->pos.y = BOUNDARY;
    if (p->pos.y < -BOUNDARY) p->pos.y = -BOUNDARY;
}

void print_particles(Particle particles[]) {
    for (int i = 0; i < NUM_PARTICLES; i++) {
        printf("Particle %d: (%.2f, %.2f)\n", i, particles[i].pos.x, particles[i].pos.y);
    }
}

int main() {
    Particle particles[NUM_PARTICLES];
    srand(0);
    for (int i = 0; i < NUM_PARTICLES; i++) {
        particles[i].pos.x = ((double)rand() / RAND_MAX) * (BOUNDARY * 2) - BOUNDARY;
        particles[i].pos.y = ((double)rand() / RAND_MAX) * (BOUNDARY * 2) - BOUNDARY;
        particles[i].vel.x = ((double)rand() / RAND_MAX) * 2 - 1;
        particles[i].vel.y = ((double)rand() / RAND_MAX) * 2 - 1;
    }
    for (double t = 0; t < 10; t += DELTA_T) {
        Vector forces[NUM_PARTICLES] = {0};
        for (int i = 0; i < NUM_PARTICLES; i++) {
            for (int j = i+1; j < NUM_PARTICLES; j++) {
                Vector force = calculate_force(particles[i].pos, particles[j].pos);
                forces[i].x += force.x;
                forces[i].y += force.y;
                forces[j].x -= force.x;
                forces[j].y -= force.y;
            }
        }
        for (int i = 0; i < NUM_PARTICLES; i++) {
            update_velocity(&particles[i], forces[i]);
            update_position(&particles[i]);
            check_boundary(&particles[i]);
        }
        print_particles(particles);
    }
    return 0;
}