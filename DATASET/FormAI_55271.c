//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Donald Knuth
#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 9

/* Utility function to print board */
void print_board(int board[][BOARD_SIZE]) {
    printf("---------------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("---------------------\n");
}

/* Utility function to check if it is safe to put a number in the given spot */
bool is_safe(int board[][BOARD_SIZE], int row, int col, int num) {
    /* Check if the number exists in the same row */
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }
    /* Check if the number exists in the same column */
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }
    /* Check if the number exists in the same 3x3 sub-grid */
    int sub_grid_row_start = (row / 3) * 3;
    int sub_grid_col_start = (col / 3) * 3;
    for (int i = sub_grid_row_start; i < sub_grid_row_start + 3; i++) {
        for (int j = sub_grid_col_start; j < sub_grid_col_start + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }
    /* If none of the above conditions are met, it is safe to put the number in the given spot */
    return true;
}

/* Main recursive function to solve the Sudoku puzzle */
bool solve_sudoku(int board[][BOARD_SIZE], int row, int col) {
    /* Check if we have reached the end of the board */
    if (row == BOARD_SIZE - 1 && col == BOARD_SIZE) {
        return true;
    }
    /* Check if we have reached the end of a row */
    if (col == BOARD_SIZE) {
        row++;
        col = 0;
    }
    /* Check if the current spot contains a number */
    if (board[row][col] > 0) {
        return solve_sudoku(board, row, col + 1);
    }
    /* Try to put numbers 1-9 in the current spot */
    for (int num = 1; num <= BOARD_SIZE; num++) {
        if (is_safe(board, row, col, num)) {
            board[row][col] = num;
            if (solve_sudoku(board, row, col + 1)) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    /* If we reach here, it means there is no valid number to put in the current spot */
    return false;
}

/* Driver function to test the Sudoku Solver */
int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 0, 0, 0, 2, 0},
        {9, 0, 0, 8, 0, 0, 0, 0, 5},
        {0, 5, 0, 0, 0, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    printf("Input board:\n");
    print_board(board);

    if (solve_sudoku(board, 0, 0)) {
        printf("Solution:\n");
        print_board(board);
    } else {
        printf("No solution exists for the given input.\n");
    }

    return 0;
}