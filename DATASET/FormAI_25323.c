//FormAI DATASET v1.0 Category: Physics simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_X 100
#define TIME_STEP 0.01
#define GRAVITY 9.8
#define MASS 1

double get_random_velocity();
double get_random_x_position();

int main() {
    double x_positions[MAX_X];
    double y_positions[MAX_X];
    double velocities[MAX_X];
    int total_time_steps = 1000;
    int n_particles = 10;
    int i;
    int j;

    // Initialize positions and velocities randomly for each particle
    for (i = 0; i < n_particles; i++) {
        x_positions[i] = get_random_x_position();
        y_positions[i] = 0;
        velocities[i] = get_random_velocity();
    }

    // Perform simulation for each time step
    for (i = 0; i < total_time_steps; i++) {
        // Update positions for each particle
        for (j = 0; j < n_particles; j++) {
            y_positions[j] += velocities[j] * TIME_STEP;
            velocities[j] -= GRAVITY * MASS * TIME_STEP;
            if (y_positions[j] < 0) {
                y_positions[j] = 0;
                velocities[j] *= -1;
            }
        }

        // Print particle positions for this time step
        printf("Time Step: %d\n", i);
        for (j = 0; j < n_particles; j++) {
            printf("\tParticle %2d: (%6.2f, %6.2f)\n", j, x_positions[j], y_positions[j]);
        }
    }

    return 0;
}

double get_random_velocity() {
    return 10 * (((double)rand() / (double)RAND_MAX) - 0.5);
}

double get_random_x_position() {
    return (double)rand() / ((double)RAND_MAX / MAX_X);
}