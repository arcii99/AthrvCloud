//FormAI DATASET v1.0 Category: Game of Life ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 50

void printGrid(int grid[][COLS], int rows, int cols);
int countNeighbors(int grid[][COLS], int row, int col);

int main(void) {
    int grid[ROWS][COLS];
    int newGrid[ROWS][COLS];
    int row, col, neighbors, i, j;

    // initialize the grid with random values
    srand(time(NULL));
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            grid[row][col] = rand() % 2;
        }
    }

    while (1) {
        // print the current state of the grid
        printGrid(grid, ROWS, COLS);

        // calculate the new state based on the current state
        for (row = 0; row < ROWS; row++) {
            for (col = 0; col < COLS; col++) {
                neighbors = countNeighbors(grid, row, col);

                if (grid[row][col] == 1) {
                    // a live cell with fewer than two neighbors or more than three neighbors dies
                    if (neighbors < 2 || neighbors > 3) {
                        newGrid[row][col] = 0;
                    }
                    // a live cell with two or three neighbors survives
                    else {
                        newGrid[row][col] = 1;
                    }
                }
                else {
                    // a dead cell with exactly three neighbors becomes alive
                    if (neighbors == 3) {
                        newGrid[row][col] = 1;
                    }
                    else {
                        newGrid[row][col] = 0;
                    }
                }
            }
        }

        // update the grid with the new state
        for (row = 0; row < ROWS; row++) {
            for (col = 0; col < COLS; col++) {
                grid[row][col] = newGrid[row][col];
            }
        }

        // wait for a second before printing the next state
        for (i = 0; i < 1000000; i++) {
            for (j = 0; j < 10; j++);
        }

        // move the cursor to the top left of the terminal window
        printf("\033[2J\033[H");
    }

    return 0;
}

// function to print the grid
void printGrid(int grid[][COLS], int rows, int cols) {
    int row, col;
    for (row = 0; row < rows; row++) {
        for (col = 0; col < cols; col++) {
            if (grid[row][col] == 1) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// function to count the number of live neighbors of a cell
int countNeighbors(int grid[][COLS], int row, int col) {
    int neighbors = 0;
    int r, c;

    // check left neighbor
    if (col > 0 && grid[row][col - 1] == 1) {
        neighbors++;
    }

    // check right neighbor
    if (col < COLS - 1 && grid[row][col + 1] == 1) {
        neighbors++;
    }

    // check top neighbor
    if (row > 0 && grid[row - 1][col] == 1) {
        neighbors++;
    }

    // check bottom neighbor
    if (row < ROWS - 1 && grid[row + 1][col] == 1) {
        neighbors++;
    }

    // check top left neighbor
    if (row > 0 && col > 0 && grid[row - 1][col - 1] == 1) {
        neighbors++;
    }

    // check top right neighbor
    if (row > 0 && col < COLS - 1 && grid[row - 1][col + 1] == 1) {
        neighbors++;
    }

    // check bottom left neighbor
    if (row < ROWS - 1 && col > 0 && grid[row + 1][col - 1] == 1) {
        neighbors++;
    }

    // check bottom right neighbor
    if (row < ROWS - 1 && col < COLS - 1 && grid[row + 1][col + 1] == 1) {
        neighbors++;
    }

    return neighbors;
}