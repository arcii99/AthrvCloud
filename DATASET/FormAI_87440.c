//FormAI DATASET v1.0 Category: Sudoku solver ; Style: medieval
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

int grid[SIZE][SIZE] = {
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

bool is_valid(int row, int col, int num) {
    for (int i = 0; i < SIZE; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }
    int sub_row = (row / 3) * 3;
    int sub_col = (col / 3) * 3;
    for (int i = sub_row; i < sub_row + 3; i++) {
        for (int j = sub_col; j < sub_col + 3; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solve_sudoku(int row, int col) {
    if (row == SIZE) {
        return true;
    }
    int next_row = row, next_col = col + 1;
    if (next_col == SIZE) {
        next_row += 1;
        next_col = 0;
    }
    if (grid[row][col]) {
        return solve_sudoku(next_row, next_col);
    }
    for (int num = 1; num <= SIZE; num++) {
        if (is_valid(row, col, num)) {
            grid[row][col] = num;
            if (solve_sudoku(next_row, next_col)) {
                return true;
            }
        }
    }
    grid[row][col] = 0;
    return false;
}

void print_grid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    if (solve_sudoku(0, 0)) {
        printf("Solution:\n");
        print_grid();
    } else {
        printf("No solution found.\n");
    }
    return 0;
}