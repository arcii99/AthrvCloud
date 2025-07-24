//FormAI DATASET v1.0 Category: Checkers Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE];
int playerTurn = 1;
int gameIsActive = 1;

void initializeBoard() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (i % 2 == j % 2) {
                if (i < 3) {
                    board[i][j] = 1;
                } else if (i > 4) {
                    board[i][j] = 2;
                } else {
                    board[i][j] = 0;
                }
            } else {
                board[i][j] = 0;
            }
        }
    }
}

void printBoard() {
    int i, j;
    printf("   ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", i+65);
    }
    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d  ", i+1);
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                printf(". ");
            } else if (board[i][j] == 1) {
                printf("O ");
            } else if (board[i][j] == 2) {
                printf("X ");
            } else if (board[i][j] == 3) {
                printf("* ");
            }
        }
        printf("%d", i+1);
        printf("\n");
    }
    printf("   ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", i+65);
    }
    printf("\n");
}

void makeMove(int fromX, int fromY, int toX, int toY) {
    if (board[toX][toY] != 0) {
        printf("Invalid move!\n");
        return;
    }
    if (playerTurn == 1 && board[fromX][fromY] != 1 && board[fromX][fromY] != 3) {
        printf("Invalid move!\n");
        return;
    }
    if (playerTurn == 2 && board[fromX][fromY] != 2 && board[fromX][fromY] != 3) {
        printf("Invalid move!\n");
        return;
    }
    if (abs(fromX - toX) != abs(fromY - toY)) {
        printf("Invalid move!\n");
        return;
    }
    if (abs(fromX - toX) != 1 && abs(fromX - toX) != 2) {
        printf("Invalid move!\n");
        return;
    }
    if (abs(fromY - toY) != 1 && abs(fromY - toY) != 2) {
        printf("Invalid move!\n");
        return;
    }
    if (abs(fromX - toX) == 2 && abs(fromY - toY) == 2) {
        if (playerTurn == 1 && board[(fromX+toX)/2][(fromY+toY)/2] == 2) {
            board[(fromX+toX)/2][(fromY+toY)/2] = 0;
        }
        if (playerTurn == 2 && board[(fromX+toX)/2][(fromY+toY)/2] == 1) {
            board[(fromX+toX)/2][(fromY+toY)/2] = 0;
        }
    }
    board[toX][toY] = board[fromX][fromY];
    board[fromX][fromY] = 0;
    if (playerTurn == 1 && toX == 7) {
        board[toX][toY] = 3;
    }
    if (playerTurn == 2 && toX == 0) {
        board[toX][toY] = 3;
    }
    if (playerTurn == 1) {
        playerTurn = 2;
    } else {
        playerTurn = 1;
    }
}

int main() {
    initializeBoard();
    printf("Welcome to Irregular Checkers!\n");
    printf("Player 1 is O, and Player 2 is X.\n");
    printf("To make a move, enter the coordinates of the piece you want to move and the place you want to move it to. For example, 'A3 B4'.\n");
    printf("If you make a double jump, enter the coordinates of each jump separately. For example, 'A3 C5 E7'.\n");
    while (gameIsActive) {
        printBoard();
        printf("Player %d's turn: ", playerTurn);
        char from[3], to[3];
        scanf("%s %s", from, to);
        int fromX = from[0] - 65;
        int fromY = from[1] - 49;
        int toX = to[0] - 65;
        int toY = to[1] - 49;
        if (strlen(from) == 2 && strlen(to) == 2) {
            makeMove(fromY, fromX, toY, toX);
        } else if (strlen(from) == 2 && strlen(to) == 4) {
            int jumpOneX = to[0] - 65;
            int jumpOneY = to[1] - 49;
            int jumpTwoX = to[2] - 65;
            int jumpTwoY = to[3] - 49;
            makeMove(fromY, fromX, jumpOneY, jumpOneX);
            makeMove(jumpOneY, jumpOneX, jumpTwoY, jumpTwoX);
        } else {
            printf("Invalid input!\n");
            continue;
        }
        int i, j, player1Count = 0, player2Count = 0;
        for (i = 0; i < BOARD_SIZE; i++) {
            for (j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == 1 || board[i][j] == 3) {
                    player1Count++;
                }
                if (board[i][j] == 2 || board[i][j] == 3) {
                    player2Count++;
                }
            }
        }
        if (player1Count == 0) {
            printf("Player 2 wins!\n");
            gameIsActive = 0;
        } else if (player2Count == 0) {
            printf("Player 1 wins!\n");
            gameIsActive = 0;
        }
    }
    return 0;
}