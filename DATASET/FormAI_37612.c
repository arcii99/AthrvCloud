//FormAI DATASET v1.0 Category: Sudoku solver ; Style: safe
#include <stdio.h>
#include <stdbool.h>

// define global variables 
#define N 9
int sudoku[N][N] = {
    {6, 5, 0, 0, 0, 0, 8, 0, 0},
    {0, 0, 0, 0, 8, 0, 0, 0, 0},
    {0, 0, 0, 7, 0, 0, 0, 0, 6},
    {3, 0, 5, 0, 6, 0, 0, 0, 0},
    {0, 4, 0, 0, 0, 5, 0, 0, 0},
    {0, 0, 6, 0, 0, 0, 9, 0, 0},
    {4, 0, 0, 0, 5, 0, 0, 0, 2},
    {0, 9, 0, 8, 0, 0, 0, 7, 0},
    {0, 0, 0, 0, 0, 0, 0, 5, 0}
};

// print the sudoku board
void print_sudoku() {
    printf("\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

// find next empty cell in the sudoku board
bool find_empty_cell(int* row, int* col) {
    for(*row=0; *row<N; (*row)++) {
        for(*col=0; *col<N; (*col)++) {
            if(sudoku[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

// check if a number is valid for a given row
bool is_valid_row(int row, int num) {
    for(int col=0; col<N; col++) {
        if(sudoku[row][col] == num) {
            return false;
        }
    }
    return true;
}

// check if a number is valid for a given column
bool is_valid_col(int col, int num) {
    for(int row=0; row<N; row++) {
        if(sudoku[row][col] == num) {
            return false;
        }
    }
    return true;
}

// check if a number is valid for a given 3x3 box
bool is_valid_box(int box_start_row, int box_start_col, int num) {
    for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            if(sudoku[row+box_start_row][col+box_start_col] == num) {
                return false;
            }
        }
    }
    return true;
}

// check if a number is valid for a given position
bool is_valid_num(int row, int col, int num) {
    return is_valid_row(row, num) && is_valid_col(col, num) && is_valid_box(row-row%3, col-col%3, num);
}

// solve sudoku recursively using backtracking algorithm
bool solve_sudoku() {
    int row, col;
    if(!find_empty_cell(&row, &col)) {
        return true;
    }
    for(int num=1; num<=9; num++) {
        if(is_valid_num(row, col, num)) {
            sudoku[row][col] = num;
            if(solve_sudoku()) {
                return true;
            }
            sudoku[row][col] = 0;
        }
    }
    return false;
}

// main function to run the program
int main() {
    printf("Initial Sudoku Board:\n");
    print_sudoku();
    if(solve_sudoku()) {
        printf("\nSudoku Solved!\n");
        print_sudoku();
    } else {
        printf("\nCould not solve Sudoku!\n");
    }
    return 0;
}