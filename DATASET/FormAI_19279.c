//FormAI DATASET v1.0 Category: Chess engine ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Define chess board size
#define BOARD_SIZE 8

// Define piece types
#define KING 1
#define QUEEN 2
#define ROOK 3
#define BISHOP 4
#define KNIGHT 5
#define PAWN 6

// Define piece colors
#define WHITE 1
#define BLACK 2

// Define piece structure
typedef struct Piece {
    int type;
    int color;
} Piece;

// Define chess board
Piece board[BOARD_SIZE][BOARD_SIZE];

// Initialize the chess board
void init_board() {
    int i, j;

    // Initialize pawns for both colors
    for (i = 0; i < BOARD_SIZE; i++) {
        board[1][i].type = PAWN;
        board[1][i].color = BLACK;
        board[6][i].type = PAWN;
        board[6][i].color = WHITE;
    }

    // Initialize other pieces for black color
    board[0][0].type = ROOK;
    board[0][0].color = BLACK;
    board[0][1].type = KNIGHT;
    board[0][1].color = BLACK;
    board[0][2].type = BISHOP;
    board[0][2].color = BLACK;
    board[0][3].type = QUEEN;
    board[0][3].color = BLACK;
    board[0][4].type = KING;
    board[0][4].color = BLACK;
    board[0][5].type = BISHOP;
    board[0][5].color = BLACK;
    board[0][6].type = KNIGHT;
    board[0][6].color = BLACK;
    board[0][7].type = ROOK;
    board[0][7].color = BLACK;

    // Initialize other pieces for white color
    board[7][0].type = ROOK;
    board[7][0].color = WHITE;
    board[7][1].type = KNIGHT;
    board[7][1].color = WHITE;
    board[7][2].type = BISHOP;
    board[7][2].color = WHITE;
    board[7][3].type = QUEEN;
    board[7][3].color = WHITE;
    board[7][4].type = KING;
    board[7][4].color = WHITE;
    board[7][5].type = BISHOP;
    board[7][5].color = WHITE;
    board[7][6].type = KNIGHT;
    board[7][6].color = WHITE;
    board[7][7].type = ROOK;
    board[7][7].color = WHITE;
}

// Print the chess board
void print_board() {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].type == 0) {
                printf(" - ");
            } else if (board[i][j].type == PAWN) {
                printf(" P ");
            } else if (board[i][j].type == ROOK) {
                printf(" R ");
            } else if (board[i][j].type == KNIGHT) {
                printf(" N ");
            } else if (board[i][j].type == BISHOP) {
                printf(" B ");
            } else if (board[i][j].type == QUEEN) {
                printf(" Q ");
            } else if (board[i][j].type == KING) {
                printf(" K ");
            }

            printf("|");
        }
        printf("\n");
    }
}

int main() {
    init_board();
    print_board();

    return 0;
}