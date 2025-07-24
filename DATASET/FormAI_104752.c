//FormAI DATASET v1.0 Category: Game of Life ; Style: Alan Touring
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ROWS 40
#define COLS 80

int grid[ROWS][COLS];
int newGrid[ROWS][COLS];

void initGrid() {
    srand(time(NULL));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void printGrid() {
    system("clear");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(grid[i][j] == 1) printf("#");
            else printf(" ");
        }
        printf("\n");
    }
    usleep(50000);
}

int countNeighbors(int row, int col) {
    int count = 0;
    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++) {
            if(i == 0 && j == 0) continue;
            int r = row + i;
            int c = col + j;
            if(r < 0 || r >= ROWS || c < 0 || c >= COLS) continue;
            if(grid[r][c] == 1) count++;
        }
    }
    return count;
}

void updateGrid() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int neighbors = countNeighbors(i, j);
            if(grid[i][j] == 1) {
                if(neighbors < 2 || neighbors > 3) newGrid[i][j] = 0;
                else newGrid[i][j] = 1;
            }
            else {
                if(neighbors == 3) newGrid[i][j] = 1;
                else newGrid[i][j] = 0;
            }
        }
    }
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    initGrid();
    while(1) {
        printGrid();
        updateGrid();
    }
    return 0;
}