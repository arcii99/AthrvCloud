//FormAI DATASET v1.0 Category: Chess engine ; Style: ephemeral
#include <stdio.h>
#include <stdbool.h>

#define ROWS 8
#define COLS 8

typedef struct {
    int row;
    int col;
} Coordinate;

enum Piece {
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING,
    BLANK
};

typedef struct {
    enum Piece piece;
    bool is_white;
} Square;

Square board[ROWS][COLS];

// Initialize the board with starting pieces
void initialize_board() {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (row == 1) {
                board[row][col].piece = PAWN;
                board[row][col].is_white = false;
            }
            else if (row == 6) {
                board[row][col].piece = PAWN;
                board[row][col].is_white = true;
            }
            else if (row == 0 || row == 7) {
                bool is_white = (row == 0);
                if (col == 0 || col == 7) {
                    board[row][col].piece = ROOK;
                }
                else if (col == 1 || col == 6) {
                    board[row][col].piece = KNIGHT;
                }
                else if (col == 2 || col == 5) {
                    board[row][col].piece = BISHOP;
                }
                else if (col == 3) {
                    board[row][col].piece = QUEEN;
                }
                else {
                    board[row][col].piece = KING;
                }
                board[row][col].is_white = is_white;
            }
            else {
                board[row][col].piece = BLANK;
            }
        }
    }
}

// Print the current state of the board
void print_board() {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            switch (board[row][col].piece) {
                case PAWN:
                    printf("%c ", (board[row][col].is_white) ? 'P' : 'p');
                    break;
                case KNIGHT:
                    printf("%c ", (board[row][col].is_white) ? 'N' : 'n');
                    break;
                case BISHOP:
                    printf("%c ", (board[row][col].is_white) ? 'B' : 'b');
                    break;
                case ROOK:
                    printf("%c ", (board[row][col].is_white) ? 'R' : 'r');
                    break;
                case QUEEN:
                    printf("%c ", (board[row][col].is_white) ? 'Q' : 'q');
                    break;
                case KING:
                    printf("%c ", (board[row][col].is_white) ? 'K' : 'k');
                    break;
                case BLANK:
                    printf(". ");
                    break;
            }
        }
        printf("\n");
    }
}

// Get the piece at a given coordinate
Square get_piece(Coordinate coord) {
    return board[coord.row][coord.col];
}

// Move a piece from one coordinate to another
void move_piece(Coordinate start, Coordinate end) {
    Square piece = board[start.row][start.col];
    board[start.row][start.col].piece = BLANK;
    board[start.row][start.col].is_white = false;
    board[end.row][end.col] = piece;
}

int main() {
    initialize_board();
    print_board();
    Coordinate start = {1, 0};
    Coordinate end = {3, 0};
    move_piece(start, end);
    printf("\n");
    print_board();
    return 0;
}