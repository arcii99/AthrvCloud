//FormAI DATASET v1.0 Category: Chess engine ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

// initialize and print the chess board
int board[BOARD_SIZE][BOARD_SIZE] = {
    {-1, -2, -3, -4, -5, -3, -2, -1},
    {-6, -6, -6, -6, -6, -6, -6, -6},
    { 0,  0,  0,  0,  0,  0,  0,  0},
    { 0,  0,  0,  0,  0,  0,  0,  0},
    { 0,  0,  0,  0,  0,  0,  0,  0},
    { 0,  0,  0,  0,  0,  0,  0,  0},
    { 6,  6,  6,  6,  6,  6,  6,  6},
    { 1,  2,  3,  4,  5,  3,  2,  1}
};

char *piece_names[] = {"", "pawn", "knight", "bishop", "rook", "queen", "king"};

void print_board()
{
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// check if a piece can move to a given position
int is_valid_move(int x1, int y1, int x2, int y2)
{
    if (x2 < 0 || x2 >= BOARD_SIZE || y2 < 0 || y2 >= BOARD_SIZE) {
        return 0;
    }
    int piece = board[x1][y1];
    int dest_piece = board[x2][y2];
    // check if the destination square is occupied by a friendly piece
    if (dest_piece != 0 && (piece < 0 && dest_piece < 0 || piece > 0 && dest_piece > 0)) {
        return 0;
    }
    // check if the move is valid for the piece type
    if (abs(piece) == 1) { // pawn
        int dy = y2 - y1;
        if (dy == 0) {
            return 0;
        }
        if (abs(dy) == 1) { // capture
            if ((piece < 0 && x2 - x1 == 1) || (piece > 0 && x2 - x1 == -1)) {
                return 1;
            }
        } else {
            int dx = x2 - x1;
            if (piece < 0) { // black pawn
                if (dx == 1) {
                    return 1;
                }
                if (dx == 2 && x1 == 1 && board[x2][y2] == 0 && board[x1 + 1][y1] == 0) {
                    return 1;
                }
            } else { // white pawn
                if (dx == -1) {
                    return 1;
                }
                if (dx == -2 && x1 == 6 && board[x2][y2] == 0 && board[x1 - 1][y1] == 0) {
                    return 1;
                }
            }
        }
    }
    // TODO - add more pieces
    return 0;
}

// execute a move
void make_move(int x1, int y1, int x2, int y2)
{
    int piece = board[x1][y1];
    board[x2][y2] = piece;
    board[x1][y1] = 0;
}

int main()
{
    print_board();

    while (1) {
        int x1, y1, x2, y2;
        printf("Move a piece (x1,y1,x2,y2): ");
        scanf("%d,%d,%d,%d", &x1, &y1, &x2, &y2);

        if (is_valid_move(x1, y1, x2, y2)) {
            make_move(x1, y1, x2, y2);
        } else {
            printf("Invalid move!\n");
        }

        print_board();
    }

    return 0;
}