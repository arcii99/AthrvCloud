//FormAI DATASET v1.0 Category: Game of Life ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define grid size
#define ROWS 10
#define COLS 10

// define cell value
#define DEAD 0
#define ALIVE 1

// store grid board state
int grid[ROWS][COLS];
int newGrid[ROWS][COLS];

// initialize grid with random values
void initGrid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// print current grid state
void printGrid() {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == ALIVE) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

// update a single cell based on its neighbors
void updateCell(int x, int y) {
    int neighbors = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (!(i == 0 && j == 0)) { // exclude current cell
                if (x+i < 0 || x+i >= ROWS) { // check for out of bounds
                    continue;
                }
                if (y+j < 0 || y+j >= COLS) { // check for out of bounds
                    continue;
                }
                if (grid[x+i][y+j] == ALIVE) {
                    neighbors++;
                }
            }
        }
    }
    if (grid[x][y] == ALIVE) {
        if (neighbors < 2 || neighbors > 3) { // death rule
            newGrid[x][y] = DEAD;
        } else { // survival rule
            newGrid[x][y] = ALIVE;
        }
    } else {
        if (neighbors == 3) { // birth rule
            newGrid[x][y] = ALIVE;
        } else { // still dead
            newGrid[x][y] = DEAD;
        }
    }
}

// update the entire grid for a new generation
void updateGrid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            updateCell(i, j);
        }
    }
    memcpy(grid, newGrid, sizeof(grid)); // copy new grid state to current grid
}

int main() {
    srand(time(NULL)); // seed random generator
    initGrid();
    int generations = 10;
    printGrid();
    for (int i = 0; i < generations; i++) {
        updateGrid();
        printGrid();
    }
    return 0;
}