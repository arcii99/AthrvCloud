//FormAI DATASET v1.0 Category: Sudoku solver ; Style: invasive
#include <stdio.h>
#include <stdbool.h>

#define N 9 // Size of Sudoku grid

// Function to print the Sudoku grid
void print_grid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Helper function to check if a number is safe to be placed in a particular cell
bool is_safe(int grid[N][N], int x, int y, int num) {
    // Check row
    for (int i = 0; i < N; i++) {
        if (grid[x][i] == num) {
            return false;
        }
    }

    // Check column
    for (int i = 0; i < N; i++) {
        if (grid[i][y] == num) {
            return false;
        }
    }

    // Check 3x3 block
    int row_start = x - x % 3;
    int col_start = y - y % 3;

    for (int i = row_start; i < row_start + 3; i++) {
        for (int j = col_start; j < col_start + 3; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }

    // If no conflicts found, the number is safe to be placed
    return true;
}

// Main recursive function to solve the Sudoku grid
bool solve_sudoku(int grid[N][N]) {
    // Find the next empty cell (with value 0)
    int row = -1;
    int col = -1;
    bool is_complete = true;

    for (int i = 0; i < N && is_complete; i++) {
        for (int j = 0; j < N && is_complete; j++) {
            if (grid[i][j] == 0) {
                row = i;
                col = j;
                is_complete = false;
            }
        }
    }

    // If no empty cell left, puzzle is solved
    if (is_complete) {
        return true;
    }

    // Try to place a number (1-9) into the empty cell
    for (int num = 1; num <= 9; num++) {
        if (is_safe(grid, row, col, num)) {
            grid[row][col] = num;

            // Recursively try to solve the puzzle
            if (solve_sudoku(grid)) {
                return true;
            }

            // If placing the number leads to an invalid solution,
            // backtrack and try a different number
            grid[row][col] = 0;
        }
    }
    
    // If all numbers have been tried and none of them
    // lead to a valid solution, the puzzle is unsolvable
    return false;
}

// Example Sudoku grid
int grid[N][N] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9},
};

int main() {
    printf("Original Sudoku grid:\n");
    print_grid(grid);

    if (solve_sudoku(grid)) {
        printf("\nSudoku solved!\n");
        print_grid(grid);
    } else {
        printf("\nSudoku is unsolvable.\n");
    }

    return 0;
}