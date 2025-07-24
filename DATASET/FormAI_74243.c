//FormAI DATASET v1.0 Category: Chess engine ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the chess board using a 2D array of 64 spaces (8x8)
char board[8][8];

// Define the chess pieces using characters
const char KING = 'K';
const char QUEEN = 'Q';
const char BISHOP = 'B';
const char KNIGHT = 'N';
const char ROOK = 'R';
const char PAWN = 'P';

// Define the pieces for each player
const char WHITE_PIECES[] = {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK};
const char BLACK_PIECES[] = {ROOK, KNIGHT, BISHOP, KING, QUEEN, BISHOP, KNIGHT, ROOK};

// Define colors for each player
const char WHITE = 'w';
const char BLACK = 'b';

// Define the starting position for each piece
const int KING_START[] = {0, 4};
const int QUEEN_START[] = {0, 3};
const int BISHOP1_START[] = {0, 2};
const int BISHOP2_START[] = {0, 5};
const int KNIGHT1_START[] = {0, 1};
const int KNIGHT2_START[] = {0, 6};
const int ROOK1_START[] = {0, 0};
const int ROOK2_START[] = {0, 7};
const int PAWN_START[] = {1, 0};

void initialize_board() {
    // Set the starting position for the white pieces
    board[ROOK1_START[0]][ROOK1_START[1]] = WHITE_PIECES[0];
    board[KNIGHT1_START[0]][KNIGHT1_START[1]] = WHITE_PIECES[1];
    board[BISHOP1_START[0]][BISHOP1_START[1]] = WHITE_PIECES[2];
    board[QUEEN_START[0]][QUEEN_START[1]] = WHITE_PIECES[3];
    board[KING_START[0]][KING_START[1]] = WHITE_PIECES[4];
    board[BISHOP2_START[0]][BISHOP2_START[1]] = WHITE_PIECES[5];
    board[KNIGHT2_START[0]][KNIGHT2_START[1]] = WHITE_PIECES[6];
    board[ROOK2_START[0]][ROOK2_START[1]] = WHITE_PIECES[7];

    // Set the starting position for the black pieces
    board[7-ROOK1_START[0]][ROOK1_START[1]] = BLACK_PIECES[0];
    board[7-KNIGHT1_START[0]][KNIGHT1_START[1]] = BLACK_PIECES[1];
    board[7-BISHOP1_START[0]][BISHOP1_START[1]] = BLACK_PIECES[2];
    board[7-QUEEN_START[0]][QUEEN_START[1]] = BLACK_PIECES[3];
    board[7-KING_START[0]][KING_START[1]] = BLACK_PIECES[4];
    board[7-BISHOP2_START[0]][BISHOP2_START[1]] = BLACK_PIECES[5];
    board[7-KNIGHT2_START[0]][KNIGHT2_START[1]] = BLACK_PIECES[6];
    board[7-ROOK2_START[0]][ROOK2_START[1]] = BLACK_PIECES[7];

    // Set the starting position for the pawns
    for (int i=0; i<8; i++) {
        board[PAWN_START[0]][PAWN_START[1]+i] = WHITE_PIECES[7];
        board[7-PAWN_START[0]][PAWN_START[1]+i] = BLACK_PIECES[7];
    }

    // Fill in the empty spaces with '-'
    for (int i=2; i<6; i++) {
        for (int j=0; j<8; j++) {
            board[i][j] = '-';
        }
    }
}

void print_board() {
    printf("\n  a b c d e f g h\n");
    for (int i=0; i<8; i++) {
        printf("%d", 8-i);
        for (int j=0; j<8; j++) {
            printf(" %c", board[i][j]);
        }
        printf(" %d", 8-i);
        printf("\n");
    }
    printf("  a b c d e f g h\n\n");
}

int main() {
    initialize_board();
    print_board();

    return 0;
}