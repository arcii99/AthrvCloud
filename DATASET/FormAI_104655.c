//FormAI DATASET v1.0 Category: Sudoku solver ; Style: decentralized
#include <stdio.h>

#define BOARD_SIZE 9
#define UNASSIGNED 0

int board[BOARD_SIZE][BOARD_SIZE];

int isValid(int row, int col, int val) {
    // check row
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[row][i] == val) return 0;
    }

    // check column
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][col] == val) return 0;
    }

    // check sub-grid
    int sub_row = row - row % 3;
    int sub_col = col - col % 3;
    for (int i = sub_row; i < sub_row + 3; i++) {
        for (int j = sub_col; j < sub_col + 3; j++) {
            if (board[i][j] == val) return 0;
        }
    }

    return 1;
}

int solve(int row, int col) {
    if (row == BOARD_SIZE) return 1;

    int next_row = col == BOARD_SIZE - 1 ? row + 1 : row;
    int next_col = (col + 1) % BOARD_SIZE;

    if (board[row][col] != UNASSIGNED) return solve(next_row, next_col);

    for (int val = 1; val <= BOARD_SIZE; val++) {
        if (isValid(row, col, val)) {
            board[row][col] = val;
            if (solve(next_row, next_col)) return 1;
            board[row][col] = UNASSIGNED;
        }
    }

    return 0;
}

void printBoard() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}

int main() {
    // initial board configuration
    int initial_board[BOARD_SIZE][BOARD_SIZE] = {
        {0, 0, 0, 2, 6, 0, 7, 0, 1},
        {6, 8, 0, 0, 7, 0, 0, 9, 0},
        {1, 9, 0, 0, 0, 4, 5, 0, 0},
        {8, 2, 0, 1, 0, 0, 0, 4, 0},
        {0, 0, 4, 6, 0, 2, 9, 0, 0},
        {0, 5, 0, 0, 0, 3, 0, 2, 8},
        {0, 0, 9, 3, 0, 0, 0, 7, 4},
        {0, 4, 0, 0, 5, 0, 0, 3, 6},
        {7, 0, 3, 0, 1, 8, 0, 0, 0},
    };

    // copy initial board configuration to the solver board
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            board[row][col] = initial_board[row][col];
        }
    }

    // solve sudoku
    if (solve(0, 0)) {
        printf("Solution:\n");
        printBoard();
    } else {
        printf("No solution exists\n");
    }

    return 0;
}