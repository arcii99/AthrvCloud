//FormAI DATASET v1.0 Category: Game of Life ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 50

int main() {

    // Initialize the grid
    int grid[ROWS][COLS] = {0};
    srand(time(NULL));
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    // Display the initial grid
    printf("Initial Grid:\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(grid[i][j]) printf("*");
            else printf(".");
        }
        printf("\n");
    }
    printf("\n");

    // Perform the game of life simulation for 100 generations
    for(int generation = 1; generation <= 100; generation++) {

        // Create a copy of the grid for updating
        int newGrid[ROWS][COLS];
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                newGrid[i][j] = grid[i][j];
            }
        }

        // Iterate through the cells and update the new grid
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                int numNeighbors = 0;

                // Check the neighbors of the current cell
                for(int k = i - 1; k <= i + 1; k++) {
                    for(int l = j - 1; l <= j + 1; l++) {
                        // Skip the current cell or cells outside the grid
                        if((k == i && l == j) || k < 0 || k >= ROWS || l < 0 || l >= COLS) continue;
                        if(grid[k][l]) numNeighbors++;
                    }
                }

                // Update the cell based on the number of live neighbors
                if(grid[i][j] && (numNeighbors < 2 || numNeighbors > 3)) newGrid[i][j] = 0;
                else if(!grid[i][j] && numNeighbors == 3) newGrid[i][j] = 1;
            }
        }

        // Update the grid with the new values
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                grid[i][j] = newGrid[i][j];
            }
        }

        // Display the updated grid
        printf("Generation %d:\n", generation);
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(grid[i][j]) printf("*");
                else printf(".");
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}