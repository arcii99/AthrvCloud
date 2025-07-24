//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: decentralized
#include <stdio.h>

#define SIZE 3

void printBoard(char board[SIZE][SIZE]) {
    // Prints the board
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("---|---|---\n");
        }
    }

    printf("\n");
}

int isWin(char board[SIZE][SIZE], char player) {
    // Checks if player has won
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    for (int i = 0; i < SIZE; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

int minimax(char board[SIZE][SIZE], int depth, int isMax, char player) {
    // Minimax algorithm
    int score;
    int bestScore;

    if (isWin(board, 'X')) {
        return -10;
    }

    if (isWin(board, 'O')) {
        return 10;
    }

    if (depth == 0) {
        return 0;
    }

    if (isMax) {
        bestScore = -1000;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == '_') {
                    board[i][j] = player;
                    score = minimax(board, depth - 1, !isMax, player);
                    if (score > bestScore) {
                        bestScore = score;
                    }
                    board[i][j] = '_';
                }
            }
        }
        return bestScore;
    } else {
        bestScore = 1000;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == '_') {
                    board[i][j] = player;
                    score = minimax(board, depth - 1, !isMax, player);
                    if (score < bestScore) {
                        bestScore = score;
                    }
                    board[i][j] = '_';
                }
            }
        }
        return bestScore;
    }
}

void getBestMove(char board[SIZE][SIZE], int *row, int *col, char player) {
    // Gets best move using minimax algorithm
    int bestScore = -1000;
    int score;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == '_') {
                board[i][j] = player;
                score = minimax(board, 5, 0, player);
                if (score > bestScore) {
                    bestScore = score;
                    *row = i;
                    *col = j;
                }
                board[i][j] = '_';
            }
        }
    }
}

int main() {
    char board[SIZE][SIZE] = {
        {'_', '_', '_'},
        {'_', '_', '_'},
        {'_', '_', '_'}
    };

    int row, col;
    int moveNumber = 1;

    while (1) {
        printBoard(board);

        int isMax;
        char player;
        if (moveNumber % 2 == 1) {
            isMax = 1;
            player = 'O';
        } else {
            isMax = 0;
            player = 'X';
        }

        if (isWin(board, 'X')) {
            printf("Player X wins!\n");
            break;
        }

        if (isWin(board, 'O')) {
            printf("Player O wins!\n");
            break;
        }

        if (moveNumber > 9) {
            printf("It's a tie!\n");
            break;
        }

        if (isMax) {
            getBestMove(board, &row, &col, player);
            board[row][col] = player;
            printf("Move %d: Player O chooses row %d, column %d\n", moveNumber, row + 1, col + 1);
        } else {
            printf("Move %d: Enter row number (1-3) and column number (1-3) for player X separated by a space: ", moveNumber);
            scanf("%d %d", &row, &col);
            row--;
            col--;
            if (board[row][col] != '_') {
                printf("Invalid move. Please try again.\n");
                continue;
            }
            board[row][col] = player;
        }

        moveNumber++;
    }

    return 0;
}