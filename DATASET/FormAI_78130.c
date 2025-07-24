//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define THRESHOLD 0.4

int grid[ROWS][COLS];
int visited[ROWS][COLS];

void printGrid() {
    printf("\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(grid[i][j]) {
                printf("* ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

void percolate(int row, int col) {
    visited[row][col] = 1;
    grid[row][col] = 1;

    if (row < ROWS - 1 && !visited[row+1][col] && (rand() < THRESHOLD * RAND_MAX)) {
        percolate(row+1, col);
    }

    if (col < COLS - 1 && !visited[row][col+1] && (rand() < THRESHOLD * RAND_MAX)) {
        percolate(row, col+1);
    }

    if (row > 0 && !visited[row-1][col] && (rand() < THRESHOLD * RAND_MAX)) {
        percolate(row-1, col);
    }

    if (col > 0 && !visited[row][col-1] && (rand() < THRESHOLD * RAND_MAX)) {
        percolate(row, col-1);
    }
}

int main() {
    srand(time(NULL));
    
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            visited[i][j] = 0;
            grid[i][j] = 0;
        }
    }

    percolate(0, 0);

    printGrid();

    return 0;
}