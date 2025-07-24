//FormAI DATASET v1.0 Category: Game of Life ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10 // Number of rows
#define COLS 10 // Number of columns

// Initialize the grid
void initGrid(int grid[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Print the current state of the grid
void printGrid(int grid[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Calculate the next state of the grid
void getNextState(int grid[][COLS]) {
    int tempGrid[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int count = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (!(x == 0 && y == 0) && i+x >= 0 && i+x < ROWS && j+y >= 0 && j+y < COLS) {
                        if (grid[i+x][j+y] == 1) {
                            count++;
                        }
                    }
                }
            }

            if (grid[i][j] == 1 && (count == 2 || count == 3)) {
                tempGrid[i][j] = 1;
            } else if (grid[i][j] == 0 && count == 3) {
                tempGrid[i][j] = 1;
            } else {
                tempGrid[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = tempGrid[i][j];
        }
    }
}

// Main function
int main() {
    srand(time(NULL)); // Seed the random number generator

    int grid[ROWS][COLS];

    initGrid(grid);
    printf("Initial state:\n");
    printGrid(grid);

    for (int i = 1; i <= 10; i++) {
        printf("State %d:\n", i);
        getNextState(grid);
        printGrid(grid);
    }

    return 0;
}