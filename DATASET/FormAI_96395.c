//FormAI DATASET v1.0 Category: Game of Life ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 60

void displayGrid(char grid[ROWS][COLS]) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

void populateGrid(char grid[ROWS][COLS], int density) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (rand() % 100 < density) {
                grid[i][j] = '#';
            } else {
                grid[i][j] = '.';
            }
        }
    }
}

int countNeighbors(char grid[ROWS][COLS], int row, int col) {
    int count = 0;
    int i, j;

    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            if (row + i < 0 || row + i >= ROWS || col + j < 0 || col + j >= COLS) continue;
            if (grid[row + i][col + j] == '#') count++;
        }
    }

    return count;
}

void updateGrid(char grid[ROWS][COLS]) {
    int i, j;
    char newGrid[ROWS][COLS];

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            int neighbors = countNeighbors(grid, i, j);

            if (grid[i][j] == '#') {
                if (neighbors < 2 || neighbors > 3) {
                    newGrid[i][j] = '.';
                } else {
                    newGrid[i][j] = '#';
                }
            } else {
                if (neighbors == 3) {
                    newGrid[i][j] = '#';
                } else {
                    newGrid[i][j] = '.';
                }
            }
        }
    }

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    srand(time(NULL));
    char grid[ROWS][COLS];
    int density = 30;

    populateGrid(grid, density);
    displayGrid(grid);

    printf("\n\n");

    for (int i = 0; i < 100; i++) {
        updateGrid(grid);
        displayGrid(grid);
        printf("\n\n");
    }

    return 0;
}