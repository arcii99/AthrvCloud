//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void printBingoCard(int card[ROWS][COLS]);
int checkHorizontal(int card[ROWS][COLS]);
int checkVertical(int card[ROWS][COLS]);
int checkDiagonal(int card[ROWS][COLS]);

int main() {
    // Seed random number generator
    srand(time(0));

    // Initialize bingo card
    int bingoCard[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // Generate random number between 1 and 75
            bingoCard[i][j] = rand() % 75 + 1;
        }
    }

    // Print bingo card
    printBingoCard(bingoCard);

    // Game loop
    int numCalled = 0;
    while (1) {
        // Generate random number between 1 and 75
        int calledNum = rand() % 75 + 1;
        printf("Number called: %d\n", calledNum);
        numCalled++;

        // Check if called number is on the bingo card
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (bingoCard[i][j] == calledNum) {
                    bingoCard[i][j] = 0; // Mark number as called
                    // Check if board is a winner
                    if (checkHorizontal(bingoCard) || checkVertical(bingoCard) || checkDiagonal(bingoCard)) {
                        printf("BINGO!! Board cleared in %d turns.\n", numCalled);
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}

void printBingoCard(int card[ROWS][COLS]) {
    printf("BINGO CARD\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%2d ", card[i][j]);
        }
        printf("\n");
    }
}

int checkHorizontal(int card[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        int count = 0;
        for (int j = 0; j < COLS; j++) {
            if (card[i][j] == 0) {
                count++;
            }
        }
        if (count == COLS) {
            return 1; // Bingo
        }
    }
    return 0; // Not bingo
}

int checkVertical(int card[ROWS][COLS]) {
    for (int j = 0; j < COLS; j++) {
        int count = 0;
        for (int i = 0; i < ROWS; i++) {
            if (card[i][j] == 0) {
                count++;
            }
        }
        if (count == ROWS) {
            return 1; // Bingo
        }
    }
    return 0; // Not bingo
}

int checkDiagonal(int card[ROWS][COLS]) {
    // Check top-left to bottom-right diagonal
    int count = 0;
    for (int i = 0; i < ROWS; i++) {
        if (card[i][i] == 0) {
            count++;
        }
    }
    if (count == ROWS) {
        return 1; // Bingo
    }

    // Check top-right to bottom-left diagonal
    count = 0;
    for (int i = 0; i < ROWS; i++) {
        if (card[i][COLS - 1 - i] == 0) {
            count++;
        }
    }
    if (count == ROWS) {
        return 1; // Bingo
    }

    return 0; // Not bingo
}