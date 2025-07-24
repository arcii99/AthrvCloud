//FormAI DATASET v1.0 Category: Game of Life ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to initialize the grid randomly */
void initGrid(int grid[][20]) {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            grid[i][j] = (rand() % 2);
        }
    }
}

/* Function to print the current state of grid */
void printGrid(int grid[][20]) {
    int i, j;
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/* Function to check the number of neighbors */
int checkNeighbors(int grid[][20], int row, int col) {
    int count = 0;
    if (row > 0 && grid[row - 1][col] == 1) {
        count++;
    }
    if (row < 19 && grid[row + 1][col] == 1) {
        count++;
    }
    if (col > 0 && grid[row][col - 1] == 1) {
        count++;
    }
    if (col < 19 && grid[row][col + 1] == 1) {
        count++;
    }
    if (row > 0 && col > 0 && grid[row - 1][col - 1] == 1) {
        count++;
    }
    if (row < 19 && col < 19 && grid[row + 1][col + 1] == 1) {
        count++;
    }
    if (row > 0 && col < 19 && grid[row - 1][col + 1] == 1) {
        count++;
    }
    if (row < 19 && col > 0 && grid[row + 1][col - 1] == 1) {
        count++;
    }
    return count;
}

/* Function to update the grid after one iteration */
void updateGrid(int grid[][20]) {
    int i, j;
    int temp[20][20];
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            int neighbors = checkNeighbors(grid, i, j);
            if (neighbors < 2 || neighbors > 3) {
                temp[i][j] = 0;
            }
            else if (neighbors == 3) {
                temp[i][j] = 1;
            }
            else {
                temp[i][j] = grid[i][j];
            }
        }
    }
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            grid[i][j] = temp[i][j];
        }
    }
}

int main() {
    int grid[20][20];
    initGrid(grid);
    printf("Initial Grid:\n");
    printGrid(grid);
    int i;
    for (i = 0; i < 5; i++) {
        printf("Iteration %d:\n", i + 1);
        updateGrid(grid);
        printGrid(grid);
    }
    return 0;
}