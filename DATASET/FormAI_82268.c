//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void init_bingo_board(int board[ROWS][COLS]) {
    int i, j, num = 1;
    srand(time(NULL));

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == 2 && j == 2) { // set center square to 0
                board[i][j] = 0;
            } else {
                board[i][j] = rand() % 75 + 1;
            }
        }
    }
}

void print_bingo_board(int board[ROWS][COLS], int status[ROWS][COLS]) {
    int i, j;
    printf("\n    B   I   N   G   O\n\n");

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (status[i][j] == 1) {
                printf("[X] ");
            } else {
                printf("[%d] ", board[i][j]);
            }
        }
        printf("\n\n");
    }
}

int check_bingo(int rows[ROWS], int cols[COLS], int diag1[ROWS], int diag2[ROWS]) {
    int i, bingo = 0;

    for (i = 0; i < ROWS; i++) {
        if (rows[i] == COLS || cols[i] == ROWS) {
            bingo = 1;
            break;
        }
    }

    if (diag1[ROWS-1] == COLS || diag2[ROWS-1] == ROWS) {
        bingo = 1;
    }

    return bingo;
}

int main() {
    int board[ROWS][COLS], status[ROWS][COLS] = {0}, rows[ROWS] = {0}, cols[COLS] = {0}, diag1[ROWS] = {0}, diag2[ROWS] = {0};
    int i, j, num, bingo = 0;

    init_bingo_board(board);

    printf("\n");
    print_bingo_board(board, status);

    while (!bingo) {
        printf("\nEnter a number between 1 and 75: ");
        scanf("%d", &num);

        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (board[i][j] == num) { // mark number as found
                    status[i][j] = 1;
                    rows[i]++;
                    cols[j]++;

                    if (i == j) {
                        diag1[i]++;
                    }

                    if (i + j == ROWS - 1) {
                        diag2[i]++;
                    }
                }
            }
        }

        printf("\n");
        print_bingo_board(board, status);

        bingo = check_bingo(rows, cols, diag1, diag2);

        if (bingo) {
            printf("\n\nBINGO!\n\n");
        }
    }

    return 0;
}