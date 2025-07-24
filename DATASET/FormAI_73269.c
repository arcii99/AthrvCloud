//FormAI DATASET v1.0 Category: Sudoku solver ; Style: satisfied
#include <stdio.h>

// Define the grid size and number of boxes per row/column
#define N 9
#define BOX_SIZE 3

// Find the next empty cell in the grid
int findEmptyCell(int grid[N][N], int *row, int *col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (grid[*row][*col] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

// Check if a number is already used in a specific row
int usedInRow(int grid[N][N], int row, int num) {
    for (int col = 0; col < N; col++) {
        if (grid[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

// Check if a number is already used in a specific column
int usedInCol(int grid[N][N], int col, int num) {
    for (int row = 0; row < N; row++) {
        if (grid[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

// Check if a number is already used in a specific box
int usedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num) {
    for (int row = 0; row < BOX_SIZE; row++) {
        for (int col = 0; col < BOX_SIZE; col++) {
            if (grid[row + boxStartRow][col + boxStartCol] == num) {
                return 1;
            }
        }
    }
    return 0;
}

// Check if a number can be placed in a specific cell
int isSafe(int grid[N][N], int row, int col, int num) {
    return !usedInRow(grid, row, num) &&
           !usedInCol(grid, col, num) &&
           !usedInBox(grid, row - row % BOX_SIZE, col - col % BOX_SIZE, num);
}

// Solve the Sudoku puzzle using a recursive backtracking algorithm
int solveSudoku(int grid[N][N]) {
    int row, col;
    if (!findEmptyCell(grid, &row, &col)) {
        return 1; // If all cells are filled, the Sudoku puzzle is solved
    }
    for (int num = 1; num <= N; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid)) {
                return 1; // If the puzzle is solved, return 1
            }
            grid[row][col] = 0; // Undo the cell if the solution is not valid
        }
    }
    return 0; // If no solution is found, return 0
}

// Print the grid with a nice formatting
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%2d ", grid[row][col]);
            if (col == 2 || col == 5) {
                printf(" "); // Add extra spacing between boxes
            }
        }
        printf("\n");
        if (row == 2 || row == 5) {
            printf("\n"); // Add extra spacing between boxes
        }
    }
}

int main() {
    // Define the sudoku puzzle to be solved
    int grid[N][N] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 0, 0, 0, 2, 0},
        {9, 0, 0, 8, 0, 0, 0, 0, 5},
        {0, 5, 0, 0, 0, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };
    printf("Original puzzle:\n");
    printGrid(grid);

    // Solve the puzzle and print the resulting grid
    if (solveSudoku(grid)) {
        printf("\nSolution found:\n");
        printGrid(grid);
    } else {
        printf("\nNo solution found.\n");
    }

    return 0;
}