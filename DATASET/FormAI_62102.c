//FormAI DATASET v1.0 Category: Chess AI ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8
#define AI_DEPTH 3

typedef int bool;
#define true 1
#define false 0

int board[BOARD_SIZE][BOARD_SIZE];
int aiColor;

void printBoard() {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", i + 'a');
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                printf(". ");
            } else if (board[i][j] == 1) {
                printf("o ");
            } else if (board[i][j] == -1) {
                printf("x ");
            }
        }
        printf("%d\n", BOARD_SIZE - i);
    }

    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", i + 'a');
    }
    printf("\n");
}

bool isOutOfBounds(int x, int y) {
    return x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE;
}

bool isValidMove(int color, int x, int y) {
    if (isOutOfBounds(x, y) || board[x][y] != 0) {
        return false;
    }

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};

    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        bool foundOpponent = false;
        while (!isOutOfBounds(tx, ty) && board[tx][ty] == -color) {
            tx += dx[i];
            ty += dy[i];
            foundOpponent = true;
        }
        if (!isOutOfBounds(tx, ty) && board[tx][ty] == color && foundOpponent) {
            return true;
        }
    }

    return false;
}

void makeMove(int color, int x, int y) {
    board[x][y] = color;

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};

    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        bool foundOpponent = false;
        while (!isOutOfBounds(tx, ty) && board[tx][ty] == -color) {
            tx += dx[i];
            ty += dy[i];
            foundOpponent = true;
        }
        if (!isOutOfBounds(tx, ty) && board[tx][ty] == color && foundOpponent) {
            tx -= dx[i];
            ty -= dy[i];
            while (tx != x || ty != y) {
                board[tx][ty] = color;
                tx -= dx[i];
                ty -= dy[i];
            }
        }
    }
}

int evaluateBoard() {
    int score = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == aiColor) {
                score++;
            } else if (board[i][j] == -aiColor) {
                score--;
            }
        }
    }
    return score;
}

int miniMax(int color, int depth, int alpha, int beta) {
    if (depth == 0) {
        return evaluateBoard();
    }

    int bestScore = color * -1000;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (isValidMove(color, i, j)) {
                int score;
                makeMove(color, i, j);
                if (color == aiColor) {
                    score = miniMax(-aiColor, depth - 1, alpha, beta);
                    if (score > bestScore) {
                        bestScore = score;
                    }
                    if (score > alpha) {
                        alpha = score;
                    }
                } else {
                    score = miniMax(-aiColor, depth - 1, alpha, beta);
                    if (score < bestScore) {
                        bestScore = score;
                    }
                    if (score < beta) {
                        beta = score;
                    }
                }
                board[i][j] = 0;
                if (alpha >= beta) {
                    return bestScore;
                }
            }
        }
    }

    return bestScore;
}

void makeAiMove() {
    int bestScore = aiColor * -1000;
    int bestX = -1;
    int bestY = -1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (isValidMove(aiColor, i, j)) {
                makeMove(aiColor, i, j);
                int score = miniMax(-aiColor, AI_DEPTH - 1, -1000, 1000);
                if (score > bestScore) {
                    bestScore = score;
                    bestX = i;
                    bestY = j;
                }
                board[i][j] = 0;
            }
        }
    }

    makeMove(aiColor, bestX, bestY);
    printf("AI played %c%d\n", bestY + 'a', BOARD_SIZE - bestX);
}

int main() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }

    board[BOARD_SIZE/2 - 1][BOARD_SIZE/2 - 1] = 1;
    board[BOARD_SIZE/2][BOARD_SIZE/2] = 1;
    board[BOARD_SIZE/2 - 1][BOARD_SIZE/2] = -1;
    board[BOARD_SIZE/2][BOARD_SIZE/2 - 1] = -1;

    aiColor = -1;

    printf("Welcome to Chess AI\n");
    printf("You are playing as o\n");
    printf("The AI is playing as x\n");

    printBoard();

    while (true) {
        bool canMove = false;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (isValidMove(1, i, j)) {
                    canMove = true;
                    break;
                }
            }
        }

        if (!canMove) {
            printf("You cannot move, AI wins!\n");
            return 0;
        }

        char input[10];
        int x, y;
        while (true) {
            printf("Enter your move (e.g. d3): ");
            scanf("%s", input);
            x = BOARD_SIZE - (input[1] - '0');
            y = input[0] - 'a';
            if (isValidMove(1, x, y)) {
                break;
            }
            printf("Invalid move\n");
        }
        makeMove(1, x, y);
        printBoard();

        canMove = false;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (isValidMove(-1, i, j)) {
                    canMove = true;
                    break;
                }
            }
        }

        if (!canMove) {
            printf("AI cannot move, you win!\n");
            return 0;
        }

        printf("AI is thinking...\n");
        makeAiMove();
        printBoard();
    }

    return 0;
}