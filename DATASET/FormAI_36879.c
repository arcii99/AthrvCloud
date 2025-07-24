//FormAI DATASET v1.0 Category: Sudoku solver ; Style: expert-level
#include <stdio.h>
#include <stdbool.h>

bool is_valid(int grid[9][9], int row, int col, int num) {
    int i, j;
    for (i = 0; i < 9; i++) {
        if (grid[row][i] == num) return false;
        if (grid[i][col] == num) return false;
        if (grid[((row/3)*3)+(i/3)][((col/3)*3)+(i%3)] == num) return false;
    }
    return true;
}

bool solve_sudoku(int grid[9][9], int row, int col) {
    if (row == 9) return true;
    if (col == 9) return solve_sudoku(grid, row + 1, 0);
    if (grid[row][col] != 0) return solve_sudoku(grid, row, col + 1);

    int num;
    for (num = 1; num <= 9; num++) {
        if (is_valid(grid, row, col, num)) {
            grid[row][col] = num;
            if (solve_sudoku(grid, row, col + 1)) {
                return true;
            }
        }
    }
    grid[row][col] = 0;
    return false;
}

void print_grid(int grid[9][9]) {
    int row, col;
    printf("\n");
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

int main() {
    int grid[9][9] = {
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

    printf("Original Sudoku Puzzle:\n");
    print_grid(grid);

    if (solve_sudoku(grid, 0, 0)) {
        printf("\nSolved Sudoku Puzzle:\n");
        print_grid(grid);
    } else {
        printf("\nNo solution found for Sudoku Puzzle.");
    }

    return 0;
}