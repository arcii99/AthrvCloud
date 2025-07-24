//FormAI DATASET v1.0 Category: Sudoku solver ; Style: retro
#include <stdio.h>

int board[9][9] = {
    {0, 9, 0, 0, 0, 3, 1, 0, 0},
    {7, 0, 0, 0, 8, 0, 0, 0, 0},
    {6, 0, 0, 0, 0, 7, 0, 0, 0},
    {0, 0, 5, 0, 0, 0, 0, 0, 4},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 2, 0, 0},
    {0, 0, 0, 5, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 3, 7},
    {0, 0, 6, 1, 0, 0, 0, 5, 0}
};

void print_board() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int valid(int num, int row, int col) {
    // check row
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) {
            return 0;
        }
    }
    // check column
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num) {
            return 0;
        }
    }
    // check subgrid
    int subgrid_row = row / 3;
    int subgrid_col = col / 3;
    for (int i = subgrid_row * 3; i < (subgrid_row + 1) * 3; i++) {
        for (int j = subgrid_col * 3; j < (subgrid_col + 1) * 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int solve() {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (valid(num, row, col)) {
                        board[row][col] = num;
                        if (solve()) {
                            return 1;
                        } else {
                            board[row][col] = 0;
                        }
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    printf("Before solving:\n");
    print_board();
    printf("\nAfter solving:\n");
    if (solve()) {
        print_board();
    } else {
        printf("No solution found!\n");
    }
    return 0;
}