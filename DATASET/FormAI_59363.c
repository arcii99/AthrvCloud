//FormAI DATASET v1.0 Category: Sudoku solver ; Style: peaceful
#include <stdio.h>
#include <stdbool.h>

// Function to print the Sudoku grid
void printGrid(int grid[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
}

// Function to check if the current cell can be assigned a value
bool isValid(int grid[9][9], int row, int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num)
            return false;
        if (grid[i][col] == num)
            return false;
        if (grid[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)
            return false;
    }
    return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(int grid[9][9]) {
    int row, col;

    // Check if there is any unassigned cell
    bool found = false;
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (grid[row][col] == 0) {
                found = true;
                break;
            }
        }
        if (found)
            break;
    }

    // If all cells are assigned, the puzzle is solved
    if (!found)
        return true;

    // Try assigning values from 1 to 9 to the current cell
    for (int num = 1; num <= 9; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;

            // Recursively solve the puzzle
            if (solveSudoku(grid))
                return true;

            // If the recursive call does not lead to a solution, undo the assignment
            grid[row][col] = 0;
        }
    }

    // If no value can be assigned to the current cell, backtrack
    return false;
}

int main() {
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
    if (solveSudoku(grid))
        printGrid(grid);
    else
        printf("No solution exists for the given Sudoku puzzle.");

    return 0;
}