//FormAI DATASET v1.0 Category: Sudoku solver ; Style: accurate
#include <stdio.h>

// Function to check if a value can be placed in the given cell
int canPlace(int grid[9][9], int row, int col, int num) {
    // Check if the number already exists in the row, column or 3x3 box
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num || grid[i][col] == num || grid[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) {
            return 0;
        }
    }
    return 1;
}

// Function to solve the Sudoku grid using backtracking
int solveSudoku(int grid[9][9]) {
    int row, col;
    int found = 0;
    
    // Find an unassigned cell
    for (row = 0; row < 9 && !found; row++) {
        for (col = 0; col < 9 && !found; col++) {
            if (grid[row][col] == 0) {
                found = 1;
            }
        }
    }
    
    // If all cells are assigned, the puzzle is solved
    if (!found) {
        return 1;
    }
    
    // Try each number from 1 to 9
    for (int num = 1; num <= 9; num++) {
        if (canPlace(grid, row, col, num)) {
            grid[row][col] = num;
            // Recursively solve the remaining grid
            if (solveSudoku(grid)) {
                return 1;
            }
            // If the recursive call fails, backtrack
            grid[row][col] = 0;
        }
    }
    return 0;
}

// Function to print the Sudoku grid
void printGrid(int grid[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

int main() {
    // Example Sudoku grid
    int grid[9][9] = {{0, 0, 0, 2, 6, 0, 7, 0, 1},
                      {6, 8, 0, 0, 7, 0, 0, 9, 0},
                      {1, 9, 0, 0, 0, 4, 5, 0, 0},
                      {8, 2, 0, 1, 0, 0, 0, 4, 0},
                      {0, 0, 4, 6, 0, 2, 9, 0, 0},
                      {0, 5, 0, 0, 0, 3, 0, 2, 8},
                      {0, 0, 9, 3, 0, 0, 0, 7, 4},
                      {0, 4, 0, 0, 5, 0, 0, 3, 6},
                      {7, 0, 3, 0, 1, 8, 0, 0, 0}};

    // Solve the Sudoku grid
    if (solveSudoku(grid)) {
        printf("Solved Sudoku grid:\n");
        printGrid(grid);
    }
    else {
        printf("No solution found.\n");
    }
    return 0;
}