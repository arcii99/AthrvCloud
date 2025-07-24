//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];

void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i != BOARD_SIZE - 1) {
            printf("\n---|---|---\n");
        }
    }
    printf("\n");
}

bool isValidMove(int row, int col) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        return false;
    }
    if (board[row][col] != ' ') {
        return false;
    }
    return true;
}

bool isBoardFull() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool isGameOver() {
    // check if any row has all Xs or Os
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }
    // check if any column has all Xs or Os
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }
    // check if any diagonal has all Xs or Os
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    // check if board is full
    if (isBoardFull()) {
        return true;
    }
    return false;
}

int getScore(char player) {
    if (player == 'X') {
        return 10;
    }
    if (player == 'O') {
        return -10;
    }
    return 0;
}

int miniMax(char player) {
    if (isGameOver()) {
        return getScore(player);
    }
    int bestScore;
    if (player == 'X') {
        bestScore = -1000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X';
                    int score = miniMax('O');
                    board[i][j] = ' ';
                    if (score > bestScore) {
                        bestScore = score;
                    }
                }
            }
        }
    } else {
        bestScore = 1000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    int score = miniMax('X');
                    board[i][j] = ' ';
                    if (score < bestScore) {
                        bestScore = score;
                    }
                }
            }
        }
    }
    return bestScore;
}

void makeMove(char player) {
    if (player == 'X') {
        printf("Enter X move (row,col): ");
    } else {
        printf("Enter O move (row,col): ");
    }
    int row, col;
    scanf("%d,%d", &row, &col);
    if (isValidMove(row, col)) {
        board[row][col] = player;
    } else {
        printf("Invalid move, try again.\n");
        makeMove(player);
    }
}

void playGame() {
    while (!isGameOver()) {
        printBoard();
        makeMove('X');
        if (!isGameOver()) {
            int bestScore = 1000;
            int bestRow = -1, bestCol = -1;
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    if (board[i][j] == ' ') {
                        board[i][j] = 'O';
                        int score = miniMax('X');
                        board[i][j] = ' ';
                        if (score < bestScore) {
                            bestScore = score;
                            bestRow = i;
                            bestCol = j;
                        }
                    }
                }
            }
            board[bestRow][bestCol] = 'O';
        }
    }
    printBoard();
    if (getScore('X') > 0) {
        printf("X wins!\n");
    } else if (getScore('O') < 0) {
        printf("O wins!\n");
    } else {
        printf("Draw!\n");
    }
}

int main() {
    initializeBoard();
    playGame();
    return 0;
}