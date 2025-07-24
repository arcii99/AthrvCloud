//FormAI DATASET v1.0 Category: Chess engine ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Constants for board size and pieces
#define BOARD_SIZE 8
#define EMPTY 0
#define PAWN 1
#define KNIGHT 2
#define BISHOP 3
#define ROOK 4
#define QUEEN 5
#define KING 6

// Structure for each piece, containing its type and color
typedef struct {
    int type;
    int color;
} Piece;

// Function to initialize the starting board state
void initializeBoard(Piece board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i == 1 || i == 6) {
                board[i][j].type = PAWN;
                board[i][j].color = (i == 1) ? 0 : 1;
            } else if ((i == 0 || i == 7) && (j == 0 || j == 7)) {
                board[i][j].type = ROOK;
                board[i][j].color = (i == 0) ? 0 : 1;
            } else if ((i == 0 || i == 7) && (j == 1 || j == 6)) {
                board[i][j].type = KNIGHT;
                board[i][j].color = (i == 0) ? 0 : 1;
            } else if ((i == 0 || i == 7) && (j == 2 || j == 5)) {
                board[i][j].type = BISHOP;
                board[i][j].color = (i == 0) ? 0 : 1;
            } else if ((i == 0 && j == 3) || (i == 7 && j == 3)) {
                board[i][j].type = QUEEN;
                board[i][j].color = (i == 0) ? 0 : 1;
            } else if ((i == 0 && j == 4) || (i == 7 && j == 4)) {
                board[i][j].type = KING;
                board[i][j].color = (i == 0) ? 0 : 1;
            } else {
                board[i][j].type = EMPTY;
                board[i][j].color = -1;
            }
        }
    }
}

// Function to print out the board state
void printBoard(Piece board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            char c;
            switch (board[i][j].type) {
                case EMPTY:
                    c = ' ';
                    break;
                case PAWN:
                    c = (board[i][j].color == 0) ? 'P' : 'p';
                    break;
                case KNIGHT:
                    c = (board[i][j].color == 0) ? 'N' : 'n';
                    break;
                case BISHOP:
                    c = (board[i][j].color == 0) ? 'B' : 'b';
                    break;
                case ROOK:
                    c = (board[i][j].color == 0) ? 'R' : 'r';
                    break;
                case QUEEN:
                    c = (board[i][j].color == 0) ? 'Q' : 'q';
                    break;
                case KING:
                    c = (board[i][j].color == 0) ? 'K' : 'k';
                    break;
            }
            printf("%c ", c);
        }
        printf("\n");
    }
}

int main() {
    Piece board[BOARD_SIZE][BOARD_SIZE];
    initializeBoard(board);
    printBoard(board);
    return 0;
}