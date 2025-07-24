//FormAI DATASET v1.0 Category: Physics simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRID_SIZE 10
#define BOLTZMANN_CONSTANT 1.380649e-23
#define MASS 9.10938356e-31

// Function to calculate the maximum velocity
double max_velocity(double temperature) {
    return sqrt((2 * BOLTZMANN_CONSTANT * temperature) / MASS);
}

int main() {
    // Initialize the grid
    int grid[GRID_SIZE][GRID_SIZE] = {0};

    // Set the initial position and velocity of the particle
    int x = GRID_SIZE/2;
    int y = GRID_SIZE/2;
    double temperature = 300; // in Kelvin
    double v_max = max_velocity(temperature);
    double vx = ((double) rand() / (RAND_MAX)) * v_max;
    double vy = ((double) rand() / (RAND_MAX)) * v_max;

    // Simulation loop
    for (int i = 0; i < 1000; i++) {
        // Calculate the new position of the particle
        int new_x = x + round(vx);
        int new_y = y + round(vy);

        // Check if the particle is within the edges of the grid
        if (new_x < 0 || new_x >= GRID_SIZE || new_y < 0 || new_y >= GRID_SIZE)
            break;

        // Update the position of the particle
        x = new_x;
        y = new_y;

        // Calculate the new velocity of the particle
        double dx = ((double) rand() / (RAND_MAX)) * 2 - 1;
        double dy = ((double) rand() / (RAND_MAX)) * 2 - 1;
        double dvx = dx * (BOLTZMANN_CONSTANT * temperature / MASS);
        double dvy = dy * (BOLTZMANN_CONSTANT * temperature / MASS);
        vx += dvx;
        vy += dvy;

        // Check if the new velocity is above the maximum velocity
        double v = sqrt(vx*vx + vy*vy);
        if (v > v_max) {
            vx = (vx / v) * v_max;
            vy = (vy / v) * v_max;
        }

        // Update the grid with the new position of the particle
        grid[x][y]++;
    }

    // Print the final grid
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}