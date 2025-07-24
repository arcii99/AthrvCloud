//FormAI DATASET v1.0 Category: Sudoku solver ; Style: multiplayer
#include <stdio.h>

#define N 9

// Function to check if a number is present in a row
int row_check(int grid[N][N], int row, int num) {
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a number is present in a column
int column_check(int grid[N][N], int column, int num) {
    for (int i = 0; i < N; i++) {
        if (grid[i][column] == num) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a number is present in a block
int block_check(int grid[N][N], int row, int column, int num) {
    int start_row = row - row % 3;
    int start_column = column - column % 3;
    for (int i = start_row; i < start_row + 3; i++) {
        for (int j = start_column; j < start_column + 3; j++) {
            if (grid[i][j] == num) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to check if it is safe to place a number in a position
int is_safe(int grid[N][N], int row, int column, int num) {
    if (!row_check(grid, row, num) && !column_check(grid, column, num) && !block_check(grid, row, column, num)) {
        return 1;
    }
    return 0;
}

// Function to print the Sudoku grid
void print_grid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to solve the Sudoku puzzle
int solve_sudoku(int grid[N][N], int row, int column) {
    if (row == N - 1 && column == N) {
        return 1;
    }
    if (column == N) {
        row++;
        column = 0;
    }
    if (grid[row][column] > 0) {
        return solve_sudoku(grid, row, column + 1);
    }
    for (int num = 1; num <= N; num++) {
        if (is_safe(grid, row, column, num)) {
            grid[row][column] = num;
            if (solve_sudoku(grid, row, column + 1)) {
                return 1;
            }
            grid[row][column] = 0;
        }
    }
    return 0;
}

int main() {
    int grid[N][N] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                      {6, 0, 0, 1, 9, 5, 0, 0, 0},
                      {0, 9, 8, 0, 0, 0, 0, 6, 0},
                      {8, 0, 0, 0, 6, 0, 0, 0, 3},
                      {4, 0, 0, 8, 0, 3, 0, 0, 1},
                      {7, 0, 0, 0, 2, 0, 0, 0, 6},
                      {0, 6, 0, 0, 0, 0, 2, 8, 0},
                      {0, 0, 0, 4, 1, 9, 0, 0, 5},
                      {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    int solved = solve_sudoku(grid, 0, 0);
    if (solved) {
        printf("Solved sudoku:\n");
        print_grid(grid);
    } else {
        printf("No solution found\n");
    }
    return 0;
}