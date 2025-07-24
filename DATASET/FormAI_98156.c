//FormAI DATASET v1.0 Category: Physics simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* This program simulates the motion of a projectile under the influence of gravity. */

int main() {
    // Define constant variables
    const float gravity = 9.81;
    const float timestep = 0.01;

    // Define initial variables
    float x = 0;
    float y = 0;
    float v_x = 10;
    float v_y = 20;
    float angle = 45;
    float time = 0;

    // Convert angle to radians
    angle = angle * (M_PI/180);

    // Open output file
    FILE *fp = fopen("projectile_motion.csv", "w");
    fprintf(fp, "Time (s), X Position (m), Y Position (m)\n");

    // Simulate motion until projectile hits the ground
    while (y >= 0) {
        // Calculate new velocity
        float v_x_new = v_x;
        float v_y_new = v_y - gravity * timestep;

        // Calculate new position
        float x_new = x + v_x * timestep;
        float y_new = y + v_y * timestep;

        // Write position data to output file
        fprintf(fp, "%.2f, %.2f, %.2f\n", time, x_new, y_new);

        // Update variables for next iteration
        v_x = v_x_new;
        v_y = v_y_new;
        x = x_new;
        y = y_new;
        time += timestep;
    }

    // Close output file
    fclose(fp);
    printf("Simulation complete. Results written to projectile_motion.csv.\n");

    return 0;
}