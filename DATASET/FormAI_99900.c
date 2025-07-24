//FormAI DATASET v1.0 Category: Game of Life ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 20
#define COLS 40
#define GENERATIONS 100

// function to display the grid
void displayGrid(int grid[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(grid[i][j] == 1) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

// function to count live neighbors
int countNeighbors(int grid[ROWS][COLS], int row, int col) {
    int count = 0;
    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++) {
            int r = (row + i + ROWS) % ROWS;
            int c = (col + j + COLS) % COLS;
            if(grid[r][c] == 1) {
                count++;
            }
        }
    }
    count -= grid[row][col];
    return count;
}

// function to apply game rules and generate the next generation
void generateNextGeneration(int grid[ROWS][COLS]) {
    int futureGrid[ROWS][COLS];
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int neighbors = countNeighbors(grid, i, j);
            if(grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                futureGrid[i][j] = 0;
            } else if (grid[i][j] == 0 && neighbors == 3) {
                futureGrid[i][j] = 1;
            } else {
                futureGrid[i][j] = grid[i][j];
            }
        }
    }
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            grid[i][j] = futureGrid[i][j];
        }
    }
}

int main() {
    int grid[ROWS][COLS] = {0};
    
    // add some initial living cells
    grid[5][5] = 1;
    grid[5][6] = 1;
    grid[6][5] = 1;
    grid[6][6] = 1;
    grid[16][20] = 1;
    grid[16][21] = 1;
    grid[16][22] = 1;
    grid[16][23] = 1;
    
    for(int i=0; i<GENERATIONS; i++) {
        system("clear"); // clear screen
        printf("Generation %d:\n", i+1);
        displayGrid(grid);
        generateNextGeneration(grid);
        usleep(250000);
    }

    return 0;
}