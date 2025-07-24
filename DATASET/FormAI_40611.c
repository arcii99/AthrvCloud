//FormAI DATASET v1.0 Category: Physics simulation ; Style: safe
#include <stdio.h>
#include <math.h>

#define G 6.67430e-11  // Gravitational constant

typedef struct {
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Particle;

void update_particles(int n, Particle* particles, double dt) {
    int i, j;

    for (i = 0; i < n; i++) {
        double fx = 0, fy = 0, fz = 0;

        for (j = 0; j < n; j++) {
            if (i != j) {
                Particle other = particles[j];
                double dx = other.x - particles[i].x;
                double dy = other.y - particles[i].y;
                double dz = other.z - particles[i].z;
                double d = sqrt(dx*dx + dy*dy + dz*dz);
                double f = G * particles[i].mass * other.mass / (d*d);

                fx += f * dx / d;
                fy += f * dy / d;
                fz += f * dz / d;
            }
        }

        particles[i].vx += fx / particles[i].mass * dt;
        particles[i].vy += fy / particles[i].mass * dt;
        particles[i].vz += fz / particles[i].mass * dt;

        particles[i].x += particles[i].vx * dt;
        particles[i].y += particles[i].vy * dt;
        particles[i].z += particles[i].vz * dt;
    }
}

int main() {
    Particle particles[2] = {
        {1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {1.0, 1.0, 0.0, 0.0, 0.0, 0.01, 0.0}
    };

    int steps = 100000;
    double dt = 1e-6;

    for (int i = 0; i < steps; i++) {
        update_particles(2, particles, dt);
    }

    printf("Final positions:\n");
    for (int i = 0; i < 2; i++) {
        printf("(%g, %g, %g)\n", particles[i].x, particles[i].y, particles[i].z);
    }

    return 0;
}