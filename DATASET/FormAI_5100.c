//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void print_board(int board[ROWS][COLS]) {
    printf(" -----------------------------\n");

    for (int i = 0; i < ROWS; i++) {
        printf("| ");
        for (int j = 0; j < COLS; j++) {
            // if the cell contains 0, print space instead
            if (board[i][j] == 0) {
                printf("  | ");
            } else {
                printf("%d | ", board[i][j]);
            }
        }
        printf("\n");
        printf(" -----------------------------\n");
    }
}

int check_bingo(int board[ROWS][COLS]) {
    int bingo_count = 0;

    // check rows
    for (int i = 0; i < ROWS; i++) {
        int sum = 0;
        for (int j = 0; j < COLS; j++) {
            sum += board[i][j];
        }
        if (sum == 0) {
            bingo_count++;
        }
    }

    // check columns
    for (int i = 0; i < COLS; i++) {
        int sum = 0;
        for (int j = 0; j < ROWS; j++) {
            sum += board[j][i];
        }
        if (sum == 0) {
            bingo_count++;
        }
    }

    // check diagonals
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < ROWS; i++) {
        sum1 += board[i][i];
        sum2 += board[i][COLS - i - 1];
    }
    if (sum1 == 0) {
        bingo_count++;
    }
    if (sum2 == 0) {
        bingo_count++;
    }

    return bingo_count;
}

int main() {
    // initialize board with 0's
    int board[ROWS][COLS] = {{0}};

    // fill in board with random numbers from 1 to 25
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int r = rand() % 25 + 1;
            int flag = 1;
            // avoid duplicates
            while (flag) {
                flag = 0;
                for (int k = 0; k < i; k++) {
                    for (int l = 0; l < j; l++) {
                        if (board[k][l] == r) {
                            r = rand() % 25 + 1;
                            flag = 1;
                        }
                    }
                }
            }
            board[i][j] = r;
        }
    }

    print_board(board);

    int bingo_count = 0;

    while (bingo_count < 5) {
        printf("Enter a number (1-25): ");
        int num;
        scanf("%d", &num);

        // mark cell if the number is found
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == num) {
                    board[i][j] = 0;
                    break;
                }
            }
        }

        print_board(board);

        bingo_count = check_bingo(board);
        printf("Bingo count: %d\n", bingo_count);
    }

    printf("Congratulations, you got a Bingo!\n");

    return 0;
}