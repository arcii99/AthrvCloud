//FormAI DATASET v1.0 Category: Game of Life ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define ROWS 10
#define COLS 10

void displayGrid(int grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                printf(" * ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int countNeighbors(int grid[ROWS][COLS], int i, int j) {
    int count = 0;
    int rowStart = i - 1 < 0 ? i : i - 1;
    int rowEnd = i + 1 > ROWS - 1 ? i : i + 1;
    int colStart = j - 1 < 0 ? j : j - 1;
    int colEnd = j + 1 > COLS - 1 ? j : j + 1;
    for (int row = rowStart; row <= rowEnd; row++) {
        for (int col = colStart; col <= colEnd; col++) {
            if (row == i && col == j) {
                continue;
            }
            if (grid[row][col] == 1) {
                count++;
            }
        }
    }
    return count;
}

void nextGeneration(int grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = countNeighbors(grid, i, j);
            if (grid[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    grid[i][j] = 0;
                }
            } else {
                if (neighbors == 3) {
                    grid[i][j] = 1;
                }
            }
        }
    }
}

bool isGridEmpty(int grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                return false;
            }
        }
    }
    return true;
}

void gameOfLife(int grid[ROWS][COLS], int generation) {
    if (isGridEmpty(grid) || generation <= 0) {
        printf("Game Over.\n");
        return;
    }
    printf("Generation: %d\n", generation);
    displayGrid(grid);
    nextGeneration(grid);
    gameOfLife(grid, generation-1);
}

int main() {
    int grid[ROWS][COLS] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
                            {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    gameOfLife(grid, 10);
    return 0;
}