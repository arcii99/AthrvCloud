//FormAI DATASET v1.0 Category: Chess AI ; Style: light-weight
#include <stdio.h>

#define BLACK_PAWN 'p'
#define BLACK_ROOK 'r'
#define BLACK_KNIGHT 'n'
#define BLACK_BISHOP 'b'
#define BLACK_QUEEN 'q'
#define BLACK_KING 'k'
#define WHITE_PAWN 'P'
#define WHITE_ROOK 'R'
#define WHITE_KNIGHT 'N'
#define WHITE_BISHOP 'B'
#define WHITE_QUEEN 'Q'
#define WHITE_KING 'K'
#define EMPTY_SQUARE '.'

// define the board
char board[8][8] = {
    {WHITE_ROOK, WHITE_KNIGHT, WHITE_BISHOP, WHITE_QUEEN, WHITE_KING, WHITE_BISHOP, WHITE_KNIGHT, WHITE_ROOK},
    {WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN},
    {EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE},
    {EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE},
    {EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE},
    {EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE},
    {BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN},
    {BLACK_ROOK, BLACK_KNIGHT, BLACK_BISHOP, BLACK_QUEEN, BLACK_KING, BLACK_BISHOP, BLACK_KNIGHT, BLACK_ROOK}
};

// returns 1 if the move is valid, 0 otherwise
int is_valid_move(int start_row, int start_col, int end_row, int end_col) {
    // check if end position is within bounds
    if (end_row < 0 || end_row > 7 || end_col < 0 || end_col > 7) {
        return 0;
    }

    // check if start and end are the same
    if (start_row == end_row && start_col == end_col) {
        return 0;
    }

    // get the piece at the start position
    char piece = board[start_row][start_col];

    // check if the piece is empty
    if (piece == EMPTY_SQUARE) {
        return 0;
    }

    // check if the end position is occupied by own piece
    char end_piece = board[end_row][end_col];
    if ((piece >= 'a' && piece <= 'z' && end_piece >= 'a' && end_piece <= 'z') || (piece >= 'A' && piece <= 'Z' && end_piece >= 'A' && end_piece <= 'Z')) {
        return 0;
    }

    // check if move is valid based on piece type
    if (piece == WHITE_PAWN || piece == BLACK_PAWN) {
        // check if move is one or two steps forward
        if (start_col == end_col && ((end_row == start_row - 1 && piece == WHITE_PAWN) || (end_row == start_row + 1 && piece == BLACK_PAWN) || (end_row == start_row - 2 && start_row == 6 && piece == WHITE_PAWN) || (end_row == start_row + 2 && start_row == 1 && piece == BLACK_PAWN))) {
            // check if end position is empty
            if (board[end_row][end_col] == EMPTY_SQUARE) {
                return 1;
            }
            return 0;
        }

        // check if move is diagonally capturing an opponent's piece
        if (abs(start_col - end_col) == 1 && ((piece == WHITE_PAWN && end_row == start_row - 1 && board[end_row][end_col] >= 'a' && board[end_row][end_col] <= 'z') || (piece == BLACK_PAWN && end_row == start_row + 1 && board[end_row][end_col] >= 'A' && board[end_row][end_col] <= 'Z'))) {
            return 1;
        }
        return 0;
    }

    // TODO: add implementation for other piece types
    return 0;
}

int main() {
    // test valid moves
    printf("Valid moves:\n");
    printf("Pawn from a2 to a3: %d\n", is_valid_move(1, 0, 2, 0));
    printf("Pawn from a2 to a4: %d\n", is_valid_move(1, 0, 3, 0));
    printf("Pawn from a7 to a6: %d\n", is_valid_move(6, 0, 5, 0));
    printf("Pawn from a7 to a5: %d\n", is_valid_move(6, 0, 4, 0));
    printf("Pawn from a2 to b3: %d\n", is_valid_move(1, 0, 2, 1));
    printf("Pawn from a2 to b1: %d\n", is_valid_move(1, 0, 0, 1));
    printf("Pawn from a7 to b6: %d\n", is_valid_move(6, 0, 5, 1));
    printf("Pawn from a7 to b8: %d\n", is_valid_move(6, 0, 7, 1));
    return 0;
}