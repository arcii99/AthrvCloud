//FormAI DATASET v1.0 Category: Sudoku solver ; Style: detailed
#include <stdio.h>
#include <stdbool.h>

#define N 9 // Sudoku grid size

// This function prints the solved Sudoku grid
void printGrid(int grid[N][N]) {
    printf("Solved Sudoku:\n");
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++)
            printf("%d ", grid[row][col]);
        printf("\n");
    }
}

// This function checks if the given number can be placed in the given cell or not
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Check if the given number exists in the same row
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num)
            return false;

    // Check if the given number exists in the same column
    for (int y = 0; y < N; y++)
        if (grid[y][col] == num)
            return false;

    // Check if the given number exists in the same 3x3 sub-grid
    int subRow = row - row % 3;
    int subCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[subRow + i][subCol + j] == num)
                return false;

    return true;
}

// This function finds the next empty cell (0 value)
bool findEmptyCell(int grid[N][N], int *row, int *col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (grid[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

// This function solves the Sudoku grid recursively
bool solveSudoku(int grid[N][N]) {
    int row, col;
    if (!findEmptyCell(grid, &row, &col)) {
        // No empty cells, Sudoku is solved
        return true;
    }

    // Try different numbers in the empty cell
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            // Place the number in the cell
            grid[row][col] = num;

            // Recursively solve the rest of the grid
            if (solveSudoku(grid)) {
                return true;
            }

            // Backtrack and try next possible number
            grid[row][col] = 0;
        }
    }

    // None of the possible numbers work, backtrack further
    return false;
}

int main() {
    int grid[N][N] = {
        {8, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 3, 6, 0, 0, 0, 0, 0},
        {0, 7, 0, 0, 9, 0, 2, 0, 0},
        {0, 5, 0, 0, 0, 7, 0, 0, 0},
        {0, 0, 0, 0, 4, 5, 7, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 3, 0},
        {0, 0, 1, 0, 0, 0, 0, 6, 8},
        {0, 0, 8, 5, 0, 0, 0, 1, 0},
        {0, 9, 0, 0, 0, 0, 4, 0, 0}
    };

    if (solveSudoku(grid)) {
        printGrid(grid);
    }
    else {
        printf("No solution exists.\n");
    }

    return 0;
}