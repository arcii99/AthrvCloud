//FormAI DATASET v1.0 Category: Game of Life ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 20 // Change this to adjust the grid size
#define GENERATIONS 100 // Change this to adjust the number of iterations

int grid[GRID_SIZE][GRID_SIZE];
int temp[GRID_SIZE][GRID_SIZE];

void initialize(); // Initialize the grid
void print(); // Print the grid
int countNeighbors(int, int); // Count the number of alive neighbors of a cell

int main()
{
    srand(time(NULL)); // Seed the random number generator

    initialize(); // Initialize the grid

    for (int i = 0; i < GENERATIONS; i++) { // Loop over the number of generations
        print(); // Print the current generation
        for (int j = 0; j < GRID_SIZE; j++) { // Loop over the rows of the grid
            for (int k = 0; k < GRID_SIZE; k++) { // Loop over the columns of the grid
                int count = countNeighbors(j, k); // Count the number of alive neighbors
                if (grid[j][k] == 1) { // If the current cell is alive
                    if (count < 2 || count > 3) { // If it has less than 2 or more than 3 neighbors, it dies
                        temp[j][k] = 0;
                    } else { // Otherwise, it stays alive
                        temp[j][k] = 1;
                    }
                } else { // If the current cell is dead
                    if (count == 3) { // If it has exactly 3 neighbors, it comes to life
                        temp[j][k] = 1;
                    } else { // Otherwise, it stays dead
                        temp[j][k] = 0;
                    }
                }
            }
        }
        for (int j = 0; j < GRID_SIZE; j++) { // Copy the temp grid to the main grid
            for (int k = 0; k < GRID_SIZE; k++) {
                grid[j][k] = temp[j][k];
            }
        }
    }

    return 0; // Exit the program
}

/**
 * Initializes the grid randomly.
 */
void initialize()
{
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

/**
 * Prints the grid to the console.
 */
void print()
{
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 1) {
                printf("X ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * Returns the number of alive neighbors of a cell.
 *
 * @param row The row index of the cell.
 * @param col The column index of the cell.
 * @return The number of alive neighbors.
 */
int countNeighbors(int row, int col)
{
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int r = row + i;
            int c = col + j;
            if (r < 0 || r >= GRID_SIZE || c < 0 || c >= GRID_SIZE) {
                continue;
            }
            if (grid[r][c] == 1) {
                count++;
            }
        }
    }
    return count;
}