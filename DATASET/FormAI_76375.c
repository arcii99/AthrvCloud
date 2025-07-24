//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void printGrid(int grid[SIZE][SIZE], int perc[SIZE][SIZE]) {
    printf("Grid: \n");
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\nPercolation Status: \n");
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf("%d ", perc[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------------\n");
}

void initGrid(int grid[SIZE][SIZE], int perc[SIZE][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            grid[i][j] = 0;
            perc[i][j] = 0;
        }
    }
}

int isValid(int i, int j) {
    if(i >= 0 && i < SIZE && j >= 0 && j < SIZE) {
        return 1;
    }
    return 0;
}

void percolate(int grid[SIZE][SIZE], int perc[SIZE][SIZE], int row, int col) {
    int changes = 1;

    perc[row][col] = 1;
    while(changes) {
        changes = 0;
        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                if(grid[i][j] == 1) {
                    if(isValid(i-1, j) && perc[i-1][j] == 1 && perc[i][j] == 0) {
                        perc[i][j] = 1;
                        changes = 1;
                    }
                    if(isValid(i+1, j) && perc[i+1][j] == 1 && perc[i][j] == 0) {
                        perc[i][j] = 1;
                        changes = 1;
                    }
                    if(isValid(i, j-1) && perc[i][j-1] == 1 && perc[i][j] == 0) {
                        perc[i][j] = 1;
                        changes = 1;
                    }
                    if(isValid(i, j+1) && perc[i][j+1] == 1 && perc[i][j] == 0) {
                        perc[i][j] = 1;
                        changes = 1;
                    }
                }
            }
        }
    }
}

void randomFill(int grid[SIZE][SIZE], float fillPercentage) {
    int numberOfFilled = 0;
    int maxFilled = (int)(SIZE * SIZE * fillPercentage);

    while(numberOfFilled < maxFilled) {
        int i = rand() % SIZE;
        int j = rand() % SIZE;

        if(grid[i][j] == 0) {
            grid[i][j] = 1;
            numberOfFilled++;
        }
    }
}

int main() {
    srand(time(NULL));
    float fillPercentage = 0.5;
    int grid[SIZE][SIZE], perc[SIZE][SIZE];
    initGrid(grid, perc);

    randomFill(grid, fillPercentage);
    printGrid(grid, perc);

    percolate(grid, perc, 0, 0);
    printGrid(grid, perc);

    return 0;
}