//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define G 9.8
#define DT 0.1
#define N 2

typedef struct {
    double x, y, vx, vy, ax, ay, m;
} Particle;

void init_particles(Particle *particles, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        particles[i].x = 0.5 * rand() / (double) RAND_MAX + 0.25;
        particles[i].y = 0.5 * rand() / (double) RAND_MAX + 0.25;
        particles[i].vx = 0;
        particles[i].vy = 0;
        particles[i].ax = 0;
        particles[i].ay = 0;
        particles[i].m = 0.01;
    }
}

void update_particle(Particle *particles, int n) {
    double fx, fy, r2, dx, dy;
    for (int i = 0; i < n; i++) {
        fx = fy = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            dx = particles[j].x - particles[i].x;
            dy = particles[j].y - particles[i].y;
            r2 = dx * dx + dy * dy;
            fx += G * particles[j].m * particles[i].m * dx / r2;
            fy += G * particles[j].m * particles[i].m * dy / r2;
        }
        particles[i].ax = fx / particles[i].m;
        particles[i].ay = fy / particles[i].m;
        particles[i].vx += particles[i].ax * DT;
        particles[i].vy += particles[i].ay * DT;
        particles[i].x += particles[i].vx * DT;
        particles[i].y += particles[i].vy * DT;
    }
}

void print_particles(Particle *particles, int n) {
    printf("Particles:\n");
    for (int i = 0; i < n; i++) {
        printf("(%g, %g)\n", particles[i].x, particles[i].y);
    }
}

int main() {
    Particle particles[N];
    init_particles(particles, N);
    for (int i = 0; i < 1000; i++) {
        update_particle(particles, N);
    }
    print_particles(particles, N);
    return 0;
}