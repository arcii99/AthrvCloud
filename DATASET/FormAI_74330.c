//FormAI DATASET v1.0 Category: Game of Life ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 30
#define COLS 60

void initializeGrid(int grid[ROWS][COLS]) {
    srand(time(NULL));
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = (rand() % 2);
            printf("%c", grid[i][j] == 1 ? '#' : ' ');
        }
        printf("\n");
    }
}

void printGrid(int grid[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c", grid[i][j] == 1 ? '#' : ' ');
        }
        printf("\n");
    }
}

int countLiveNeighbors(int grid[ROWS][COLS], int row, int col) {
    int count = 0;
    for(int i = row-1; i <= row+1; i++) {
        for(int j = col-1; j <= col+1; j++) {
            if(i>=0 && i<ROWS && j>=0 && j<COLS && !(i==row && j==col) && grid[i][j]==1) {
                count++;
            }
        }
    }
    return count;
}

void updateGrid(int grid[ROWS][COLS]) {
    int nextGrid[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int liveNeighbors = countLiveNeighbors(grid,i,j);
            if(grid[i][j] == 1 && (liveNeighbors == 2 || liveNeighbors == 3)) {
                nextGrid[i][j] = 1;
            }
            else if(grid[i][j] == 0 && liveNeighbors == 3) {
                nextGrid[i][j] = 1;
            }
            else {
                nextGrid[i][j] = 0;
            }
        }
    }
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = nextGrid[i][j];
        }
    }
}

int main() {
    int grid[ROWS][COLS];
    initializeGrid(grid);
    while(1) {
        printf("\033[H\033[J");
        printGrid(grid);
        updateGrid(grid);
        usleep(50000);
    }
    return 0;
}