//FormAI DATASET v1.0 Category: Sudoku solver ; Style: thoughtful
#include <stdio.h>

#define N 9

int board[N][N];

void print_board() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid(int row, int col, int num) {
    // Check row
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num) {
            return 0;
        }
    }
    // Check column
    for (int i = 0; i < N; i++) {
        if (board[i][col] == num) {
            return 0;
        }
    }
    // Check region
    int region_start_row = (row / 3) * 3;
    int region_start_col = (col / 3) * 3;
    for (int i = region_start_row; i < region_start_row + 3; i++) {
        for (int j = region_start_col; j < region_start_col + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int solve(int row, int col) {
    if (row == N) {
        return 1;
    }
    int next_row = row;
    int next_col = col + 1;
    if (next_col == N) {
        next_row++;
        next_col = 0;
    }
    if (board[row][col] != 0) {
        return solve(next_row, next_col);
    }
    for (int num = 1; num <= 9; num++) {
        if (is_valid(row, col, num)) {
            board[row][col] = num;
            if (solve(next_row, next_col)) {
                return 1;
            }
            board[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    // Initialize the board with zeros
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }
    // Example board from https://en.wikipedia.org/wiki/Sudoku#Solving_a_sudoku
    board[0][1] = 9;
    board[0][3] = 1;
    board[0][4] = 7;
    board[0][6] = 6;
    board[0][7] = 8;
    board[1][0] = 2;
    board[1][1] = 7;
    board[1][5] = 6;
    board[1][6] = 4;
    board[1][8] = 1;
    board[2][4] = 9;
    board[2][8] = 7;
    board[3][0] = 4;
    board[3][4] = 8;
    board[3][5] = 3;
    board[3][8] = 2;
    board[4][2] = 3;
    board[4][3] = 2;
    board[4][5] = 1;
    board[4][6] = 9;
    board[5][0] = 9;
    board[5][3] = 7;
    board[5][4] = 4;
    board[5][8] = 5;
    board[6][0] = 7;
    board[6][4] = 6;
    board[6][8] = 9;
    board[7][0] = 6;
    board[7][2] = 1;
    board[7][3] = 9;
    board[7][7] = 7;
    board[7][8] = 4;
    board[8][1] = 4;
    board[8][2] = 2;
    board[8][4] = 5;
    board[8][7] = 1;
    // Print the initial board
    printf("Initial board:\n");
    print_board();
    // Solve the board
    solve(0, 0);
    // Print the solved board
    printf("Solved board:\n");
    print_board();
    return 0;
}