//FormAI DATASET v1.0 Category: Game of Life ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 20

void printGrid(int grid[GRID_SIZE][GRID_SIZE]) {
    printf("\n");
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            if(grid[i][j] == 1) {
                printf("* ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int countNeighbours(int grid[GRID_SIZE][GRID_SIZE], int x, int y) {
    int count = 0;
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            if(i == 0 && j == 0) {
                continue;
            }
            
            int row = (x + i + GRID_SIZE) % GRID_SIZE;
            int col = (y + j + GRID_SIZE) % GRID_SIZE;
            
            if(grid[row][col] == 1) {
                count++;
            }
        }
    }
    return count;
}

void step(int grid[GRID_SIZE][GRID_SIZE]) {
    int newGrid[GRID_SIZE][GRID_SIZE];
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            int neighbours = countNeighbours(grid, i, j);
            
            if(grid[i][j] == 1 && neighbours < 2) {
                newGrid[i][j] = 0;
            } else if(grid[i][j] == 1 && (neighbours == 2 || neighbours == 3)) {
                newGrid[i][j] = 1;
            } else if(grid[i][j] == 1 && neighbours > 3) {
                newGrid[i][j] = 0;
            } else if(grid[i][j] == 0 && neighbours == 3) {
                newGrid[i][j] = 1;
            } else {
                newGrid[i][j] = grid[i][j];
            }
        }
    }
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    int grid[GRID_SIZE][GRID_SIZE];
    srand(time(NULL));
    
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    
    for(int i = 0; i < 50; i++) {
        printGrid(grid);
        step(grid);
    }
    
    return 0;
}