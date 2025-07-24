//FormAI DATASET v1.0 Category: Chess AI ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

#define BOARD_SIZE 8

#define PAWN 'P'
#define KNIGHT 'N'
#define BISHOP 'B'
#define ROOK 'R'
#define QUEEN 'Q'
#define KING 'K'

#define WHITESIDE 'W'
#define BLACKSIDE 'B'

char sideToMove = WHITESIDE; // Initially, white moves first.

char board[BOARD_SIZE][BOARD_SIZE] = {
    {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK},
    {PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN},
    {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK}
};

// Returns 1 if move is legal, 0 otherwise.
int isLegalMove(int srcX, int srcY, int destX, int destY) {
    if (srcX < 0 || srcX >= BOARD_SIZE ||
        srcY < 0 || srcY >= BOARD_SIZE ||
        destX < 0 || destX >= BOARD_SIZE ||
        destY < 0 || destY >= BOARD_SIZE ||
        board[srcX][srcY] == ' ' || // Empty squares cannot move.
        (board[srcX][srcY] == PAWN && (destX == srcX || abs(destY - srcY) > 1)) || // Pawns can only move forward one square, except on their first move they can move two squares.
        (board[srcX][srcY] == PAWN && sideToMove == WHITESIDE && destX <= srcX) || // White pawns can only move upward.
        (board[srcX][srcY] == PAWN && sideToMove == BLACKSIDE && destX >= srcX) || // Black pawns can only move downward.
        (board[srcX][srcY] == KNIGHT && (abs(destX - srcX) + abs(destY - srcY) != 3 || abs(destX - srcX) > 2 || abs(destY - srcY) > 2)) ||  // Knight can move 2 steps in one direction and 1 in other
        (board[srcX][srcY] == BISHOP && (abs(destX - srcX) != abs(destY - srcY))) || // Bishop can move only diagonally
        (board[srcX][srcY] == ROOK && (destX != srcX && destY != srcY)) || // Rook can move in straight line
        (board[srcX][srcY] == QUEEN && (abs(destX - srcX) != abs(destY - srcY)) && destX != srcX && destY != srcY) ||
        (board[srcX][srcY] == KING && (abs(destX - srcX) > 1 || abs(destY - srcY) > 1))) { // King can move only one square in any direction.
        return 0;
    }
    return 1;
}

void makeMove(int srcX, int srcY, int destX, int destY) {
    if (!isLegalMove(srcX, srcY, destX, destY)) {
        return;
    }
    board[destX][destY] = board[srcX][srcY];
    board[srcX][srcY] = ' ';
    sideToMove = (sideToMove == WHITESIDE) ? BLACKSIDE : WHITESIDE; // Switch sides.
}

void printBoard() {
    printf("  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("%d", i);
        printf("\n");
    }
    printf("  0 1 2 3 4 5 6 7\n");
}

int main() {
    srand(time(NULL)); // Use system time as seed for better randomness.
    int srcX, srcY, destX, destY;
    while (1) {
        printf("Move %c: Please enter source x, source y, dest x, dest y: ", sideToMove);
        scanf("%d %d %d %d", &srcX, &srcY, &destX, &destY);
        makeMove(srcX, srcY, destX, destY);
        printBoard();
    }
    return 0;
}