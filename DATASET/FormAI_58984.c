//FormAI DATASET v1.0 Category: Sudoku solver ; Style: decentralized
#include <stdio.h>

// Function to check if a number can be placed in the specified cell in the grid
int is_valid(int grid[9][9], int row, int col, int num) {
    int i, j;

    // Check row
    for (i = 0; i < 9; i++) {
        if (grid[row][i] == num) {
            return 0;
        }
    }

    // Check column
    for (i = 0; i < 9; i++) {
        if (grid[i][col] == num) {
            return 0;
        }
    }

    // Check box
    int box_start_row = row - row % 3;
    int box_start_col = col - col % 3;

    for (i = box_start_row; i < box_start_row + 3; i++) {
        for (j = box_start_col; j < box_start_col + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

// Function to solve the Sudoku puzzle using backtracking
int solve(int grid[9][9]) {
    int row, col, num;

    // Check if the grid is solved
    if (!find_empty_cell(grid, &row, &col)) {
        return 1;
    }

    // Try numbers from 1 to 9 in the specified cell
    for (num = 1; num <= 9; num++) {
        if (is_valid(grid, row, col, num)) {
            grid[row][col] = num;
            
            // Try to solve the puzzle recursively
            if (solve(grid)) {
                return 1;
            }

            // If the puzzle cannot be solved with this number, backtrack
            grid[row][col] = 0;
        }
    }

    return 0;
}

// Function to find the next empty cell in the grid
int find_empty_cell(int grid[9][9], int* row, int* col) {
    for (*row = 0; *row < 9; (*row)++) {
        for (*col = 0; *col < 9; (*col)++) {
            if (grid[*row][*col] == 0) {
                return 1;
            }
        }
    }

    return 0; // There are no empty cells in the grid
}

// Function to print the Sudoku puzzle
void print_puzzle(int grid[9][9]) {
    int i, j;

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
        }

        printf("\n");
    }
}

int main() {
    // Initialize the Sudoku puzzle
    int grid[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    // Solve the Sudoku puzzle
    if (solve(grid)) {
        printf("Solution:\n");
        print_puzzle(grid);
    } else {
        printf("No solution found\n");
    }

    return 0;
}