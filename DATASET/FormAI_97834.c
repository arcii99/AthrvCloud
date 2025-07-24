//FormAI DATASET v1.0 Category: Checkers Game ; Style: Linus Torvalds
#include <stdio.h>

#define BOARD_SIZE 8

#define BLACK 'B'
#define WHITE 'W'
#define EMPTY '.'

#define MOVE_VALID 0
#define MOVE_OUT_OF_BOUNDS 1
#define MOVE_OCCUPIED 2

#define TURN_BLACK 0
#define TURN_WHITE 1

#define MAX_MOVES 60

char gameBoard[BOARD_SIZE][BOARD_SIZE] = {0};
char turn = TURN_BLACK;
int numMoves = 0;

struct Move {
    int fromX;
    int fromY;
    int toX;
    int toY;
};
struct Move moves[MAX_MOVES];

int checkMove(int fromX, int fromY, int toX, int toY) {
    if (toX < 0 || toX >= BOARD_SIZE || toY < 0 || toY >= BOARD_SIZE) {
        return MOVE_OUT_OF_BOUNDS;
    }

    if (gameBoard[toX][toY] != EMPTY) {
        return MOVE_OCCUPIED;
    }

    if (fromY == toY) {
        if ((fromX - toX) == 1 || (toX - fromX) == 1) {
            return MOVE_VALID;
        }
    } else if (fromX == toX) {
        if ((fromY - toY) == 1 || (toY - fromY) == 1) {
            return MOVE_VALID;
        }
    }

    return MOVE_OCCUPIED;
}

void play(struct Move move) {
    int result = checkMove(move.fromX, move.fromY, move.toX, move.toY);
    if (result == MOVE_VALID) {
        gameBoard[move.toX][move.toY] = gameBoard[move.fromX][move.fromY];
        gameBoard[move.fromX][move.fromY] = EMPTY;

        moves[numMoves++] = move;

        if (turn == TURN_BLACK) {
            turn = TURN_WHITE;
        } else {
            turn = TURN_BLACK;
        }
    } else {
        printf("Invalid move\n");
    }
}

void printBoard() {
    int i, j;
    for (i = BOARD_SIZE - 1; i >= 0; i--) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", gameBoard[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            gameBoard[i][j] = EMPTY;
        }
    }

    for (i = 0; i < BOARD_SIZE; i++) {
        if (i < 3) {
            for (j = 0; j < BOARD_SIZE; j++) {
                if ((i + j) % 2 == 1) {
                    gameBoard[i][j] = BLACK;
                }
            }
        } else if (i >= 5) {
            for (j = 0; j < BOARD_SIZE; j++) {
                if ((i + j) % 2 == 1) {
                    gameBoard[i][j] = WHITE;
                }
            }
        }
    }

    printBoard();

    struct Move testMove = {
        .fromX = 5,
        .fromY = 1,
        .toX = 4,
        .toY = 0
    };

    play(testMove);

    printBoard();

    return 0;
}