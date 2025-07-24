//FormAI DATASET v1.0 Category: Checkers Game ; Style: asynchronous
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define BLACK 0
#define WHITE 1
#define EMPTY 2

bool isMoveValid(int board[BOARD_SIZE][BOARD_SIZE], int turn, int startX, int startY, int endX, int endY) {
    // check if starting position is valid
    if (board[startX][startY] != turn) {
        return false;
    }

    // check if end position is within board boundaries
    if (endX < 0 || endX > BOARD_SIZE - 1 || endY < 0 || endY > BOARD_SIZE - 1) {
        return false;
    }

    // check if end position is empty
    if (board[endX][endY] != EMPTY) {
        return false;
    }

    // check if move is a diagonal move
    int xDiff = abs(startX - endX);
    int yDiff = abs(startY - endY);
    if (xDiff != yDiff) {
        return false;
    }

    // check if move is a single or double move
    if (xDiff == 1) {
        return true;    // single move
    } else if (xDiff == 2) {
        // capture move
        int captureX = (startX + endX) / 2;
        int captureY = (startY + endY) / 2;

        if (board[captureX][captureY] == turn) {
            return false;   // can't capture own pieces
        } else {
            return true;
        }
    } else {
        return false;   // can't move more than 2 tiles diagonally
    }
}

bool hasValidMoves(int board[BOARD_SIZE][BOARD_SIZE], int turn) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == turn) {
                // check all four diagonal directions for valid moves
                if (isMoveValid(board, turn, i, j, i+1, j+1)
                    || isMoveValid(board, turn, i, j, i+1, j-1)
                    || isMoveValid(board, turn, i, j, i-1, j+1)
                    || isMoveValid(board, turn, i, j, i-1, j-1)) {
                    return true;
                }
            }
        }
    }

    return false;
}

int getOpponent(int player) {
    return player == BLACK ? WHITE : BLACK;
}

void printBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    printf("     0  1  2  3  4  5  6  7\n");
    printf("   +-----------------------+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" %d |", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
                case BLACK:
                    printf(" B ");
                    break;
                case WHITE:
                    printf(" W ");
                    break;
                case EMPTY:
                    printf(" . ");
                    break;
            }
            printf("|");
        }
        printf("\n");
        printf("   +-----------------------+\n");
    }
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {
            {EMPTY, WHITE, EMPTY, WHITE, EMPTY, WHITE, EMPTY, WHITE},
            {WHITE, EMPTY, WHITE, EMPTY, WHITE, EMPTY, WHITE, EMPTY},
            {EMPTY, WHITE, EMPTY, WHITE, EMPTY, WHITE, EMPTY, WHITE},
            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
            {BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY},
            {EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK},
            {BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY}
    };

    int turn = BLACK;

    printBoard(board);

    while (true) {
        int startX, startY, endX, endY;

        printf("Player %d's turn\n", turn);
        printf("Enter start position (x y): ");
        scanf("%d %d", &startX, &startY);
        printf("Enter end position (x y): ");
        scanf("%d %d", &endX, &endY);

        if (isMoveValid(board, turn, startX, startY, endX, endY)) {
            board[endX][endY] = turn;
            board[startX][startY] = EMPTY;

            // capture move
            if (abs(startX - endX) == 2) {
                int captureX = (startX + endX) / 2;
                int captureY = (startY + endY) / 2;
                board[captureX][captureY] = EMPTY;
            }

            printBoard(board);

            // check for win
            if (!hasValidMoves(board, getOpponent(turn))) {
                printf("Player %d wins!\n", turn);
                break;
            }

            // switch turn to other player
            turn = getOpponent(turn);
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}