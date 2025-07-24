//FormAI DATASET v1.0 Category: Sudoku solver ; Style: secure
#include <stdio.h>
#include <stdbool.h>

#define N 9

bool is_valid(int puzzle[N][N], int row, int col, int num) {
    // check if num is present in row
    for (int i = 0; i < N; i++) {
        if (puzzle[row][i] == num) {
            return false;
        }
    }
    // check if num is present in col
    for (int i = 0; i < N; i++) {
        if (puzzle[i][col] == num) {
            return false;
        }
    }
    // check if num is present in box
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (puzzle[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

bool find_empty(int puzzle[N][N], int *row, int *col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (puzzle[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool solve_puzzle(int puzzle[N][N]) {
    int row, col;
    if (!find_empty(puzzle, &row, &col)) {
        return true;
    }
    for (int num = 1; num <= 9; num++) {
        if (is_valid(puzzle, row, col, num)) {
            puzzle[row][col] = num;
            if (solve_puzzle(puzzle)) {
                return true;
            }
            puzzle[row][col] = 0;
        }
    }
    return false;
}

void print_puzzle(int puzzle[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%d ", puzzle[row][col]);
        }
        printf("\n");
    }
}

int main() {
    int puzzle[N][N] = {
        { 0, 0, 0, 0, 0, 0, 0, 9, 0 },
        { 0, 8, 5, 0, 0, 2, 0, 0, 3 },
        { 0, 6, 0, 0, 9, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 8, 0, 0, 2, 0 },
        { 9, 0, 0, 0, 3, 0, 0, 4, 0 },
        { 2, 1, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 8, 0 },
        { 0, 0, 9, 6, 0, 0, 0, 0, 0 },
        { 3, 0, 0, 0, 0, 5, 0, 0, 0 }
    };

    if (solve_puzzle(puzzle)) {
        printf("Sudoku puzzle solved:\n");
        print_puzzle(puzzle);
    } else {
        printf("Unable to solve sudoku puzzle\n");
    }
    return 0;
}