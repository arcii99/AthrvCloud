//FormAI DATASET v1.0 Category: Chess AI ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define ROWS 8
#define COLS 8

char board[ROWS][COLS];

typedef struct piece {
    char type;
    int row;
    int col;
} Piece;

Piece create_piece(char type, int row, int col) {
    Piece p;
    p.type = type;
    p.row = row;
    p.col = col;
    return p;
}

void init_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = '#';
            } else {
                board[i][j] = '.';
            }
        }
    }
}

void place_pieces() {
    // Place white pieces
    board[0][0] = 'R';
    board[0][1] = 'N';
    board[0][2] = 'B';
    board[0][3] = 'Q';
    board[0][4] = 'K';
    board[0][5] = 'B';
    board[0][6] = 'N';
    board[0][7] = 'R';
    for (int i = 0; i < COLS; i++) {
        board[1][i] = 'P';
    }

    // Place black pieces
    board[7][0] = 'r';
    board[7][1] = 'n';
    board[7][2] = 'b';
    board[7][3] = 'q';
    board[7][4] = 'k';
    board[7][5] = 'b';
    board[7][6] = 'n';
    board[7][7] = 'r';
    for (int i = 0; i < COLS; i++) {
        board[6][i] = 'p';
    }
}

void print_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    init_board();
    place_pieces();
    print_board();
    return 0;
}