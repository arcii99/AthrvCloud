//FormAI DATASET v1.0 Category: Sudoku solver ; Style: cheerful
#include <stdio.h>

void print_board(int board[9][9]) {
    printf(" -------------------------\n");
    for (int i = 0; i < 9; i++) {
        printf("|");
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                printf("   ");
            } else {
                printf(" %d ", board[i][j]);
            }
            if ((j + 1) % 3 == 0) {
                printf("|");
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0) {
            printf(" -------------------------\n");
        }
    }
}

int is_valid(int board[9][9], int num, int row, int col) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return 0;
        }
    }
    int row_start = (row / 3) * 3;
    int col_start = (col / 3) * 3;
    for (int i = row_start; i < row_start + 3; i++) {
        for (int j = col_start; j < col_start + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int solve_board(int board[9][9], int row, int col) {
    if (row == 9) {
        return 1;
    }
    int next_row = row;
    int next_col = col + 1;
    if (next_col == 9) {
        next_row++;
        next_col = 0;
    }
    if (board[row][col] != 0) {
        return solve_board(board, next_row, next_col);
    }
    for (int i = 1; i <= 9; i++) {
        if (is_valid(board, i, row, col)) {
            board[row][col] = i;
            if (solve_board(board, next_row, next_col)) {
                return 1;
            }
            board[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    int board[9][9] = {
        {0, 0, 0, 0, 4, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 6, 0, 0, 5},
        {0, 0, 7, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 5, 0, 6, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 3},
        {2, 0, 0, 6, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 9, 2, 0},
        {0, 0, 0, 0, 7, 0, 0, 0, 0},
        {8, 0, 0, 0, 0, 0, 0, 5, 0}
    };
    printf("Original Sudoku board:\n");
    print_board(board);
    if (solve_board(board, 0, 0)) {
        printf("Solved Sudoku board:\n");
        print_board(board);
    } else {
        printf("Unable to solve Sudoku board\n");
    }
    return 0;
}