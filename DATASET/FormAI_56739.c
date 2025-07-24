//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int main()
{
    int board[ROWS][COLS];
    int calledNumbers[75] = { 0 };
    int numCalled = 0;

    // Initialize random number generator
    srand(time(NULL));

    // Initialize board
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            board[row][col] = rand() % 15 + (col * 15) + 1;
        }
    }
    board[2][2] = 0; // Free space in center

    printf("Welcome to C Bingo Simulator!\n\n");

    while (numCalled < 75) {
        // Generate random number
        int calledNum;
        do {
            calledNum = rand() % 75 + 1;
        } while (calledNumbers[calledNum - 1]);
        calledNumbers[calledNum - 1] = 1;
        numCalled++;

        printf("Called number: %d\n", calledNum);

        // Check board
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                if (board[row][col] == calledNum) {
                    board[row][col] = 0;
                }
            }
        }

        // Print board
        printf("\n");
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                if (board[row][col] == 0) {
                    printf("[  ]");
                } else {
                    printf("[%2d]", board[row][col]);
                }
            }
            printf("\n");
        }
        printf("\n");

        // Check for bingo
        for (int row = 0; row < ROWS; row++) {
            int sum = 0;
            for (int col = 0; col < COLS; col++) {
                sum += board[row][col];
            }
            if (sum == 0) {
                printf("Bingo! Row %d\n", row + 1);
                return 0;
            }
        }

        for (int col = 0; col < COLS; col++) {
            int sum = 0;
            for (int row = 0; row < ROWS; row++) {
                sum += board[row][col];
            }
            if (sum == 0) {
                printf("Bingo! Column %d\n", col + 1);
                return 0;
            }
        }

        int sum = 0;
        for (int i = 0; i < ROWS; i++) {
            sum += board[i][i];
        }
        if (sum == 0) {
            printf("Bingo! Diagonal\n");
            return 0;
        }

        sum = 0;
        for (int i = 0; i < ROWS; i++) {
            sum += board[i][COLS - i - 1];
        }
        if (sum == 0) {
            printf("Bingo! Diagonal\n");
            return 0;
        }

        printf("No bingo yet...\n\n");
    }

    printf("No more numbers to call, game over.\n");
    return 0;
}