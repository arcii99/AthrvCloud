//FormAI DATASET v1.0 Category: Physics simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10 // Define number of particles

typedef struct {
    double x;
    double y;
    double vx;
    double vy;
    double ax;
    double ay;
    double fx;
    double fy;
} Particle;

void calculate_force(Particle* particles) {
    // Calculate force acting on each particle
    for (int i = 0; i < N; i++) {
        particles[i].fx = 0.0;
        particles[i].fy = 0.0;

        for (int j = 0; j < N; j++) {
            if (i == j) continue;

            double dx = particles[j].x - particles[i].x;
            double dy = particles[j].y - particles[i].y;
            double r = sqrt(dx*dx + dy*dy);
            double f = 1.0/(r*r);

            particles[i].fx += f*dx/r;
            particles[i].fy += f*dy/r;
        }
    }
}

void move_particles(Particle* particles, double dt) {
    // Move particles based on velocity and acceleration
    for (int i = 0; i < N; i++) {
        particles[i].vx += particles[i].ax*dt;
        particles[i].vy += particles[i].ay*dt;
        particles[i].x += particles[i].vx*dt;
        particles[i].y += particles[i].vy*dt;
    }
}

void update_acceleration(Particle* particles) {
    // Update acceleration based on force
    for (int i = 0; i < N; i++) {
        particles[i].ax = particles[i].fx;
        particles[i].ay = particles[i].fy;
    }
}

int main() {
    Particle particles[N];

    // Initialize particle positions
    for (int i = 0; i < N; i++) {
        particles[i].x = rand()/(double)RAND_MAX;
        particles[i].y = rand()/(double)RAND_MAX;
        particles[i].vx = 0.0;
        particles[i].vy = 0.0;
        particles[i].ax = 0.0;
        particles[i].ay = 0.0;
        particles[i].fx = 0.0;
        particles[i].fy = 0.0;
    }

    // Time evolution
    double t = 0.0;
    double dt = 0.01;
    int nsteps = 10000;

    for (int i = 0; i < nsteps; i++) {
        calculate_force(particles);
        update_acceleration(particles);
        move_particles(particles, dt);
        t += dt;
    }

    return 0;
}