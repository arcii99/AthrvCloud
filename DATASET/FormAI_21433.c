//FormAI DATASET v1.0 Category: Game of Life ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 50
#define COLS 50

int grid[ROWS][COLS];
int newGrid[ROWS][COLS];

void initialize() {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
            newGrid[i][j] = 0;
        }
    }
}

void printGrid() {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(grid[i][j] == 1)
                printf("X");
            else
                printf(".");
        }
        printf("\n");
    }
}

int countNeighbors(int row, int col) {
    int count = 0;
    int i, j;
    for(i = -1; i <= 1; i++) {
        for(j = -1; j <= 1; j++) {
            int neighborRow = row + i;
            int neighborCol = col + j;
            if(neighborRow >= 0 && neighborRow < ROWS && neighborCol >= 0 && neighborCol < COLS) {
                if(i != 0 || j != 0) {
                    count += grid[neighborRow][neighborCol];
                }
            }
        }
    }
    return count;
}

void updateGrid() {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            int neighbors = countNeighbors(i, j);
            if(grid[i][j] == 1) {
                if(neighbors < 2 || neighbors > 3)
                    newGrid[i][j] = 0;
                else
                    newGrid[i][j] = 1;
            }
            else {
                if(neighbors == 3)
                    newGrid[i][j] = 1;
            }
        }
    }
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    srand(time(NULL));
    initialize();

    while(1) {
        system("clear");
        printGrid();
        updateGrid();
        sleep(1);
    }

    return 0;
}