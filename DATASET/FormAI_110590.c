//FormAI DATASET v1.0 Category: Sudoku solver ; Style: realistic
#include <stdio.h>

#define BOARD_SIZE 9
#define EMPTY_CELL 0

void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int num) {
    // check row
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[row][i] == num) {
            return 0;
        }
    }
    // check col
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][col] == num) {
            return 0;
        }
    }
    // check box
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int solve_sudoku(int board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    if (row == BOARD_SIZE - 1 && col == BOARD_SIZE) {
        return 1;
    }
    if (col == BOARD_SIZE) {
        row++;
        col = 0;
    }
    if (board[row][col] != EMPTY_CELL) {
        return solve_sudoku(board, row, col + 1);
    }
    for (int num = 1; num <= 9; num++) {
        if (is_valid(board, row, col, num)) {
            board[row][col] = num;
            if (solve_sudoku(board, row, col + 1)) {
                return 1;
            }
            board[row][col] = EMPTY_CELL;
        }
    }
    return 0;
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {
        {0, 0, 0, 0, 7, 0, 6, 0, 2},
        {0, 2, 8, 3, 0, 0, 0, 5, 4},
        {4, 0, 0, 0, 5, 0, 0, 0, 0},
        {0, 6, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 8, 0, 5, 0, 0},
        {9, 0, 0, 0, 0, 2, 0, 6, 0},
        {3, 0, 6, 0, 0, 0, 8, 0, 0},
        {7, 4, 0, 0, 0, 3, 1, 9, 0},
        {0, 0, 5, 0, 2, 0, 0, 0, 0}
    };
    if (solve_sudoku(board, 0, 0)) {
        printf("Solved Sudoku Board:\n");
        print_board(board);
    } else {
        printf("No solution exists for the given sudoku board.\n");
    }
    return 0;
}