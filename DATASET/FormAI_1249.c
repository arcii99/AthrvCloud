//FormAI DATASET v1.0 Category: Chess AI ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Piece values
#define PAWN 1
#define ROOK 5
#define KNIGHT 3
#define BISHOP 3
#define QUEEN 9
#define KING 0

typedef int Piece;

// Piece colors
#define WHITE 0
#define BLACK 1

typedef int Color;

// Pieces
#define WHITE_PAWN 1
#define WHITE_ROOK 2
#define WHITE_KNIGHT 3
#define WHITE_BISHOP 4
#define WHITE_QUEEN 5
#define WHITE_KING 6
#define BLACK_PAWN -1
#define BLACK_ROOK -2
#define BLACK_KNIGHT -3
#define BLACK_BISHOP -4
#define BLACK_QUEEN -5
#define BLACK_KING -6

// Chess board
Piece board[BOARD_SIZE][BOARD_SIZE];

// Initialize the board
void init_board(Piece board[][BOARD_SIZE]) {
    int i, j;

    // Set the pawns
    for (i = 0; i < BOARD_SIZE; i++) {
        board[1][i] = WHITE_PAWN;
        board[6][i] = BLACK_PAWN;
    }

    // Set the other pieces
    board[0][0] = WHITE_ROOK;
    board[0][1] = WHITE_KNIGHT;
    board[0][2] = WHITE_BISHOP;
    board[0][3] = WHITE_QUEEN;
    board[0][4] = WHITE_KING;
    board[0][5] = WHITE_BISHOP;
    board[0][6] = WHITE_KNIGHT;
    board[0][7] = WHITE_ROOK;

    board[7][0] = BLACK_ROOK;
    board[7][1] = BLACK_KNIGHT;
    board[7][2] = BLACK_BISHOP;
    board[7][3] = BLACK_QUEEN;
    board[7][4] = BLACK_KING;
    board[7][5] = BLACK_BISHOP;
    board[7][6] = BLACK_KNIGHT;
    board[7][7] = BLACK_ROOK;

    // Set the rest of the squares to 0
    for (i = 2; i < 6; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

// Print the board
void print_board(Piece board[][BOARD_SIZE]) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            switch(board[i][j]) {
                case WHITE_PAWN:
                    printf("P");
                    break;
                case WHITE_ROOK:
                    printf("R");
                    break;
                case WHITE_KNIGHT:
                    printf("N");
                    break;
                case WHITE_BISHOP:
                    printf("B");
                    break;
                case WHITE_QUEEN:
                    printf("Q");
                    break;
                case WHITE_KING:
                    printf("K");
                    break;
                case BLACK_PAWN:
                    printf("p");
                    break;
                case BLACK_ROOK:
                    printf("r");
                    break;
                case BLACK_KNIGHT:
                    printf("n");
                    break;
                case BLACK_BISHOP:
                    printf("b");
                    break;
                case BLACK_QUEEN:
                    printf("q");
                    break;
                case BLACK_KING:
                    printf("k");
                    break;
                default:
                    printf(" ");
            }
            printf(" ");
        }
        printf("\n");
    }
}

// Example usage
int main() {
    init_board(board);
    print_board(board);

    return 0;
}