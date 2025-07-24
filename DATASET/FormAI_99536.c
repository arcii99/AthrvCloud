//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int grid[ROWS][COLS];

void printGrid() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(grid[i][j] == 0) {
                printf(". ");
            } else {
                printf("O ");
            }
        }
        printf("\n");
    }
}

int checkNeighbor(int x, int y) {
    int neighborCount = 0;

    if(x > 0 && y > 0 && grid[x-1][y-1] == 1) {
        neighborCount++;
    }
    if(x > 0 && grid[x-1][y] == 1) {
        neighborCount++;
    }
    if(x > 0 && y < COLS-1 && grid[x-1][y+1] == 1) {
        neighborCount++;
    }
    if(y > 0 && grid[x][y-1] == 1) {
        neighborCount++;
    }
    if(y < COLS-1 && grid[x][y+1] == 1) {
        neighborCount++;
    }
    if(x < ROWS-1 && y > 0 && grid[x+1][y-1] == 1) {
        neighborCount++;
    }
    if(x < ROWS-1 && grid[x+1][y] == 1) {
        neighborCount++;
    }
    if(x < ROWS-1 && y < COLS-1 && grid[x+1][y+1] == 1) {
        neighborCount++;
    }

    return neighborCount;
}

int percolate() {
    int percolateFlag = 0;

    for(int i = 0; i < ROWS; i++) {
        if(grid[0][i] == 1) {
            percolateFlag = 1;
            break;
        }
    }

    return percolateFlag;
}

int main() {
    srand(time(NULL));

    // initialize grid
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(rand() % 2 == 0) {
                grid[i][j] = 0;
            } else {
                grid[i][j] = 1;
            }
        }
    }

    // print initial grid
    printf("Initial grid:\n");
    printGrid();

    // simulate percolation
    int count = 1;
    while(!percolate()) {
        count++;

        // iterate over grid
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                int neighborCount = checkNeighbor(i, j);
                if(neighborCount >= 4 && grid[i][j] == 0) {
                    grid[i][j] = 1;
                }
            }
        }
    }

    // print final grid
    printf("Final grid:\n");
    printGrid();

    // print number of iterations for percolation
    printf("Percolation finished after %d iterations.\n", count);

    return 0;
}