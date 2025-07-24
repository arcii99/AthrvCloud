//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 75

// function to check if a number has already been called
int isDuplicate(int num, int *called, int calledCount) {
    for (int i = 0; i < calledCount; i++) {
        if (called[i] == num) {
            return 1; // number is a duplicate
        }
    }
    // number is not a duplicate
    return 0;
}

int main() {
    // initialize game board
    int board[ROWS][COLS];
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            board[row][col] = -1; // -1 indicates an empty spot
        }
    }

    // initialize array of called numbers
    int called[MAX_NUM];
    int calledCount = 0;

    // seed random number generator
    srand(time(NULL));

    // play game until someone wins
    int winner = 0;
    while (!winner) {
        // generate a random number between 1 and 75
        int num = rand() % MAX_NUM + 1;

        // check if number has already been called
        if (isDuplicate(num, called, calledCount)) {
            continue; // number has already been called, try again
        }

        // add new number to called array
        called[calledCount++] = num;

        // check if number is on the board and mark it if it is
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                if (board[row][col] == num) {
                    board[row][col] = -2; // -2 indicates a called number on the board
                    break;
                }
            }
        }

        // check for winning patterns
        for (int row = 0; row < ROWS; row++) {
            int rowMatch = 0; // count of matching numbers in row
            for (int col = 0; col < COLS; col++) {
                if (board[row][col] == -2) {
                    rowMatch++;
                }
            }
            if (rowMatch == COLS) {
                printf("BINGO! You won with a full row!\n");
                winner = 1;
                break;
            }
        }

        for (int col = 0; col < COLS; col++) {
            int colMatch = 0; // count of matching numbers in column
            for (int row = 0; row < ROWS; row++) {
                if (board[row][col] == -2) {
                    colMatch++;
                }
            }
            if (colMatch == ROWS) {
                printf("BINGO! You won with a full column!\n");
                winner = 1;
                break;
            }
        }

        // check diagonal patterns
        int diagMatch = 0; // count of matching numbers in diagonal
        for (int i = 0; i < ROWS; i++) {
            if (board[i][i] == -2) {
                diagMatch++;
            }
        }
        if (diagMatch == ROWS) {
            printf("BINGO! You won with a diagonal!\n");
            winner = 1;
            break;
        }

        diagMatch = 0; // reset for other diagonal
        for (int i = 0; i < ROWS; i++) {
            if (board[i][ROWS - i - 1] == -2) {
                diagMatch++;
            }
        }
        if (diagMatch == ROWS) {
            printf("BINGO! You won with a diagonal!\n");
            winner = 1;
            break;
        }

        // print current state of board
        printf("Called numbers:");
        for (int i = 0; i < calledCount; i++) {
            printf(" %d", called[i]);
        }
        printf("\n");

        printf("Current board:\n");
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                if (board[row][col] == -1) {
                    printf("  ");
                } else if (board[row][col] == -2) {
                    printf("[X]");
                } else {
                    printf("[%d]", board[row][col]);
                }
            }
            printf("\n");
        }

        printf("\nPress enter to call the next number...");
        getchar();
    }

    return 0;
}