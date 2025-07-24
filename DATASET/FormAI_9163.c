//FormAI DATASET v1.0 Category: Robot movement control ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_STEPS 1000

int main() {
    // Initialize variables
    double x[MAX_STEPS], y[MAX_STEPS], theta[MAX_STEPS];
    int current_step = 0;
    double current_x = 0, current_y = 0, current_theta = 0;
    double dt = 0.01; // Time step
    double v = 0.1; // Forward speed
    double w = 0.5; // Angular speed

    // Set a random seed
    srand(time(NULL));

    // Move the robot
    while (current_step < MAX_STEPS) {
        // Get a random direction
        double direction = M_PI / 2 * ((double)rand() / RAND_MAX - 0.5);

        // Calculate the new position and angle
        double delta_x = v * cos(current_theta) * dt;
        double delta_y = v * sin(current_theta) * dt;
        double delta_theta = w * direction * dt;
        current_x += delta_x;
        current_y += delta_y;
        current_theta += delta_theta;

        // Store the new position and angle
        x[current_step] = current_x;
        y[current_step] = current_y;
        theta[current_step] = current_theta;

        // Increment the step counter
        current_step++;
    }

    // Print the results
    printf("x, y, theta\n");
    for (int i = 0; i < MAX_STEPS; i++) {
        printf("%f, %f, %f\n", x[i], y[i], theta[i]);
    }

    return 0;
}