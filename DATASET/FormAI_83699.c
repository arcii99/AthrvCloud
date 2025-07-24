//FormAI DATASET v1.0 Category: Game of Life ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20 // Number of rows in the world
#define COLS 40 // Number of columns in the world
#define GENERATIONS 100 // Number of generations to simulate

// Function to initialize the world randomly
void initializeWorld(int world[ROWS][COLS]) {
    srand(time(NULL)); // Seed the random number generator
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            world[i][j] = rand() % 2; // Set each cell to either 0 or 1 randomly
        }
    }
}

// Function to print the current state of the world
void printWorld(int world[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (world[i][j] == 0) {
                printf("-");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to simulate one generation of the world
void simulateGeneration(int world[ROWS][COLS]) {
    int newWorld[ROWS][COLS]; // Array to hold the next generation of the world
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = 0; // Number of living neighbors
            
            // Check the eight neighbors around the cell
            for (int x = i - 1; x <= i + 1; x++) {
                for (int y = j - 1; y <= j + 1; y++) {
                    if (x >= 0 && x < ROWS && y >= 0 && y < COLS && !(x == i && y == j)) {
                        neighbors += world[x][y];
                    }
                }
            }
            
            // Apply the rules of the game of life to determine the new state of the cell
            if (world[i][j] == 1 && neighbors < 2) {
                newWorld[i][j] = 0; // Cell dies from loneliness
            } else if (world[i][j] == 1 && (neighbors == 2 || neighbors == 3)) {
                newWorld[i][j] = 1; // Cell survives to the next generation
            } else if (world[i][j] == 1 && neighbors > 3) {
                newWorld[i][j] = 0; // Cell dies from overcrowding
            } else if (world[i][j] == 0 && neighbors == 3) {
                newWorld[i][j] = 1; // Cell is born from reproduction
            } else {
                newWorld[i][j] = world[i][j]; // Cell stays the same
            }
        }
    }
    
    // Copy the new world back into the old world
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            world[i][j] = newWorld[i][j];
        }
    }
}

int main() {
    int world[ROWS][COLS]; // Array to hold the current state of the world
    
    initializeWorld(world); // Initialize the world randomly
    
    for (int i = 0; i < GENERATIONS; i++) {
        printf("Generation %d:\n", i + 1);
        printWorld(world); // Print the current state of the world
        simulateGeneration(world); // Simulate one generation of the world
    }
    
    return 0;
}