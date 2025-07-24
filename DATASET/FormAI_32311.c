//FormAI DATASET v1.0 Category: Game of Life ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void randomFill(int grid[ROWS][COLS]) {
    srand(time(NULL));

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void showGrid(int grid[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j] ? '#' : '.');
        }
        printf("\n");
    }
}

int countNeighbors(int grid[ROWS][COLS], int row, int col) {
    int count = 0;

    for(int i = row - 1; i <= row + 1; i++) {
        for(int j = col - 1; j <= col + 1; j++) {
            if(i < 0 || i >= ROWS || j < 0 || j >= COLS) {
                continue;
            }
            if(i == row && j == col) {
                continue;
            }
            if(grid[i][j]) {
                count++;
            }
        }
    }

    return count;
}

void updateGrid(int grid[ROWS][COLS]) {
    int newGrid[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int neighbors = countNeighbors(grid, i, j);
            if(grid[i][j]) {
                if(neighbors < 2 || neighbors > 3) {
                    newGrid[i][j] = 0;
                } else {
                    newGrid[i][j] = 1;
                }
            } else {
                if(neighbors == 3) {
                    newGrid[i][j] = 1;
                } else {
                    newGrid[i][j] = 0;
                }
            }
        }
    }
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    int grid[ROWS][COLS];
    randomFill(grid);
    for(int i = 0; i < 10; i++) {
        showGrid(grid);
        printf("\n");
        updateGrid(grid);
    }
    return 0;
}