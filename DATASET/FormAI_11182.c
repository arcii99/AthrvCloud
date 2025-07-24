//FormAI DATASET v1.0 Category: Sudoku solver ; Style: statistical
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

void print_board(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool check_row(int board[SIZE][SIZE], int row, int num) {
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }
    return true;
}

bool check_col(int board[SIZE][SIZE], int col, int num) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }
    return true;
}

bool check_box(int board[SIZE][SIZE], int row, int col, int num) {
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

bool is_valid_move(int board[SIZE][SIZE], int row, int col, int num) {
    return check_row(board, row, num) && check_col(board, col, num) && check_box(board, row, col, num);
}

bool find_empty(int board[SIZE][SIZE], int *row, int *col) {
    for (*row = 0; *row < SIZE; (*row)++) {
        for (*col = 0; *col < SIZE; (*col)++) {
            if (board[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool solve_sudoku(int board[SIZE][SIZE]) {
    int row, col;
    if (!find_empty(board, &row, &col)) {
        return true;
    }

    for (int num = 1; num <= SIZE; num++) {
        if (is_valid_move(board, row, col, num)) {
            board[row][col] = num;
            if (solve_sudoku(board)) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

int main() {
    int board[SIZE][SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 0}
    };

    printf("Unsolved board:\n");
    print_board(board);

    if (solve_sudoku(board)) {
        printf("\nSolved board:\n");
        print_board(board);
    } else {
        printf("\nNo solution found.\n");
    }

    return 0;
}