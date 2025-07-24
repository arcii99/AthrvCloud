//FormAI DATASET v1.0 Category: Sudoku solver ; Style: decentralized
#include <stdio.h>

#define N 9

// Check if the number is valid in the given row
int valid_row(int grid[N][N], int row, int num) {
    for (int col = 0; col < N; col++) {
        if (grid[row][col] == num) {
            return 0;
        }
    }
    return 1;
}

// Check if the number is valid in the given column
int valid_col(int grid[N][N], int col, int num) {
    for (int row = 0; row < N; row++) {
        if (grid[row][col] == num) {
            return 0;
        }
    }
    return 1;
}

// Check if the number is valid in the given sub-grid
int valid_subgrid(int grid[N][N], int row, int col, int num) {
    int subgrid_row = (row / 3) * 3;
    int subgrid_col = (col / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[subgrid_row+i][subgrid_col+j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

// Check if the number is valid at the given position
int valid_num(int grid[N][N], int row, int col, int num) {
    return valid_row(grid, row, num) &&
           valid_col(grid, col, num) &&
           valid_subgrid(grid, row, col, num);
}

// Find the next empty cell in the grid
int find_empty_cell(int grid[N][N], int* row, int* col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (grid[*row][*col] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

// Solve the Sudoku puzzle using backtracking
int solve_sudoku(int grid[N][N]) {
    int row, col;
    // If there are no more empty cells, we're done
    if (!find_empty_cell(grid, &row, &col)) {
        return 1;
    }
    // Try every possible number at this cell until we find a valid one
    for (int num = 1; num <= 9; num++) {
        if (valid_num(grid, row, col, num)) {
            grid[row][col] = num;
            // Recursively solve the rest of the puzzle
            if (solve_sudoku(grid)) {
                return 1;
            }
            // If the recursion fails, backtrack
            grid[row][col] = 0;
        }
    }
    // If we've tried every possible number and none worked, the puzzle is unsolvable
    return 0;
}

int main() {
    int grid[N][N] = {{0, 9, 4, 3, 0, 0, 6, 0, 0},
                      {0, 1, 0, 0, 9, 5, 0, 0, 0},
                      {0, 0, 6, 0, 0, 0, 7, 4, 0},
                      {0, 0, 0, 1, 0, 3, 0, 8, 0},
                      {9, 4, 0, 0, 0, 0, 0, 1, 3},
                      {0, 2, 0, 8, 0, 9, 0, 0, 0},
                      {0, 3, 5, 0, 0, 0, 8, 0, 0},
                      {0, 0, 0, 6, 1, 0, 0, 9, 0},
                      {0, 0, 9, 0, 0, 8, 5, 7, 0}};
    if (solve_sudoku(grid)) {
        printf("Solved Sudoku puzzle:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Unsolvable Sudoku puzzle\n");
    }
    return 0;
}