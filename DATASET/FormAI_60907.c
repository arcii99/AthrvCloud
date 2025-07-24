//FormAI DATASET v1.0 Category: Physics simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TOTAL_PARTICLES 1000 // Change this value to increase/decrease number of particles
#define BOX_SIZE 10 // Change this value to increase/decrease the size of the box
#define MAX_VELOCITY 1 // Change this value to increase/decrease the max velocity of the particles
#define MASS 1 // Change this value to change the mass of the particles

struct particle {
    double x, y, vx, vy, ax, ay, kinetic_energy;
};

double random_double() {
    return ((double) rand() / (RAND_MAX));
}

void calculate_forces(struct particle particles[]) {
    for (int i = 0; i < TOTAL_PARTICLES; i++) {
        particles[i].ax = 0;
        particles[i].ay = 0;
        for (int j = 0; j < TOTAL_PARTICLES; j++) {
            if (j == i) {
                continue;
            }
            double dx = particles[j].x - particles[i].x;
            double dy = particles[j].y - particles[i].y;
            double r = sqrt(dx * dx + dy * dy);
            double f = 1 / (r * r);
            particles[i].ax += f * dx / r;
            particles[i].ay += f * dy / r;
        }
    }
}

void move_particles(struct particle particles[], double time_step) {
    for (int i = 0; i < TOTAL_PARTICLES; i++) {
        particles[i].vx += particles[i].ax * time_step;
        particles[i].vy += particles[i].ay * time_step;
        particles[i].x += particles[i].vx * time_step;
        particles[i].y += particles[i].vy * time_step;
        particles[i].kinetic_energy = 0.5 * MASS * (particles[i].vx * particles[i].vx + particles[i].vy * particles[i].vy);
    }
}

void print_particle_info(struct particle particles[]) {
    for (int i = 0; i < TOTAL_PARTICLES; i++) {
        printf("Particle %d: x=%.2f, y=%.2f, vx=%.2f, vy=%.2f, KE=%.2f\n", i + 1,
            particles[i].x, particles[i].y, particles[i].vx, particles[i].vy, particles[i].kinetic_energy);
    }
}

int main() {
    srand(time(NULL));
    struct particle particles[TOTAL_PARTICLES];
    for (int i = 0; i < TOTAL_PARTICLES; i++) {
        particles[i].x = random_double() * BOX_SIZE;
        particles[i].y = random_double() * BOX_SIZE;
        particles[i].vx = (random_double() * 2 - 1) * MAX_VELOCITY;
        particles[i].vy = (random_double() * 2 - 1) * MAX_VELOCITY;
        particles[i].ax = 0;
        particles[i].ay = 0;
        particles[i].kinetic_energy = 0;
    }

    for (int i = 0; i < 1000; i++) { // Change this loop to increase/decrease simulation time
        calculate_forces(particles);
        move_particles(particles, 0.0001); // Change this value to increase/decrease time step
        print_particle_info(particles);
    }

    return 0;
}