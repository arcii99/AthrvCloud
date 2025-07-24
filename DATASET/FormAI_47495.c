//FormAI DATASET v1.0 Category: Physics simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define gravitational constant G
#define G 6.674E-11

// Define structure for particles
typedef struct particle {
    double x, y; // position
    double vx, vy; // velocity
    double m; // mass
} particle_t;

// Calculate force between two particles
void force(particle_t *p1, particle_t *p2, double *fx, double *fy) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double r = sqrt(dx*dx + dy*dy);
    double f = G * p1->m * p2->m / (r*r);
    *fx = f*dx/r;
    *fy = f*dy/r;
}

int main() {
    // Define particles
    particle_t particles[3] = {
        {0.0, 0.0, 5.0, 0.0, 10.0},
        {1.0, 0.0, 0.0, 0.0, 1.0},
        {1.0, 1.0, 0.0, 0.0, 1.0}
    };

    // Define time step and simulation duration
    double dt = 0.01;
    double t_end = 10.0;

    // Loop over time steps
    for (double t=0.0; t<t_end; t+=dt) {
        // Calculate forces
        double fx[3] = {0.0, 0.0, 0.0};
        double fy[3] = {0.0, 0.0, 0.0};
        for (int i=0; i<3; i++) {
            for (int j=i+1; j<3; j++) {
                double fxi, fyi;
                force(&particles[i], &particles[j], &fxi, &fyi);
                fx[i] += fxi;
                fy[i] += fyi;
                fx[j] -= fxi;
                fy[j] -= fyi;
            }
        }

        // Update positions and velocities
        for (int i=0; i<3; i++) {
            particles[i].x += particles[i].vx * dt;
            particles[i].y += particles[i].vy * dt;
            particles[i].vx += fx[i] / particles[i].m * dt;
            particles[i].vy += fy[i] / particles[i].m * dt;
        }

        // Print positions
        printf("t=%lf: (%lf,%lf) (%lf,%lf) (%lf,%lf)\n", t, particles[0].x, particles[0].y, particles[1].x, particles[1].y, particles[2].x, particles[2].y);
    }

    // Exit program
    return 0;
}