//FormAI DATASET v1.0 Category: Table Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 6
#define COLS 6

void initializeBoard(int board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = rand() % 10;
        }
    }
}

void printBoard(int board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int getRow() {
    int row;
    printf("Enter row: ");
    scanf("%d", &row);
    return row;
}

int getCol() {
    int col;
    printf("Enter column: ");
    scanf("%d", &col);
    return col;
}

int isMoveValid(int board[ROWS][COLS], int row, int col) {
    if (row >= ROWS || row < 0 || col >= COLS || col < 0) {
        return 0;
    }
    return 1;
}

int calculateScore(int board[ROWS][COLS], int row, int col, int num) {
    int i, j, score = 0;
    for (i = row - 1; i <= row + 1; i++) {
        for (j = col - 1; j <= col + 1; j++) {
            if (isMoveValid(board, i, j) && board[i][j] == num) {
                score += num;
            }
        }
    }
    return score;
}

int main() {
    int board[ROWS][COLS];
    initializeBoard(board);
    printBoard(board);

    int row, col, num, score = 0;

    while (1) {
        row = getRow();
        col = getCol();
        if (!isMoveValid(board, row, col)) {
            printf("Invalid move\n");
            continue;
        }
        num = board[row][col];
        score += calculateScore(board, row, col, num);
        board[row][col] = rand() % 10;
        printBoard(board);
        printf("Score: %d\n", score);
    }

    return 0;
}