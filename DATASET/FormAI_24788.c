//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int rows = 25;
    int cols = 25;

    srand(time(NULL)); // Seed the random number generator

    int world[rows][cols]; // Initialize the world

    // Set all cells to blocked
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            world[i][j] = 0;
        }
    }

    // Create a starting point
    int startX = rand() % rows;
    int startY = rand() % cols;
    world[startX][startY] = 1;

    // Create a wall of debris around the edge of the world
    for (int i = 0; i < rows; i++) {
        world[i][0] = 1;
        world[i][cols-1] = 1;
    }
    for (int j = 0; j < cols; j++) {
        world[0][j] = 1;
        world[rows-1][j] = 1;
    }

    // Simulate the percolation process
    int percolates = 0;
    while (!percolates) {
        // Check for adjacent open cells and open them with a certain probability
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (world[i][j] == 0) {
                    // Check north
                    if (i > 0 && world[i-1][j] == 1 && rand() % 100 < 60) {
                        world[i][j] = 1;
                    }
                    // Check south
                    else if (i < rows-1 && world[i+1][j] == 1 && rand() % 100 < 60) {
                        world[i][j] = 1;
                    }
                    // Check west
                    else if (j > 0 && world[i][j-1] == 1 && rand() % 100 < 60) {
                        world[i][j] = 1;
                    }
                    // Check east
                    else if (j < cols-1 && world[i][j+1] == 1 && rand() % 100 < 60) {
                        world[i][j] = 1;
                    }
                }
            }
        }

        // Check if there is a path from the top to the bottom of the world
        for (int j = 1; j < cols-1; j++) {
            if (world[1][j] == 1) {
                if (explore(world, 1, j)) {
                    percolates = 1;
                    break;
                }
            }
        }
    }

    // Print the final state of the world
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (world[i][j] == 1) {
                printf("# ");
            }
            else {
                printf(". ");
            }
        }
        printf("\n");
    }

    return 0;
}

// Helper function to recursively explore the world
int explore(int world[][25], int row, int col) {
    if (row == 23) {
        return 1; // Found a path to the bottom of the world
    }
    else {
        world[row][col] = 2; // Mark cell as explored
        // Recursively check adjacent cells
        if (row > 0 && world[row-1][col] == 1) {
            if (explore(world, row-1, col)) {
                return 1;
            }
        }
        if (row < 23 && world[row+1][col] == 1) {
            if (explore(world, row+1, col)) {
                return 1;
            }
        }
        if (col > 0 && world[row][col-1] == 1) {
            if (explore(world, row, col-1)) {
                return 1;
            }
        }
        if (col < 23 && world[row][col+1] == 1) {
            if (explore(world, row, col+1)) {
                return 1;
            }
        }
        return 0; // Found no path to the bottom of the world
    }
}