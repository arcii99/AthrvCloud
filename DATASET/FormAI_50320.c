//FormAI DATASET v1.0 Category: Chess engine ; Style: systematic
#include <stdio.h>

// defining the size of the chess board
#define BOARD_SIZE 8

// defining the struct for each chess piece
typedef struct {
    int x;
    int y;
    int piece;
} chess_piece;

// defining constants for each chess piece
#define EMPTY 0
#define WP 1
#define WR 2
#define WN 3
#define WB 4
#define WQ 5
#define WK 6
#define BP 7
#define BR 8
#define BN 9
#define BB 10
#define BQ 11
#define BK 12

// defining the chess board and initializing it
int chess_board[BOARD_SIZE][BOARD_SIZE] = {
    {WR, WN, WB, WQ, WK, WB, WN, WR},
    {WP, WP, WP, WP, WP, WP, WP, WP},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {BP, BP, BP, BP, BP, BP, BP, BP},
    {BR, BN, BB, BQ, BK, BB, BN, BR}
};

// finding the piece on the board
chess_piece find_piece(int piece) {
    chess_piece cp = {-1, -1, -1};
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(chess_board[i][j] == piece) {
                cp.x = i;
                cp.y = j;
                cp.piece = piece;
                break;
            }
        }
    }
    return cp;
}

// print the chess board
void print_board() {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", chess_board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Initial Chess Board:\n\n");
    print_board();

    chess_piece wp = find_piece(WP);
    chess_board[wp.x+2][wp.y] = EMPTY;
    chess_board[wp.x+3][wp.y] = WP;

    printf("\n\nAfter the white pawn moves two spaces forward:\n\n");
    print_board();

    return 0;
}