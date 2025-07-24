//FormAI DATASET v1.0 Category: Sudoku solver ; Style: mathematical
#include <stdio.h>

// Function to print the Sudoku grid
void printGrid(int grid[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

// Helper function to check if a digit is already present in the current row
int usedInRow(int grid[9][9], int row, int num) {
    for (int col = 0; col < 9; col++) {
        if (grid[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

// Helper function to check if a digit is already present in the current column
int usedInCol(int grid[9][9], int col, int num) {
    for (int row = 0; row < 9; row++) {
        if (grid[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

// Helper function to check if a digit is already present in the current 3x3 box
int usedInBox(int grid[9][9], int boxStartRow, int boxStartCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row + boxStartRow][col + boxStartCol] == num) {
                return 1;
            }
        }
    }
    return 0;
}

// Helper function to check if it's safe to place a digit at a given location
int isSafe(int grid[9][9], int row, int col, int num) {
    return !usedInRow(grid, row, num) &&
           !usedInCol(grid, col, num) &&
           !usedInBox(grid, row - row % 3, col - col % 3, num);
}

// Recursive function to solve the Sudoku grid
int solveSudoku(int grid[9][9]) {
    int row, col;

    // Check if there are any empty cells left in the grid
    if (!findEmptyCell(grid, &row, &col)) {
        return 1;   // Success: No empty cells left
    }

    // Try each digit from 1 to 9 in the current empty cell
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            // Recurse to attempt to solve the modified grid
            if (solveSudoku(grid)) {
                return 1;
            }

            // If solution not found, backtrack and try next digit
            grid[row][col] = 0;
        }
    }

    return 0;   // Failure: No solutions found for the current grid
}

// Helper function to find the next empty cell in the grid
int findEmptyCell(int grid[9][9], int *row, int *col) {
    for (*row = 0; *row < 9; (*row)++) {
        for (*col = 0; *col < 9; (*col)++) {
            if (grid[*row][*col] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int grid[9][9] = {
        {0, 3, 0, 0, 9, 7, 2, 0, 0},
        {0, 0, 0, 4, 0, 0, 0, 0, 9},
        {2, 0, 6, 0, 0, 0, 0, 4, 7},
        {9, 0, 5, 0, 0, 0, 0, 2, 4},
        {0, 0, 0, 6, 5, 9, 0, 0, 0},
        {8, 4, 0, 0, 0, 0, 3, 0, 5},
        {7, 2, 0, 0, 0, 0, 4, 0, 8},
        {6, 0, 0, 0, 0, 4, 0, 0, 0},
        {0, 0, 4, 7, 3, 0, 0, 6, 0}
    };

    printf("Sudoku grid before solving:\n");
    printGrid(grid);

    if (solveSudoku(grid)) {
        printf("\nSudoku grid after solving:\n");
        printGrid(grid);
    } else {
        printf("\nNo solution found for the given Sudoku grid.\n");
    }

    return 0;
}