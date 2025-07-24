//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 75

int bingoBoard[ROWS][COLS];
int bingoNumbers[MAX_NUM];
int selectedNumbers[MAX_NUM];
int numSelected = 0;

void initializeBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            bingoBoard[i][j] = -1;
        }
    }
}

void initializeNumbers() {
    for (int i = 0; i < MAX_NUM; i++) {
        bingoNumbers[i] = i + 1;
    }
}

void shuffleNumbers() {
    srand(time(NULL));
    for (int i = 0; i < MAX_NUM; i++) {
        int j = rand() % MAX_NUM;
        int temp = bingoNumbers[i];
        bingoNumbers[i] = bingoNumbers[j];
        bingoNumbers[j] = temp;
    }
}

void printBoard() {
    printf("\n");
    printf("  B   I   N   G   O\n");
    for (int i = 0; i < ROWS; i++) {
        printf("-------------------\n");
        for (int j = 0; j < COLS; j++) {
            if (bingoBoard[i][j] == -1) {
                printf("|   ");
            } else {
                printf("| %d ", bingoBoard[i][j]);
            }
        }
        printf("|\n");
    }
    printf("-------------------\n");
    printf("\n");
}

void selectNumber() {
    int index = -1;
    do {
        index = rand() % MAX_NUM;
    } while (selectedNumbers[index] == 1);
    selectedNumbers[index] = 1;
    numSelected++;
    printf("Selected number: %d\n", bingoNumbers[index]);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (bingoBoard[i][j] == bingoNumbers[index]) {
                bingoBoard[i][j] = -1;
            }
        }
    }
}

int main() {
    // Initialize board and numbers
    initializeBoard();
    initializeNumbers();

    // Shuffle numbers
    shuffleNumbers();

    // Set center of board to FREE space
    bingoBoard[ROWS / 2][COLS / 2] = -1;

    // Main loop
    while (numSelected < MAX_NUM) {
        printBoard();
        selectNumber();
    }

    // All numbers have been selected
    printf("Bingo!\n");

    return 0;
}