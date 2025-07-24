//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLUMNS 5

void initialize_board(int board[ROWS][COLUMNS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            if (i == 2 && j == 2) {
                board[i][j] = 0;
            } else {
                board[i][j] = -1;
            }
        }
    }
}

void print_board(int board[ROWS][COLUMNS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            if (board[i][j] == -1) {
                printf(" X ");
            } else if (board[i][j] == 0) {
                printf("   ");
            } else {
                printf("%2d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

int check_bingo(int board[ROWS][COLUMNS]) {
    int i, j, sum;
    for (i = 0; i < ROWS; i++) {
        sum = 0;
        for (j = 0; j < COLUMNS; j++) {
            sum += board[i][j];
        }
        if (sum == 0) {
            return 1;
        }
    }
    for (j = 0; j < COLUMNS; j++) {
        sum = 0;
        for (i = 0; i < ROWS; i++) {
            sum += board[i][j];
        }
        if (sum == 0) {
            return 1;
        }
    }
    sum = 0;
    for (i = 0; i < ROWS; i++) {
        sum += board[i][i];
    }
    if (sum == 0) {
        return 1;
    }
    sum = 0;
    for (i = 0; i < ROWS; i++) {
        sum += board[i][COLUMNS-i-1];
    }
    if (sum == 0) {
        return 1;
    }
    return 0;
}

int main() {
    int board[ROWS][COLUMNS];
    initialize_board(board);
    srand(time(NULL));
    int num, i, j, count = 0, bingo = 0;
    while (!bingo) {
        count++;
        printf("Press enter to draw the next number.\n");
        getchar();
        num = rand() % 75 + 1;
        printf("The next number is: %d\n", num);
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLUMNS; j++) {
                if (board[i][j] == num) {
                    board[i][j] = 0;
                }
            }
        }
        print_board(board);
        bingo = check_bingo(board);
    }
    printf("Bingo! It took you %d draws to win.\n", count);
    return 0;
}