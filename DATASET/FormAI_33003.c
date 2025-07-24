//FormAI DATASET v1.0 Category: Game of Life ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 50
#define COLS 50

// Initialize the grid with random values
void initialize_grid(int grid[ROWS][COLS]) {
    srand(time(NULL));
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Print the grid
void print_grid(int grid[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(grid[i][j] == 1) {
                printf("* ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// Count the number of live neighbors for a given cell
int count_live_neighbors(int grid[ROWS][COLS], int row, int col) {
    int count = 0;
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <=1; j++) {
            int neighbor_row = row + i;
            int neighbor_col = col + j;
            if(neighbor_row >= 0 && neighbor_row < ROWS && neighbor_col >= 0 && neighbor_col < COLS) {
                if(!(i == 0 && j == 0) && grid[neighbor_row][neighbor_col] == 1) {
                    count++;
                }
            }
        }
    }
    return count;
}

// Update the grid for the next iteration
void update_grid(int grid[ROWS][COLS]) {
    int new_grid[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int live_neighbors = count_live_neighbors(grid, i, j);
            if(grid[i][j] == 0) {
                if(live_neighbors == 3) {
                    new_grid[i][j] = 1;
                } else {
                    new_grid[i][j] = 0;
                }
            } else {
                if(live_neighbors < 2 || live_neighbors > 3) {
                    new_grid[i][j] = 0;
                } else {
                    new_grid[i][j] = 1;
                }
            }
        }
    }
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

// Main function
int main() {
    int grid[ROWS][COLS];
    initialize_grid(grid);
    for(int i = 0; i < 100; i++) {
        system("clear"); // Clear the screen before printing the new grid
        printf("Iteration: %d\n", i);
        print_grid(grid);
        update_grid(grid);
        usleep(50000); // Wait for 50 milliseconds before updating the grid again
    }
    return 0;
}