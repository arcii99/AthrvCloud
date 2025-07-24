//FormAI DATASET v1.0 Category: Table Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 3
#define COLS 3
#define MAX_MOVES 9

char board[ROWS][COLS];
int moveCount = 0;

void displayBoard() {
    printf("\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

bool isInputValid(int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        return false;
    }
    if (board[row][col] == 'X' || board[row][col] == 'O') {
        return false;
    }
    return true;
}

bool isWinningMove(int row, int col) {
    char player = board[row][col];
    int i;
    // Check row
    for (i = 0; i < COLS; i++) {
        if (board[row][i] != player) {
            break;
        }
    }
    if (i == COLS) {
        return true;
    }
    // Check column
    for (i = 0; i < ROWS; i++) {
        if (board[i][col] != player) {
            break;
        }
    }
    if (i == ROWS) {
        return true;
    }
    // Check diagonal (if applicable)
    if (row == col) {
        for (i = 0; i < ROWS; i++) {
            if (board[i][i] != player) {
                break;
            }
        }
        if (i == ROWS) {
            return true;
        }
    }
    // Check anti-diagonal (if applicable)
    if (row + col == ROWS - 1) {
        for (i = 0; i < ROWS; i++) {
            if (board[i][ROWS - i - 1] != player) {
                break;
            }
        }
        if (i == ROWS) {
            return true;
        }
    }
    return false;
}

bool playerMove(char player) {
    int row, col;
    printf("Player %c turn:\n", player);
    printf("Enter row number (0, 1, 2): ");
    scanf("%d", &row);
    printf("Enter column number (0, 1, 2): ");
    scanf("%d", &col);
    if (!isInputValid(row, col)) {
        printf("Invalid input, please try again.\n");
        return false;
    }
    board[row][col] = player;
    moveCount++;
    displayBoard();
    if (isWinningMove(row, col)) {
        printf("Player %c wins!\n", player);
        return true;
    }
    if (moveCount == MAX_MOVES) {
        printf("Game ends in a tie.\n");
        return true;
    }
    return false;
}

void resetBoard() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
    moveCount = 0;
}

int main() {
    char playAgain = 'Y';
    while (playAgain == 'Y') {
        resetBoard();
        displayBoard();
        while (true) {
            if (playerMove('X')) {
                break;
            }
            if (playerMove('O')) {
                break;
            }
        }
        printf("Do you want to play again? (Y/N): ");
        scanf(" %c", &playAgain);
        playAgain = toupper(playAgain);
    }
    return 0;
}