//FormAI DATASET v1.0 Category: Game of Life ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 60

int grid[ROWS][COLS];
int newGrid[ROWS][COLS];

void initGrid() {
    srand(time(NULL));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int value = rand() % 2;
            grid[i][j] = value;
        }
    }
}

int countNeighbors(int row, int col) {
    int count = 0;
    if(row > 0 && col > 0 && grid[row-1][col-1]) count++;
    if(row > 0 && grid[row-1][col]) count++;
    if(row > 0 && col < COLS-1 && grid[row-1][col+1]) count++;
    if(col < COLS-1 && grid[row][col+1]) count++;
    if(row < ROWS-1 && col < COLS-1 && grid[row+1][col+1]) count++;
    if(row < ROWS-1 && grid[row+1][col]) count++;
    if(row < ROWS-1 && col > 0 && grid[row+1][col-1]) count++;
    if(col > 0 && grid[row][col-1]) count++;
    return count;
}

void updateGrid() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int neighbors = countNeighbors(i, j);
            if(grid[i][j] == 1) {
                if(neighbors < 2 || neighbors > 3) {
                    newGrid[i][j] = 0;
                } else {
                    newGrid[i][j] = 1;
                }
            } else {
                if(neighbors == 3) {
                    newGrid[i][j] = 1;
                } else {
                    newGrid[i][j] = 0;
                }
            }
        }
    }
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

void printGrid() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(grid[i][j]) {
                printf("O");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    initGrid();
    while(1) {
        system("clear");
        printGrid();
        updateGrid();
    }
    return 0;
}