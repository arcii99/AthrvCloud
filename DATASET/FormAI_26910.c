//FormAI DATASET v1.0 Category: Sudoku solver ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>

#define ROWS 9
#define COLS 9

void print_grid(int grid[ROWS][COLS]) {
    // Function to print the Sudoku grid
    printf("The Sudoku grid is:\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int is_possible(int grid[ROWS][COLS], int row, int col, int num) {
    // Function to check if it is possible to place a number in the grid
    for(int i=0; i<ROWS; i++) {
        if(grid[row][i] == num) {
            return 0;
        }
        if(grid[i][col] == num) {
            return 0;
        }
    }
    int subrow = (row/3)*3;
    int subcol = (col/3)*3;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(grid[subrow+i][subcol+j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int solve_sudoku(int grid[ROWS][COLS]) {
    // Function to solve the Sudoku grid recursively
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(grid[i][j] == 0) {
                for(int num=1; num<=9; num++) {
                    if(is_possible(grid, i, j, num)) {
                        grid[i][j] = num;
                        if(solve_sudoku(grid)) {
                            return 1;
                        }
                        grid[i][j] = 0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    // Sample Sudoku grid
    int grid[ROWS][COLS] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 0, 0, 0, 2, 0},
        {9, 0, 0, 8, 0, 0, 0, 0, 5},
        {0, 5, 0, 0, 0, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    // Solving the Sudoku grid
    if (solve_sudoku(grid)) {
        print_grid(grid);
    } else {
        printf("No solution exists\n");
    }

    return 0;
}