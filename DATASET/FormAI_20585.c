//FormAI DATASET v1.0 Category: Chess AI ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef enum { false, true } bool;

/* define chess pieces and their values */
enum Pieces { EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING };
enum Values { PVAL = 1, NVAL = 3, BVAL = 3, RVAL = 5, QVAL = 9, KVAL = 0 };

/* define a structure to hold chess pieces */
struct square {
    enum Pieces piece;
    bool isWhite;
};

/* define the chess board */
struct square board[BOARD_SIZE][BOARD_SIZE];

/* utility function to initialize the board */
void initBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            /* set the piece type */
            if (i == 1 || i == BOARD_SIZE - 2) {
                board[i][j].piece = PAWN;
            } else if (j == 0 || j == BOARD_SIZE - 1) {
                board[i][j].piece = ROOK;
            } else if (j == 1 || j == BOARD_SIZE - 2) {
                board[i][j].piece = KNIGHT;
            } else if (j == 2 || j == BOARD_SIZE - 3) {
                board[i][j].piece = BISHOP;
            } else if (j == 3) {
                board[i][j].piece = QUEEN;
            } else if (j == 4) {
                board[i][j].piece = KING;
            } else {
                board[i][j].piece = EMPTY;
            }

            /* set the color */
            if (i < BOARD_SIZE / 2) {
                board[i][j].isWhite = true;
            } else {
                board[i][j].isWhite = false;
            }
        }
    }
}

/* utility function to print the board */
void printBoard() {
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch(board[i][j].piece) {
                case EMPTY:
                    printf(". ");
                    break;
                case PAWN:
                    printf("P ");
                    break;
                case KNIGHT:
                    printf("N ");
                    break;
                case BISHOP:
                    printf("B ");
                    break;
                case ROOK:
                    printf("R ");
                    break;
                case QUEEN:
                    printf("Q ");
                    break;
                case KING:
                    printf("K ");
                    break;
                default:
                    printf("? ");
                    break;
            }
        }

        printf("\n");
    }

    printf("\n");
}

int main() {
    initBoard();
    printBoard();

    return 0;
}