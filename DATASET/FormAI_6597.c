//FormAI DATASET v1.0 Category: Sudoku solver ; Style: peaceful
#include <stdlib.h>
#include <stdio.h>

void print_board(int board[9][9]) {
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid(int board[9][9], int row, int col, int num) {
    int i, j;
    for (i = 0; i < 9; i++) {
        if (board[row][i] == num) return 0;
        if (board[i][col] == num) return 0;
    }
    int start_row = (row / 3) * 3;
    int start_col = (col / 3) * 3;
    for (i = start_row; i < start_row + 3; i++) {
        for (j = start_col; j < start_col + 3; j++) {
            if (board[i][j] == num) return 0;
        }
    }
    return 1;
}

int solve_board(int board[9][9]) {
    int row, col, num;
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                for (num = 1; num <= 9; num++) {
                    if (is_valid(board, row, col, num)) {
                        board[row][col] = num;
                        if (solve_board(board)) {
                            return 1;
                        } else {
                            board[row][col] = 0;
                        }
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int board[9][9] = {
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

    printf("Sudoku board before solving:\n");
    print_board(board);

    if (solve_board(board)) {
        printf("\nSudoku board after solving:\n");
        print_board(board);
    } else {
        printf("\nUnable to solve Sudoku board.\n");
    }

    return 0;
}