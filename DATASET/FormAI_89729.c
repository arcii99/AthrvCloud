//FormAI DATASET v1.0 Category: Game of Life ; Style: intelligent
#include <stdio.h>

#define SIZE 20 // size of the grid

void clearGrid(int grid[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = 0; // initialize all cells to dead
        }
    }
}

void printGrid(int grid[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 1) {
                printf(" * ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int countNeighbors(int grid[][SIZE], int row, int col) {
    int count = 0;
    for (int i = row-1; i <= row+1; i++) {
        for (int j = col-1; j <= col+1; j++) {
            if (i >= 0 && i < SIZE && j >= 0 && j < SIZE) { // check if within bounds
                if (i != row || j != col) { // exclude current cell
                    count += grid[i][j];
                }
            }
        }
    }
    return count;
}

void updateGrid(int grid[][SIZE]) {
    int newGrid[SIZE][SIZE];
    clearGrid(newGrid);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int neighbors = countNeighbors(grid, i, j);
            if (grid[i][j] == 1 && (neighbors == 2 || neighbors == 3)) { // survive
                newGrid[i][j] = 1;
            } else if (grid[i][j] == 0 && neighbors == 3) { // birth
                newGrid[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = newGrid[i][j]; // update original grid
        }
    }
}

int main() {
    int grid1[SIZE][SIZE], grid2[SIZE][SIZE], *currGrid, *prevGrid;
    clearGrid(grid1);
    grid1[10][9] = 1;
    grid1[10][10] = 1;
    grid1[10][11] = 1;
    grid1[9][11] = 1;
    grid1[8][10] = 1;
    grid1[5][5] = 1;
    grid1[5][6] = 1;
    grid1[6][5] = 1;
    grid1[6][6] = 1;
    clearGrid(grid2);
    currGrid = &grid1[0][0]; // start with grid1 as current grid
    prevGrid = &grid2[0][0];
    while (1) {
        updateGrid(currGrid);
        printGrid(currGrid);
        // swap grids
        int *tempGrid = currGrid;
        currGrid = prevGrid;
        prevGrid = tempGrid;
    }
    return 0;
}