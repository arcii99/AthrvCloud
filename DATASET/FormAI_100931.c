//FormAI DATASET v1.0 Category: Sudoku solver ; Style: peaceful
#include <stdio.h>

#define N 9 // Sudoku grid size
#define UNASSIGNED 0 // Constant for unassigned cells

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
}

// Function to check if a value can be placed in a cell
int isSafe(int grid[N][N], int row, int col, int num) {
    // Check row and column for conflicts
    for (int i = 0; i < N; i++)
        if (grid[row][i] == num || grid[i][col] == num)
            return 0;
    // Check 3x3 subgrid for conflicts
    int subRow = row - row % 3;
    int subCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + subRow][j + subCol] == num)
                return 0;
    // Return 1 if no conflicts found
    return 1;
}

// Function to find an unassigned cell
int findUnassigned(int grid[N][N], int *row, int *col) {
    for (*row = 0; *row < N; (*row)++)
        for (*col = 0; *col < N; (*col)++)
            if (grid[*row][*col] == UNASSIGNED)
                return 1;
    return 0;
}

// Function to solve the Sudoku puzzle
int solveSudoku(int grid[N][N]) {
    int row, col;
    // Find an unassigned cell
    if (!findUnassigned(grid, &row, &col))
        return 1; // Puzzle solved
    // Try each number from 1 to 9 in the current cell
    for (int num = 1; num <= 9; num++) {
        // Check if the number is safe to place
        if (isSafe(grid, row, col, num)) {
            // Place the number in the current cell
            grid[row][col] = num;
            // Recursively solve the remaining cells
            if (solveSudoku(grid))
                return 1; // Puzzle solved
            // Remove the number from the current cell and try the next number
            grid[row][col] = UNASSIGNED;
        }
    }
    return 0; // No solution found
}

int main() {
    int grid[N][N] = { {3, 0, 6, 5, 0, 8, 4, 0, 0},
                       {5, 2, 0, 0, 0, 0, 0, 0, 0},
                       {0, 8, 7, 0, 0, 0, 0, 3, 1},
                       {0, 0, 3, 0, 0, 0, 0, 2, 0},
                       {9, 0, 0, 8, 0, 0, 0, 0, 5},
                       {0, 5, 0, 0, 0, 0, 6, 0, 0},
                       {1, 3, 0, 0, 0, 0, 2, 5, 0},
                       {0, 0, 0, 0, 0, 0, 0, 7, 4},
                       {0, 0, 5, 2, 0, 6, 3, 0, 0} };
    printf("Before:\n");
    printGrid(grid);
    if (solveSudoku(grid) == 1) {
        printf("\nAfter:\n");
        printGrid(grid);
    } else {
        printf("No solution exists\n");
    }
    return 0;
}