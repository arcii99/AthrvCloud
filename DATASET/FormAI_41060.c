//FormAI DATASET v1.0 Category: Sudoku solver ; Style: all-encompassing
#include <stdio.h>

#define N 9

void print_board(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int is_in_row(int board[N][N], int row, int num) {
    for (int col = 0; col < N; col++) {
        if (board[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

int is_in_col(int board[N][N], int col, int num) {
    for (int row = 0; row < N; row++) {
        if (board[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

int is_in_box(int board[N][N], int start_row, int start_col, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row + start_row][col + start_col] == num) {
                return 1;
            }
        }
    }
    return 0;
}

int is_valid_move(int board[N][N], int row, int col, int num) {
    return !is_in_row(board, row, num) &&
           !is_in_col(board, col, num) &&
           !is_in_box(board, row - row % 3, col - col % 3, num);
}

int find_empty_cell(int board[N][N], int *row, int *col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (board[*row][*col] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

int solve_board(int board[N][N]) {
    int row, col;

    if (!find_empty_cell(board, &row, &col)) {
        return 1;
    }

    for (int num = 1; num <= 9; num++) {
        if (is_valid_move(board, row, col, num)) {
            board[row][col] = num;

            if (solve_board(board)) {
                return 1;
            }

            board[row][col] = 0;
        }
    }

    return 0;
}

int main() {
    int board[N][N] = {
        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0}
    };

    if (solve_board(board)) {
        printf("Solved Sudoku:\n");
        print_board(board);
        return 0;
    }

    printf("Sudoku could not be solved\n");

    return 0;
}