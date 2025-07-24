//FormAI DATASET v1.0 Category: Sudoku solver ; Style: detailed
#include <stdio.h>

#define N 9      // Sudoku size: a 9x9 grid
#define UNASSIGNED 0     // Indicates that a cell is unassigned

int grid[N][N];        // The Sudoku grid

// Returns whether or not it is safe to place a value in the specified row, column, and sub-grid
int isSafe(int row, int col, int val) {
    // Check if value is already used in the row
    for (int j = 0; j < N; j++) {
        if (grid[row][j] == val) {
            return 0;
        }
    }

    // Check if value is already used in the column
    for (int i = 0; i < N; i++) {
        if (grid[i][col] == val) {
            return 0;
        }
    }

    // Check if value is already used in the sub-grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[startRow+i][startCol+j] == val) {
                return 0;
            }
        }
    }

    // If value is not already used in row, column, or sub-grid, then it is safe to use
    return 1;
}

// Recursive function to solve the Sudoku puzzle
int solve() {
    int row, col;

    // Check if all cells have been assigned a value
    if (!findUnassigned(&row, &col)) {
        return 1;
    }

    // Try each value from 1 to 9
    for (int val = 1; val <= 9; val++) {
        if (isSafe(row, col, val)) {
            // Try assigning the value to the current cell
            grid[row][col] = val;

            // Recursively solve the rest of the puzzle
            if (solve()) {
                return 1;
            }

            // If assigning the value did not lead to a solution, undo the assignment
            grid[row][col] = UNASSIGNED;
        }
    }

    return 0;
}

// Searches the grid for an unassigned cell
// Returns 1 and sets row and col if found, 0 otherwise
int findUnassigned(int *row, int *col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (grid[*row][*col] == UNASSIGNED) {
                return 1;
            }
        }
    }
    return 0;
}

// Prints the Sudoku grid
void printGrid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Example Sudoku grid (0 means unassigned cell)
    int grid[N][N] = {
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

    // Copy the example grid to the global grid variable
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = grid[i][j];
        }
    }

    // Solve the Sudoku puzzle
    if (solve()) {
        printf("Solution:\n");
        printGrid();
    }
    else {
        printf("No solution exists.");
    }

    return 0;
}