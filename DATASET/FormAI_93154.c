//FormAI DATASET v1.0 Category: Game of Life ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define ROWS 30
#define COLS 30

void printGrid(int grid[ROWS][COLS]);
void updateGrid(int grid[ROWS][COLS]);

int main() {
    int grid[ROWS][COLS] = {0};

    // set up initial cells
    grid[5][5] = 1;
    grid[5][6] = 1;
    grid[5][7] = 1;

    printf("Initial Grid:\n");
    printGrid(grid);

    for (int i = 0; i < 10; i++) {
        updateGrid(grid);
        printf("\nGrid after %d generations:\n", i+1);
        printGrid(grid);
    }

    return 0;
}

void printGrid(int grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

void updateGrid(int grid[ROWS][COLS]) {
    int newGrid[ROWS][COLS] = {0};
    int neighbors, x, y;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            neighbors = 0;

            // count neighbors
            for (int m = -1; m <= 1; m++) {
                for (int n = -1; n <= 1; n++) {
                    x = (i + m + ROWS) % ROWS;
                    y = (j + n + COLS) % COLS;
                    if (grid[x][y] == 1) {
                        neighbors++;
                    }
                }
            }

            // remove self from neighbor count
            if (grid[i][j] == 1) {
                neighbors--;
            }

            // apply rules to generate new grid
            if (grid[i][j] == 1 && (neighbors == 2 || neighbors == 3)) {
                newGrid[i][j] = 1;
            } else if (grid[i][j] == 0 && neighbors == 3) {
                newGrid[i][j] = 1;
            } else {
                newGrid[i][j] = 0;
            } 
        }
    }

    // copy new grid to original grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}