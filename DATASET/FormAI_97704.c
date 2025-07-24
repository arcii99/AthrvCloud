//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Claude Shannon
#include <stdio.h>

#define N 9

int sudoku[N][N] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                    {6, 0, 0, 1, 9, 5, 0, 0, 0},
                    {0, 9, 8, 0, 0, 0, 0, 6, 0},
                    {8, 0, 0, 0, 6, 0, 0, 0, 3},
                    {4, 0, 0, 8, 0, 3, 0, 0, 1},
                    {7, 0, 0, 0, 2, 0, 0, 0, 6},
                    {0, 6, 0, 0, 0, 0, 2, 8, 0},
                    {0, 0, 0, 4, 1, 9, 0, 0, 5},
                    {0, 0, 0, 0, 8, 0, 0, 7, 9}};

// function to print the Sudoku grid
void print_sudoku() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

// check if the given number is valid in the given row
int check_row(int row, int num) {
    for (int i = 0; i < N; i++) {
        if (sudoku[row][i] == num) {
            return 0;
        }
    }
    return 1;
}

// check if the given number is valid in the given column
int check_col(int col, int num) {
    for (int i = 0; i < N; i++) {
        if (sudoku[i][col] == num) {
            return 0;
        }
    }
    return 1;
}

// check if the given number is valid in the given 3x3 box
int check_box(int row, int col, int num) {
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (sudoku[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

// check if the given number is valid at the given position
int is_valid(int row, int col, int num) {
    return check_row(row, num) && check_col(col, num) && check_box(row, col, num);
}

// find the next empty cell in the Sudoku grid
int find_empty_cell(int *row, int *col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (sudoku[*row][*col] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

// solve the Sudoku grid using backtracking
int solve_sudoku() {
    int row, col;
    if (!find_empty_cell(&row, &col)) { // if all cells are filled
        return 1;
    }
    for (int num = 1; num <= 9; num++) { // try numbers 1-9
        if (is_valid(row, col, num)) {
            sudoku[row][col] = num;
            if (solve_sudoku()) {
                return 1; // if solution found, return true
            }
            sudoku[row][col] = 0; // backtrack
        }
    }
    return 0; // if no solution found, return false
}

int main() {
    printf("\nSudoku grid before solving:\n");
    print_sudoku();
    printf("\nSudoku grid after solving:\n");
    if (solve_sudoku()) {
        print_sudoku();
    } else {
        printf("No solution found.\n");
    }
    return 0;
}