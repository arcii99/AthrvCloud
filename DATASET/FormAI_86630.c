//FormAI DATASET v1.0 Category: Sudoku solver ; Style: thoughtful
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

// Function to print the Sudoku grid
void printGrid(int grid[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a number can be placed in a certain position
bool canPlace(int grid[SIZE][SIZE], int row, int col, int num) {
    int i, j;
    // Check row and column for the number
    for (i = 0; i < SIZE; i++) {
        if (grid[row][i] == num || grid[i][col] == num)
            return false;
    }
    // Check the 3x3 square for the number
    int startRow = row - row % 3, startCol = col - col % 3;
    for (i = startRow; i < startRow + 3; i++) {
        for (j = startCol; j < startCol + 3; j++) {
            if (grid[i][j] == num)
                return false;
        }
    }
    // If the number is not found in the row, column or 3x3 square
    return true;
}

// Function to solve the Sudoku grid
bool solveSudoku(int grid[SIZE][SIZE]) {
    int row, col, num;
    // Find the first empty cell in the grid
    bool found = false;
    for (row = 0; row < SIZE && !found; row++) {
        for (col = 0; col < SIZE && !found; col++) {
            if (grid[row][col] == 0) {
                found = true;
            }
        }
    }
    // If no empty cell is found, the grid is solved
    if (!found) {
        return true;
    }
    // Try each number from 1 to 9 in the empty cell
    for (num = 1; num <= 9; num++) {
        // If the number can be placed in the empty cell
        if (canPlace(grid, row, col, num)) {
            // Place the number in the empty cell
            grid[row][col] = num;
            // Recursively solve the updated grid
            if (solveSudoku(grid))
                return true;
            // If the updated grid cannot be solved, reset the cell
            grid[row][col] = 0;
        }
    }
    // If no number can be placed in the empty cell
    return false;
}

int main() {
    int grid[SIZE][SIZE] = {
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
    if (solveSudoku(grid)) {
        printf("Sudoku grid:\n");
        printGrid(grid);
    }
    else {
        printf("No solution found!\n");
    }
    return 0;
}