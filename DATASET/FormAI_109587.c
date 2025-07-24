//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void print_board(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == -1) {
                printf("   ");
            } else if (board[i][j] < 10) {
                printf(" %d ", board[i][j]);
            } else {
                printf("%d ", board[i][j]);   
            }
        }
        printf("\n");
    }
}

int mark_board(int board[ROWS][COLS], int num) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == num) {
                board[i][j] = -1;
                return 1;
            }
        }
    }
    return 0;
}

int check_row(int board[ROWS][COLS], int row) {
    for (int i = 0; i < COLS; i++) {
        if (board[row][i] != -1) {
            return 0;
        }
    }
    return 1;
}

int check_col(int board[ROWS][COLS], int col) {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][col] != -1) {
            return 0;
        }
    }
    return 1;
}

int check_diag(int board[ROWS][COLS]) {
    int left_to_right = 1;
    int right_to_left = 1;
    
    for (int i = 0; i < ROWS; i++) {
        if (board[i][i] != -1) {
            left_to_right = 0;
        }
        if (board[i][COLS-i-1] != -1) {
            right_to_left = 0;
        }
    }
    
    if (left_to_right || right_to_left) {
        return 1;
    }
    return 0;
}

int check_bingo(int board[ROWS][COLS]) {
    int row_bingo, col_bingo, diag_bingo;
    row_bingo = col_bingo = diag_bingo = 0;
    
    for (int i = 0; i < ROWS; i++) {
        row_bingo += check_row(board, i);
        col_bingo += check_col(board, i);
    }
    
    diag_bingo = check_diag(board);
    
    if (row_bingo + col_bingo + diag_bingo >= 5) {
        return 1;
    }
    return 0;
}

int main() {
    int board[ROWS][COLS];
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = i * 5 + j + 1;
        }
    }
    board[2][2] = -1;
    
    srand(time(NULL));
    
    for (int i = 0; i < 75; i++) {
        int num = rand() % 75 + 1;
        printf("Next number is: %d\n", num);
        mark_board(board, num);
        print_board(board);
        if (check_bingo(board)) {
            printf("BINGO!\n");
            break;
        }
    }
    return 0;
}