//FormAI DATASET v1.0 Category: Chess engine ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define WHITE 0
#define BLACK 1
#define BOARD_SIZE 8

struct Piece {
    int type; // 0: pawn, 1: rook, 2: knight, 3: bishop, 4: queen, 5: king
    int color; // WHITE or BLACK
};

struct Board {
    struct Piece cells[BOARD_SIZE][BOARD_SIZE];
};

void initialize_board(struct Board* board) {
    // set up pawns for white and black
    for(int x=0; x<BOARD_SIZE; x++) {
        board->cells[x][1] = (struct Piece) {0, WHITE};
        board->cells[x][6] = (struct Piece) {0, BLACK};
    }

    // set up rooks for white and black
    board->cells[0][0] = (struct Piece) {1, WHITE};
    board->cells[7][0] = (struct Piece) {1, WHITE};
    board->cells[0][7] = (struct Piece) {1, BLACK};
    board->cells[7][7] = (struct Piece) {1, BLACK};

    // set up knights for white and black
    board->cells[1][0] = (struct Piece) {2, WHITE};
    board->cells[6][0] = (struct Piece) {2, WHITE};
    board->cells[1][7] = (struct Piece) {2, BLACK};
    board->cells[6][7] = (struct Piece) {2, BLACK};

    // set up bishops for white and black
    board->cells[2][0] = (struct Piece) {3, WHITE};
    board->cells[5][0] = (struct Piece) {3, WHITE};
    board->cells[2][7] = (struct Piece) {3, BLACK};
    board->cells[5][7] = (struct Piece) {3, BLACK};

    // set up queens for white and black
    board->cells[3][0] = (struct Piece) {4, WHITE};
    board->cells[3][7] = (struct Piece) {4, BLACK};

    // set up kings for white and black
    board->cells[4][0] = (struct Piece) {5, WHITE};
    board->cells[4][7] = (struct Piece) {5, BLACK};
}

void print_board(struct Board board) {
    printf("  a b c d e f g h\n");
    for(int y=0; y<BOARD_SIZE; y++) {
        printf("%d ", BOARD_SIZE-y);
        for(int x=0; x<BOARD_SIZE; x++) {
            struct Piece piece = board.cells[x][BOARD_SIZE-1-y];
            if(piece.type == 0) {
                printf(piece.color == WHITE ? "p " : "P ");
            } else if(piece.type == 1) {
                printf(piece.color == WHITE ? "r " : "R ");
            } else if(piece.type == 2) {
                printf(piece.color == WHITE ? "n " : "N ");
            } else if(piece.type == 3) {
                printf(piece.color == WHITE ? "b " : "B ");
            } else if(piece.type == 4) {
                printf(piece.color == WHITE ? "q " : "Q ");
            } else if(piece.type == 5) {
                printf(piece.color == WHITE ? "k " : "K ");
            } else {
                printf("  ");
            }
        }
        printf("%d\n", BOARD_SIZE-y);
    }
    printf("  a b c d e f g h\n");
}

int main() {
    struct Board board;
    initialize_board(&board);
    print_board(board);
    return 0;
}