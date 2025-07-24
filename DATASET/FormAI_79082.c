//FormAI DATASET v1.0 Category: Sudoku solver ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 9
#define NUM_COLS 9

void print_board(int board[NUM_ROWS][NUM_COLS]) {
    printf("\n");
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int row_contains(int board[NUM_ROWS][NUM_COLS], int row, int num) {
    for (int i = 0; i < NUM_COLS; i++) {
        if (board[row][i] == num) {
            return 1;
        }
    }
    return 0;
}

int col_contains(int board[NUM_ROWS][NUM_COLS], int col, int num) {
    for (int i = 0; i < NUM_ROWS; i++) {
        if (board[i][col] == num) {
            return 1;
        }
    }
    return 0;
}

int box_contains(int board[NUM_ROWS][NUM_COLS], int box_start_row, int box_start_col, int num) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[box_start_row + i][box_start_col + j] == num) {
                return 1;
            }
        }
    }
    return 0;
}

int is_valid(int board[NUM_ROWS][NUM_COLS], int row, int col, int num) {
    return !row_contains(board, row, num)
           && !col_contains(board, col, num)
           && !box_contains(board, row - row % 3, col - col % 3, num);
}

int find_empty(int board[NUM_ROWS][NUM_COLS], int *row, int *col) {
    for (*row = 0; *row < NUM_ROWS; (*row)++) {
        for (*col = 0; *col < NUM_COLS; (*col)++) {
            if (board[*row][*col] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

int solve_board(int board[NUM_ROWS][NUM_COLS]) {
    int row, col;
    if (!find_empty(board, &row, &col)) {
        return 1;
    }
    for (int num = 1; num <= 9; num++) {
        if (is_valid(board, row, col, num)) {
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
    int board[NUM_ROWS][NUM_COLS] = {
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
    solve_board(board);
    print_board(board);
    return 0;
}