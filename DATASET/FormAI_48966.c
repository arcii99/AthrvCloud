//FormAI DATASET v1.0 Category: Game of Life ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50 // Width of the grid
#define HEIGHT 25 // Height of the grid
#define ALIVE 'O' // Symbol for an alive cell
#define DEAD ' ' // Symbol for a dead cell

// Function prototypes
void initialize_grid(char grid[HEIGHT][WIDTH]);
void print_grid(char grid[HEIGHT][WIDTH]);
int count_neighbors(char grid[HEIGHT][WIDTH], int row, int col);

int main() {
    char grid[HEIGHT][WIDTH];
    int generation = 0;

    srand(time(NULL)); // Seed the random number generator

    initialize_grid(grid); // Initialize the grid with random cells

    while (1) {
        system("clear"); // Clear the screen
        printf("Generation: %d\n", generation);
        print_grid(grid); // Print the grid

        char new_grid[HEIGHT][WIDTH]; // Create a new grid to hold the next generation

        // Loop through each cell in the grid
        for (int row = 0; row < HEIGHT; row++) {
            for (int col = 0; col < WIDTH; col++) {
                int neighbors = count_neighbors(grid, row, col);
                char state = grid[row][col];

                // Apply the rules of the Game of Life
                if (state == ALIVE && (neighbors < 2 || neighbors > 3)) {
                    new_grid[row][col] = DEAD;
                } else if (state == DEAD && neighbors == 3) {
                    new_grid[row][col] = ALIVE;
                } else {
                    new_grid[row][col] = state;
                }
            }
        }

        // Copy the new grid to the original grid
        for (int row = 0; row < HEIGHT; row++) {
            for (int col = 0; col < WIDTH; col++) {
                grid[row][col] = new_grid[row][col];
            }
        }

        generation++; // Increment the generation counter
    }

    return 0;
}

// Initializes the grid with random alive and dead cells
void initialize_grid(char grid[HEIGHT][WIDTH]) {
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            // Fill each cell with a 50/50 chance of being alive or dead
            grid[row][col] = (rand() % 2) ? ALIVE : DEAD;
        }
    }
}

// Prints the grid to the console
void print_grid(char grid[HEIGHT][WIDTH]) {
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            printf("%c ", grid[row][col]);
        }
        printf("\n");
    }
}

// Returns the number of alive neighbor cells for a given cell
int count_neighbors(char grid[HEIGHT][WIDTH], int row, int col) {
    int count = 0;

    // Check the eight neighbors around the cell
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int neighbor_row = row + i;
            int neighbor_col = col + j;

            // Skip cells outside of the grid or the current cell
            if (neighbor_row < 0 || neighbor_row >= HEIGHT || neighbor_col < 0 || neighbor_col >= WIDTH || (i == 0 && j == 0)) {
                continue;
            }

            if (grid[neighbor_row][neighbor_col] == ALIVE) {
                count++;
            }
        }
    }

    return count;
}