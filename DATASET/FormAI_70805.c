//FormAI DATASET v1.0 Category: Game of Life ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

int grid[ROWS][COLS];
int tempGrid[ROWS][COLS];

void initializeGrid() {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void printGrid() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (grid[i][j] == 1)
                printf("* ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

int getNeighborCount(int row, int col) {
    int count = 0;

    if (row - 1 >= 0 && col - 1 >= 0 && grid[row - 1][col - 1] == 1) // top left
        count++;
    if (row - 1 >= 0 && grid[row - 1][col] == 1) // top
        count++;
    if (row - 1 >= 0 && col + 1 < COLS && grid[row - 1][col + 1] == 1) // top right
        count++;
    if (col + 1 < COLS && grid[row][col + 1] == 1) // right
        count++;
    if (row + 1 < ROWS && col + 1 < COLS && grid[row + 1][col + 1] == 1) // bottom right
        count++;
    if (row + 1 < ROWS && grid[row + 1][col] == 1) // bottom
        count++;
    if (row + 1 < ROWS && col - 1 >= 0 && grid[row + 1][col - 1] == 1) // bottom left
        count++;
    if (col - 1 >= 0 && grid[row][col - 1] == 1) // left
        count++;

    return count;
}

void getNextIteration() {
    int i, j, neighbors;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            neighbors = getNeighborCount(i, j);
            if (grid[i][j] == 1 && (neighbors == 2 || neighbors == 3))
                tempGrid[i][j] = 1;
            else if (grid[i][j] == 0 && neighbors == 3)
                tempGrid[i][j] = 1;
            else
                tempGrid[i][j] = 0;
        }
    }

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = tempGrid[i][j];
        }
    }
}

int main() {
    int i;
    initializeGrid();
    for (i = 0; i < 100; i++) {
        printGrid();
        getNextIteration();
    }
    return 0;
}