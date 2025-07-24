//FormAI DATASET v1.0 Category: Chess engine ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

// Represent the chess board as a 2D array of integers
int board[BOARD_SIZE][BOARD_SIZE];

// Initialize the board with starting pieces
void initializeBoard() {
    // Set up black pieces
    board[0][0] = board[0][7] = 2; // Rook
    board[0][1] = board[0][6] = 1; // Knight
    board[0][2] = board[0][5] = 3; // Bishop
    board[0][3] = 4; // Queen
    board[0][4] = 5; // King
    for (int col = 0; col < BOARD_SIZE; col++) {
        board[1][col] = 6; // Pawn
    }

    // Set up white pieces
    board[7][0] = board[7][7] = -2; // Rook
    board[7][1] = board[7][6] = -1; // Knight
    board[7][2] = board[7][5] = -3; // Bishop
    board[7][3] = -4; // Queen
    board[7][4] = -5; // King
    for (int col = 0; col < BOARD_SIZE; col++) {
        board[6][col] = -6; // Pawn
    }
}

// Print out the current state of the board
void printBoard() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == 0) {
                printf(". ");
            } else {
                printf("%d ", board[row][col]);
            }
        }
        printf("\n");
    }
}

int main() {
    initializeBoard();
    printBoard();
    return 0;
}