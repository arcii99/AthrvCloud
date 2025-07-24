//FormAI DATASET v1.0 Category: Physics simulation ; Style: artistic
#include <stdio.h>
#include <math.h>

#define GRAV_CONST 6.674e-11 // gravitational constant

// Define 'particle' structure
typedef struct {
    double x;
    double y;
    double mass;
    double vx;
    double vy;
} Particle;

// Define function to calculate distance between particles
double distance(Particle p1, Particle p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Define function to calculate gravitational force between particles
double grav_force(Particle p1, Particle p2) {
    return -GRAV_CONST * p1.mass * p2.mass / pow(distance(p1, p2), 2);
}

int main() {
    int num_particles = 3;
    Particle particles[num_particles];
    particles[0].x = 0.0;
    particles[0].y = 0.0;
    particles[0].mass = 1.0;
    particles[0].vx = 0.1;
    particles[0].vy = 0.0;

    particles[1].x = 100.0;
    particles[1].y = 0.0;
    particles[1].mass = 10.0;
    particles[1].vx = 0.0;
    particles[1].vy = 0.01;

    particles[2].x = 50.0;
    particles[2].y = 100.0;
    particles[2].mass = 5.0;
    particles[2].vx = -0.1;
    particles[2].vy = 0.04;

    double time_step = 0.001; // time step in seconds
    double total_time = 100.0; // total simulation time in seconds
    int num_steps = (int) (total_time / time_step);

    for (int i = 0; i < num_steps; i++) {
        // Calculate gravitational forces on each particle
        double forces[num_particles][2];
        for (int j = 0; j < num_particles; j++) {
            forces[j][0] = 0.0;
            forces[j][1] = 0.0;
            for (int k = 0; k < num_particles; k++) {
                if (j == k) {
                    continue;
                }
                double f = grav_force(particles[j], particles[k]);
                double angle = atan2(particles[k].y - particles[j].y, particles[k].x - particles[j].x);
                forces[j][0] += f * cos(angle);
                forces[j][1] += f * sin(angle);
            }
        }

        // Update velocities and positions of particles
        for (int j = 0; j < num_particles; j++) {
            particles[j].vx += forces[j][0] / particles[j].mass * time_step;
            particles[j].vy += forces[j][1] / particles[j].mass * time_step;
            particles[j].x += particles[j].vx * time_step;
            particles[j].y += particles[j].vy * time_step;
        }

        // Print particle positions
        printf("Time: %fs\n", i * time_step);
        for (int j = 0; j < num_particles; j++) {
            printf("Particle %d: (%f, %f)\n", j, particles[j].x, particles[j].y);
        }
        printf("\n");
    }

    return 0;
}