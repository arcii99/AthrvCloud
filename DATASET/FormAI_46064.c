//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MIN_NUMBER 1
#define MAX_NUMBER 75
#define BINGO "BINGO!"

typedef struct {
    int row;
    int col;
} BingoNumber;

void seedRand() {
    srand(time(NULL));
}

int randInRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int checkRows(int board[][COLS]) {
    int i, j, isBingo = 0;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] != -1) {
                break;
            }
        }
        if (j == COLS) {
            isBingo = 1;
        }
    }
    return isBingo;
}

int checkCols(int board[][COLS]) {
    int i, j, isBingo = 0;
    for (j = 0; j < COLS; j++) {
        for (i = 0; i < ROWS; i++) {
            if (board[i][j] != -1) {
                break;
            }
        }
        if (i == ROWS) {
            isBingo = 1;
        }
    }
    return isBingo;
}

int checkDiagonal(int board[][COLS]) {
    int i, isBingo = 0;
    for (i = 0; i < ROWS; i++) {
        if (board[i][i] != -1) {
            break;
        }
    }
    if (i == ROWS) {
        isBingo = 1;
    }
    if (!isBingo) {
        for (i = 0; i < ROWS; i++) {
            if (board[i][ROWS - i - 1] != -1) {
                break;
            }
        }
        if (i == ROWS) {
            isBingo = 1;
        }
    }
    return isBingo;
}

int checkBingo(int board[][COLS]) {
    if (checkRows(board) || checkCols(board) || checkDiagonal(board)) {
        return 1;
    } else {
        return 0;
    }
}

void printBoard(int board[][COLS]) {
    int i, j;
    printf("  B  I  N  G  O\n");
    printf("-----------------\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == -1) {
                printf("|X ");
            } else {
                printf("|%2d", board[i][j]);
            }
        }
        printf("|\n");
        printf("-----------------\n");
    }
}

void fillBoard(int board[][COLS], BingoNumber *numbers, int count) {
    int i, j, index;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = -1;
        }
    }
    for (i = 0; i < count; i++) {
        if (checkBingo(board)) {
            break;
        }
        index = randInRange(0, MAX_NUMBER - i - 1);
        board[numbers[index].row][numbers[index].col] = i + 1;
        numbers[index] = numbers[MAX_NUMBER - i - 1];
    }
}

int main() {
    int board[ROWS][COLS];
    BingoNumber numbers[MAX_NUMBER];
    int i, j, count = 0;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            numbers[count].row = i;
            numbers[count].col = j;
            count++;
        }
    }

    seedRand();
    fillBoard(board, numbers, MAX_NUMBER);

    printf("%s\n\n", BINGO);
    printBoard(board);

    return 0;
}