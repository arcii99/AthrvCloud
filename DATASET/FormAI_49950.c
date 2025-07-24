//FormAI DATASET v1.0 Category: Game of Life ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// Function to print the updated grid
void print(int grid[ROWS][COLS]) {
    system("clear");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(grid[i][j] == 0) printf(" . ");
            else printf(" * ");
        }
        printf("\n");
    }
}

// Function to count the number of live neighbours
int countNeighbours(int grid[ROWS][COLS], int r, int c) {
    int count = 0;
    for(int i = r-1; i <= r+1; i++) {
        for(int j = c-1; j <= c+1; j++) {
            if((i >= 0 && i < ROWS) && (j >= 0 && j < COLS)) {
                if(grid[i][j] == 1) count++;
            }
        }
    }
    count -= grid[r][c];
    return count;
}

// Function to update the grid based on Game of Life rules
void update(int grid[ROWS][COLS]) {
    int newGrid[ROWS][COLS] = {0};
    // Loop through each cell in the grid
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int neighbours = countNeighbours(grid, i, j);
            // If the cell is alive
            if(grid[i][j] == 1) {
                // If it has less than 2 or more than 3 neighbours, it dies
                if(neighbours < 2 || neighbours > 3) newGrid[i][j] = 0;
                // Otherwise, it stays alive
                else newGrid[i][j] = 1;
            }
            // If the cell is dead
            if(grid[i][j] == 0) {
                // If it has exactly 3 neighbours, it comes to life
                if(neighbours == 3) newGrid[i][j] = 1;
            }
        }
    }
    // Copy the new grid to the original grid
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    // Initialize the grid with random values
    int grid[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    // Main loop to update and print the grid
    while(1) {
        print(grid);
        update(grid);
        // Wait for 200 milliseconds before updating again
        struct timespec delay = {0, 200000000};
        nanosleep(&delay, NULL);
    }
    return 0;
}