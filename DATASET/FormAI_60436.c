//FormAI DATASET v1.0 Category: Chess engine ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// define board dimensions
#define BOARD_SIZE 8

// define piece values
#define PAWN_VALUE 1
#define KNIGHT_VALUE 3
#define BISHOP_VALUE 3
#define ROOK_VALUE 5
#define QUEEN_VALUE 9
#define KING_VALUE 100

// define piece colors
#define WHITE 0
#define BLACK 1

// define piece types
#define PAWN 'P'
#define KNIGHT 'N'
#define BISHOP 'B'
#define ROOK 'R'
#define QUEEN 'Q'
#define KING 'K'

// define board representation
char board[BOARD_SIZE][BOARD_SIZE];

// define function to initialize the board with pieces
void initBoard() {
    // white pieces
    board[0][0] = board[0][7] = ROOK;
    board[0][1] = board[0][6] = KNIGHT;
    board[0][2] = board[0][5] = BISHOP;
    board[0][3] = QUEEN;
    board[0][4] = KING;
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[1][i] = PAWN;
    }
    // black pieces
    board[7][0] = board[7][7] = ROOK;
    board[7][1] = board[7][6] = KNIGHT;
    board[7][2] = board[7][5] = BISHOP;
    board[7][3] = QUEEN;
    board[7][4] = KING;
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[6][i] = PAWN;
    }
    // empty spaces
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// define function to print the board
void printBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
}

// define function to calculate the value of a piece
int pieceValue(char piece) {
    switch (piece) {
        case PAWN:
            return PAWN_VALUE;
        case KNIGHT:
            return KNIGHT_VALUE;
        case BISHOP:
            return BISHOP_VALUE;
        case ROOK:
            return ROOK_VALUE;
        case QUEEN:
            return QUEEN_VALUE;
        case KING:
            return KING_VALUE;
    }
}

// define function to calculate the material value of a side
int materialValue(int side) {
    int value = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != ' ' && (board[i][j] >= 'A' && board[i][j] <= 'Z') == side) {
                value += pieceValue(board[i][j]);
            }
        }
    }
    return value;
}

int main() {
    initBoard();
    printBoard();
    int whiteMaterialValue = materialValue(WHITE);
    int blackMaterialValue = materialValue(BLACK);
    printf("White material value: %d\n", whiteMaterialValue);
    printf("Black material value: %d\n", blackMaterialValue);
    return 0;
}