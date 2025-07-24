//FormAI DATASET v1.0 Category: Game of Life ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 20
#define COLS 30

// Function to initialize the grid randomly
void initGrid(bool grid[ROWS][COLS]) {
    srand(time(NULL));
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Function to print the current grid state
void printGrid(bool grid[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c", grid[i][j] ? '#' : '.');
        }
        printf("\n");
    }
}

// Function to count the number of live neighbors for a given cell
int getLiveNeighbors(bool grid[ROWS][COLS], int row, int col) {
    int count = 0;
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            int nRow = row + i;
            int nCol = col + j;
            if(i == 0 && j == 0) continue;
            if(nRow < 0 || nRow >= ROWS || nCol < 0 || nCol >= COLS) continue;
            if(grid[nRow][nCol]) count++;
        }
    }
    return count;
}

// Function to update the grid state for the next generation
void updateGrid(bool grid[ROWS][COLS]) {
    bool newGrid[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int neighbors = getLiveNeighbors(grid, i, j);
            if(grid[i][j] && neighbors < 2) newGrid[i][j] = false;
            else if(grid[i][j] && (neighbors == 2 || neighbors == 3)) newGrid[i][j] = true;
            else if(grid[i][j] && neighbors > 3) newGrid[i][j] = false;
            else if(!grid[i][j] && neighbors == 3) newGrid[i][j] = true;
            else newGrid[i][j] = grid[i][j];
        }
    }
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

// Main function to run the game of life
int main() {
    bool grid[ROWS][COLS];
    initGrid(grid);
    while(true) {
        system("clear");    // Clear the terminal for a fresh display
        printGrid(grid);
        updateGrid(grid);
        usleep(500000);     // Add a delay for better visualization
    }
    return 0;
}