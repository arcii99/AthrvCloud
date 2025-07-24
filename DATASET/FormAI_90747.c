//FormAI DATASET v1.0 Category: Game of Life ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20 // number of rows in the grid
#define COLS 50 // number of columns in the grid
#define GENERATIONS 100 // number of generations to simulate

// function to initialize the grid with random values
void initialize_grid(int grid[ROWS][COLS]) {
    srand(time(NULL)); // seed the random number generator
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            grid[row][col] = rand() % 2; // randomly assign 0 or 1 to each cell
        }
    }
}

// function to print the grid
void print_grid(int grid[ROWS][COLS]) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (grid[row][col] == 1) {
                printf("*"); // print an asterisk for live cells
            } else {
                printf("."); // print a period for dead cells
            }
        }
        printf("\n"); // move to the next row
    }
}

// function to count the number of live neighbors for a given cell
int count_neighbors(int grid[ROWS][COLS], int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int neighbor_row = (row + i + ROWS) % ROWS; // handle edge wrapping
            int neighbor_col = (col + j + COLS) % COLS; // handle edge wrapping
            if (grid[neighbor_row][neighbor_col] == 1 && (i != 0 || j != 0)) {
                count++; // increment the count if the neighbor is alive
            }
        }
    }
    return count;
}

// function to update the grid for each generation
void update_grid(int grid[ROWS][COLS]) {
    int new_grid[ROWS][COLS]; // create a new grid to hold the updated values
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            int neighbors = count_neighbors(grid, row, col);
            if (grid[row][col] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[row][col] = 0; // cell dies due to underpopulation or overpopulation
            } else if (grid[row][col] == 0 && neighbors == 3) {
                new_grid[row][col] = 1; // cell is born due to exactly 3 neighbors
            } else {
                new_grid[row][col] = grid[row][col]; // cell stays the same
            }
        }
    }
    // copy the updated values back to the original grid
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            grid[row][col] = new_grid[row][col];
        }
    }
}

int main() {
    int grid[ROWS][COLS];
    initialize_grid(grid);
    for (int gen = 1; gen <= GENERATIONS; gen++) {
        printf("Generation %d:\n", gen);
        print_grid(grid);
        update_grid(grid);
    }
    return 0;
}