//FormAI DATASET v1.0 Category: Game of Life ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define constants
#define ROWS 20
#define COLS 20
#define GENERATIONS 50

// Game of Life Function
void game_of_life(int world[][COLS]);

// Main Function
int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Initialize the world with random values
    int world[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            world[i][j] = rand() % 2;
        }
    }
    
    // Print the initial world
    printf("Initial World:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", world[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // Run the generations of the Game of Life
    for (int generation = 0; generation < GENERATIONS; generation++) {
        game_of_life(world);
        
        // Print the world after each generation
        printf("Generation %d:\n", generation+1);
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%d ", world[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    
    return 0;
}

void game_of_life(int world[][COLS]) {
    int new_world[ROWS][COLS]; // Create a new world to hold the changes
    
    // Loop through each cell of the world
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = 0; // Count the number of neighbors
            
            // Check the eight neighbors surrounding the cell
            for (int row = -1; row <= 1; row++) {
                for (int col = -1; col <= 1; col++) {
                    int r = i + row;
                    int c = j + col;
                    
                    // Make sure not to go out of bounds
                    if (r < 0 || r >= ROWS || c < 0 || c >= COLS || (row == 0 && col == 0)) {
                        continue;
                    }
                    
                    // Check if the neighbor is alive
                    if (world[r][c] == 1) {
                        neighbors++;
                    }
                }
            }
            
            // Apply the rules of the Game of Life
            if (world[i][j] == 1 && neighbors < 2) {
                new_world[i][j] = 0; // Underpopulation
            } else if (world[i][j] == 1 && neighbors > 3) {
                new_world[i][j] = 0; // Overpopulation
            } else if (world[i][j] == 0 && neighbors == 3) {
                new_world[i][j] = 1; // Reproduction
            } else {
                new_world[i][j] = world[i][j]; // Stasis
            }
        }
    }
    
    // Copy the changes back to the original world
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            world[i][j] = new_world[i][j];
        }
    }
}