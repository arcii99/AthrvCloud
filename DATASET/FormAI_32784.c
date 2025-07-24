//FormAI DATASET v1.0 Category: Sudoku solver ; Style: paranoid
#include <stdio.h>

#define BOARD_SIZE 9
#define SUB_BOARD_SIZE 3

// Function to check if a digit is valid in the given row
int isValidRow(int row, int digit, int board[][BOARD_SIZE]) {
    for(int c = 0; c < BOARD_SIZE; c++) {
        if(board[row][c] == digit) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a digit is valid in the given column
int isValidCol(int col, int digit, int board[][BOARD_SIZE]) {
    for(int r = 0; r < BOARD_SIZE; r++) {
        if(board[r][col] == digit) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a digit is valid in the given sub-board
int isValidSubBoard(int row, int col, int digit, int board[][BOARD_SIZE]) {
    int sub_board_row_start = (row / SUB_BOARD_SIZE) * SUB_BOARD_SIZE;
    int sub_board_col_start = (col / SUB_BOARD_SIZE) * SUB_BOARD_SIZE;
    for(int r = 0; r < SUB_BOARD_SIZE; r++) {
        for(int c = 0; c < SUB_BOARD_SIZE; c++) {
            if(board[sub_board_row_start + r][sub_board_col_start + c] == digit) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to check if a digit is valid at the given position
int isValid(int row, int col, int digit, int board[][BOARD_SIZE]) {
    return isValidRow(row, digit, board)
        && isValidCol(col, digit, board)
        && isValidSubBoard(row, col, digit, board);
}

// Function to print the Sudoku board
void printBoard(int board[][BOARD_SIZE]) {
    for(int r = 0; r < BOARD_SIZE; r++) {
        for(int c = 0; c < BOARD_SIZE; c++) {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }
}

// Function to solve the Sudoku board
int solve(int board[][BOARD_SIZE], int r, int c) {
    int next_r = r;
    int next_c = c + 1;
    if(next_c >= BOARD_SIZE) {
        next_r += 1;
        next_c = 0;
    }
    if(r == BOARD_SIZE) {
        return 1;
    }
    if(board[r][c] != 0) {
        return solve(board, next_r, next_c);
    }
    for(int digit = 1; digit <= BOARD_SIZE; digit++) {
        if(isValid(r, c, digit, board)) {
            board[r][c] = digit;
            if(solve(board, next_r, next_c)) {
                return 1;
            }
            board[r][c] = 0;
        }
    }
    return 0;
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {
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
    if(solve(board, 0, 0)) {
        printBoard(board);
    } else {
        printf("No solution found.\n");
    }
    return 0;
}