//FormAI DATASET v1.0 Category: Game of Life ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 20

int grid[ROWS][COLS];

void initializeGrid() {
    // Randomly initializes the grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void printGrid() {
    // Prints out the current grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                printf("X ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int countNeighbors(int i, int j) {
    // Counts the number of live neighbors around a cell
    int count = 0;
    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            int neighborI = i + x;
            int neighborJ = j + y;
            if (neighborI >= 0 && neighborI < ROWS && neighborJ >= 0 && neighborJ < COLS) {
                count += grid[neighborI][neighborJ];
            }
        }
    }
    count -= grid[i][j]; // Subtract the cell itself
    return count;
}

void updateGrid() {
    // Updates the grid according to the rules of Game of Life
    int newGrid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = countNeighbors(i, j);
            if (grid[i][j] == 0 && neighbors == 3) {
                newGrid[i][j] = 1; // Cell is born
            } else if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                newGrid[i][j] = 0; // Cell dies
            } else {
                newGrid[i][j] = grid[i][j]; // Cell stays the same
            }
        }
    }
    // Update the original grid with the new one
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    initializeGrid();
    for (int i = 0; i < 100; i++) { // Runs for 100 generations
        printGrid();
        updateGrid();
    }
    return 0;
}