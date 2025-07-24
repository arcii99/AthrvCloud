//FormAI DATASET v1.0 Category: Chess engine ; Style: scalable
#include <stdio.h>

typedef char Piece;

enum {
    EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING
};

enum {
    WHITE, BLACK
};

Piece board[8][8] = {
    { ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK },
    { PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN },
    { ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK }
};

void print_board() {
    for (int rank = 7; rank >= 0; rank--) {
        printf("%d ", rank + 1);
        for (int file = 0; file < 8; file++) {
            Piece piece = board[rank][file];
            char symbol = "-PNBRQK"[piece];
            printf("%c ", symbol);
        }
        printf("\n");
    }
    printf("  A B C D E F G H\n");
}

int main() {
    print_board();
    // Move e2 pawn to e4
    board[3][4] = board[1][4];
    board[1][4] = EMPTY;
    print_board();
    return 0;
}