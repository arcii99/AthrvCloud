//FormAI DATASET v1.0 Category: Chess AI ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define WHITE 0
#define BLACK 1

#define PAWN 'p'
#define ROOK 'r'
#define KNIGHT 'n'
#define BISHOP 'b'
#define QUEEN 'q'
#define KING 'k'

#define DEFAULT_BOARD "\
r n b q k b n r \
p p p p p p p p \
. . . . . . . . \
. . . . . . . . \
. . . . . . . . \
. . . . . . . . \
P P P P P P P P \
R N B Q K B N R"

typedef struct {
    char type;
    int color;
} Piece;

Piece board[8][8];
int current_turn = WHITE;

int main() {
    fill_board();
    print_board();

    return 0;
}

void fill_board() {
    int i, j;
    char piece;

    for(i=0; i<8; i++) {
        for(j=0; j<8; j++) {
            piece = DEFAULT_BOARD[(i * 8) + j];
            board[i][j].type = piece;
            if(piece == '.') {
                board[i][j].color = -1;
            } else if(piece >= 'a' && piece <= 'z') {
                board[i][j].color = BLACK;
            } else {
                board[i][j].color = WHITE;
            }
        }
    }
}

void print_board() {
    int i, j;

    for(i=0; i<8; i++) {
        for(j=0; j<8; j++) {
            printf("%c ", board[i][j].type);
        }
        printf("\n");
    }
}