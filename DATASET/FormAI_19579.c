//FormAI DATASET v1.0 Category: Sudoku solver ; Style: high level of detail
#include <stdio.h>
#include <stdbool.h>

#define N 9

bool find_empty(int grid[][N], int *row, int *col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (grid[*row][*col] == 0)
                return true;
        }
    }
    return false;
}

bool is_valid(int grid[][N], int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num)
            return false;
    }
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[box_row + i][box_col + j] == num)
                return false;
        }
    }
    return true;
}

void print_grid(int grid[][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

bool solve_sudoku(int grid[][N]) {
    int row, col;
    if (!find_empty(grid, &row, &col))
        return true;
    for (int num = 1; num <= 9; num++) {
        if (is_valid(grid, row, col, num)) {
            grid[row][col] = num;
            if (solve_sudoku(grid))
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

int main() {
    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 0, 0, 0, 2, 0 },
                       { 9, 0, 0, 8, 0, 0, 0, 0, 5 },
                       { 0, 5, 0, 0, 0, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 0, 0, 4 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
    if (solve_sudoku(grid) == true)
        print_grid(grid);
    else
        printf("No solution exists");
    return 0;
}