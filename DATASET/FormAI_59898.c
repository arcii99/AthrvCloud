//FormAI DATASET v1.0 Category: Chess AI ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

enum Pieces {
    King = 'K',
    Queen = 'Q',
    Rook = 'R',
    Bishop = 'B',
    Knight = 'N',
    Pawn = 'P',
    Empty = '.'
};

enum Colors {
    White = 'w',
    Black = 'b'
};

typedef struct {
    int x;
    int y;
} Coordinate;

typedef struct {
    char piece;
    char color;
} Piece;

typedef struct {
    Piece grid[BOARD_SIZE][BOARD_SIZE];
    char turn;
    bool white_king_moved;
    bool black_king_moved;
    bool white_rook_am_left_moved;
    bool white_rook_h_left_moved;
    bool black_rook_am_left_moved;
    bool black_rook_h_left_moved;
    Coordinate en_passant;
    bool white_can_castle;
    bool black_can_castle;
} Board;

// Initialize an empty chess board
void init_board(Board* board)
{
    // Set all the pieces on the board to empty
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->grid[i][j].piece = Empty;
            board->grid[i][j].color = ' ';
        }
    }

    // Put the pieces in their starting positions
    board->grid[0][0].piece = Rook;
    board->grid[0][0].color = Black;
    board->grid[0][1].piece = Knight;
    board->grid[0][1].color = Black;
    board->grid[0][2].piece = Bishop;
    board->grid[0][2].color = Black;
    board->grid[0][3].piece = Queen;
    board->grid[0][3].color = Black;
    board->grid[0][4].piece = King;
    board->grid[0][4].color = Black;
    board->grid[0][5].piece = Bishop;
    board->grid[0][5].color = Black;
    board->grid[0][6].piece = Knight;
    board->grid[0][6].color = Black;
    board->grid[0][7].piece = Rook;
    board->grid[0][7].color = Black;

    board->grid[7][0].piece = Rook;
    board->grid[7][0].color = White;
    board->grid[7][1].piece = Knight;
    board->grid[7][1].color = White;
    board->grid[7][2].piece = Bishop;
    board->grid[7][2].color = White;
    board->grid[7][3].piece = Queen;
    board->grid[7][3].color = White;
    board->grid[7][4].piece = King;
    board->grid[7][4].color = White;
    board->grid[7][5].piece = Bishop;
    board->grid[7][5].color = White;
    board->grid[7][6].piece = Knight;
    board->grid[7][6].color = White;
    board->grid[7][7].piece = Rook;
    board->grid[7][7].color = White;

    for (int i = 0; i < BOARD_SIZE; i++) {
        board->grid[1][i].piece = Pawn;
        board->grid[1][i].color = Black;
        board->grid[6][i].piece = Pawn;
        board->grid[6][i].color = White;
    }

    board->turn = White;
    board->white_king_moved = false;
    board->black_king_moved = false;
    board->white_rook_am_left_moved = false;
    board->white_rook_h_left_moved = false;
    board->black_rook_am_left_moved = false;
    board->black_rook_h_left_moved = false;
    board->en_passant.x = -1;
    board->en_passant.y = -1;
    board->white_can_castle = true;
    board->black_can_castle = true;
}

int main()
{
    printf("Welcome to C Chess AI!\n");

    Board board;

    init_board(&board);

    printf("The initial state of the board:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c%c ", board.grid[i][j].color, board.grid[i][j].piece);
        }
        printf("\n");
    }

    return 0;
}