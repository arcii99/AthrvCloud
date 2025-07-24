//FormAI DATASET v1.0 Category: Chess AI ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Constants
#define BOARD_SIZE 8
#define MAX_DEPTH 3

// Global Variables
int evaluationTable[BOARD_SIZE][BOARD_SIZE] = { { 50, -10, 10, 5, 5, 10, -10, 50 },
                                           { -10, -20, -5, -5, -5, -5, -20, -10 },
                                           { 10, -5, -5, -2, -2, -5, -5, 10 },
                                           { 5, -5, -2, -1, -1, -2, -5, 5 },
                                           { 5, -5, -2, -1, -1, -2, -5, 5 },
                                           { 10, -5, -5, -2, -2, -5, -5, 10 },
                                           { -10, -20, -5, -5, -5, -5, -20, -10 },
                                           { 50, -10, 10, 5, 5, 10, -10, 50 } };
char board[BOARD_SIZE][BOARD_SIZE] = { { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' },
                                    { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
                                    { '.', '.', '.', '.', '.', '.', '.', '.' },
                                    { '.', '.', '.', '.', '.', '.', '.', '.' },
                                    { '.', '.', '.', '.', '.', '.', '.', '.' },
                                    { '.', '.', '.', '.', '.', '.', '.', '.' },
                                    { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
                                    { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' } };
int max(int a, int b) { return (a > b) ? a : b; }
int min(int a, int b) { return (a < b) ? a : b; }
int evaluate() {
    int whiteScore = 0, blackScore = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == '.')
                continue;
            int currentScore = 0;
            if (isupper(board[i][j]))
                currentScore = evaluationTable[i][j];
            else
                currentScore = evaluationTable[BOARD_SIZE - i - 1][BOARD_SIZE - j - 1];
            if (isupper(board[i][j]))
                whiteScore += currentScore;
            else
                blackScore += currentScore;
        }
    }
    return whiteScore - blackScore;
}
bool isInBounds(int x, int y) {
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}
bool isKing(int x, int y, char player) {
    return toupper(player) == 'K' && toupper(board[x][y]) == 'K';
}
bool isPseudoLegalMove(int startX, int startY, int endX, int endY, char player) {
    char piece = board[startX][startY];
    if (piece == '.')
        return false;
    if (isupper(piece) != isupper(player))
        return false;
    if (piece == 'P') {
        if (startX == 1 && endX == 3 && board[2][endY] == '.') {
            return true;
        } else if (startX + 1 == endX) {
            if (startY == endY && board[endX][endY] == '.')
                return true;
            else if (abs(startY - endY) == 1 && islower(board[endX][endY]))
                return true;
        }
    } else if (piece == 'p') {
        if (startX == 6 && endX == 4 && board[5][endY] == '.') {
            return true;
        }
        else if (startX - 1 == endX) {
            if (startY == endY && board[endX][endY] == '.')
                return true;
            else if (abs(startY - endY) == 1 && isupper(board[endX][endY]))
                return true;
        }
    } else if (piece == 'K' || piece == 'k') {
        if (abs(startX - endX) + abs(startY - endY) == 1 || (abs(startX - endX) + abs(startY - endY) == 2 && abs(startX - endX) != 0 && abs(startY - endY) != 0))
            return true;
    } else if (piece == 'Q' || piece == 'q') {
        if (startX == endX || startY == endY || abs(startX - endX) == abs(startY - endY))
            return true;
    } else if (piece == 'R' || piece == 'r') {
        if (startX == endX || startY == endY)
            return true;
    } else if (piece == 'B' || piece == 'b') {
        if (abs(startX - endX) == abs(startY - endY))
            return true;
    } else if (piece == 'N' || piece == 'n') {
        if (abs(startX - endX) * abs(startY - endY) == 2)
            return true;
    }
    return false;
}
bool canMove(char player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == '.')
                continue;
            if (isupper(board[i][j]) == isupper(player)) {
                for (int k = 0; k < BOARD_SIZE; k++) {
                    for (int l = 0; l < BOARD_SIZE; l++) {
                        if (isPseudoLegalMove(i, j, k, l, player))
                            if (isKing(k, l, player) || board[k][l] == '.')
                                return true;
                    }
                }
            }
        }
    }
    return false;
}
void move(int startX, int startY, int endX, int endY) {
    board[endX][endY] = board[startX][startY];
    board[startX][startY] = '.';
}
void undoMove(int startX, int startY, int endX, int endY, char captured) {
    board[startX][startY] = board[endX][endY];
    board[endX][endY] = captured;
}
int alphaBeta(int depth, int alpha, int beta, char player) {
    if (depth == 0)
        return evaluate();
    int bestValue = -9999;
    char tempBoard[BOARD_SIZE][BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == '.')
                continue;
            if (isupper(board[i][j]) == isupper(player)) {
                for (int k = 0; k < BOARD_SIZE; k++) {
                    for (int l = 0; l < BOARD_SIZE; l++) {
                        if (isPseudoLegalMove(i, j, k, l, player)) {
                            if (isKing(k, l, player) || board[k][l] == '.') {
                                char captured = board[k][l];
                                move(i, j, k, l);
                                int currentValue = -alphaBeta(depth - 1, -beta, -alpha, tolower(player));
                                undoMove(i, j, k, l, captured);
                                if (currentValue > bestValue)
                                    bestValue = currentValue;
                                if (bestValue > alpha)
                                    alpha = bestValue;
                                if (bestValue >= beta)
                                    return bestValue;
                            }
                        }
                    }
                }
            }
        }
    }
    return bestValue;
}
void makeMove() {
    int bestValue = -9999;
    int currentBestValue;
    int startX, startY, endX, endY;
    char captured;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == '.')
                continue;
            if (isupper(board[i][j])) {
                for (int k = 0; k < BOARD_SIZE; k++) {
                    for (int l = 0; l < BOARD_SIZE; l++) {
                        if (isPseudoLegalMove(i, j, k, l, 'w')) {
                            if (isKing(k, l, 'w') || board[k][l] == '.') {
                                captured = board[k][l];
                                move(i, j, k, l);
                                currentBestValue = alphaBeta(MAX_DEPTH, -9999, 9999, 'b');
                                undoMove(i, j, k, l, captured);
                                if (currentBestValue > bestValue) {
                                    bestValue = currentBestValue;
                                    startX = i;
                                    startY = j;
                                    endX = k;
                                    endY = l;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("Computer moves piece at (%d, %d) to (%d, %d)\n", startX, startY, endX, endY);
    move(startX, startY, endX, endY);
}
int main() {
    printf("Welcome to Chess!\n");
    printf("Valid moves are entered as (start x, start y, end x, end y)\n");
    printf("The computer plays as Black (lowercase pieces)\n");
    while (true) {
        printf("Current position:\n\n");
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++)
                printf("%c ", board[i][j]);
            printf("\n");
        }
        if (!canMove('w')) {
            printf("White is in Checkmate! Black wins.\n");
            break;
        }
        if (!canMove('b')) {
            printf("Black is in Checkmate! White wins.\n");
            break;
        }
        int startX, startY, endX, endY;
        printf("Enter your move: ");
        scanf("%d%d%d%d", &startX, &startY, &endX, &endY);
        if (isPseudoLegalMove(startX, startY, endX, endY, 'w')) {
            char captured = board[endX][endY];
            move(startX, startY, endX, endY);
            if (!canMove('b')) {
                printf("White is in Checkmate! White wins.\n");
                break;
            }
            printf("Computer is thinking...\n");
            makeMove();
            if (!canMove('w')) {
                printf("Black is in Checkmate! Black wins.\n");
                break;
            }
        }
        else {
            printf("Invalid move. Please try again.\n");
        }
    }
    return 0;
}