//FormAI DATASET v1.0 Category: Chess AI ; Style: lively
#include <stdio.h>

#define BOARD_SIZE 8

enum Piece {NOPIECE, PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING};
enum Color {WHITE, BLACK};

typedef struct {
    enum Piece piece;
    enum Color color;
} Square;

Square board[BOARD_SIZE][BOARD_SIZE];

void init_board() {
    for (int i=0; i<BOARD_SIZE; i++) {
        for (int j=0; j<BOARD_SIZE; j++) {
            board[i][j].piece = NOPIECE;
            board[i][j].color = WHITE;
        }
    }
    // Initialize pawns
    for (int i=0; i<BOARD_SIZE; i++) {
        board[1][i].piece = PAWN;
        board[6][i].piece = PAWN;
        board[1][i].color = BLACK;
        board[6][i].color = WHITE;
    }
    // Initialize rooks
    board[0][0].piece = ROOK;
    board[0][7].piece = ROOK;
    board[7][0].piece = ROOK;
    board[7][7].piece = ROOK;
    board[0][0].color = BLACK;
    board[0][7].color = BLACK;
    board[7][0].color = WHITE;
    board[7][7].color = WHITE;
    // Initialize knights
    board[0][1].piece = KNIGHT;
    board[0][6].piece = KNIGHT;
    board[7][1].piece = KNIGHT;
    board[7][6].piece = KNIGHT;
    board[0][1].color = BLACK;
    board[0][6].color = BLACK;
    board[7][1].color = WHITE;
    board[7][6].color = WHITE;
    // Initialize bishops
    board[0][2].piece = BISHOP;
    board[0][5].piece = BISHOP;
    board[7][2].piece = BISHOP;
    board[7][5].piece = BISHOP;
    board[0][2].color = BLACK;
    board[0][5].color = BLACK;
    board[7][2].color = WHITE;
    board[7][5].color = WHITE;
    // Initialize queens
    board[0][3].piece = QUEEN;
    board[7][3].piece = QUEEN;
    board[0][3].color = BLACK;
    board[7][3].color = WHITE;
    // Initialize kings
    board[0][4].piece = KING;
    board[7][4].piece = KING;
    board[0][4].color = BLACK;
    board[7][4].color = WHITE;
}

void print_board() {
    for (int i=0; i<BOARD_SIZE; i++) {
        for (int j=0; j<BOARD_SIZE; j++) {
            switch(board[i][j].piece) {
                case NOPIECE:
                    printf(".");
                    break;
                case PAWN:
                    printf("P");
                    break;
                case ROOK:
                    printf("R");
                    break;
                case KNIGHT:
                    printf("N");
                    break;
                case BISHOP:
                    printf("B");
                    break;
                case QUEEN:
                    printf("Q");
                    break;
                case KING:
                    printf("K");
                    break;
            }
            switch(board[i][j].color) {
                case WHITE:
                    printf("W ");
                    break;
                case BLACK:
                    printf("B ");
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    init_board();
    print_board();
    return 0;
}