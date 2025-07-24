//FormAI DATASET v1.0 Category: Game of Life ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 50

int grid[ROWS][COLS];

void initializeGrid() {
    srand(time(NULL));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void printGrid() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%c ", grid[i][j] == 1 ? '@' : '-');
        }
        printf("\n");
    }
}

int getNeighbors(int row, int col) {
    int neighbors = 0;
    for(int i=row-1; i<=row+1; i++) {
        for(int j=col-1; j<=col+1; j++) {
            if(i==row && j==col) {
                continue;
            }
            if(i>=0 && i<ROWS && j>=0 && j<COLS && grid[i][j] == 1) {
                neighbors++;
            }
        }
    }
    return neighbors;
}

void updateGrid() {
    int newGrid[ROWS][COLS];
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int neighbors = getNeighbors(i, j);
            if(neighbors < 2 || neighbors > 3) {
                newGrid[i][j] = 0;
            } else if(neighbors == 3) {
                newGrid[i][j] = 1;
            } else {
                newGrid[i][j] = grid[i][j];
            }
        }
    }
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    initializeGrid();
    printf("Initial Grid:\n");
    printGrid();
    for(int i=0; i<10; i++) {
        updateGrid();
        printf("\nGrid after %d generations:\n", i+1);
        printGrid();
    }
    return 0;
}