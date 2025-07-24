//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the simulation grid
#define SIZE 10

// Define the threshold value for percolation
#define THRESHOLD 0.6

// Function to initialize the grid with random values
void init_grid(float grid[SIZE][SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = (float) rand() / RAND_MAX;
        }
    }
}

// Function to print the current state of the grid
void print_grid(float grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%.2f ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the grid percolates
int does_percolate(float grid[SIZE][SIZE]) {
    int top_open = 0;
    for (int j = 0; j < SIZE; j++) {
        if (grid[0][j] < THRESHOLD) {
            top_open = 1;
            break;
        }
    }

    int bottom_open = 0;
    for (int j = 0; j < SIZE; j++) {
        if (grid[SIZE-1][j] < THRESHOLD) {
            bottom_open = 1;
            break;
        }
    }

    return (top_open && bottom_open);
}

// Main function to run the simulation
int main() {
    float grid[SIZE][SIZE];
    init_grid(grid);
    int percolates = does_percolate(grid);

    printf("Initial grid:\n");
    print_grid(grid);

    int count = 0;
    while (!percolates) {
        int i = rand() % SIZE;
        int j = rand() % SIZE;
        grid[i][j] = (float) rand() / RAND_MAX;
        count++;
        percolates = does_percolate(grid);
    }

    printf("\nPercolation achieved after %d updates:\n", count);
    print_grid(grid);

    return 0;
}