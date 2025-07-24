//FormAI DATASET v1.0 Category: Game of Life ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20 // Size of the world
#define GENERATIONS 10 // Number of generations to simulate

// Declare functions
void initializeWorld(int world[][SIZE]);
void printWorld(int world[][SIZE]);
int countNeighbors(int world[][SIZE], int i, int j);
void updateWorld(int world[][SIZE]);

int main() {
    int world[SIZE][SIZE]; // Initialize the world

    // Seed the random number generator
    srand(time(NULL));

    // Initialize the world
    initializeWorld(world);

    // Print the initial world
    printf("Initial World:\n");
    printWorld(world);

    // Simulate each generation
    for(int i = 0; i < GENERATIONS; i++) {
        updateWorld(world); // Update the world for this generation
        printf("Generation %d:\n", i+1); // Print the current generation
        printWorld(world); // Print the world for this generation
    }

    return 0;
}

// Initialize the world
void initializeWorld(int world[][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            // Randomly set cells to be alive or dead
            if(rand() % 2 == 0) {
                world[i][j] = 0; // Dead
            } else {
                world[i][j] = 1; // Alive
            }
        }
    }
}

// Print the current state of the world
void printWorld(int world[][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(world[i][j] == 1) {
                printf("*"); // Alive
            } else {
                printf("."); // Dead
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Count the number of alive neighbors around a cell
int countNeighbors(int world[][SIZE], int i, int j) {
    int count = 0;

    // Check the neighbors in the 8 surrounding cells
    for(int x = -1; x <= 1; x++) {
        for(int y = -1; y <= 1; y++) {
            // Skip the current cell
            if(x == 0 && y == 0) {
                continue;
            }

            // Calculate the coordinates of the neighbor cell
            int neighborX = i + x;
            int neighborY = j + y;

            // Make sure the neighbor cell is within the world
            if(neighborX < 0 || neighborX >= SIZE || neighborY < 0 || neighborY >= SIZE) {
                continue;
            }

            // If the neighbor cell is alive, increment the count
            if(world[neighborX][neighborY] == 1) {
                count++;
            }
        }
    }

    return count;
}

// Update the world for a new generation
void updateWorld(int world[][SIZE]) {
    int newWorld[SIZE][SIZE]; // Create a new world to hold the updated values

    // Calculate the new state for each cell in the world
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            int neighbors = countNeighbors(world, i, j); // Count the number of alive neighbors around this cell

            // Determine if this cell should be alive or dead for the next generation
            if(world[i][j] == 1) { // If the cell is currently alive
                if(neighbors < 2 || neighbors > 3) { // If it has less than 2 or more than 3 alive neighbors, it dies
                    newWorld[i][j] = 0; // Dead
                } else { // If it has 2 or 3 alive neighbors, it survives
                    newWorld[i][j] = 1; // Alive
                }
            } else { // If the cell is currently dead
                if(neighbors == 3) { // If it has exactly 3 alive neighbors, it comes to life
                    newWorld[i][j] = 1; // Alive
                } else { // Otherwise, it stays dead
                    newWorld[i][j] = 0; // Dead
                }
            }
        }
    }

    // Copy the new world back to the original world
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            world[i][j] = newWorld[i][j];
        }
    }
}