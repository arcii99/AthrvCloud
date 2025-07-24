//FormAI DATASET v1.0 Category: Game of Life ; Style: high level of detail
// Game of Life
// Implementing Conway's Game of Life in C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

int grid[ROWS][COLS];
int nextGrid[ROWS][COLS];

// Initializes the grid with random cell values
void initializeGrid() {
    srand(time(NULL));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int value = rand() % 2;
            grid[i][j] = value;
        }
    }
}

// Displays the current generation of the grid
void printGrid() {
    printf("\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(grid[i][j]) {
                printf("* ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// Calculates the next generation of the grid
void calculateNextGeneration() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int neighbors = 0;

            // Count neighbors
            if(i > 0 && j > 0 && grid[i-1][j-1]) neighbors++;
            if(i > 0 && grid[i-1][j]) neighbors++;
            if(i > 0 && j < COLS-1 && grid[i-1][j+1]) neighbors++;
            if(j > 0 && grid[i][j-1]) neighbors++;
            if(j < COLS-1 && grid[i][j+1]) neighbors++;
            if(i < ROWS-1 && j > 0 && grid[i+1][j-1]) neighbors++;
            if(i < ROWS-1 && grid[i+1][j]) neighbors++;
            if(i < ROWS-1 && j < COLS-1 && grid[i+1][j+1]) neighbors++;

            // Apply rules to calculate next generation
            if(grid[i][j] && (neighbors==2 || neighbors==3)) {
                nextGrid[i][j] = 1;
            } else if(!grid[i][j] && neighbors==3) {
                nextGrid[i][j] = 1;
            } else {
                nextGrid[i][j] = 0;
            }
        }
    }
}

// Updates the current grid with the next generation
void updateGrid() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            grid[i][j] = nextGrid[i][j];
        }
    }
}

// Runs the Game of Life simulation
void runGameOfLife(int generations) {
    initializeGrid();
    printGrid();
    for(int i=0; i<generations; i++) {
        calculateNextGeneration();
        updateGrid();
        printf("\nGeneration %d:\n", i+1);
        printGrid();
    }
}

int main() {
    runGameOfLife(10);
    return 0;
}