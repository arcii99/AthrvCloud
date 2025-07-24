//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 20 // Size of the grid
#define NUM_TRIALS 1000 // Number of trials to run
#define PERCOLATION_THRESHOLD 0.5 // Percolation threshold

int grid[GRID_SIZE][GRID_SIZE]; // Grid to simulate percolation

int is_percolating(); // Function to check if a percolation happens in the current grid configuration
void reset_grid(); // Function to reset the grid to the initial state

int main() {
    srand(time(NULL)); // Initialize random number generator with current time

    int i, j, trial_count, percolating_count = 0;
    float percolation_probability;

    for (trial_count = 1; trial_count <= NUM_TRIALS; trial_count++) {
        reset_grid();

        // Randomly fill the grid with sites
        for (i = 0; i < GRID_SIZE; i++) {
            for (j = 0; j < GRID_SIZE; j++) {
                if ((float)rand()/(float)RAND_MAX > PERCOLATION_THRESHOLD) {
                    grid[i][j] = 1;
                }
            }
        }

        if (is_percolating()) {
            percolating_count++;
        }

        // Calculate and print current percolation probability
        percolation_probability = (float)percolating_count/trial_count;
        printf("Trial %d: Percolation probability = %.3f\n", trial_count, percolation_probability);
    }

    // Final percolation probability
    percolation_probability = (float)percolating_count/NUM_TRIALS;
    printf("\nPercolation probability = %.3f\n", percolation_probability);

    return 0;
}

int is_percolating() {
    int i, j;
    int top[GRID_SIZE], bottom[GRID_SIZE];
    int component_labels[GRID_SIZE*GRID_SIZE];
    int component_count = 0;

    // Initialize separate labels for each site
    for (i = 0; i < GRID_SIZE*GRID_SIZE; i++) {
        component_labels[i] = -1;
    }

    // Label the top and bottom rows separately
    for (i = 0; i < GRID_SIZE; i++) {
        top[i] = -1;
        bottom[i] = -1;

        if (grid[0][i]) {
            top[i] = ++component_count;
        }

        if (grid[GRID_SIZE-1][i]) {
            bottom[i] = ++component_count;
        }
    }

    // Label the remaining sites using a two-pass algorithm
    int root, current_label;
    for (i = 1; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j]) {
                root = -1;

                // Check the left neighbor
                if (j > 0 && grid[i][j-1]) {
                    root = component_labels[i*GRID_SIZE+j-1];
                }

                // Check the top neighbor
                if (root == -1 && i > 0 && grid[i-1][j]) {
                    root = component_labels[(i-1)*GRID_SIZE+j];
                }

                // Create a new component label if necessary
                if (root == -1) {
                    current_label = ++component_count;
                }
                // Use the root label otherwise
                else {
                    current_label = root;
                }

                // Assign current label to the current site
                component_labels[i*GRID_SIZE+j] = current_label;

                // Merge components if necessary
                if (root != -1 && top[j] != -1 && top[j] != current_label) {
                    for (int k = 0; k < GRID_SIZE; k++) {
                        if (component_labels[k] == top[j]) {
                            component_labels[k] = current_label;
                        }
                    }
                }

                if (root != -1 && bottom[j] != -1 && bottom[j] != current_label) {
                    for (int k = 0; k < GRID_SIZE; k++) {
                        if (component_labels[(GRID_SIZE-1)*GRID_SIZE+k] == bottom[j]) {
                            component_labels[(GRID_SIZE-1)*GRID_SIZE+k] = current_label;
                        }
                    }
                }

                // Update top and bottom row labels
                if (i == 1 && top[j] == -1) {
                    top[j] = current_label;
                }

                if (i == GRID_SIZE-1 && bottom[j] == -1) {
                    bottom[j] = current_label;
                }
            }
        }
    }

    // Check if the top and bottom rows are connected through a single component
    for (i = 0; i < GRID_SIZE; i++) {
        if (top[i] != -1 && bottom[i] != -1 && top[i] == bottom[i]) {
            return 1;
        }
    }

    return 0;
}

void reset_grid() {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = 0;
        }
    }
}