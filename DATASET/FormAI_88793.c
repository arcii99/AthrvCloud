//FormAI DATASET v1.0 Category: Sudoku solver ; Style: minimalist
#include <stdio.h>
#include <stdbool.h>

#define N 9

bool is_valid(int grid[N][N], int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }

    int row_start = row - row % 3;
    int col_start = col - col % 3;

    for (int i = row_start; i < row_start + 3; i++) {
        for (int j = col_start; j < col_start + 3; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool find_unassigned_location(int grid[N][N], int* row, int* col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (grid[*row][*col] == 0) {
                return true;
            }
        }
    }

    return false;
}

bool solve_sudoku(int grid[N][N]) {
    int row, col;

    if (!find_unassigned_location(grid, &row, &col)) {
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (is_valid(grid, row, col, num)) {
            grid[row][col] = num;

            if (solve_sudoku(grid)) {
                return true;
            }

            grid[row][col] = 0;
        }
    }

    return false;
}

void print_grid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%d ", grid[row][col]);
        }

        printf("\n");
    }
}

int main() {
    int grid[N][N] = {{0, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 6, 0, 0, 0, 0, 3},
                      {0, 7, 4, 0, 8, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 3, 0, 0, 2},
                      {0, 8, 0, 0, 4, 0, 0, 1, 0},
                      {6, 0, 0, 5, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 1, 0, 7, 8, 0},
                      {5, 0, 0, 0, 0, 9, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 4, 0}};
    
    if (solve_sudoku(grid)) {
        print_grid(grid);
    } else {
        printf("No solution exists.");
    }

    return 0;
}