//FormAI DATASET v1.0 Category: Sudoku solver ; Style: ultraprecise
#include <stdio.h>

// Define the size of the Sudoku grid
#define N 9

// Function to print the Sudoku grid
void print_grid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a given number can be placed in the specified location
int can_place(int grid[N][N], int row, int col, int num) {
    // Check row for duplicate numbers
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num) {
            return 0;
        }
    }

    // Check column for duplicate numbers
    for (int i = 0; i < N; i++) {
        if (grid[i][col] == num) {
            return 0;
        }
    }

    // Check box for duplicate numbers
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[box_row + i][box_col + j] == num) {
                return 0;
            }
        }
    }

    // Number can be placed
    return 1;
}

// Function to solve the Sudoku grid using a backtracking algorithm
int solve(int grid[N][N], int row, int col) {
    // Move to next row if end of current row is reached
    if (col == N) {
        row++;
        col = 0;
    }

    // Return 1 if entire grid has been traversed
    if (row == N) {
        return 1;
    }

    // Skip location if it already contains a number
    if (grid[row][col] != 0) {
        return solve(grid, row, col + 1);
    }

    // Try placing numbers from 1 to 9
    for (int num = 1; num <= 9; num++) {
        if (can_place(grid, row, col, num)) {
            grid[row][col] = num;
            if (solve(grid, row, col + 1)) {
                return 1;
            }
            grid[row][col] = 0;
        }
    }

    // No number can be placed at current location
    return 0;
}

int main() {
    int grid[N][N] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 0, 0, 0, 2, 0},
        {9, 0, 0, 8, 0, 0, 0, 0, 5},
        {0, 5, 0, 0, 0, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 0, 7, 0},
        {0, 0, 0, 0, 4, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Solve the Sudoku grid
    if (solve(grid, 0, 0)) {
        // Print the solved grid if a solution is found
        printf("Solved Sudoku grid:\n");
        print_grid(grid);
    } else {
        // Solution not found
        printf("No solution exists!");
    }

    return 0;
}