//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11      // gravitational constant
#define num_particles 100 // number of particles

// particle struct with position and velocity data
struct particle {
    double x_pos;
    double y_pos;
    double x_vel;
    double y_vel;
};

// function to calculate gravitational force
void calc_force(double m1, double m2, double x1, double y1, double x2, double y2, double *f_x, double *f_y) {
    double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)); // distance between particles
    double force = G * m1 * m2 / pow(dist, 2);              // magnitude of force
    *f_x = force * (x2 - x1) / dist;                        // x component of force
    *f_y = force * (y2 - y1) / dist;                        // y component of force
}

int main () {
    int i, j, k;
    double time_step = 0.01;             // time step for simulation
    double m[num_particles];             // mass of particles
    double x[num_particles], y[num_particles], x_vel[num_particles], y_vel[num_particles]; // particle position and velocity arrays
    double f_x[num_particles], f_y[num_particles]; // particle force arrays

    // initialize particle properties randomly
    for (i = 0; i < num_particles; i++) {
        m[i] = rand() % 10 + 1;          // mass between 1 and 10
        x[i] = rand() % 100 + 1;         // x position between 1 and 100
        y[i] = rand() % 100 + 1;         // y position between 1 and 100
        x_vel[i] = rand() % 20 - 10;     // x velocity between -10 and 10
        y_vel[i] = rand() % 20 - 10;     // y velocity between -10 and 10
        f_x[i] = 0;                      // initialize x force to 0
        f_y[i] = 0;                      // initialize y force to 0
    }

    // simulate particle movement
    for (k = 0; k < 1000; k++) {         // run simulation for 1000 steps
        for (i = 0; i < num_particles; i++) {
            f_x[i] = 0;                  // reset x force
            f_y[i] = 0;                  // reset y force
            for (j = 0; j < num_particles; j++) {
                if (i != j) {            // only calculate force for different particles
                    calc_force(m[i], m[j], x[i], y[i], x[j], y[j], &f_x[i], &f_y[i]);
                }
            }
        }
        // update particle position and velocity
        for (i = 0; i < num_particles; i++) {
            x[i] += x_vel[i] * time_step + 0.5 * f_x[i] / m[i] * pow(time_step, 2);
            y[i] += y_vel[i] * time_step + 0.5 * f_y[i] / m[i] * pow(time_step, 2);
            x_vel[i] += f_x[i] / m[i] * time_step;
            y_vel[i] += f_y[i] / m[i] * time_step;
        }
        printf("Step %d:\n", k+1);
        for (i = 0; i < num_particles; i++) {
            printf("Particle %d: (%.2f, %.2f), Velocity: (%.2f, %.2f)\n", i+1, x[i], y[i], x_vel[i], y_vel[i]);
        }
    }

    return 0;
}