//FormAI DATASET v1.0 Category: Sudoku solver ; Style: complete
#include <stdio.h>
#include <stdbool.h>

#define UNASSIGNED 0
#define N 9

bool find_unassigned_cell(int grid[N][N], int *row, int *col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (grid[*row][*col] == UNASSIGNED) {
                return true;
            }
        }
    }
    return false;
}

bool used_in_row(int grid[N][N], int row, int num) {
    for (int col = 0; col < N; col++) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool used_in_col(int grid[N][N], int col, int num) {
    for (int row = 0; row < N; row++) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool used_in_box(int grid[N][N], int box_start_row, int box_start_col, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row + box_start_row][col + box_start_col] == num) {
                return true;
            }
        }
    }
    return false;
}

bool is_safe(int grid[N][N], int row, int col, int num) {
    return !used_in_row(grid, row, num) &&
           !used_in_col(grid, col, num) &&
           !used_in_box(grid, row - row % 3, col - col % 3, num);
}

bool solve_sudoku(int grid[N][N]) {
    int row, col;
    if (!find_unassigned_cell(grid, &row, &col)) {
        return true;
    }
    for (int num = 1; num <= 9; num++) {
        if (is_safe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solve_sudoku(grid)) {
                return true;
            }
            grid[row][col] = UNASSIGNED;
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
    int sudoku[N][N] = {
        { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
        { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
        { 0, 0, 3, 0, 0, 0, 0, 2, 0 },
        { 9, 0, 0, 8, 0, 0, 0, 0, 5 },
        { 0, 5, 0, 0, 0, 0, 6, 0, 0 },
        { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
        { 0, 0, 5, 2, 0, 6, 3, 0, 0 }
    };
    if (solve_sudoku(sudoku)) {
        printf("Sudoku solved successfully using backtracking algorithm.\n");
        print_grid(sudoku);
    } else {
        printf("Sudoku can't be solved.\n");
    }
    return 0;
}