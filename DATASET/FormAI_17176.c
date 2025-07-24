//FormAI DATASET v1.0 Category: Game of Life ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 2-dimensional array representing the grid */
int grid[20][20];

/* Function to print the grid */
void printGrid() {
    for (int i=0; i<20; i++) {
        for (int j=0; j<20; j++) {
            if (grid[i][j] == 1) {
                printf("%c", 'x');
            } else {
                printf("%c", '-');
            }
        }
        printf("\n");
    }
}

/* Function to count the live neighbors of a cell */
int countNeighbors(int x, int y) {
    int count = 0;
    for (int i=x-1; i<=x+1; i++) {
        for (int j=y-1; j<=y+1; j++) {
            if (i>=0 && i<20 && j>=0 && j<20 && !(i==x && j==y) && grid[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

/* Function to simulate the next generation of cells */
void nextGeneration() {
    int nextGrid[20][20];
    for (int i=0; i<20; i++) {
        for (int j=0; j<20; j++) {
            int count = countNeighbors(i, j);
            if (grid[i][j] == 1 && (count < 2 || count > 3)) {
                nextGrid[i][j] = 0;
            } else if (grid[i][j] == 0 && count == 3) {
                nextGrid[i][j] = 1;
            } else {
                nextGrid[i][j] = grid[i][j];
            }
        }
    }
    memcpy(grid, nextGrid, sizeof(grid));
}

int main() {
    /* initialize the grid randomly */
    srand(time(NULL));
    for (int i=0; i<20; i++) {
        for (int j=0; j<20; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    /* Run the simulation for 50 generations and print the grid at each step */
    for (int gen=0; gen<50; gen++) {
        printf("Generation %d:\n", gen);
        printGrid();
        nextGeneration();
    }

    return 0;
}