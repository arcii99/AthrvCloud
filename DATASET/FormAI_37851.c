//FormAI DATASET v1.0 Category: Chess engine ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BOARD_SIZE 8

struct Move {
    int fromRow, fromCol;
    int toRow, toCol;
};

enum Piece {
    EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING
};

enum Color {
    WHITE, BLACK
};

struct Board {
    enum Piece squares[BOARD_SIZE][BOARD_SIZE];
    enum Color currentPlayer;
    int whiteKingRow, whiteKingCol, blackKingRow, blackKingCol;
    int halfmoveClock;
    struct Move moves[1000];
};

void initBoard(struct Board* board) {
    int row, col;
    for(row = 0; row < BOARD_SIZE; row++) {
        for(col = 0; col < BOARD_SIZE; col++) {
            board->squares[row][col] = EMPTY;
        }
    }
    for(col = 0; col < BOARD_SIZE; col++) {
        board->squares[1][col] = PAWN;
        board->squares[6][col] = PAWN;
    }
    board->squares[0][0] = ROOK;
    board->squares[0][1] = KNIGHT;
    board->squares[0][2] = BISHOP;
    board->squares[0][3] = QUEEN;
    board->squares[0][4] = KING;
    board->squares[0][5] = BISHOP;
    board->squares[0][6] = KNIGHT;
    board->squares[0][7] = ROOK;
    board->squares[7][0] = ROOK;
    board->squares[7][1] = KNIGHT;
    board->squares[7][2] = BISHOP;
    board->squares[7][3] = QUEEN;
    board->squares[7][4] = KING;
    board->squares[7][5] = BISHOP;
    board->squares[7][6] = KNIGHT;
    board->squares[7][7] = ROOK;
    board->currentPlayer = WHITE;
    board->whiteKingRow = 0;
    board->whiteKingCol = 4;
    board->blackKingRow = 7;
    board->blackKingCol = 4;
    board->halfmoveClock = 0;
}

void printBoard(struct Board* board) {
    int row, col;
    for(row = 0; row < BOARD_SIZE; row++) {
        for(col = 0; col < BOARD_SIZE; col++) {
            switch(board->squares[row][col]) {
                case EMPTY:
                    printf(".");
                    break;
                case PAWN:
                    printf("P");
                    break;
                case KNIGHT:
                    printf("N");
                    break;
                case BISHOP:
                    printf("B");
                    break;
                case ROOK:
                    printf("R");
                    break;
                case QUEEN:
                    printf("Q");
                    break;
                case KING:
                    printf("K");
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    struct Board board;
    initBoard(&board);
    printBoard(&board);
    return 0;
}