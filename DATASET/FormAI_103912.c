//FormAI DATASET v1.0 Category: Game of Life ; Style: systematic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

int count_neighbors(int grid[][COLS], int row, int col) {
    /*
    A function that returns the number of live neighbors
    of the cell in row `row` and column `col`.
    */
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i < 0 || i >= ROWS || j < 0 || j >= COLS || (i == row && j == col))
                continue;
            if (grid[i][j])
                count++;
        }
    }
    return count;
}

void print_grid(int grid[][COLS]) {
    /*
    Prints the current state of the grid
    */
    system("clear"); // used to clear the screen on UNIX systems

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j])
                printf("x");
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("\n\n");
}

void update_grid(int grid[][COLS]) {
    /*
    Updates the grid based on the Game of Life rules.
    */
    int new_grid[ROWS][COLS] = {0};
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = count_neighbors(grid, i, j);

            // apply Game of Life rules
            if (neighbors < 2 || neighbors > 3)
                new_grid[i][j] = 0;
            else if (neighbors == 3)
                new_grid[i][j] = 1;
            else
                new_grid[i][j] = grid[i][j];
        }
    }

    // copy the new grid to the old grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main() {
    // seed the random number generator
    srand(time(NULL));

    // initialize the grid with some random values
    int grid[ROWS][COLS] = {0};
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (rand() % 2 == 1) {
                grid[i][j] = 1;
            }
        }
    }

    // run the simulation
    while (true) {
        print_grid(grid);
        update_grid(grid);
        // sleep for some time before updating again
        // to give the user a chance to see the grid
        // and to prevent the simulation from running too fast
        usleep(100000);
    }

    return 0;
}