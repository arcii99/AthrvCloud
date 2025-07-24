//FormAI DATASET v1.0 Category: Sudoku solver ; Style: multiplayer
#include <stdio.h>
#include <stdbool.h>

#define N 9

bool find_unassigned(int grid[N][N], int *row, int *col);
bool is_safe(int grid[N][N], int row, int col, int num);
bool solve_sudoku(int grid[N][N]);
void print_sudoku(int grid[N][N]);

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

    solve_sudoku(grid);

    print_sudoku(grid);

    return 0;
}

bool find_unassigned(int grid[N][N], int *row, int *col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (grid[*row][*col] == 0) {
                return true;
            }
        }
    }

    return false;
}

bool is_safe(int grid[N][N], int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }

    int row_start = (row / 3) * 3;
    int col_start = (col / 3) * 3;

    for (int i = row_start; i < row_start + 3; i++) {
        for (int j = col_start; j < col_start + 3; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solve_sudoku(int grid[N][N]) {
    int row, col;
    if (!find_unassigned(grid, &row, &col)) {
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (is_safe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solve_sudoku(grid)) {
                return true;
            }
            grid[row][col] = 0;
        }
    }

    return false;
}

void print_sudoku(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}