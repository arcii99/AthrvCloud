//FormAI DATASET v1.0 Category: Game of Life ; Style: statistical
/*
 * C Game of Life Example Program
 * Author: Your Name
 * Date: Date Here
 * Description: This program implements Conway's Game of Life using a statistical approach.
 *              The initial state of the simulation is randomly generated and the rules of the game
 *              are applied to update the state of the simulation.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50 // Size of the simulation grid

int grid[SIZE][SIZE]; // The simulation grid

/*
 * Function to initialize the grid randomly.
 */
void init_grid() {
    srand(time(NULL)); // Seed the random number generator with the current time
 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = rand() % 2; // Assign a random binary value to each cell
        }
    }
}

/*
 * Function to display the current state of the grid.
 */
void display_grid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j] ? '*' : ' '); // Display '*' if cell is alive, ' ' if cell is dead
        }
        printf("\n");
    }
}

/*
 * Function to apply the rules of the game to update the state of the grid.
 */
void update_grid() {
    int temp_grid[SIZE][SIZE] = {0}; // Temporary grid to store the updated state
 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int neighbors = 0;
 
            // Count the number of alive neighbors
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    neighbors += grid[(i+x+SIZE)%SIZE][(j+y+SIZE)%SIZE];
                }
            }
            neighbors -= grid[i][j]; // Subtract the cell itself from the count
 
            // Apply the rules of the game
            if (grid[i][j] && (neighbors < 2 || neighbors > 3)) {
                temp_grid[i][j] = 0; // Cell dies due to underpopulation or overpopulation
            } else if (!grid[i][j] && neighbors == 3) {
                temp_grid[i][j] = 1; // Cell comes to life due to reproduction
            } else {
                temp_grid[i][j] = grid[i][j]; // Cell remains in the same state
            }
        }
    }
 
    // Update the state of the grid
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = temp_grid[i][j];
        }
    }
}

int main() {
    init_grid(); // Initialize the grid randomly
 
    for (int i = 0; i < 100; i++) { // Simulate 100 generations
        printf("Generation %d:\n", i);
        display_grid(); // Display the current state of the grid
        update_grid(); // Update the state of the grid
    }
 
    return 0;
}