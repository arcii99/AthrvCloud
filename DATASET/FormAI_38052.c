//FormAI DATASET v1.0 Category: Sudoku solver ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define N 9

void print_board(int board[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}

int is_safe(int board[N][N], int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return 0;
        }
    }
    
    int start_row = row - row % 3;
    int start_col = col - col % 3;
    for (int i = start_row; i < start_row + 3; i++) {
        for (int j = start_col; j < start_col + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }
    
    return 1;
}

int solve_board(int board[N][N], int row, int col) {
    if (row == N - 1 && col == N) {
        return 1;
    }
    
    if (col == N) {
        row++;
        col = 0;
    }
    
    if (board[row][col] != 0) {
        return solve_board(board, row, col + 1);
    }
    
    for (int num = 1; num <= N; num++) {
        if (is_safe(board, row, col, num)) {
            board[row][col] = num;
            if (solve_board(board, row, col + 1)) {
                return 1;
            }
            board[row][col] = 0;
        }
    }
    
    return 0;
}

int main() {
    int board[N][N] = {{0, 0, 9, 0, 0, 0, 0, 0, 5},
                       {6, 0, 0, 0, 1, 0, 0, 2, 0},
                       {0, 1, 2, 0, 0, 0, 0, 9, 6},
                       {0, 0, 8, 0, 0, 0, 5, 0, 0},
                       {0, 7, 0, 9, 0, 0, 0, 0, 0},
                       {2, 0, 6, 0, 8, 0, 4, 0, 0},
                       {8, 0, 0, 0, 4, 0, 0, 5, 0},
                       {0, 3, 0, 0, 6, 0, 0, 0, 8},
                       {0, 0, 0, 0, 0, 7, 0, 0, 0}};
                       
    if (solve_board(board, 0, 0)) {
        printf("Solved Sudoku:\n");
        print_board(board);
    }
    else {
        printf("Could not solve Sudoku\n");
    }
    
    return 0;
}