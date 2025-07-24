//FormAI DATASET v1.0 Category: Physics simulation ; Style: mathematical
#include <stdio.h>
#define G 6.67430E-11 // Gravitational constant

struct particle { // structure for particles
    double x, y; // position
    double m; // mass
    double vx, vy; // velocity
    double ax, ay; // acceleration
};

double distance(struct particle p1, struct particle p2) { // function to calculate distance between two particles
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;

    return sqrt(dx*dx + dy*dy);
}

double force(struct particle p1, struct particle p2) { // function to calculate gravitational force between two particles
    double dist = distance(p1, p2);
    double f = G * p1.m * p2.m / (dist * dist);

    return f;
}

int main() {
    int n = 3; // number of particles
    struct particle particles[n];

    // initialize particles
    particles[0].x = 0; particles[0].y = 0; particles[0].m = 10;
    particles[1].x = 0; particles[1].y = 5; particles[1].m = 20;
    particles[2].x = 5; particles[2].y = 0; particles[2].m = 15;

    for (int i = 0; i < n; i++) {
        particles[i].vx = 0;
        particles[i].vy = 0;
        particles[i].ax = 0;
        particles[i].ay = 0;
    }

    double dt = 0.01; // time step

    for (int step = 0; step < 1000; step++) { // simulate 1000 time steps
        for (int i = 0; i < n; i++) { // calculate acceleration for each particle
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                double f = force(particles[i], particles[j]);
                double dist = distance(particles[i], particles[j]);
                double fx = f * (particles[j].x - particles[i].x) / dist;
                double fy = f * (particles[j].y - particles[i].y) / dist;

                particles[i].ax += fx / particles[i].m;
                particles[i].ay += fy / particles[i].m;
            }
        }

        for (int i = 0; i < n; i++) { // update position and velocity for each particle
            particles[i].x += particles[i].vx * dt + 0.5 * particles[i].ax * dt * dt;
            particles[i].y += particles[i].vy * dt + 0.5 * particles[i].ay * dt * dt;
            particles[i].vx += particles[i].ax * dt;
            particles[i].vy += particles[i].ay * dt;
        }

        // print position of each particle
        printf("Step %d:\n", step+1);
        for (int i = 0; i < n; i++) {
            printf("Particle %d: (%.2f, %.2f)\n", i+1, particles[i].x, particles[i].y);
        }
        printf("\n");
    }

    return 0;
}