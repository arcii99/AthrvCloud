//FormAI DATASET v1.0 Category: Physics simulation ; Style: Donald Knuth
// Donald Knuth Style Physics Simulation Example

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

// Define a structure to represent a particle
struct particle {
    double x, y;    // position
    double vx, vy;  // velocity
    double m;       // mass
};

int main() {
    // Create an array of particles
    struct particle particles[3] = {
        {1.0, 0.0, 0.0, 0.0, 1.0},     // Particle 1
        {1.0, 1.0, 0.0, 0.0, 2.0},     // Particle 2
        {0.0, 0.0, 0.0, 0.0, 3.0}      // Particle 3
    };

    double dt = 0.01;   // time step
    double t = 0.0;     // current time
    double G = 6.67e-11; // gravitational constant

    // Perform simulation for a fixed number of steps
    for (int step = 0; step < 1000; step++) {
        // Print particle positions
        printf("Time: %lf\n", t);
        for (int i = 0; i < 3; i++) {
            printf("Particle %d: (%lf, %lf)\n", i+1, particles[i].x, particles[i].y);
        }

        // Compute forces between particles
        for (int i = 0; i < 3; i++) {
            double Fx = 0.0;
            double Fy = 0.0;
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                double dx = particles[j].x - particles[i].x;
                double dy = particles[j].y - particles[i].y;
                double r = sqrt(dx*dx + dy*dy);
                double F = G * particles[i].m * particles[j].m / (r*r);
                double theta = atan2(dy, dx);
                Fx += F * cos(theta);
                Fy += F * sin(theta);
            }
            particles[i].vx += Fx / particles[i].m * dt;
            particles[i].vy += Fy / particles[i].m * dt;
        }

        // Update particle positions
        for (int i = 0; i < 3; i++) {
            particles[i].x += particles[i].vx * dt;
            particles[i].y += particles[i].vy * dt;
        }

        // Increment time
        t += dt;
    }

    return 0;
}