//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// Function to initialize the grid with random values
void initializeGrid(int grid[ROWS][COLS], int probability) {
    srand(time(NULL));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int randNum = rand()%100 + 1;
            if(randNum <= probability) {
                grid[i][j] = 1;
            }
            else {
                grid[i][j] = 0;
            }
        }
    }
}

// Function to output the grid
void outputGrid(int grid[ROWS][COLS]) {
    printf("Grid:\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to simulate percolation using DFS algorithm
void percolate(int grid[ROWS][COLS], int r, int c) {
    if(r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] != 1) {
        return;
    }
    grid[r][c] = 2; // marking cell as visited
    percolate(grid, r-1, c);
    percolate(grid, r+1, c);
    percolate(grid, r, c-1);
    percolate(grid, r, c+1);
}

// Function to check if the grid percolates
int checkPercolation(int grid[ROWS][COLS]) {
    int topVisited = 0;
    int bottomVisited = 0;
    for(int i=0; i<COLS; i++) {
        if(grid[0][i] == 2) {
            topVisited = 1;
        }
        if(grid[ROWS-1][i] == 2) {
            bottomVisited = 1;
        }
    }
    return topVisited && bottomVisited;
}

int main() {
    int grid[ROWS][COLS] = {0};
    int probability = 50; // chance of a cell being 1, in percentage
    initializeGrid(grid, probability);
    outputGrid(grid);
    printf("Simulating percolation...\n");
    for(int i=0; i<COLS; i++) {
        if(grid[0][i] == 1) {
            percolate(grid, 0, i);
        }
    }
    if(checkPercolation(grid)) {
        printf("The grid percolates!\n");
    }
    else {
        printf("The grid does not percolate.\n");
    }
    return 0;
}