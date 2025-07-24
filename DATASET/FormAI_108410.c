//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void printBoard(int board[ROWS][COLS], int called[]) {
    printf("----------------------\n");
    printf("| B | I | N | G | O |\n");
    printf("----------------------\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == -1) {
                printf("| %c ", 'X');
            } else {
                printf("| %2d ", board[i][j]);
            }
        }
        printf("|\n");
    }
    printf("----------------------\n");
    printf("Called: ");
    for (int i = 0; i < ROWS*COLS; i++) {
        printf("%d ", called[i]);
    }
    printf("\n");
}

int checkRow(int board[ROWS][COLS], int row) {
    for (int i = 0; i < COLS; i++) {
        if (board[row][i] != -1) {
            return 0;
        }
    }
    return 1;
}

int checkColumn(int board[ROWS][COLS], int col) {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][col] != -1) {
            return 0;
        }
    }
    return 1;
}

int checkDiagonal(int board[ROWS][COLS], int dir) {
    int row = dir == 0 ? 0 : ROWS-1;
    int col = 0;
    int rowDir = dir == 0 ? 1 : -1;
    int colDir = 1;
    for (int i = 0; i < ROWS; i++) {
        if (board[row][col] != -1) {
            return 0;
        }
        row += rowDir;
        col += colDir;
    }
    return 1;
}

int checkWin(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        if (checkRow(board, i)) {
            return 1;
        }
    }
    for (int i = 0; i < COLS; i++) {
        if (checkColumn(board, i)) {
            return 1;
        }
    }
    if (checkDiagonal(board, 0) || checkDiagonal(board, 1)) {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    int board[ROWS][COLS];
    int called[ROWS*COLS];
    for (int i = 0; i < ROWS*COLS; i++) {
        called[i] = 0;
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = -1;
        }
    }
    int count = 0;
    while (!checkWin(board)) {
        int num = rand() % 75 + 1;
        int found = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == num) {
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("Calling: %d\n", num);
            called[count++] = num;
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    if (board[i][j] == -1 && (j == num/15 || (j == 4 && num == 75))) {
                        board[i][j] = num;
                        break;
                    }
                }
            }
            printBoard(board, called);
        }
    }
    printf("Bingo! You win!\n");
    return 0;
}