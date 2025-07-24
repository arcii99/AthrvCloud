//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAXRANGE 25
#define MAXCALLS 75

void init_board(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }
}

void display_board(int board[ROWS][COLS]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 0) {
                printf(" - ");
            } else {
                printf(" %2d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

void generate_call(int *range, int *called) {
    int number = rand() % *range + 1;
    while (called[number-1]) {
        number = rand() % *range + 1;
    }
    called[number-1] = 1;
    *range -= 1;
    printf("Bingo ball: %d\n", number);
}

int check_bingo(int board[ROWS][COLS], int *bingo_count) {
    int count = 0;
    for (int i = 0; i < ROWS; i++) {
        int row_sum = 0;
        for (int j = 0; j < COLS; j++) {
            row_sum += board[i][j];
        }
        if (row_sum == 0) {
            count++;
        }
    }
    for (int i = 0; i < COLS; i++) {
        int col_sum = 0;
        for (int j = 0; j < ROWS; j++) {
            col_sum += board[j][i];
        }
        if (col_sum == 0) {
            count++;
        }
    }
    int diag_sum = 0;
    for (int i = 0; i < ROWS; i++) {
        diag_sum += board[i][i];
    }
    if (diag_sum == 0) {
        count++;
    }
    diag_sum = 0;
    for (int i = 0; i < ROWS; i++) {
        diag_sum += board[i][COLS-i-1];
    }
    if (diag_sum == 0) {
        count++;
    }
    *bingo_count = count;
    if (count == 5) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    srand(time(0));
    int board[ROWS][COLS];
    int range = MAXRANGE;
    int called[MAXRANGE] = {0};
    int bingo_calls[MAXCALLS];
    int bingo_count = 0;
    init_board(board);
    printf("Welcome to Bingo Simulator!\n");
    while (bingo_count < 5) {
        generate_call(&range, called);
        int found = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == 0 && (i*COLS+j+1) == called[i*COLS+j]) {
                    board[i][j] = called[i*COLS+j];
                    found = 1;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        bingo_calls[range] = called[range];
        display_board(board);
        if (check_bingo(board, &bingo_count)) {
            printf("BINGO! You won!\n");
            break;
        }
    }
    printf("Bingo calls:\n");
    for (int i = 0; i < MAXRANGE - range; i++) {
        printf("%d ", bingo_calls[i]);
        if ((i+1) % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n");
    return 0;
}