//FormAI DATASET v1.0 Category: Game of Life ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 40
#define COLUMNS 80
#define GENERATIONS 1000

// Function to randomly initialize the grid
void initializeGrid(int grid[ROWS][COLUMNS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Function to print the grid
void printGrid(int grid[ROWS][COLUMNS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            if(grid[i][j] == 1) {
                printf("*");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
}

// Function to count the number of live neighbors for a given cell
int countLiveNeighbors(int grid[ROWS][COLUMNS], int row, int col) {
    int count = 0;
    for(int i=row-1; i<=row+1; i++) {
        for(int j=col-1; j<=col+1; j++) {
            if(i >= 0 && j >= 0 && i < ROWS && j < COLUMNS) {
                if(i != row || j != col) {
                    count += grid[i][j];
                }
            }
        }
    }
    return count;
}

// Function to update the grid based on the rules of the game of life
void updateGrid(int grid[ROWS][COLUMNS]) {
    int newGrid[ROWS][COLUMNS];
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            int liveNeighbors = countLiveNeighbors(grid, i, j);
            if(grid[i][j] == 1) {
                if(liveNeighbors < 2 || liveNeighbors > 3) {
                    newGrid[i][j] = 0;
                } else {
                    newGrid[i][j] = 1;
                }
            } else {
                if(liveNeighbors == 3) {
                    newGrid[i][j] = 1;
                } else {
                    newGrid[i][j] = 0;
                }
            }
        }
    }
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    int grid[ROWS][COLUMNS];
    initializeGrid(grid);
    for(int i=0; i<GENERATIONS; i++) {
        printf("\033c"); // Clear the terminal
        printf("Generation %d:\n", i+1);
        printGrid(grid);
        updateGrid(grid);
        usleep(10000); // Sleep for 10 milliseconds
    }
    return 0;
}