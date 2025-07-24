//FormAI DATASET v1.0 Category: Game of Life ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define ROWS 30
#define COLS 80

int grid[ROWS][COLS];

// function to initialize the grid
void initGrid() {
    srand(time(NULL));

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// function to print the grid
void printGrid() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(grid[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("----------------------------------------------\n");
}

// function to count the number of neighbors
int countNeighbors(int row, int col) {
    int count = 0;

    // loop through the neighboring cells
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            int r = (row + i + ROWS) % ROWS; // handling edge cases
            int c = (col + j + COLS) % COLS; // handling edge cases
            if(grid[r][c] == 1) {
                count++;
            }
        }
    }

    // subtracting the cell itself
    count -= grid[row][col];

    return count;
}

// function to update the grid
void updateGrid() {
    int newGrid[ROWS][COLS];

    // loop through each cell
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int neighbors = countNeighbors(i, j);

            // applying the rules of the game
            if(grid[i][j] == 0 && neighbors == 3) {
                newGrid[i][j] = 1;
            } else if(grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                newGrid[i][j] = 0;
            } else {
                newGrid[i][j] = grid[i][j];
            }
        }
    }

    // updating the grid
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

// main function
int main() {
    initGrid();

    while(1) {
        printGrid();
        updateGrid();
        usleep(100000); // sleep for 100ms between updates
    }

    return 0;
}