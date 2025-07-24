//FormAI DATASET v1.0 Category: Sudoku solver ; Style: modular
#include <stdio.h>

#define N 9

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%2d ", grid[row][col]);
        }
        printf("\n");
    }
}

// Function to check if the current cell is safe or not
int isSafe(int grid[N][N], int row, int col, int num) {
    // Check if the number is already present in the same row
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num) {
            return 0;
        }
    }

    // Check if the number is already present in the same column
    for (int y = 0; y < N; y++) {
        if (grid[y][col] == num) {
            return 0;
        }
    }

    // Check if the number is already present in the same 3x3 subgrid
    int subgridRow = row - row % 3;
    int subgridCol = col - col % 3;
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (grid[subgridRow + x][subgridCol + y] == num) {
                return 0;
            }
        }
    }

    // If the number is not present in the same row, column, or subgrid, it is safe to place
    return 1;
}

// Function to solve the Sudoku puzzle
int solveSudoku(int grid[N][N], int row, int col) {
    // Check if we have reached the end of the grid
    if (row == N - 1 && col == N) {
        return 1;
    }

    // Check if we have reached the end of a row
    if (col == N) {
        row++;
        col = 0;
    }

    // Check if the current cell already has a value
    if (grid[row][col] != 0) {
        return solveSudoku(grid, row, col + 1);
    }

    // Try all possible values in the current cell
    for (int num = 1; num <= N; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1)) {
                return 1;
            }
            grid[row][col] = 0;
        }
    }

    // If none of the values work, backtrack
    return 0;
}

// Sample Sudoku puzzle
int main() {
    int grid[N][N] = {
        {0, 0, 0, 2, 6, 0, 7, 0, 1},
        {6, 8, 0, 0, 7, 0, 0, 9, 0},
        {1, 9, 0, 0, 0, 4, 5, 0, 0},
        {8, 2, 0, 1, 0, 0, 0, 4, 0},
        {0, 0, 4, 6, 0, 2, 9, 0, 0},
        {0, 5, 0, 0, 0, 3, 0, 2, 8},
        {0, 0, 9, 3, 0, 0, 0, 7, 4},
        {0, 4, 0, 0, 5, 0, 0, 3, 6},
        {7, 0, 3, 0, 1, 8, 0, 0, 0}
    };

    // Solve the Sudoku puzzle
    if (solveSudoku(grid, 0, 0)) {
        printf("Solution:\n");
        printGrid(grid);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}