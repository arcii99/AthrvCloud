//FormAI DATASET v1.0 Category: Chess engine ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Represents a piece on the board
typedef struct {
    char type;  // 'P' for pawn, 'R' for rook, etc.
    int x;      // x-coordinate on the board
    int y;      // y-coordinate on the board
} Piece;

// Represents the chess board
typedef struct {
    Piece* pieces[BOARD_SIZE][BOARD_SIZE];
} Board;

// Draws the chess board
void draw_board(Board* board) {
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            Piece* piece = board->pieces[x][y];
            if (piece == NULL) {
                printf("-");
            } else {
                printf("%c", piece->type);
            }
        }
        printf("\n");
    }
}

// Initializes the board with default piece placements
void init_board(Board* board) {
    Piece* pieces[BOARD_SIZE][BOARD_SIZE] = {
        {&((Piece){'R', 0, 0}), &((Piece){'N', 1, 0}), &((Piece){'B', 2, 0}), &((Piece){'Q', 3, 0}), &((Piece){'K', 4, 0}), &((Piece){'B', 5, 0}), &((Piece){'N', 6, 0}), &((Piece){'R', 7, 0})},
        {&((Piece){'P', 0, 1}), &((Piece){'P', 1, 1}), &((Piece){'P', 2, 1}), &((Piece){'P', 3, 1}), &((Piece){'P', 4, 1}), &((Piece){'P', 5, 1}), &((Piece){'P', 6, 1}), &((Piece){'P', 7, 1})},
        {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
        {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
        {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
        {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
        {&((Piece){'P', 0, 6}), &((Piece){'P', 1, 6}), &((Piece){'P', 2, 6}), &((Piece){'P', 3, 6}), &((Piece){'P', 4, 6}), &((Piece){'P', 5, 6}), &((Piece){'P', 6, 6}), &((Piece){'P', 7, 6})},
        {&((Piece){'R', 0, 7}), &((Piece){'N', 1, 7}), &((Piece){'B', 2, 7}), &((Piece){'Q', 3, 7}), &((Piece){'K', 4, 7}), &((Piece){'B', 5, 7}), &((Piece){'N', 6, 7}), &((Piece){'R', 7, 7})}
    };
    memcpy(board->pieces, pieces, sizeof(board->pieces));
}

int main() {
    Board board;
    init_board(&board);
    draw_board(&board);
    return 0;
}