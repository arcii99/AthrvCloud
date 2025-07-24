//FormAI DATASET v1.0 Category: Checkers Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

void printBoard(char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void initializeBoard(char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i < 3 && (i + j) % 2 == 0) {
                board[i][j] = 'x';
            } else if (i > 4 && (i + j) % 2 == 0) {
                board[i][j] = 'o';
            } else {
                board[i][j] = '-';
            }
        }
    }
}

int isMoveValid(char board[][BOARD_SIZE], int startX, int startY, int endX, int endY, char player) {
    if (endX < 0 || endY < 0 || endX >= BOARD_SIZE || endY >= BOARD_SIZE) {
        return 0;
    }
    if (board[endX][endY] != '-') {
        return 0;
    }
    if (player == 'x') {
        if (startX - endX == 1 && abs(startY - endY) == 1 && board[startX][startY] == 'x') {
            return 1;
        } else if (startX - endX == 2 && abs(startY - endY) == 2 && board[startX - 1][(startY + endY) / 2] == 'o' && board[startX][startY] == 'x') {
            board[startX - 1][(startY + endY) / 2] = '-';
            return 1;
        }
    } else if (player == 'o') {
        if (endX - startX == 1 && abs(startY - endY) == 1 && board[startX][startY] == 'o') {
            return 1;
        } else if (endX - startX == 2 && abs(startY - endY) == 2 && board[startX + 1][(startY + endY) / 2] == 'x' && board[startX][startY] == 'o') {
            board[startX + 1][(startY + endY) / 2] = '-';
            return 1;
        }
    }
    return 0;
}

int isGameOver(char board[][BOARD_SIZE], char player) {
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == player || board[i][j] == toupper(player)) {
                if (player == 'x') {
                    if (isMoveValid(board, i, j, i - 1, j - 1, player)) {
                        count++;
                    }
                    if (isMoveValid(board, i, j, i - 1, j + 1, player)) {
                        count++;
                    }
                    if (isMoveValid(board, i, j, i - 2, j - 2, player)) {
                        count++;
                    }
                    if (isMoveValid(board, i, j, i - 2, j + 2, player)) {
                        count++;
                    }
                } else if (player == 'o') {
                    if (isMoveValid(board, i, j, i + 1, j - 1, player)) {
                        count++;
                    }
                    if (isMoveValid(board, i, j, i + 1, j + 1, player)) {
                        count++;
                    }
                    if (isMoveValid(board, i, j, i + 2, j - 2, player)) {
                        count++;
                    }
                    if (isMoveValid(board, i, j, i + 2, j + 2, player)) {
                        count++;
                    }
                }
            }
        }
    }
    return count == 0;
}

void togglePlayer(char *player) {
    if (*player == 'x') {
        *player = 'o';
    } else {
        *player = 'x';
    }
}

int main() {

    char board[BOARD_SIZE][BOARD_SIZE];
    char player = 'x';
    int startX, startY, endX, endY;

    initializeBoard(board);

    while (!isGameOver(board, player)) {

        printBoard(board);

        printf("Player %c's turn\n", player);

        do {
            printf("Enter the starting position (row, column): ");
            scanf("%d%d", &startX, &startY);
            printf("Enter the ending position (row, column): ");
            scanf("%d%d", &endX, &endY);
        } while (!isMoveValid(board, startX, startY, endX, endY, player));

        board[endX][endY] = board[startX][startY];
        board[startX][startY] = '-';

        if ((player == 'x' && endX == 0) || (player == 'o' && endX == BOARD_SIZE - 1)) {
            board[endX][endY] = toupper(player);
        }

        togglePlayer(&player);
    }

    printBoard(board);

    if (player == 'x') {
        printf("Player o wins!\n");
    } else {
        printf("Player x wins!\n");
    }

    return 0;
}