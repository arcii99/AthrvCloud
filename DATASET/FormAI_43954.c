//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLUMNS 5

int numbers[ROWS][COLUMNS];
int calledNumbers[ROWS*COLUMNS];
int currentIndex = 0;

void initialize() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            numbers[i][j] = -1;
        }
    }
}

void printBoard() {
    printf("\n");
    printf("B   I   N   G   O\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (numbers[i][j] >= 0) {
                printf("%d   ", numbers[i][j]);
            } else {
                printf("    ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int generateNumber() {
    return rand() % 75 + 1;
}

int isUnique(int num) {
    for (int i = 0; i < currentIndex; i++) {
        if (calledNumbers[i] == num) {
            return 0;
        }
    }
    return 1;
}

void callNumber() {
    int num = generateNumber();
    while (!isUnique(num)) {
        num = generateNumber();
    }
    calledNumbers[currentIndex++] = num;
    printf("CALLING NUMBER: %d\n", num);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (numbers[i][j] == num) {
                numbers[i][j] = -1;
            }
        }
    }
}

int checkBoard() {
    int count = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (numbers[i][j] == -1) {
                count++;
            }
        }
        if (count == ROWS) {
            return 1;
        } else {
            count = 0;
        }
    }
    count = 0;
    for (int j = 0; j < COLUMNS; j++) {
        for (int i = 0; i < ROWS; i++) {
            if (numbers[i][j] == -1) {
                count++;
            }
        }
        if (count == COLUMNS) {
            return 1;
        } else {
            count = 0;
        }
    }
    count = 0;
    for (int i = 0; i < ROWS; i++) {
        if (numbers[i][i] == -1) {
            count++;
        }
    }
    if (count == ROWS) {
        return 1;
    }
    count = 0;
    for (int i = 0; i < ROWS; i++) {
        if (numbers[i][ROWS - i - 1] == -1) {
            count++;
        }
    }
    if (count == ROWS) {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(0));
    initialize();
    while (!checkBoard()) {
        printBoard();
        callNumber();
    }
    printf("BINGO!\n");
    printBoard();
    return 0;
}