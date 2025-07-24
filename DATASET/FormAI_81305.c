//FormAI DATASET v1.0 Category: Sudoku solver ; Style: beginner-friendly
#include <stdio.h>

// Constants
#define UNASSIGNED 0
#define N 9

// Function to print grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

// Function to check if the given value already exists in the row
int usedInRow(int grid[N][N], int row, int num) {
    for (int col = 0; col < N; col++) {
        if (grid[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the given value already exists in the column
int usedInCol(int grid[N][N], int col, int num) {
    for (int row = 0; row < N; row++) {
        if (grid[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the given value already exists in the box (3X3)
int usedInBox(int grid[N][N], int startRow, int startCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row+startRow][col+startCol] == num) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to check if the value can be placed in a cell
int isValid(int grid[N][N], int row, int col, int num) {
    return !usedInRow(grid, row, num) && !usedInCol(grid, col, num) && !usedInBox(grid, row - row % 3 , col - col % 3, num) && grid[row][col] == UNASSIGNED;
}

// Function to solve the Sudoku puzzle
int solveSudoku(int grid[N][N]) {
    int row, col;
    if (!findUnassignedLocation(grid, &row, &col)) {
        return 1;
    }

    for (int num = 1; num <= N; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid)) {
                return 1;
            }
            grid[row][col] = UNASSIGNED;
        }
    }
    return 0;
}

// Function to find the next unassigned location in the Sudoku puzzle
int findUnassignedLocation(int grid[N][N], int *row, int *col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (grid[*row][*col] == UNASSIGNED) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    // Puzzle to solve
    int grid[N][N] = { {0, 0, 0, 9, 0, 0, 5, 0, 0},
                       {4, 3, 0, 0, 0, 0, 7, 0, 0},
                       {0, 0, 8, 2, 0, 3, 0, 0, 0},
                       {6, 2, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 7, 3, 0, 0, 8, 0},
                       {1, 0, 3, 0, 0, 0, 0, 0, 0},
                       {3, 0, 0, 0, 0, 1, 6, 0, 2},
                       {0, 0, 0, 0, 0, 0, 0, 7, 5},
                       {0, 0, 0, 0, 0, 5, 1, 0, 0} };

    if (solveSudoku(grid)) {
        // Print the solved grid
        printGrid(grid);
    } else {
        printf("No solution exists!");
    }
    return 0;
}