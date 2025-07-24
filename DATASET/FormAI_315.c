//FormAI DATASET v1.0 Category: Sudoku solver ; Style: curious
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

void print_grid(int grid[][SIZE]) {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

bool is_safe(int grid[][SIZE], int row, int col, int num) {
    // check row and column
    for(int i=0; i<SIZE; i++) {
        if(grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }
    // check sub-grid
    int start_row = row - row%3;
    int start_col = col - col%3;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(grid[start_row+i][start_col+j] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solve_sudoku(int grid[][SIZE], int row, int col) {
    if(row == SIZE) {
        return true; // solution found
    }
    if(col == SIZE) {
        return solve_sudoku(grid, row+1, 0); // move to next row
    }
    if(grid[row][col] != 0) {
        return solve_sudoku(grid, row, col+1); // skip filled cells
    }
    for(int num=1; num<=9; num++) {
        if(is_safe(grid, row, col, num)) {
            grid[row][col] = num;
            if(solve_sudoku(grid, row, col+1)) {
                return true; // solution found
            }
            grid[row][col] = 0; // backtrack
        }
    }
    return false; // no solution found
}

int main() {
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
    printf("Initial grid:\n");
    print_grid(grid);
    if(solve_sudoku(grid, 0, 0)) {
        printf("Solution found:\n");
        print_grid(grid);
    } else {
        printf("No solution found\n");
    }
    return 0;
}