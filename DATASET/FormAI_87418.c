//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int grid[ROWS][COLS];
int visited[ROWS][COLS];

void fillGrid(int fillProb) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            visited[i][j] = 0;
            if (rand() % 101 < fillProb) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
}

void printGrid() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                printf("# ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void percolate(int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return;
    }
    if (grid[row][col] == 0 || visited[row][col] == 1) {
        return;
    }
    visited[row][col] = 1;
    percolate(row - 1, col);
    percolate(row + 1, col);
    percolate(row, col - 1);
    percolate(row, col + 1);
}

int isPercolating() {
    int i;
    for (i = 0; i < COLS; i++) {
        if (grid[0][i] == 1) {
            percolate(0, i);
        }
    }
    for (i = 0; i < COLS; i++) {
        if (visited[ROWS - 1][i] == 1) {
            return 1;
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    int fillProb = 45;
    fillGrid(fillProb);
    printGrid();
    if (isPercolating()) {
        printf("The grid is percolating\n");
    } else {
        printf("The grid is not percolating\n");
    }
    return 0;
}