//FormAI DATASET v1.0 Category: Sudoku solver ; Style: complex
#include <stdio.h>

#define N 9

void printBoard(int board[N][N]) {
    int row, col;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}

int canPlace(int board[N][N], int row, int col, int num) {
    int i, j;
    for (i = 0; i < N; i++) {
        if (board[row][i] == num) return 0;
        if (board[i][col] == num) return 0;
    }
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    for (i = boxRow; i < boxRow + 3; i++) {
        for (j = boxCol; j < boxCol + 3; j++) {
            if (board[i][j] == num) return 0;
        }
    }
    return 1;
}

int solve(int board[N][N], int row, int col) {
    if (row == N) return 1;
    if (col == N) return solve(board, row + 1, 0);
    if (board[row][col] != 0) return solve(board, row, col + 1);
    int num;
    for (num = 1; num <= N; num++) {
        if (canPlace(board, row, col, num)) {
            board[row][col] = num;
            if (solve(board, row, col + 1)) {
                return 1;
            }
            board[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    int board[N][N] = {
        {7, 0, 0, 2, 5, 0, 0, 9, 0},
        {0, 4, 0, 0, 0, 8, 5, 0, 0},
        {5, 8, 6, 4, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 6, 8, 4, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 5, 0, 0, 9, 2, 0, 0, 0},
        {0, 0, 2, 5, 0, 0, 4, 0, 0},
        {0, 6, 0, 9, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    if (solve(board, 0, 0)) {
        printBoard(board);
    } else {
        printf("No solution found\n");
    }
    return 0;
}