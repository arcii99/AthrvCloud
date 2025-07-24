//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define BOARDSIZE 3
#define PLAYER_1 'X'
#define PLAYER_2 'O'
#define EMPTY_SQUARE '-'

char board[BOARDSIZE][BOARDSIZE];

void clearBoard() {
    for (int row = 0; row < BOARDSIZE; row++) {
        for (int col = 0; col < BOARDSIZE; col++) {
            board[row][col] = EMPTY_SQUARE;
        }
    }
}

void printBoard() {
    printf("\n");
    for (int row = 0; row < BOARDSIZE; row++) {
        for (int col = 0; col < BOARDSIZE; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

int gameIsOver(char player) {
    // Check rows
    for (int row = 0; row < BOARDSIZE; row++) {
        int matches = 0;
        for (int col = 0; col < BOARDSIZE; col++) {
            if (board[row][col] == player) matches++;
            else break;
        }
        if (matches == BOARDSIZE) return 1;
    }

    // Check columns
    for (int col = 0; col < BOARDSIZE; col++) {
        int matches = 0;
        for (int row = 0; row < BOARDSIZE; row++) {
            if (board[row][col] == player) matches++;
            else break;
        }
        if (matches == BOARDSIZE) return 1;
    }

    // Check diagonals
    int matches = 0;
    for (int diag = 0; diag < BOARDSIZE; diag++) {
        if (board[diag][diag] == player) matches++;
        else break;
    }
    if (matches == BOARDSIZE) return 1;

    matches = 0;
    for (int diag = 0; diag < BOARDSIZE; diag++) {
        if (board[diag][BOARDSIZE - diag - 1] == player) matches++;
        else break;
    }
    if (matches == BOARDSIZE) return 1;

    return 0;
}

int playerHasMove(char player) {
    for (int row = 0; row < BOARDSIZE; row++) {
        for (int col = 0; col < BOARDSIZE; col++) {
            if (board[row][col] == EMPTY_SQUARE) return 1;
        }
    }
    return 0;
}

int evaluateBoard() {
    if (gameIsOver(PLAYER_1)) return 10;
    if (gameIsOver(PLAYER_2)) return -10;
    return 0;
}

int minimax(char player) {
    int score = evaluateBoard();

    if (score == 10 || score == -10) return score;

    if (!playerHasMove(player)) return 0;

    int bestScore = (player == PLAYER_1) ? -1000 : 1000;

    for (int row = 0; row < BOARDSIZE; row++) {
        for (int col = 0; col < BOARDSIZE; col++) {
            if (board[row][col] == EMPTY_SQUARE) {
                board[row][col] = player;

                if (player == PLAYER_1) {
                    bestScore = (bestScore > minimax(PLAYER_2)) ? bestScore : minimax(PLAYER_2);
                } else {
                    bestScore = (bestScore < minimax(PLAYER_1)) ? bestScore : minimax(PLAYER_1);
                }

                board[row][col] = EMPTY_SQUARE;
            }
        }
    }

    return bestScore;
}

void makeBestMove(char player) {
    int bestScore = -1000;
    int bestRow = -1;
    int bestCol = -1;

    for (int row = 0; row < BOARDSIZE; row++) {
        for (int col = 0; col < BOARDSIZE; col++) {
            if (board[row][col] == EMPTY_SQUARE) {
                board[row][col] = player;
                int moveScore = minimax((player == PLAYER_1) ? PLAYER_2 : PLAYER_1);
                board[row][col] = EMPTY_SQUARE;

                if (moveScore > bestScore) {
                    bestScore = moveScore;
                    bestRow = row;
                    bestCol = col;
                }
            }
        }
    }

    board[bestRow][bestCol] = player;
}

int main() {
    clearBoard();

    while (playerHasMove(PLAYER_1) && !gameIsOver(PLAYER_1) && !gameIsOver(PLAYER_2)) {
        printBoard();

        int row, col;
        printf("Player 1, enter row and column (1-3): ");
        scanf("%d %d", &row, &col);
        row--; col--;

        if (board[row][col] != EMPTY_SQUARE) {
            printf("Square is already taken, try again.\n");
            continue;
        }

        board[row][col] = PLAYER_1;

        if (!playerHasMove(PLAYER_2) || gameIsOver(PLAYER_1) || gameIsOver(PLAYER_2)) break;

        makeBestMove(PLAYER_2);

        if (gameIsOver(PLAYER_1) || gameIsOver(PLAYER_2)) break;
    }

    printBoard();

    if (gameIsOver(PLAYER_1)) {
        printf("Congratulations, you won!\n");
    }
    else if (gameIsOver(PLAYER_2)) {
        printf("Sorry, you lost. Try again!\n");
    }
    else {
        printf("It's a tie. Good game!\n");
    }

    return 0;
}