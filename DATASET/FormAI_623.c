//FormAI DATASET v1.0 Category: Sudoku solver ; Style: mathematical
#include <stdio.h>

/*
A Sudoku puzzle is represented as a 9x9 array of integers. 
An unfilled cell is represented by a 0 value.
*/

#define N 9

void print_solution(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

int not_in_row(int grid[N][N], int row, int num) {
    for (int col = 0; col < N; col++) {
        if (grid[row][col] == num) {
            return 0;
        }
    }
    return 1;
}

int not_in_col(int grid[N][N], int col, int num) {
    for (int row = 0; row < N; row++) {
        if (grid[row][col] == num) {
            return 0;
        }
    }
    return 1;
}

int not_in_box(int grid[N][N], int box_start_row, int box_start_col, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row + box_start_row][col + box_start_col] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int is_safe(int grid[N][N], int row, int col, int num) {
    return not_in_row(grid, row, num) &&
           not_in_col(grid, col, num) &&
           not_in_box(grid, row - row % 3, col - col % 3, num);
}

int find_unassigned_location(int grid[N][N], int *row, int *col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (grid[*row][*col] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

int solve_sudoku(int grid[N][N]) {
    int row, col;
    if (!find_unassigned_location(grid, &row, &col)) {
        return 1;
    }
    for (int num = 1; num <= 9; num++) {
        if (is_safe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solve_sudoku(grid)) {
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 0, 0, 0, 2, 0},
                      {9, 0, 0, 8, 0, 0, 0, 0, 5},
                      {0, 5, 0, 0, 0, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    if (solve_sudoku(grid)) {
        printf("Solution:\n");
        print_solution(grid);
    }
    else {
        printf("No solution found.\n");
    }
    return 0;
}