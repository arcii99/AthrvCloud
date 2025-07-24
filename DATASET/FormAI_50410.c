//FormAI DATASET v1.0 Category: Sudoku solver ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>

// Define the size of the grid
#define SIZE 9

// Define a structure to represent each cell of the grid
typedef struct {
    int row;
    int col;
    int value;
} Cell;

// Define a function to print the grid to the console
void print_grid(int grid[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Define a function to check if a given value is valid in a given cell
int is_valid(Cell cell, int grid[SIZE][SIZE]) {
    // Check if the value is already in the same row or column
    for (int i = 0; i < SIZE; i++) {
        if (grid[i][cell.col] == cell.value || grid[cell.row][i] == cell.value) {
            return 0;
        }
    }
    // Check if the value is already in the same subgrid
    int subgrid_row = (cell.row / 3) * 3;
    int subgrid_col = (cell.col / 3) * 3;
    for (int i = subgrid_row; i < subgrid_row + 3; i++) {
        for (int j = subgrid_col; j < subgrid_col + 3; j++) {
            if (grid[i][j] == cell.value) {
                return 0;
            }
        }
    }
    // If the value is not already in the same row, column or subgrid, then it's valid
    return 1;
}

// Define a recursive function to solve the puzzle
int solve(int grid[SIZE][SIZE], int cells_to_solve) {
    // Base case: If there are no cells left to solve, then the puzzle is solved
    if (cells_to_solve == 0) {
        return 1;
    }
    // Find the next empty cell in the grid (i.e., with value 0)
    Cell next_cell;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0) {
                next_cell.row = i;
                next_cell.col = j;
                break;
            }
        }
        if (grid[next_cell.row][next_cell.col] == 0) {
            break;
        }
    }
    // Try all possible values for the next cell
    for (int value = 1; value <= SIZE; value++) {
        next_cell.value = value;
        if (is_valid(next_cell, grid)) {
            // Set the value of the next cell in the grid
            grid[next_cell.row][next_cell.col] = next_cell.value;
            // Recursively solve the puzzle with the new grid
            if (solve(grid, cells_to_solve - 1)) {
                return 1;
            }
            // If we get here, then the current value didn't lead to a valid solution, so reset the cell
            grid[next_cell.row][next_cell.col] = 0;
        }
    }
    // If we get here, then none of the possible values for the next cell led to a valid solution, so backtrack
    return 0;
}

int main() {
    // Create a 9x9 grid with some cells filled in (0 represents an empty cell)
    int grid[SIZE][SIZE] = {
        {6, 0, 0, 1, 0, 8, 0, 0, 0},
        {7, 9, 0, 0, 0, 6, 0, 0, 2},
        {0, 0, 0, 0, 0, 9, 0, 0, 0},
        {0, 7, 0, 0, 0, 5, 3, 0, 0},
        {0, 8, 0, 3, 0, 4, 0, 7, 0},
        {0, 0, 4, 7, 0, 0, 0, 6, 0},
        {0, 0, 0, 8, 0, 0, 0, 0, 0},
        {8, 0, 0, 0, 7, 0, 0, 1, 3},
        {0, 0, 0, 9, 0, 3, 0, 0, 6}
    };
    // Count the number of cells that need to be solved
    int cells_to_solve = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0) {
                cells_to_solve++;
            }
        }
    }
    // Print the initial grid
    printf("Initial grid:\n");
    print_grid(grid);
    // Solve the puzzle
    if (solve(grid, cells_to_solve)) {
        // Print the solution
        printf("Solution:\n");
        print_grid(grid);
    } else {
        printf("No solution found.\n");
    }
    // Exit the program
    return 0;
}