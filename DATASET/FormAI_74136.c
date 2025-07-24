//FormAI DATASET v1.0 Category: Game of Life ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLUMNS 20

// Initialize the game of life grid with random values
void initializeGrid(int grid[][COLUMNS]) {
    // Seed the random number generator
    srand(time(NULL));
    
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            int randomValue = rand() % 2; // Generate a random value of either 0 or 1
            grid[i][j] = randomValue;
        }
    }
}

// Compute the next state of the grid
void computeNextState(int grid[][COLUMNS]) {
    int tempGrid[ROWS][COLUMNS]; // Create a temporary grid to store the next state of the grid
    
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            int livingNeighbors = 0;
            
            for(int k=-1; k<=1; k++) {
                for(int l=-1; l<=1; l++) {
                    if(i+k>=0 && i+k<ROWS && j+l>=0 && j+l<COLUMNS) { // Check if the neighbor is within the bounds of the grid
                        livingNeighbors += grid[i+k][j+l]; // Add the value of the neighbor to the livingNeighbors count
                    }
                }
            }
            
            // Don't count the current cell
            livingNeighbors -= grid[i][j];
            
            // Apply the game of life rules
            if(grid[i][j] == 1 && livingNeighbors < 2) {
                tempGrid[i][j] = 0; // Cell dies due to underpopulation
            }
            else if(grid[i][j] == 1 && (livingNeighbors == 2 || livingNeighbors == 3)) {
                tempGrid[i][j] = 1; // Cell stays alive
            }
            else if(grid[i][j] == 1 && livingNeighbors > 3) {
                tempGrid[i][j] = 0; // Cell dies due to overpopulation
            }
            else if(grid[i][j] == 0 && livingNeighbors == 3) {
                tempGrid[i][j] = 1; // Dead cell becomes alive due to reproduction
            }
            else {
                tempGrid[i][j] = grid[i][j]; // Cell stays the same
            }
        }
    }
    
    // Copy the contents of the temporary grid back to the original grid
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            grid[i][j] = tempGrid[i][j];
        }
    }
}

// Print the current state of the grid
void printGrid(int grid[][COLUMNS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            if(grid[i][j] == 1) {
                printf("* ");
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    int grid[ROWS][COLUMNS];
    initializeGrid(grid);
    printGrid(grid);
    
    for(int i=0; i<50; i++) {
        computeNextState(grid);
        printf("\nGeneration: %d\n", i+1);
        printGrid(grid);
    }
    
    return 0;
}