//FormAI DATASET v1.0 Category: Game of Life ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLUMNS 20

// Function to generate a random starting grid
void generateGrid(int grid[ROWS][COLUMNS]) {
    srand(time(NULL));
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLUMNS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Function to print grid
void printGrid(int grid[ROWS][COLUMNS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLUMNS; j++) {
            if(grid[i][j] == 1) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to count number of alive neighbors 
int countNeighbors(int grid[ROWS][COLUMNS], int row, int col) {
    int count = 0;
    int row_above = (row - 1 + ROWS) % ROWS;
    int row_below = (row + 1) % ROWS;
    int col_left = (col - 1 + COLUMNS) % COLUMNS;
    int col_right = (col + 1) % COLUMNS;
    count += grid[row_above][col_left];
    count += grid[row_above][col];
    count += grid[row_above][col_right];
    count += grid[row][col_left];
    count += grid[row][col_right];
    count += grid[row_below][col_left];
    count += grid[row_below][col];
    count += grid[row_below][col_right];
    return count;
}

// Function to update grid based on rules of Game of Life
void updateGrid(int grid[ROWS][COLUMNS]) {
    int new_grid[ROWS][COLUMNS];
    int i, j, count;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLUMNS; j++) {
            count = countNeighbors(grid, i, j);
            if(grid[i][j] == 1) {
                if(count < 2 || count > 3) {
                    new_grid[i][j] = 0;
                } else {
                    new_grid[i][j] = 1;
                }
            } else {
                if(count == 3) {
                    new_grid[i][j] = 1;
                } else {
                    new_grid[i][j] = 0;
                }
            }
        }
    }
    // Copy new grid over old grid
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLUMNS; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main() {
    int grid[ROWS][COLUMNS];
    generateGrid(grid);
    int generations = 20;
    int i;
    for(i = 0; i < generations; i++) {
        printGrid(grid);
        updateGrid(grid);
    }
    return 0;
}