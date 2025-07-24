//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

// function to print the Tic Tac Toe board
void printBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// function to check if the game is over
int isOver(char board[SIZE][SIZE]) {
    // check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    // check columns
    for (int i = 0; i < SIZE; i++) {
        if (board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    // check diagonals
    if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    // check if board is full
    int isFull = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == '-') {
                isFull = 0;
            }
        }
    }
    if (isFull) {
        return 2;
    }
    return 0;
}

// function to make a random move
void makeRandomMove(char board[SIZE][SIZE], char player) {
    int row, col;
    do {
        row = rand() % SIZE;
        col = rand() % SIZE;
    } while (board[row][col] != '-');
    board[row][col] = player;
}

// function to get the score of a move
int getMoveScore(char board[SIZE][SIZE], int row, int col, char player) {
    int score = 0;
    // check row
    if (board[row][0] == '-' && board[row][1] == player && board[row][2] == player) {
        score += 10;
    }
    if (board[row][0] == player && board[row][1] == '-' && board[row][2] == player) {
        score += 10;
    }
    if (board[row][0] == player && board[row][1] == player && board[row][2] == '-') {
        score += 10;
    }
    // check column
    if (board[0][col] == '-' && board[1][col] == player && board[2][col] == player) {
        score += 10;
    }
    if (board[0][col] == player && board[1][col] == '-' && board[2][col] == player) {
        score += 10;
    }
    if (board[0][col] == player && board[1][col] == player && board[2][col] == '-') {
        score += 10;
    }
    // check diagonal
    if (row == col) {
        if (board[0][0] == '-' && board[1][1] == player && board[2][2] == player) {
            score += 10;
        }
        if (board[0][0] == player && board[1][1] == '-' && board[2][2] == player) {
            score += 10;
        }
        if (board[0][0] == player && board[1][1] == player && board[2][2] == '-') {
            score += 10;
        }
    }
    if (row + col == 2) {
        if (board[0][2] == '-' && board[1][1] == player && board[2][0] == player) {
            score += 10;
        }
        if (board[0][2] == player && board[1][1] == '-' && board[2][0] == player) {
            score += 10;
        }
        if (board[0][2] == player && board[1][1] == player && board[2][0] == '-') {
            score += 10;
        }
    }
    return score;
}

// function to make an optimal move
void makeOptimalMove(char board[SIZE][SIZE], char player) {
    int bestScore = -1;
    int bestRow = -1;
    int bestCol = -1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == '-') {
                int score = getMoveScore(board, i, j, player);
                if (score > bestScore) {
                    bestScore = score;
                    bestRow = i;
                    bestCol = j;
                }
            }
        }
    }
    board[bestRow][bestCol] = player;
}

int main() {
    char board[SIZE][SIZE];
    // initialize board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '-';
        }
    }
    // randomly decide who goes first
    srand(time(NULL));
    char player = rand() % 2 == 0 ? 'X' : 'O';
    while (1) {
        printBoard(board);
        int result = isOver(board);
        if (result == 1) {
            printf("%c wins!\n", player);
            break;
        } else if (result == 2) {
            printf("It's a tie!\n");
            break;
        }
        if (player == 'X') {
            makeOptimalMove(board, player);
        } else {
            makeRandomMove(board, player);
        }
        player = player == 'X' ? 'O' : 'X';
    }
    return 0;
}