//FormAI DATASET v1.0 Category: Chess engine ; Style: modular
#include <stdio.h>
#include <stdlib.h>

typedef struct Piece {
    char type; // 'P' for pawn, 'R' for rook, 'N' for knight, 'B' for bishop, 'Q' for queen, 'K' for king
    char color; // 'W' for white, 'B' for black
    int row;
    int col;
    int moves;
} Piece;

typedef struct Board {
    Piece *pieces[8][8];
    char turn; // 'W' for white, 'B' for black
} Board;

// Function to initialize the board with starting positions of pieces
void init_board(Board *board) {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            board->pieces[row][col] = NULL;
        }
    }

    // Creating and placing pawns
    for (int col = 0; col < 8; col++) {
        board->pieces[1][col] = malloc(sizeof(Piece));
        board->pieces[1][col]->type = 'P';
        board->pieces[1][col]->color = 'W';
        board->pieces[1][col]->row = 1;
        board->pieces[1][col]->col = col;
        board->pieces[1][col]->moves = 0;

        board->pieces[6][col] = malloc(sizeof(Piece));
        board->pieces[6][col]->type = 'P';
        board->pieces[6][col]->color = 'B';
        board->pieces[6][col]->row = 6;
        board->pieces[6][col]->col = col;
        board->pieces[6][col]->moves = 0;
    }

    // Creating and placing rooks
    board->pieces[0][0] = malloc(sizeof(Piece));
    board->pieces[0][0]->type = 'R';
    board->pieces[0][0]->color = 'W';
    board->pieces[0][0]->row = 0;
    board->pieces[0][0]->col = 0;
    board->pieces[0][0]->moves = 0;

    board->pieces[0][7] = malloc(sizeof(Piece));
    board->pieces[0][7]->type = 'R';
    board->pieces[0][7]->color = 'W';
    board->pieces[0][7]->row = 0;
    board->pieces[0][7]->col = 7;
    board->pieces[0][7]->moves = 0;

    board->pieces[7][0] = malloc(sizeof(Piece));
    board->pieces[7][0]->type = 'R';
    board->pieces[7][0]->color = 'B';
    board->pieces[7][0]->row = 7;
    board->pieces[7][0]->col = 0;
    board->pieces[7][0]->moves = 0;

    board->pieces[7][7] = malloc(sizeof(Piece));
    board->pieces[7][7]->type = 'R';
    board->pieces[7][7]->color = 'B';
    board->pieces[7][7]->row = 7;
    board->pieces[7][7]->col = 7;
    board->pieces[7][7]->moves = 0;

    // Creating and placing knights
    board->pieces[0][1] = malloc(sizeof(Piece));
    board->pieces[0][1]->type = 'N';
    board->pieces[0][1]->color = 'W';
    board->pieces[0][1]->row = 0;
    board->pieces[0][1]->col = 1;
    board->pieces[0][1]->moves = 0;

    board->pieces[0][6] = malloc(sizeof(Piece));
    board->pieces[0][6]->type = 'N';
    board->pieces[0][6]->color = 'W';
    board->pieces[0][6]->row = 0;
    board->pieces[0][6]->col = 6;
    board->pieces[0][6]->moves = 0;

    board->pieces[7][1] = malloc(sizeof(Piece));
    board->pieces[7][1]->type = 'N';
    board->pieces[7][1]->color = 'B';
    board->pieces[7][1]->row = 7;
    board->pieces[7][1]->col = 1;
    board->pieces[7][1]->moves = 0;

    board->pieces[7][6] = malloc(sizeof(Piece));
    board->pieces[7][6]->type = 'N';
    board->pieces[7][6]->color = 'B';
    board->pieces[7][6]->row = 7;
    board->pieces[7][6]->col = 6;
    board->pieces[7][6]->moves = 0;

    // Creating and placing bishops
    board->pieces[0][2] = malloc(sizeof(Piece));
    board->pieces[0][2]->type = 'B';
    board->pieces[0][2]->color = 'W';
    board->pieces[0][2]->row = 0;
    board->pieces[0][2]->col = 2;
    board->pieces[0][2]->moves = 0;

    board->pieces[0][5] = malloc(sizeof(Piece));
    board->pieces[0][5]->type = 'B';
    board->pieces[0][5]->color = 'W';
    board->pieces[0][5]->row = 0;
    board->pieces[0][5]->col = 5;
    board->pieces[0][5]->moves = 0;

    board->pieces[7][2] = malloc(sizeof(Piece));
    board->pieces[7][2]->type = 'B';
    board->pieces[7][2]->color = 'B';
    board->pieces[7][2]->row = 7;
    board->pieces[7][2]->col = 2;
    board->pieces[7][2]->moves = 0;

    board->pieces[7][5] = malloc(sizeof(Piece));
    board->pieces[7][5]->type = 'B';
    board->pieces[7][5]->color = 'B';
    board->pieces[7][5]->row = 7;
    board->pieces[7][5]->col = 5;
    board->pieces[7][5]->moves = 0;

    // Creating and placing queens
    board->pieces[0][3] = malloc(sizeof(Piece));
    board->pieces[0][3]->type = 'Q';
    board->pieces[0][3]->color = 'W';
    board->pieces[0][3]->row = 0;
    board->pieces[0][3]->col = 3;
    board->pieces[0][3]->moves = 0;

    board->pieces[7][3] = malloc(sizeof(Piece));
    board->pieces[7][3]->type = 'Q';
    board->pieces[7][3]->color = 'B';
    board->pieces[7][3]->row = 7;
    board->pieces[7][3]->col = 3;
    board->pieces[7][3]->moves = 0;

    // Creating and placing kings
    board->pieces[0][4] = malloc(sizeof(Piece));
    board->pieces[0][4]->type = 'K';
    board->pieces[0][4]->color = 'W';
    board->pieces[0][4]->row = 0;
    board->pieces[0][4]->col = 4;
    board->pieces[0][4]->moves = 0;

    board->pieces[7][4] = malloc(sizeof(Piece));
    board->pieces[7][4]->type = 'K';
    board->pieces[7][4]->color = 'B';
    board->pieces[7][4]->row = 7;
    board->pieces[7][4]->col = 4;
    board->pieces[7][4]->moves = 0;

    // White goes first
    board->turn = 'W';
}

// Function to display the current board state
void print_board(Board *board) {
    printf("\n  a b c d e f g h\n");
    for (int row = 0; row < 8; row++) {
        printf("%d ", row + 1);
        for (int col = 0; col < 8; col++) {
            if (board->pieces[row][col] == NULL) {
                printf(". ");
            } else {
                printf("%c ", board->pieces[row][col]->type);
            }
        }
        printf("%d\n", row + 1);
    }
    printf("  a b c d e f g h\n\n");
}

int main() {
    Board board;

    init_board(&board);

    print_board(&board);

    return 0;
}