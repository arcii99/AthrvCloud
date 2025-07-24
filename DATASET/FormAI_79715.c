//FormAI DATASET v1.0 Category: Physics simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to randomly generate a 2D grid
void generateGrid(int grid[4][4]) {
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Function to print the 2D grid
void printGrid(int grid[4][4]) {
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Initialize random seed

    int grid[4][4];
    generateGrid(grid);
    printf("Original Grid:\n");
    printGrid(grid);

    // The goal is to flip all the cells in the grid to 1s
    // We can only flip a cell if at least 2 of its adjacent cells are 1s

    // We will use a flag variable to keep track of whether we have made a flip or not
    int flag = 1;
    int numFlips = 0; // Keep track of the number of flips we make

    while(flag) {
        flag = 0; // Reset flag at the start of each iteration

        // Loop through each cell in the grid
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                int adjacentOnes = 0;

                // Check the up, down, left, and right adjacent cells
                if(i > 0 && grid[i-1][j] == 1) adjacentOnes++;
                if(i < 3 && grid[i+1][j] == 1) adjacentOnes++;
                if(j > 0 && grid[i][j-1] == 1) adjacentOnes++;
                if(j < 3 && grid[i][j+1] == 1) adjacentOnes++;

                // If at least 2 adjacent cells are 1s, flip the current cell
                if(adjacentOnes >= 2 && grid[i][j] == 0) {
                    grid[i][j] = 1;
                    flag = 1;
                    numFlips++;
                }
            }
        }
    }

    printf("Final Grid:\n");
    printGrid(grid);
    printf("Number of Flips: %d\n", numFlips);

    return 0;
}