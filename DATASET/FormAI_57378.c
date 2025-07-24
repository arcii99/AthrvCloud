//FormAI DATASET v1.0 Category: Game of Life ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the grid size
#define GRIDSIZE 30

// Define the maximum number of generations
#define MAXGEN 1000

// Define the range for random cell placement
#define RANDRANGE 10

// Define the number of live neighbors required for a dead cell to revive
#define REVIVE 3

// Define the minimum and maximum number of live neighbors required for a live cell to survive
#define MINLIVE 2
#define MAXLIVE 3

// Define the characters to print for live and dead cells
#define LIVECELL 'O'
#define DEADCELL ' '

// Define a 2D array representing the grid
int grid[GRIDSIZE][GRIDSIZE];

/*
 * Function: initializeGrid
 * ------------------------
 * Initializes the grid by randomly placing alive and dead cells
 *
 * returns: void
 */
void initializeGrid() {
    srand(time(NULL)); // Seed random number generator with current time
    
    int i, j;
    for (i = 0; i < GRIDSIZE; i++) {
        for (j = 0; j < GRIDSIZE; j++) {
            // Generate a random number between 0 and RANDRANGE
            int randNum = rand() % RANDRANGE;
            if (randNum == 0) { // If the number is 0, the cell is alive
                grid[i][j] = 1;
            } else { // Otherwise, the cell is dead
                grid[i][j] = 0;
            }
        }
    }
}

/*
 * Function: printGrid
 * -------------------
 * Prints the grid to the console
 *
 * returns: void
 */
void printGrid() {
    int i, j;
    for (i = 0; i < GRIDSIZE; i++) {
        for (j = 0; j < GRIDSIZE; j++) {
            if (grid[i][j] == 1) { // If the cell is alive, print LIVECELL character
                printf("%c ", LIVECELL);
            } else { // Otherwise, print DEADCELL character
                printf("%c ", DEADCELL);
            }
        }
        printf("\n"); // Move to next row
    }
    printf("\n"); // Add extra newline for spacing
}

/*
 * Function: updateGrid
 * --------------------
 * Updates the grid to the next generation based on the rules of Game of Life
 *
 * returns: void
 */
void updateGrid() {
    int i, j, k, l;
    int newGrid[GRIDSIZE][GRIDSIZE]; // Create a new grid to store the updated state
    
    for (i = 0; i < GRIDSIZE; i++) {
        for (j = 0; j < GRIDSIZE; j++) {
            int numNeighbors = 0; // Initialize the number of live neighbors to 0
            
            // Check the 8 adjacent cells for live cells
            for (k = -1; k <= 1; k++) {
                for (l = -1; l <= 1; l++) {
                    if (k == 0 && l == 0) { // Skip the current cell
                        continue;
                    }
                    int row = (i + k + GRIDSIZE) % GRIDSIZE; // Handle edge wrapping with modulus
                    int col = (j + l + GRIDSIZE) % GRIDSIZE;
                    if (grid[row][col] == 1) { // If the cell is alive, increment the number of live neighbors
                        numNeighbors++;
                    }
                }
            }
            
            // Determine the state of the cell based on the number of live neighbors
            if (grid[i][j] == 1) { // If the cell is alive
                if (numNeighbors >= MINLIVE && numNeighbors <= MAXLIVE) { // If it has the right number of live neighbors, it survives
                    newGrid[i][j] = 1;
                } else { // Otherwise, it dies
                    newGrid[i][j] = 0;
                }
            } else { // If the cell is dead
                if (numNeighbors == REVIVE) { // If it has the right number of live neighbors, it revives
                    newGrid[i][j] = 1;
                } else { // Otherwise, it stays dead
                    newGrid[i][j] = 0;
                }
            }
        }
    }
    
    // Copy the new grid back to the original grid
    for (i = 0; i < GRIDSIZE; i++) {
        for (j = 0; j < GRIDSIZE; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    initializeGrid(); // Initialize the grid with random cells
    
    int generation = 0;
    while (generation < MAXGEN) { // Loop through the generations
        printf("Generation %d:\n", generation);
        printGrid(); // Print the current grid
        updateGrid(); // Update the grid to the next generation
        generation++; // Increment the generation counter
    }
    
    return 0;
}