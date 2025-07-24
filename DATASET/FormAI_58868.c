//FormAI DATASET v1.0 Category: Sudoku solver ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define N 9

void print_board(int board[N][N]) {
    printf("-------------------------\n");
    for (int i = 0; i < N; i++) {
        printf("| ");
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
            if (j % 3 == 2) printf("| ");
        }
        printf("\n");
        if (i % 3 == 2) printf("-------------------------\n");
    }
    printf("\n");
}

int is_valid(int board[N][N], int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num) return 0;
        if (board[i][col] == num) return 0;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) return 0;
    }
    return 1;
}

int solve_board(int board[N][N], int row, int col) {
    if (row == N) return 1;
    if (col == N) return solve_board(board, row + 1, 0);
    if (board[row][col] > 0) return solve_board(board, row, col + 1);

    for (int num = 1; num <= N; num++) {
        if (is_valid(board, row, col, num)) {
            board[row][col] = num;
            if (solve_board(board, row, col + 1)) return 1;
            board[row][col] = 0;
        }
    }

    return 0;
}

int main() {
    int board[N][N] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    if (solve_board(board, 0, 0)) {
        printf("Sudoku solved successfully:\n");
        print_board(board);
    } else {
        printf("Failed to solve Sudoku.\n");
    }

    return 0;
}