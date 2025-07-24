//FormAI DATASET v1.0 Category: Game of Life ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define ROWS 20 //number of rows in the grid
#define COLS 20 //number of columns in the grid

void printGrid(char grid[][COLS]) {
    //function to print the grid
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int getNeighbors(char grid[][COLS], int x, int y) {
    //function to count the number of neighbors for a given cell
    int count = 0;
    for (int i=-1; i<=1; i++) {
        for (int j=-1; j<=1; j++) {
            if (i == 0 && j == 0) {
                //skip the cell itself
                continue;
            }
            int row = (x + i + ROWS) % ROWS;
            int col = (y + j + COLS) % COLS;
            if (grid[row][col] == 'X') {
                count++;
            }
        }
    }
    return count;
}

void nextGeneration(char grid[][COLS]) {
    //function to calculate the next generation of cells
    char newGrid[ROWS][COLS];
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            int neighbors = getNeighbors(grid, i, j);
            if (grid[i][j] == 'X') {
                //if the cell is alive
                if (neighbors < 2 || neighbors > 3) {
                    newGrid[i][j] = ' ';
                }
                else {
                    newGrid[i][j] = 'X';
                }
            }
            else {
                //if the cell is dead
                if (neighbors == 3) {
                    newGrid[i][j] = 'X';
                }
                else {
                    newGrid[i][j] = ' ';
                }
            }
        }
    }
    //copy the new grid to the old grid
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    //initialize the grid randomly
    char grid[ROWS][COLS];
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            if (rand() % 2) {
                grid[i][j] = 'X';
            }
            else {
                grid[i][j] = ' ';
            }
        }
    }
    //run the simulation for 100 generations
    for (int gen=1; gen<=100; gen++) {
        printf("Generation %d:\n", gen);
        printGrid(grid);
        nextGeneration(grid);
    }
    return 0;
}