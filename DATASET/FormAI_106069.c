//FormAI DATASET v1.0 Category: Sudoku solver ; Style: standalone
#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 9

int board[BOARD_SIZE][BOARD_SIZE] = {
    {8, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 3, 6, 0, 0, 0, 0, 0},
    {0, 7, 0, 0, 9, 0, 2, 0, 0},
    {0, 5, 0, 0, 0, 7, 0, 0, 0},
    {0, 0, 0, 0, 4, 5, 7, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 3, 0},
    {0, 0, 1, 0, 0, 0, 0, 6, 8},
    {0, 0, 8, 5, 0, 0, 0, 1, 0},
    {0, 9, 0, 0, 0, 0, 4, 0, 0}
};

void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    printf("-------------------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("| ");
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
            if ((j + 1) % 3 == 0) {
                printf("| ");
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0) {
            printf("-------------------------\n");
        }
    }
}

bool is_valid_move(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int num) {
    // Check row and column
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }
    // Check 3x3 box
    int box_row = (row / 3) * 3;
    int box_col = (col / 3) * 3;
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solve_sudoku(int board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    if (row == BOARD_SIZE) {
        return true;
    }
    if (col == BOARD_SIZE) {
        return solve_sudoku(board, row + 1, 0);
    }
    if (board[row][col] != 0) {
        return solve_sudoku(board, row, col + 1);
    }
    for (int num = 1; num <= 9; num++) {
        if (is_valid_move(board, row, col, num)) {
            board[row][col] = num;
            if (solve_sudoku(board, row, col + 1)) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

int main() {
    printf("Before solving:\n");
    print_board(board);

    if (solve_sudoku(board, 0, 0)) {
        printf("\nAfter solving:\n");
        print_board(board);
    } else {
        printf("No solution found.");
    }

    return 0;
}