//FormAI DATASET v1.0 Category: Game ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define ROWS 6
#define COLUMNS 7

char board[ROWS][COLUMNS];
int player = 1;
int turn = 0;
int maxTurns = ROWS * COLUMNS;

void initBoard() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("\n");
    for(int i = 0; i < ROWS; i++) {
        printf("|");
        for(int j = 0; j < COLUMNS; j++) {
            printf(" %c |",board[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------------\n");
    printf("  1   2   3   4   5   6   7  \n");
    printf("-----------------------------\n");
}

int checkWin() {
    // Check horizontal
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS - 3; j++) {
            if(board[i][j] == board[i][j+1] && board[i][j] == board[i][j+2] && board[i][j] == board[i][j+3] && board[i][j] != ' ') {
                return 1;
            }
        }
    }
    // Check vertical
    for(int i = 0; i < ROWS - 3; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            if(board[i][j] == board[i+1][j] && board[i][j] == board[i+2][j] && board[i][j] == board[i+3][j] && board[i][j] != ' ') {
                return 1;
            }
        }
    }
    // Check diagonal (top left to bottom right)
    for(int i = 0; i < ROWS - 3; i++) {
        for(int j = 0; j < COLUMNS - 3; j++) {
            if(board[i][j] == board[i+1][j+1] && board[i][j] == board[i+2][j+2] && board[i][j] == board[i+3][j+3] && board[i][j] != ' ') {
                return 1;
            }
        }
    }
    // Check diagonal (bottom left to top right)
    for(int i = ROWS - 1; i >= 3; i--) {
        for(int j = 0; j < COLUMNS - 3; j++) {
            if(board[i][j] == board[i-1][j+1] && board[i][j] == board[i-2][j+2] && board[i][j] == board[i-3][j+3] && board[i][j] != ' ') {
                return 1;
            }
        }
    }
    return 0;
}

int placePiece(int column) {
    for(int i = ROWS - 1; i >= 0; i--) {
        if(board[i][column] == ' ') {
            if(player == 1) {
                board[i][column] = 'X';
                player = 2;
            }
            else {
                board[i][column] = 'O';
                player = 1;
            }
            return 1;
        }
    }
    return 0;
}

int main() {
    int column;

    initBoard();

    while(1) {
        turn++;

        printBoard();

        printf("Player %d, enter a column number (1-7): ", player);
        scanf("%d", &column);

        if(column < 1 || column > 7) {
            printf("Invalid column number.\n");
            continue;
        }

        if(!placePiece(column-1)) {
            printf("Column is full.\n");
            continue;
        }

        if(checkWin()) {
            printBoard();
            printf("Player %d wins!\n", player);
            break;
        }

        if(turn == maxTurns) {
            printBoard();
            printf("It is a draw.\n");
            break;
        }
    }

    return 0;
}