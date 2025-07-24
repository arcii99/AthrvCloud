//FormAI DATASET v1.0 Category: Game of Life ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 50
#define COLS 100

int grid[ROWS][COLS];
int nextGrid[ROWS][COLS];

void initializeGrid() {
    srand(time(NULL));
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

void printGrid() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(grid[i][j] == 0) {
                printf(".");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

int countNeighbors(int row, int col) {
    int count = 0;
    int newRow, newCol;

    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            newRow = (row + i + ROWS) % ROWS;
            newCol = (col + j + COLS) % COLS;

            if(grid[newRow][newCol] == 1) {
                count++;
            }
        }
    }

    if(grid[row][col] == 1) {
        count--;
    }

    return count;
}

void updateGrid() {
    int neighbors;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            neighbors = countNeighbors(i, j);
            if(grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                nextGrid[i][j] = 0;
            } else if(grid[i][j] == 0 && neighbors == 3) {
                nextGrid[i][j] = 1;
            } else {
                nextGrid[i][j] = grid[i][j];
            }
        }
    }

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = nextGrid[i][j];
        }
    }
}

int main() {
    initializeGrid();
    while(1) {
        printGrid();
        updateGrid();
    }
    return 0;
}