//FormAI DATASET v1.0 Category: Game of Life ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

int grid[ROWS][COLS];
int tempGrid[ROWS][COLS];

// Initializes the grid with random values
void initializeGrid() {
    time_t t;
    srand((unsigned) time(&t));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Prints the current state of the grid
void printGeneration() {
    printf("Current Generation:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 0) {
                printf("-");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Determines the next state for each cell in the grid
void computeNextGeneration() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = 0;

            // Check the surrounding cells for live neighbors
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) {
                        continue;
                    }

                    int x = i + dx;
                    int y = j + dy;

                    if (x < 0) {
                        x = ROWS - 1;
                    } else if (x >= ROWS) {
                        x = 0;
                    }

                    if (y < 0) {
                        y = COLS - 1;
                    } else if (y >= COLS) {
                        y = 0;
                    }

                    neighbors += grid[x][y];
                }
            }

            // Apply the rules of Life to determine the cell's new state
            tempGrid[i][j] = grid[i][j];
            if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                tempGrid[i][j] = 0;
            } else if (grid[i][j] == 0 && neighbors == 3) {
                tempGrid[i][j] = 1;
            }
        }
    }
}

// Updates the grid with the new generation
void updateGrid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = tempGrid[i][j];
        }
    }
}

int main() {
    initializeGrid();

    for (int i = 0; i < 10; i++) {
        printGeneration();
        computeNextGeneration();
        updateGrid();
    }

    return 0;
}