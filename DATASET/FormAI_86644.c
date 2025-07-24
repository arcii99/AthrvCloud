//FormAI DATASET v1.0 Category: Physics simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 50
#define MASS 10
#define GRAVITY 9.81

typedef struct {
    double x, y;
    double vx, vy;
    double ax, ay;
    double force_x, force_y;
    double mass;
} Particle;

void simulation_step(Particle *particles, int n, double dt) {
    for (int i = 0; i < n; i++) {
        particles[i].force_x = 0;
        particles[i].force_y = -GRAVITY * particles[i].mass;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dx = particles[j].x - particles[i].x;
            double dy = particles[j].y - particles[i].y;
            double r2 = dx * dx + dy * dy;
            double r = sqrt(r2);
            double f = MASS * MASS * GRAVITY / r2;

            particles[i].force_x += f * dx / r;
            particles[i].force_y += f * dy / r;

            particles[j].force_x -= f * dx / r;
            particles[j].force_y -= f * dy / r;
        }
    }

    for (int i = 0; i < n; i++) {
        particles[i].ax = particles[i].force_x / particles[i].mass;
        particles[i].ay = particles[i].force_y / particles[i].mass;

        particles[i].vx += particles[i].ax * dt;
        particles[i].vy += particles[i].ay * dt;

        particles[i].x += particles[i].vx * dt;
        particles[i].y += particles[i].vy * dt;
    }
}

int main() {
    Particle particles[SIZE];
    for (int i = 0; i < SIZE; i++) {
        particles[i].x = rand() % 20;
        particles[i].y = rand() % 20;
        particles[i].vx = 0;
        particles[i].vy = 0;
        particles[i].mass = rand() % MASS + MASS;
    }

    double t = 0;
    double dt = 0.1;

    while (t < 10) {
        simulation_step(particles, SIZE, dt);

        for (int i = 0; i < SIZE; i++) {
            printf("%.2f,%.2f ", particles[i].x, particles[i].y);
        }
        printf("\n");

        t += dt;
    }

    return 0;
}