//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5
#define RANGE 25

typedef struct {
    int num;
    bool marked;
} Cell;

Cell board[ROWS][COLS];

bool checkRow(int row) {
    for (int j = 0; j < COLS; j++) {
        if (!board[row][j].marked)
            return false;
    }
    return true;
}

bool checkCol(int col) {
    for (int i = 0; i < ROWS; i++) {
        if (!board[i][col].marked)
            return false;
    }
    return true;
}

bool checkDiagonal(int row, int col) {
    if (row == col) {
        for (int i = 0; i < ROWS; i++) {
            if (!board[i][i].marked)
                return false;
        }
        return true;
    }

    if (row + col == ROWS - 1) {
        for (int i = 0; i < ROWS; i++) {
            if (!board[i][ROWS - i - 1].marked)
                return false;
        }
        return true;
    }

    return false;
}

bool checkWin(int row, int col) {

    if (checkRow(row) || checkCol(col) || checkDiagonal(row, col)) {
        return true;
    }

    return false;
}

void markNumber(int num) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j].num == num) {
                board[i][j].marked = true;
            }
        }
    }
}

int getRandNum() {
    return (rand() % RANGE) + 1;
}

void init() {
    srand(time(NULL));

    for (int i = 0; i < RANGE; i++) {
        int num = getRandNum();

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j].num == num) {
                    num = getRandNum();
                    i = -1;
                    break;
                }
            }
        }

        int row = i / COLS;
        int col = i % COLS;

        board[row][col].num = num;
        board[row][col].marked = false;
    }
}

void printBoard() {
    printf("\nB\tI\tN\tG\tO\n");

    for (int i = 0; i < ROWS; i++) {

        for (int j = 0; j < COLS; j++) {
            printf("%d", board[i][j].num);

            if (board[i][j].marked) {
                printf("  X\t");
            } else {
                printf("  \t");
            }
        }
        printf("\n");
    }
}

void playBingo() {
    int num;
    int count = 0;

    while (count < RANGE) {
        printf("\nEnter a number between 1-25 (or 0 to exit): ");
        scanf("%d", &num);

        if (num == 0)
            break;

        if (num < 1 || num > 25) {
            printf("\nInvalid number! Try again.");
            continue;
        }

        markNumber(num);
        printBoard();

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {

                if (board[i][j].num == num) {
                    if (checkWin(i, j)) {
                        printf("\nCongratulations! You won Bingo!\n");
                        return;
                    }
                    count++;
                    printf("\nCount: %d\n", count);
                    break;
                }
            }
        }
    }

    printf("\nThanks for playing!\n");
}

int main() {
    init();
    printBoard();
    playBingo();
    return 0;
}