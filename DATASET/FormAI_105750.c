//FormAI DATASET v1.0 Category: Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printBoard(int board[10][10]) {
    printf("\nCurrent Board Position:\n");
    printf(" ------------------------\n");
    for (int i = 0; i < 10; i++) {
        printf("|");
        for (int j = 0; j < 10; j++) {
            if (board[i][j] == 0) {
                printf("  ");
            } else if (board[i][j] == 1) {
                printf(" X");
            } else if (board[i][j] == 2) {
                printf(" O");
            }
            if (j == 9) {
                printf("|\n");
            }
        }
    }
    printf(" ------------------------\n");
}

int checkWin(int board[10][10], int player) {
    int win = 0;
    // Check rows
    for (int i = 0; i < 10; i++) {
        int count = 0;
        for (int j = 0; j < 10; j++) {
            if (board[i][j] == player) {
                count++;
            } else {
                count = 0;
            }
            if (count >= 4) {
                win = 1;
            }
        }
    }
    // Check columns
    for (int i = 0; i < 10; i++) {
        int count = 0;
        for (int j = 0; j < 10; j++) {
            if (board[j][i] == player) {
                count++;
            } else {
                count = 0;
            }
            if (count >= 4) {
                win = 1;
            }
        }
    }
    // Check diagonals
    for (int i = 0; i <= 6; i++) {
        for (int j = 0; j <= 6; j++) {
            if (board[i][j] == player && board[i+1][j+1] == player && board[i+2][j+2] == player && board[i+3][j+3] == player) {
                win = 1;
            }
            if (board[i+3][j] == player && board[i+2][j+1] == player && board[i+1][j+2] == player && board[i][j+3] == player) {
                win = 1;
            }
        }
    }
    return win;
}

int main() {
    int board[10][10] = {0};
    int player1 = 1;
    int player2 = 2;
    int currentPlayer = player1;
    int move;
    srand(time(0));
    printf("Welcome to Futuristic Connect Four!\n");
    printf("Instructions: This game is played on a 10x10 board. Each player takes turns placing their piece, X or O, in the board. The first player to connect 4 of their pieces in a row, column, or diagonal wins!\n\n");
    printBoard(board);
    while (1) {
        printf("\nPlayer %d:\n", currentPlayer);
        if (currentPlayer == player1) {
            printf("Enter your move (0-9): ");
            scanf("%d", &move);
        } else {
            // AI player
            move = rand() % 10;
            printf("AI Player chooses move %d\n", move);
        }
        int row = 9;
        while (row >= 0) {
            if (board[row][move] == 0) {
                board[row][move] = currentPlayer;
                break;
            }
            row--;
        }
        if (checkWin(board, currentPlayer) == 1) {
            printf("Player %d wins!\n", currentPlayer);
            break;
        }
        printBoard(board);
        if (currentPlayer == player1) {
            currentPlayer = player2;
        } else {
            currentPlayer = player1;
        }
    }
    return 0;
}