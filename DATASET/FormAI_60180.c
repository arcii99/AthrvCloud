//FormAI DATASET v1.0 Category: Chess AI ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef enum {
    EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING
} Piece;

typedef enum {
    BLACK, WHITE
} Color;

typedef struct {
    Piece piece;
    Color color;
} Square;

Square board[BOARD_SIZE][BOARD_SIZE];

void initialize_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].piece = EMPTY;
        }
    }

    // initialize pawns
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[1][i].piece = PAWN;
        board[6][i].piece = PAWN;
        board[1][i].color = BLACK;
        board[6][i].color = WHITE;
    }

    // initialize knights
    board[0][1].piece = KNIGHT;
    board[0][6].piece = KNIGHT;
    board[7][1].piece = KNIGHT;
    board[7][6].piece = KNIGHT;
    board[0][1].color = BLACK;
    board[0][6].color = BLACK;
    board[7][1].color = WHITE;
    board[7][6].color = WHITE;

    // initialize bishops
    board[0][2].piece = BISHOP;
    board[0][5].piece = BISHOP;
    board[7][2].piece = BISHOP;
    board[7][5].piece = BISHOP;
    board[0][2].color = BLACK;
    board[0][5].color = BLACK;
    board[7][2].color = WHITE;
    board[7][5].color = WHITE;

    // initialize rooks
    board[0][0].piece = ROOK;
    board[0][7].piece = ROOK;
    board[7][0].piece = ROOK;
    board[7][7].piece = ROOK;
    board[0][0].color = BLACK;
    board[0][7].color = BLACK;
    board[7][0].color = WHITE;
    board[7][7].color = WHITE;

    // initialize queens
    board[0][3].piece = QUEEN;
    board[7][3].piece = QUEEN;
    board[0][3].color = BLACK;
    board[7][3].color = WHITE;

    // initialize kings
    board[0][4].piece = KING;
    board[7][4].piece = KING;
    board[0][4].color = BLACK;
    board[7][4].color = WHITE;
}

void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j].piece) {
                case EMPTY:
                    printf("   ");
                    break;
                case PAWN:
                    printf("%cP ", board[i][j].color == BLACK ? 'B' : 'W');
                    break;
                case KNIGHT:
                    printf("%cN ", board[i][j].color == BLACK ? 'B' : 'W');
                    break;
                case BISHOP:
                    printf("%cB ", board[i][j].color == BLACK ? 'B' : 'W');
                    break;
                case ROOK:
                    printf("%cR ", board[i][j].color == BLACK ? 'B' : 'W');
                    break;
                case QUEEN:
                    printf("%cQ ", board[i][j].color == BLACK ? 'B' : 'W');
                    break;
                case KING:
                    printf("%cK ", board[i][j].color == BLACK ? 'B' : 'W');
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    initialize_board();
    print_board();
    return 0;
}