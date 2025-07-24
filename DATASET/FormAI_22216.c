//FormAI DATASET v1.0 Category: Sudoku solver ; Style: expert-level
#include <stdio.h>
#include <stdbool.h>

// Function to print the Sudoku grid
void printGrid(int grid[9][9]) {
    printf("+-------+-------+-------+\n");
    for (int i = 0; i < 9; i++) {
        printf("| ");
        for (int j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
            if ((j + 1) % 3 == 0) printf("| ");
        }
        printf("\n");
        if ((i + 1) % 3 == 0) printf("+-------+-------+-------+\n");
    }
}

// Function to check if a given digit can be placed in the given cell
bool isSafe(int grid[9][9], int row, int col, int num) {
    // Check if the number is already present in the row
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num) return false;
    }
    // Check if the number is already present in the column
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == num) return false;
    }
    // Check if the number is already present in the box
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    for (int i = boxRow; i < boxRow + 3; i++) {
        for (int j = boxCol; j < boxCol + 3; j++) {
            if (grid[i][j] == num) return false;
        }
    }
    // If all the checks pass, return true
    return true;
}

// Function to solve the Sudoku grid recursively
bool solveSudoku(int grid[9][9]) {
    int row, col;
    // Find the first empty cell in the grid (0 represents empty cells)
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (grid[row][col] == 0) goto found;
        }
    }
    // If there are no empty cells left, the grid is solved
    return true;
    found:
    // Try to fill the empty cell with numbers from 1 to 9
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            // Recursively solve the grid with the new cell filled
            if (solveSudoku(grid)) return true;
            // If the new cell leads to an unsolvable grid, backtrack
            grid[row][col] = 0;
        }
    }
    // If no number can be placed in the cell, the grid is unsolvable
    return false;
}

int main() {
    int grid[9][9] = {
        {0, 0, 0, 0, 0, 4, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 3, 1, 0},
        {0, 0, 0, 0, 7, 0, 0, 0, 8},
        {0, 7, 8, 5, 0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 4, 0},
        {5, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 6, 0, 7, 0, 0},
        {0, 3, 0, 0, 0, 0, 6, 0, 0}
    };
    printf("Sudoku grid:\n");
    printGrid(grid);
    if (solveSudoku(grid)) {
        printf("Solution:\n");
        printGrid(grid);
    } else {
        printf("No solution exists\n");
    }
    return 0;
}