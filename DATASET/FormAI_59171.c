//FormAI DATASET v1.0 Category: Sudoku solver ; Style: standalone
#include <stdio.h>

// Function to print the Sudoku grid
void print(int grid[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the current cell is safe to fill in with the given number
int isSafe(int grid[9][9], int row, int col, int num) {
    // Check the row
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num) {
            return 0;
        }
    }
    // Check the column
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == num) {
            return 0;
        }
    }
    // Check the box
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    for (int i = boxRow; i < boxRow + 3; i++) {
        for (int j = boxCol; j < boxCol + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

// Recursive function to solve the Sudoku puzzle
int solve(int grid[9][9], int row, int col) {
    // Base case - the puzzle is solved
    if (row == 9) {
        return 1;
    }
    // If the current cell is not empty, move on to the next cell
    if (grid[row][col] != 0) {
        if (col == 8) {
            return solve(grid, row+1, 0);
        } else {
            return solve(grid, row, col+1);
        }
    }
    // Try to fill the current cell with numbers 1 to 9
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (col == 8) {
                if (solve(grid, row+1, 0)) {
                    return 1;
                }
            } else {
                if (solve(grid, row, col+1)) {
                    return 1;
                }
            }
        }
    }
    // Backtrack and try again with a different number
    grid[row][col] = 0;
    return 0;
}

// Main function
int main() {
    int grid[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    printf("Enter the Sudoku puzzle (use 0 for empty cells):\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    if (solve(grid, 0, 0)) {
        printf("Sudoku solved!\n");
        print(grid);
    } else {
        printf("Cannot solve Sudoku...\n");
    }
    return 0;
}