//FormAI DATASET v1.0 Category: Sudoku solver ; Style: recursive
#include <stdio.h>

/* Size of the Sudoku */
#define SIZE 9

/* Check if value can be placed in the given row */
int check_row(int grid[][SIZE], int row, int value) {
    int col;
    for(col=0; col<SIZE; col++) {
        if(grid[row][col] == value) {
            return 0;
        }
    }
    return 1;
}

/* Check if value can be placed in the given column */
int check_col(int grid[][SIZE], int col, int value) {
    int row;
    for(row=0; row<SIZE; row++) {
        if(grid[row][col] == value) {
            return 0;
        }
    }
    return 1;
}

/* Check if value can be placed in the given square */
int check_square(int grid[][SIZE], int row, int col, int value) {
    int square_row = (row/3)*3;
    int square_col = (col/3)*3;
    int i, j;
    for(i=square_row; i<square_row+3; i++) {
        for(j=square_col; j<square_col+3; j++) {
            if(grid[i][j] == value) {
                return 0;
            }
        }
    }
    return 1;
}

/* Check if value can be placed in the given cell */
int is_valid(int grid[][SIZE], int row, int col, int value) {
    return check_row(grid, row, value) &&
           check_col(grid, col, value) &&
           check_square(grid, row, col, value);
}

/* Find the next empty cell */
int find_empty(int grid[][SIZE], int *row, int *col) {
    for(*row=0; *row<SIZE; (*row)++) {
        for(*col=0; *col<SIZE; (*col)++) {
            if(grid[*row][*col] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

/* Solve the Sudoku */
int solve_sudoku(int grid[][SIZE]) {
    int row, col, value;
    if(find_empty(grid, &row, &col) == 0) {
        return 1;
    }
    for(value=1; value<=SIZE; value++) {
        if(is_valid(grid, row, col, value)) {
            grid[row][col] = value;
            if(solve_sudoku(grid)) {
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    return 0;
}

/* Print the Sudoku */
void print_sudoku(int grid[][SIZE]) {
    int row, col;
    for(row=0; row<SIZE; row++) {
        for(col=0; col<SIZE; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

/* Test the Sudoku solver */
int main() {
    int grid[SIZE][SIZE] = {
            {0, 0, 0, 0, 0, 5, 0, 8, 0},
            {0, 0, 0, 0, 0, 1, 0, 0, 0},
            {0, 0, 7, 0, 0, 0, 4, 0, 0},
            {0, 0, 0, 0, 7, 0, 0, 0, 5},
            {0, 2, 4, 0, 0, 0, 0, 9, 0},
            {8, 0, 0, 0, 0, 0, 0, 3, 0},
            {0, 0, 0, 7, 0, 0, 0, 0, 0},
            {6, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 5, 0, 0, 0, 6, 0, 0, 8}
    };
    if(solve_sudoku(grid)) {
        printf("Solution:\n");
        print_sudoku(grid);
    }
    else {
        printf("No solution found!\n");
    }
    return 0;
}