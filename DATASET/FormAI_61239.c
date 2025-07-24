//FormAI DATASET v1.0 Category: Game of Life ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define ROWS 20 // Number of rows for the grid
#define COLS 50 // Number of columns for the grid

// Function to initialize the grid with random values
void initializeGrid(int grid[][COLS]) {
    int i, j;
    srand(time(NULL));
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Function to print the grid
void printGrid(int grid[][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%c", grid[i][j] ? '#' : ' ');
        }
        printf("\n");
    }
}

// Function to check if a given cell is valid
int isValid(int i, int j) {
    return (i >= 0 && i < ROWS && j >= 0 && j < COLS);
}

// Function to count the number of live neighbors for a given cell
int countNeighbors(int grid[][COLS], int i, int j) {
    int count = 0, x, y;
    for(x = -1; x <= 1; x++) {
        for(y = -1; y <= 1; y++) {
            if(x == 0 && y == 0) continue;
            if(isValid(i+x, j+y) && grid[i+x][j+y]) {
                count++;
            }
        }
    }
    return count;
}

// Function to update the grid for the next generation
void updateGrid(int grid[][COLS]) {
    int i, j, neighbors;
    int newGrid[ROWS][COLS] = {{0}};
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            neighbors = countNeighbors(grid, i, j);
            if(grid[i][j] == 1) {
                if(neighbors < 2 || neighbors > 3) {
                    newGrid[i][j] = 0;
                } else {
                    newGrid[i][j] = 1;
                }
            } else {
                if(neighbors == 3) {
                    newGrid[i][j] = 1;
                }
            }
        }
    }
    // Copy the new grid to the original grid
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    int grid[ROWS][COLS];
    initializeGrid(grid);
    printf("Initial Grid:\n");
    printGrid(grid);

    int i;
    for(i = 1; i <= 10; i++) {
        updateGrid(grid);
        printf("\nGeneration %d:\n", i);
        printGrid(grid);
    }

    return 0;
}