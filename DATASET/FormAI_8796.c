//FormAI DATASET v1.0 Category: Game of Life ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 20
#define MAX_COLS 50

// Initialize the grid
void initialize_grid(int grid[][MAX_COLS], int rows, int cols) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Randomly set each cell to either 1 or 0
            grid[i][j] = (rand() % 2);
        }
    }
}

// Print the current state of the grid
void print_grid(int grid[][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                printf("O ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Get the number of live neighbors for a given cell
int get_num_live_neighbors(int grid[][MAX_COLS], int i, int j, int rows, int cols) {
    int num_live_neighbors = 0;
    
    // Get the neighbors
    int row_neighbors[] = {i-1, i-1, i-1, i, i, i+1, i+1, i+1};
    int col_neighbors[] = {j-1, j, j+1, j-1, j+1, j-1, j, j+1};
    
    for (int k = 0; k < 8; k++) {
        int row = row_neighbors[k];
        int col = col_neighbors[k];
        
        // Check if the neighbor is within the bounds of the grid
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            num_live_neighbors += grid[row][col];
        }
    }
    
    return num_live_neighbors;
}

// Update the grid based on the rules of the game
void update_grid(int grid[][MAX_COLS], int rows, int cols) {
    int new_grid[MAX_ROWS][MAX_COLS];
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int num_live_neighbors = get_num_live_neighbors(grid, i, j, rows, cols);
            
            // Apply the rules of the game
            if (grid[i][j] == 1 && (num_live_neighbors < 2 || num_live_neighbors > 3)) {
                new_grid[i][j] = 0;
            } else if (grid[i][j] == 0 && num_live_neighbors == 3) {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = grid[i][j];
            }
        }
    }
    
    // Copy the new grid to the original grid
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main() {
    int grid[MAX_ROWS][MAX_COLS];
    
    // Initialize the grid
    initialize_grid(grid, MAX_ROWS, MAX_COLS);
    
    // Run the game for 100 iterations
    for (int i = 0; i < 100; i++) {
        printf("Iteration %d:\n", i);
        print_grid(grid, MAX_ROWS, MAX_COLS);
        update_grid(grid, MAX_ROWS, MAX_COLS);
    }
    
    return 0;
}