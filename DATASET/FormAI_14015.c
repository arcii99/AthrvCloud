//FormAI DATASET v1.0 Category: Game of Life ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

void displayGrid(int grid[][WIDTH]) {
    for (int i=0; i<HEIGHT; i++) {
        for (int j=0; j<WIDTH; j++) {
            printf("%c ", grid[i][j] ? '#' : ' ');
        }
        printf("\n");
    }
    printf("\n");
}

int countNeighbors(int grid[][WIDTH], int row, int col) {
    int count = 0;
    for (int i=row-1; i<=row+1; i++) {
        for (int j=col-1; j<=col+1; j++) {
            if (i>=0 && i<HEIGHT && j>=0 && j<WIDTH && !(i==row && j==col) && grid[i][j]) {
                count++;
            }
        }
    }
    return count;
}

void updateGrid(int grid[][WIDTH]) {
    int newGrid[HEIGHT][WIDTH] = {0};
    for (int i=0; i<HEIGHT; i++) {
        for (int j=0; j<WIDTH; j++) {
            int neighbors = countNeighbors(grid, i, j);
            if (grid[i][j]) {
                if (neighbors < 2 || neighbors > 3) {
                    newGrid[i][j] = 0;
                } else {
                    newGrid[i][j] = 1;
                }
            } else {
                if (neighbors == 3) {
                    newGrid[i][j] = 1;
                } else {
                    newGrid[i][j] = 0;
                }
            }
        }
    }
    for (int i=0; i<HEIGHT; i++) {
        for (int j=0; j<WIDTH; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    int grid[HEIGHT][WIDTH];
    srand(time(NULL));
    for (int i=0; i<HEIGHT; i++) {
        for (int j=0; j<WIDTH; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    while (1) {
        displayGrid(grid);
        updateGrid(grid);
    }
    return 0;
}