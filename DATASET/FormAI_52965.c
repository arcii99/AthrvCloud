//FormAI DATASET v1.0 Category: Sudoku solver ; Style: systematic
#include <stdio.h>

#define SIZE 9

int board[SIZE][SIZE] = {{0, 6, 0, 0, 0, 0, 0, 9, 3},
                         {0, 0, 0, 3, 0, 0, 7, 0, 8},
                         {0, 0, 0, 0, 0, 8, 0, 4, 0},
                         {0, 0, 8, 0, 0, 0, 0, 6, 0},
                         {0, 2, 0, 0, 0, 0, 0, 0, 0},
                         {7, 0, 0, 0, 1, 0, 0, 0, 9},
                         {0, 0, 0, 9, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 8, 1, 0, 0, 0},
                         {6, 0, 0, 0, 0, 0, 0, 0, 0}};

int is_valid(int row, int col, int num) {
    int i, j;
    // check row
    for (i = 0; i < SIZE; i++) {
        if (board[row][i] == num) {
            return 0;
        }
    }
    // check column
    for (i = 0; i < SIZE; i++) {
        if (board[i][col] == num) {
            return 0;
        }
    }
    // check subgrid
    int subgrid_row = row - row % 3;
    int subgrid_col = col - col % 3;
    for (i = subgrid_row; i < subgrid_row + 3; i++) {
        for (j = subgrid_col; j < subgrid_col + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int solve(int row, int col) {
    int num, i;
    if (row == SIZE) {
        return 1;
    }
    if (board[row][col] != 0) {
        if (col == SIZE - 1) {
            return solve(row + 1, 0);
        } else {
            return solve(row, col + 1);
        }
    }
    for (num = 1; num <= SIZE; num++) {
        if (is_valid(row, col, num)) {
            board[row][col] = num;
            if (col == SIZE - 1) {
                if (solve(row + 1, 0)) {
                    return 1;
                }
            } else {
                if (solve(row, col + 1)) {
                    return 1;
                }
            }
            board[row][col] = 0;
        }
    }
    return 0;
}

void print_board() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    if (solve(0, 0)) {
        printf("Solution:\n");
        print_board();
    } else {
        printf("No solution\n");
    }
    return 0;
}