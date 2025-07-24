//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10

// function to print the 2D grid
void printGrid(int grid[][COL]) {
    printf("Grid:\n");
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// function to check if the given cell is valid or not
int isValid(int grid[][COL], int row, int col) {
    if(row >= 0 && row < ROW && col >= 0 && col < COL) {
        return (grid[row][col] == 0);
    }
    return 0;
}

// function to check if the given cell is connected to the top
int isTopConnected(int grid[][COL], int row, int col) {
    if(row == 0) {
        return 1;
    }
    if(isValid(grid, row-1, col) && grid[row-1][col] == 1) {
        return 1;
    }
    return 0;
}

// function to check if the given cell is connected to the bottom
int isBottomConnected(int grid[][COL], int row, int col) {
    if(row == ROW-1) {
        return 1;
    }
    if(isValid(grid, row+1, col) && grid[row+1][col] == 1) {
        return 1;
    }
    return 0;
}

// function to check if the given cell is connected to the left
int isLeftConnected(int grid[][COL], int row, int col) {
    if(col == 0) {
        return 1;
    }
    if(isValid(grid, row, col-1) && grid[row][col-1] == 1) {
        return 1;
    }
    return 0;
}

// function to check if the given cell is connected to the right
int isRightConnected(int grid[][COL], int row, int col) {
    if(col == COL-1) {
        return 1;
    }
    if(isValid(grid, row, col+1) && grid[row][col+1] == 1) {
        return 1;
    }
    return 0;
}

// function to check if the given cell is full or not
int isFullCell(int grid[][COL], int row, int col) {
    return (isValid(grid, row, col) && isTopConnected(grid, row, col));
}

// function to percolate the grid
int percolate(int grid[][COL], int row, int col) {
    if(!isValid(grid, row, col)) {
        return 0;
    }
    grid[row][col] = 1;
    if(isBottomConnected(grid, row, col)) {
        return 1;
    }
    int left = isLeftConnected(grid, row, col) ? percolate(grid, row, col-1) : 0;
    int right = isRightConnected(grid, row, col) ? percolate(grid, row, col+1) : 0;
    int top = isTopConnected(grid, row, col) ? percolate(grid, row-1, col) : 0;
    int bottom = isBottomConnected(grid, row, col) ? percolate(grid, row+1, col) : 0;
    return (left || right || top || bottom);
}

int main() {
    srand(time(NULL));
    int grid[ROW][COL] = {0};
    int openCellsCount = 0;
    // randomly open some cells
    while(openCellsCount < 15) {
        int row = rand() % ROW;
        int col = rand() % COL;

        if(!isValid(grid, row, col)) {
            continue;
        }
        grid[row][col] = 1;
        openCellsCount++;
    }

    printGrid(grid);
    // percolate the grid
    if(percolate(grid, 0, 0)) {
        printf("The grid percolates!\n");
    } else {
        printf("The grid does not percolate!\n");
    }

    return 0;
}