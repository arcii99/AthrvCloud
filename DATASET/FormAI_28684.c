//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// Function to print the grid
void printGrid(char grid[ROWS][COLS]){
    printf("\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to randomly fill the grid with water and balls
void fillGrid(char grid[ROWS][COLS], int numBalls) {
    int randRow, randCol;

    // Fill the grid with water
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = '~';
        }
    }

    // Place the balls randomly on the grid
    for(int i = 0; i < numBalls; i++) {
        randRow = rand() % ROWS;
        randCol = rand() % COLS;
        if(grid[randRow][randCol] != 'o') {
            grid[randRow][randCol] = 'o';
        } else {
            i--; // try again
        }
    }
}

// Function to simulate percolation
void percolate(char grid[ROWS][COLS]) {
    int topRow, bottomRow;
    char symbol;
    int percolates = 0;

    // Find the top and bottom of the grid
    topRow = 0;
    bottomRow = ROWS - 1;

    // Mark the top row as visited
    for(int j = 0; j < COLS; j++) {
        if(grid[topRow][j] == 'o') {
            grid[topRow][j] = 'X';
        }
    }

    // Check if the balls reach the bottom row
    for(int j = 0; j < COLS; j++) {
        if(grid[bottomRow][j] == 'o') {
            percolates = 1;
        }
    }

    // Expand the visited region until it reaches the bottom row
    while(!percolates) {
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(grid[i][j] == 'X') {
                    // Visit neighbouring cells
                    if(i > 0) {
                        symbol = grid[i-1][j];
                        if(symbol == 'o') {
                            percolates = 1;
                        } else if(symbol == '~') {
                            grid[i-1][j] = 'X';
                        }
                    }
                    if(i < (ROWS-1)) {
                        symbol = grid[i+1][j];
                        if(symbol == 'o') {
                            percolates = 1;
                        } else if(symbol == '~') {
                            grid[i+1][j] = 'X';
                        }
                    }
                    if(j > 0) {
                        symbol = grid[i][j-1];
                        if(symbol == 'o') {
                            percolates = 1;
                        } else if(symbol == '~') {
                            grid[i][j-1] = 'X';
                        }
                    }
                    if(j < (COLS-1)) {
                        symbol = grid[i][j+1];
                        if(symbol == 'o') {
                            percolates = 1;
                        } else if(symbol == '~') {
                            grid[i][j+1] = 'X';
                        }
                    }
                }
            }
        }
    }
}

int main() {
    char grid[ROWS][COLS];
    int numBalls = 10;

    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Fill the grid with water and balls randomly
    fillGrid(grid, numBalls);

    // Print the initial state of the grid
    printf("Initial Configuration:\n");
    printGrid(grid);

    // Percolate the grid
    percolate(grid);

    // Print the final state of the grid
    printf("Final Configuration:\n");
    printGrid(grid);

    return 0;
}