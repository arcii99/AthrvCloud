//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10 // Change grid size as desired
#define THRESHOLD 0.5 // Change threshold as desired

int main()
{
    srand(time(NULL)); // Seed the random number generator with current time

    int grid[GRID_SIZE][GRID_SIZE]; // Create the grid
    int i, j;

    // Fill the grid with random values
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            float r = (float) rand() / RAND_MAX; // Generate a random number between 0 and 1
            grid[i][j] = r <= THRESHOLD ? 1 : 0; // If the random number is less than or equal to the threshold, set the cell to 1 (occupied), otherwise set it to 0 (empty)
        }
    }

    // Print the initial grid
    printf("Initial Grid:\n");
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Check if top and bottom of the grid are connected
    int top_connected = 0, bottom_connected = 0;
    for (j = 0; j < GRID_SIZE; j++) {
        if (grid[0][j] == 1) {
            top_connected = 1;
        }
        if (grid[GRID_SIZE-1][j] == 1) {
            bottom_connected = 1;
        }
    }

    // Perform percolation
    while (!top_connected || !bottom_connected) {
        // Choose a random cell to occupy
        int row = rand() % GRID_SIZE;
        int col = rand() % GRID_SIZE;
        if (grid[row][col] == 0) {
            grid[row][col] = 1;
            if (row == 0) {
                top_connected = 1;
            }
            if (row == GRID_SIZE-1) {
                bottom_connected = 1;
            }
        }
    }

    // Print the final grid
    printf("Final Grid:\n");
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Print whether percolation was successful or not
    if (top_connected && bottom_connected) {
        printf("Percolation successful!\n");
    } else {
        printf("Percolation failed!\n");
    }

    return 0;
}