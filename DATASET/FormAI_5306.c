//FormAI DATASET v1.0 Category: Game of Life ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50 // Width of the grid
#define HEIGHT 20 // Height of the grid
#define GENERATIONS 1000 // Number of generations to simulate

// Function to update the grid based on the rules of Game of Life
void updateGrid(int grid[][WIDTH]) {
    int nextGrid[HEIGHT][WIDTH]; // Array to hold the updated grid

    // Loop through every cell in the grid
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            
            // Count the number of live neighbors for this cell
            int liveNeighbors = 0;
            for (int j = -1; j <= 1; j++) {
                for (int i = -1; i <= 1; i++) {
                    if (!(i == 0 && j == 0)) { // Ignore the current cell
                        int dx = x + i;
                        int dy = y + j;
                        if (dx >= 0 && dx < WIDTH && dy >= 0 && dy < HEIGHT && grid[dy][dx] == 1) {
                            liveNeighbors++;
                        }
                    }
                }
            }
            
            // Update the cell based on the rules of Game of Life
            if (grid[y][x] == 1) {
                if (liveNeighbors < 2 || liveNeighbors > 3) {
                    nextGrid[y][x] = 0; // Cell dies
                } else {
                    nextGrid[y][x] = 1; // Cell lives
                }
            } else {
                if (liveNeighbors == 3) {
                    nextGrid[y][x] = 1; // New cell is born
                } else {
                    nextGrid[y][x] = 0; // Cell stays dead
                }
            }
        }
    }
    
    // Copy the updated grid back to the original grid
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            grid[y][x] = nextGrid[y][x];
        }
    }
}

// Function to randomly initialize the grid
void initGrid(int grid[][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (rand() % 2 == 0) {
                grid[y][x] = 1; // Cell is alive
            } else {
                grid[y][x] = 0; // Cell is dead
            }
        }
    }
}

// Function to print the grid
void printGrid(int grid[][WIDTH], int generation) {
    printf("Generation %d:\n", generation);
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (grid[y][x] == 1) {
                printf("*"); // Cell is alive
            } else {
                printf("."); // Cell is dead
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    int grid[HEIGHT][WIDTH]; // 2D array to hold the grid
    
    initGrid(grid); // Initialize the grid
    
    printGrid(grid, 0); // Print the initial grid
    
    for (int i = 1; i <= GENERATIONS; i++) {
        updateGrid(grid); // Update the grid
        printGrid(grid, i); // Print the updated grid
    }
    
    return 0;
}