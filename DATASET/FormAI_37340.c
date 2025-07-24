//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 25 // define the grid size
#define PERCOLATION_THRESHOLD 0.55 // define the percolation threshold

/*
* Function Declaration Section.
*/
int randomNumber(int max); // generates a random number between 0 and max
void initGrid(int grid[GRID_SIZE + 2][GRID_SIZE + 2]); // initializes the grid
void printGrid(int grid[GRID_SIZE + 2][GRID_SIZE + 2]); // prints the grid
void percolate(int grid[GRID_SIZE + 2][GRID_SIZE + 2]); // percolates the grid

/*
* Main Function Section.
*/
int main() {

    int grid[GRID_SIZE + 2][GRID_SIZE + 2];
    srand(time(NULL)); // seed the random number generator
    
    initGrid(grid); // initialize the grid
    printGrid(grid); // print the grid
    
    printf("\n");
    percolate(grid); // percolate the grid
    printf("\n");
    printGrid(grid); // print the grid

    return 0;
}

/*
* Function Definition Section.
*/
int randomNumber(int max) {
    return rand() % max;
}

void initGrid(int grid[GRID_SIZE + 2][GRID_SIZE + 2]) {
    for (int i = 1; i <= GRID_SIZE; i++) {
        for (int j = 1; j <= GRID_SIZE; j++) {
            if (randomNumber(100) < PERCOLATION_THRESHOLD * 100) {
                grid[i][j] = 1; // if random number is less than percolation threshold, set cell to open
            } else {
                grid[i][j] = 0; // otherwise set cell to blocked
            }
        }
    }

    // set all the cells in first and last rows as blocked
    for (int i = 0; i <= GRID_SIZE + 1; i++) {
        grid[0][i] = 0;
        grid[GRID_SIZE + 1][i] = 0;
    }

    // set all the cells in first and last columns as blocked
    for (int i = 0; i <= GRID_SIZE + 1; i++) {
        grid[i][0] = 0;
        grid[i][GRID_SIZE + 1] = 0;
    }
}

void printGrid(int grid[GRID_SIZE + 2][GRID_SIZE + 2]) {
    for (int i = 1; i <= GRID_SIZE; i++) {
        for (int j = 1; j <= GRID_SIZE; j++) {
            if (grid[i][j] == 1) {
                printf("O "); // print "O" for open cells
            } else {
                printf("X "); // print "X" for blocked cells
            }
        }
        printf("\n");
    }
}

// performs percolation on the grid
void percolate(int grid[GRID_SIZE + 2][GRID_SIZE + 2]) {
    for (int j = 1; j <= GRID_SIZE; j++) {
        if (grid[1][j] == 1) {
            grid[1][j] = 2; // mark open cells in first row as full
        }
    }

    int percolates;
    do {
        percolates = 0;
        for (int i = 1; i <= GRID_SIZE; i++) {
            for (int j = 1; j <= GRID_SIZE; j++) {
                if (grid[i][j] == 2) {
                    // check if any neighbor is open and mark it as full
                    if (grid[i - 1][j] == 1) {
                        grid[i - 1][j] = 2;
                        percolates = 1;
                    }
                    if (grid[i + 1][j] == 1) {
                        grid[i + 1][j] = 2;
                        percolates = 1;
                    }
                    if (grid[i][j - 1] == 1) {
                        grid[i][j - 1] = 2;
                        percolates = 1;
                    }
                    if (grid[i][j + 1] == 1) {
                        grid[i][j + 1] = 2;
                        percolates = 1;
                    }
                }
            }
        }
    } while (percolates);

    // mark all the cells that are open and full as percolating
    for (int i = 1; i <= GRID_SIZE; i++) {
        for (int j = 1; j <= GRID_SIZE; j++) {
            if (grid[i][j] == 1 || grid[i][j] == 2) {
                grid[i][j] = 3;
            }
        }
    }
}