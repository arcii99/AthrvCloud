//FormAI DATASET v1.0 Category: Sudoku solver ; Style: imaginative
#include<stdio.h>

int check_rows(int board[9][9], int row, int num) {
    for (int col = 0; col < 9; col++) {
        if (board[row][col] == num)
            return 0;
    }
    return 1;
}

int check_cols(int board[9][9], int col, int num) {
    for (int row = 0; row < 9; row++) {
        if (board[row][col] == num)
            return 0;
    }
    return 1;
}

int check_grid(int board[9][9], int start_row, int start_col, int num) {
    for (int row = 0; row < 3; row++) {
        for(int col = 0; col < 3; col++) {
            if (board[row+start_row][col+start_col] == num)
                return 0;
        }
    }
    return 1;
}

void print_board(int board[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            printf("%d ", board[row][col]);
            if (col % 3 == 2)
                printf("| ");
        }
        printf("\n");
        if (row % 3 == 2)
            printf("-----------------------\n");
    }
}

int solve_sudoku(int board[9][9]) {
    int row, col, num;
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                for (num = 1; num <= 9; num++) {
                    if (check_rows(board, row, num) && check_cols(board, col, num) && check_grid(board, row-row%3, col-col%3, num)) {
                        board[row][col] = num;
                        if (solve_sudoku(board))
                            return 1;
                        board[row][col] = 0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int board[9][9] = {{8,0,0,5,3,0,0,0,9},
                       {0,0,9,0,0,7,6,1,5},
                       {6,0,2,0,0,9,8,0,0},
                       {3,1,0,6,8,0,9,0,0},
                       {4,0,0,7,0,3,0,5,8},
                       {0,0,0,0,0,0,0,0,1},
                       {0,0,0,0,1,0,2,6,0},
                       {0,3,0,4,0,0,0,0,0},
                       {0,7,8,9,0,0,0,0,4}
                      };
    printf("Original Sudoku Board:\n");
    print_board(board);
    if (solve_sudoku(board)) {
        printf("\nSolved Sudoku Board:\n");
        print_board(board);
    }
    else {
        printf("Unsolvable Sudoku Board\n");
    }
    return 0;
}