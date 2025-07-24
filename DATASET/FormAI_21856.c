//FormAI DATASET v1.0 Category: Game of Life ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW_SIZE 40
#define COL_SIZE 40

// Function to initialize the grid
void initializeGrid(int grid[][COL_SIZE]) {
    srand(time(NULL));
    for(int i = 0; i < ROW_SIZE; i++) {
        for(int j = 0; j < COL_SIZE; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Function to print the grid
void printGrid(int grid[][COL_SIZE]) {
    for(int i = 0; i < ROW_SIZE; i++) {
        for(int j = 0; j < COL_SIZE; j++) {
            if(grid[i][j] == 1) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

// Function to count the number of live neighboring cells for each cell
int countNeighbors(int grid[][COL_SIZE], int row, int col) {
    int numNeighbors = 0;
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            if(i == 0 && j == 0) { // current cell
                continue;
            }
            int row_idx = row + i;
            int col_idx = col + j;
            // Check if the neighbor is out of bounds
            if(row_idx < 0 || col_idx < 0 || row_idx >= ROW_SIZE || col_idx >= COL_SIZE) {
                continue;
            }
            numNeighbors += grid[row_idx][col_idx];
        }
    }
    return numNeighbors;
}

// Function to generate the next state of the grid based on Conway's rules
void generateNextState(int grid[][COL_SIZE]) {
    int nextGrid[ROW_SIZE][COL_SIZE];
    for(int i = 0; i < ROW_SIZE; i++) {
        for(int j = 0; j < COL_SIZE; j++) {
            int numNeighbors = countNeighbors(grid, i, j);
            if(grid[i][j] == 1) { // If cell is alive
                if(numNeighbors < 2 || numNeighbors > 3) {
                    nextGrid[i][j] = 0; // Overcrowding or isolation, cell dies
                } else {
                    nextGrid[i][j] = 1;
                }
            } else { // Cell is dead
                if(numNeighbors == 3) {
                    nextGrid[i][j] = 1; // Reproduction, cell becomes alive
                } else {
                    nextGrid[i][j] = 0;
                }
            }
        }
    }
    // Copy nextGrid to grid
    for(int i = 0; i < ROW_SIZE; i++) {
        for(int j = 0; j < COL_SIZE; j++) {
            grid[i][j] = nextGrid[i][j];
        }
    }
}

int main() {
    int grid[ROW_SIZE][COL_SIZE];
    initializeGrid(grid);
    printf("Initial state:\n");
    printGrid(grid);
    for(int i = 0; i < 100; i++) {
        printf("Generation %d:\n", i+1);
        generateNextState(grid);
        printGrid(grid);
    }
    return 0;
}