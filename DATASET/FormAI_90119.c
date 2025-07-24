//FormAI DATASET v1.0 Category: Sudoku solver ; Style: shocked
#include <stdio.h>

#define BOARD_SIZE 9

int board[BOARD_SIZE][BOARD_SIZE];

void print_board() {
    printf("-----------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
            if ((j+1) % 3 == 0) {
                printf("| ");
            }
        }
        printf("\n");
        if ((i+1) % 3 == 0) {
            printf("-----------------\n");
        }
    }
}

int safe_to_place(int row, int col, int num) {
    // check row
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[row][i] == num) {
            return 0;
        }
    }

    // check column
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][col] == num) {
            return 0;
        }
    }

    // check box
    int box_start_row = row - (row % 3);
    int box_start_col = col - (col % 3);
    for (int i = box_start_row; i < box_start_row + 3; i++) {
        for (int j = box_start_col; j < box_start_col + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

int solve_sudoku() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= BOARD_SIZE; num++) {
                    if (safe_to_place(row, col, num)) {
                        board[row][col] = num;
                        if (solve_sudoku()) {
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
    // example board
    board[0][0] = 0;
    board[0][1] = 0;
    board[0][2] = 5;
    board[0][3] = 3;
    board[0][4] = 0;
    board[0][5] = 0;
    board[0][6] = 0;
    board[0][7] = 0;
    board[0][8] = 0;
    board[1][0] = 8;
    board[1][1] = 0;
    board[1][2] = 0;
    board[1][3] = 0;
    board[1][4] = 0;
    board[1][5] = 0;
    board[1][6] = 0;
    board[1][7] = 2;
    board[1][8] = 0;
    board[2][0] = 0;
    board[2][1] = 7;
    board[2][2] = 0;
    board[2][3] = 0;
    board[2][4] = 1;
    board[2][5] = 0;
    board[2][6] = 5;
    board[2][7] = 0;
    board[2][8] = 0;
    board[3][0] = 4;
    board[3][1] = 0;
    board[3][2] = 0;
    board[3][3] = 0;
    board[3][4] = 0;
    board[3][5] = 5;
    board[3][6] = 3;
    board[3][7] = 0;
    board[3][8] = 0;
    board[4][0] = 0;
    board[4][1] = 1;
    board[4][2] = 0;
    board[4][3] = 0;
    board[4][4] = 7;
    board[4][5] = 0;
    board[4][6] = 0;
    board[4][7] = 0;
    board[4][8] = 6;
    board[5][0] = 0;
    board[5][1] = 0;
    board[5][2] = 3;
    board[5][3] = 0;
    board[5][4] = 0;
    board[5][5] = 0;
    board[5][6] = 0;
    board[5][7] = 4;
    board[5][8] = 0;
    board[6][0] = 0;
    board[6][1] = 0;
    board[6][2] = 0;
    board[6][3] = 0;
    board[6][4] = 0;
    board[6][5] = 9;
    board[6][6] = 7;
    board[6][7] = 0;
    board[6][8] = 0;
    board[7][0] = 0;
    board[7][1] = 0;
    board[7][2] = 0;
    board[7][3] = 4;
    board[7][4] = 0;
    board[7][5] = 0;
    board[7][6] = 0;
    board[7][7] = 0;
    board[7][8] = 0;
    board[8][0] = 0;
    board[8][1] = 0;
    board[8][2] = 5;
    board[8][3] = 2;
    board[8][4] = 0;
    board[8][5] = 6;
    board[8][6] = 0;
    board[8][7] = 0;
    board[8][8] = 0;

    printf("Original board:\n");
    print_board();

    if (solve_sudoku()) {
        printf("\nSolved board:\n");
        print_board();
    } else {
        printf("Unable to solve Sudoku!\n");
    }

    return 0;
}