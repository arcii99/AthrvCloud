//FormAI DATASET v1.0 Category: Game of Life ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the grid size
#define GRID_SIZE 15

// Define the number of generations to simulate
#define NUM_GENERATIONS 20

// Define the probability of a cell being alive at the start
#define PROB_LIVE_CELL 0.3

// Define the structure of a cell
typedef struct {
    int x;
    int y;
    int alive;
} cell;

// Define the function to initialize the grid
void init_grid(cell grid[GRID_SIZE][GRID_SIZE]) {
    // Seed the random number generator
    srand(time(NULL));
    
    // Loop through each cell in the grid
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            // Set the x and y coordinates of the cell
            grid[i][j].x = i;
            grid[i][j].y = j;
            
            // Set the initial state of the cell based on a random probability
            if (((double) rand() / (RAND_MAX)) < PROB_LIVE_CELL) {
                grid[i][j].alive = 1;
            } else {
                grid[i][j].alive = 0;
            }
        }
    }
}

// Define the function to print the grid
void print_grid(cell grid[GRID_SIZE][GRID_SIZE]) {
    // Loop through each cell in the grid
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            // Print an 'X' if the cell is alive, otherwise print a '.'
            if (grid[i][j].alive) {
                printf("X ");
            } else {
                printf(". ");
            }
        }
        
        // Print a newline at the end of each row
        printf("\n");
    }
    
    // Print a newline at the end of the grid
    printf("\n");
}

// Define the function to count the number of live neighbors of a cell
int count_live_neighbors(cell grid[GRID_SIZE][GRID_SIZE], int x, int y) {
    // Initialize the count to zero
    int count = 0;
    
    // Loop through the neighboring cells of the cell
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            // Make sure that the neighboring cell is inside the grid
            if (i >= 0 && i < GRID_SIZE && j >= 0 && j < GRID_SIZE) {
                // Exclude the cell itself (i.e., the center cell in the loop)
                if (!(i == x && j == y)) {
                    // Count the neighboring cell if it is alive
                    count += grid[i][j].alive;
                }
            }
        }
    }
    
    return count;
}

// Define the function to simulate one generation of the game
void simulate_generation(cell grid[GRID_SIZE][GRID_SIZE]) {
    // Initialize a new grid to hold the next generation of cells
    cell new_grid[GRID_SIZE][GRID_SIZE];
    
    // Loop through each cell in the grid
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            // Count the number of live neighbors of the cell
            int live_neighbor_count = count_live_neighbors(grid, i, j);
            
            // Apply the rules of the game to decide the state of the cell in the next generation
            if (grid[i][j].alive) {  // Cell is alive in the current generation
                if (live_neighbor_count < 2 || live_neighbor_count > 3) {
                    // Any live cell with fewer than two live neighbors dies, as if caused by underpopulation.
                    // Any live cell with more than three live neighbors dies, as if by overpopulation.
                    new_grid[i][j].alive = 0;
                } else {
                    // Any live cell with two or three live neighbors lives on to the next generation.
                    new_grid[i][j].alive = 1;
                }
            } else {  // Cell is dead in the current generation
                if (live_neighbor_count == 3) {
                    // Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
                    new_grid[i][j].alive = 1;
                } else {
                    // Any other dead cell stays dead in the next generation.
                    new_grid[i][j].alive = 0;
                }
            }
        }
    }
    
    // Copy the new grid back to the original grid
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j].alive = new_grid[i][j].alive;
        }
    }
}

// Define the main function
int main() {
    // Initialize the grid
    cell grid[GRID_SIZE][GRID_SIZE];
    init_grid(grid);
    
    // Loop through the generations and simulate each one
    for (int generation = 0; generation < NUM_GENERATIONS; generation++) {
        // Print the current state of the grid
        printf("Generation %d:\n", generation);
        print_grid(grid);
        
        // Simulate the next generation of the grid
        simulate_generation(grid);
    }
    
    return 0;
}