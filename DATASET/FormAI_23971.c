//FormAI DATASET v1.0 Category: Game of Life ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLUMNS 20

int countNeighbors(int grid[][COLUMNS], int row, int col) {
    int count = 0;
    int i, j;
    for(i = -1; i <= 1; i++) {
        for(j = -1; j <= 1; j++) {
            if(i == 0 && j == 0) {
                continue;
            }
            int r = row + i;
            int c = col + j;
            if(r < 0 || r >= ROWS || c < 0 || c >= COLUMNS) {
                continue;
            }
            if(grid[r][c] == 1) {
                count++;
            }
        }
    }
    return count;
}

void lifeCycle(int grid[][COLUMNS]) {
    int newGrid[ROWS][COLUMNS];
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLUMNS; j++) {
            int neighbors = countNeighbors(grid, i, j);
            if(grid[i][j] == 1) {
                if(neighbors == 2 || neighbors == 3) {
                    newGrid[i][j] = 1;
                }
                else {
                    newGrid[i][j] = 0;
                }
            }
            else {
                if(neighbors == 3) {
                    newGrid[i][j] = 1;
                }
                else {
                    newGrid[i][j] = 0;
                }
            }
        }
    }
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLUMNS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

void printGrid(int grid[][COLUMNS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLUMNS; j++) {
            printf("%c", grid[i][j] == 1 ? '*' : ' ');
        }
        printf("\n");
    }
}

int main() {
    int grid[ROWS][COLUMNS];
    int i, j;
    srand((unsigned)time(NULL));
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLUMNS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    for(i = 0; i < 100; i++) {
        system("clear");
        printGrid(grid);
        lifeCycle(grid);
        usleep(100000);
    }
    return 0;
}