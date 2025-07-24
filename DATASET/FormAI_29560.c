//FormAI DATASET v1.0 Category: Chess engine ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8    // The size of the chess board 

typedef struct square_t {
    char piece;         // The piece on this square (P, N, B, R, Q, K, or ' ')
    int color;          // The color of the piece (0 for black, 1 for white)
} Square;

Square board[BOARD_SIZE][BOARD_SIZE];   // The chess board

void init_board() {
    // Initialize the chess board with starting pieces
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            // Check if this square is in the starting position for a piece
            if (i == 1) {
                board[i][j].piece = 'P';
                board[i][j].color = 0;  // black pawn
            }
            else if (i == 6) {
                board[i][j].piece = 'P';
                board[i][j].color = 1;  // white pawn
            }
            else {
                board[i][j].piece = ' ';
            }
        }
    }
}

void print_board() {
    // Print out the chess board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("+---");
        }
        printf("+\n");
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("| %c ", board[i][j].piece);
        }
        printf("|\n");
    }
    for (int j = 0; j < BOARD_SIZE; j++) {
        printf("+---");
    }
    printf("+\n");
}

int main() {
    printf("Welcome to our Chess engine in C!\n");
    printf("Let's start by initializing the board...\n");
    init_board();
    printf("Here is the starting position:\n");
    print_board();
    printf("Good luck playing!\n");
    return 0;
}