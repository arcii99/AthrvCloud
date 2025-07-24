//FormAI DATASET v1.0 Category: Game of Life ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLUMNS 20
#define GENERATIONS 50

void printGrid(int grid[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (grid[i][j])
                printf("*");
            else
                printf(".");
        }
        printf("\n");
    }
    printf("\n");
}

void initializeGrid(int grid[ROWS][COLUMNS]) {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void updateGrid(int grid[ROWS][COLUMNS]) {
    int neighborCount;
    int tempGrid[ROWS][COLUMNS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            neighborCount = 0;
            // Check neighbors 
            if (i > 0 && grid[i-1][j]) // Above 
                neighborCount++;
            if (i < ROWS - 1 && grid[i+1][j]) // Below
                neighborCount++;
            if (j > 0 && grid[i][j-1]) // Left
                neighborCount++;
            if (j < COLUMNS - 1 && grid[i][j+1]) // Right
                neighborCount++;
            if (i > 0 && j > 0 && grid[i-1][j-1]) // Upper left
                neighborCount++;
            if (i > 0 && j < COLUMNS - 1 && grid[i-1][j+1]) // Upper right
                neighborCount++;
            if (i < ROWS - 1 && j > 0 && grid[i+1][j-1]) // Lower left
                neighborCount++;
            if (i < ROWS - 1 && j < COLUMNS - 1 && grid[i+1][j+1]) // Lower right
                neighborCount++;
            if (grid[i][j]) {
                // Cell is alive
                if (neighborCount < 2 || neighborCount > 3)
                    tempGrid[i][j] = 0; // Cell dies
                else
                    tempGrid[i][j] = 1; // Cell lives
            } else {
                // Cell is dead
                if (neighborCount == 3)
                    tempGrid[i][j] = 1; // Cell lives
                else
                    tempGrid[i][j] = 0; // Cell stays dead
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            grid[i][j] = tempGrid[i][j];
        }
    }
}

int main() {
    int grid[ROWS][COLUMNS];
    initializeGrid(grid);
    printGrid(grid);
    for (int i = 0; i < GENERATIONS; i++) {
        updateGrid(grid);
        printGrid(grid);
    }
    return 0;
}