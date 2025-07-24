//FormAI DATASET v1.0 Category: Chess engine ; Style: beginner-friendly
#include <stdio.h>

// Define the chess board and its dimensions
#define BOARD_SIZE 8
char board[BOARD_SIZE][BOARD_SIZE];

// Define the chess pieces
#define EMPTY_SPACE ' '
#define WHITE_PAWN 'P'
#define WHITE_ROOK 'R'
#define WHITE_KNIGHT 'N'
#define WHITE_BISHOP 'B'
#define WHITE_QUEEN 'Q'
#define WHITE_KING 'K'
#define BLACK_PAWN 'p'
#define BLACK_ROOK 'r'
#define BLACK_KNIGHT 'n'
#define BLACK_BISHOP 'b'
#define BLACK_QUEEN 'q'
#define BLACK_KING 'k'

// Initial setup of the chess board
void initialize_board() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (row == 0 || row == BOARD_SIZE - 1) {
                if (col == 0 || col == BOARD_SIZE - 1) {
                    board[row][col] = row == 0 ? WHITE_ROOK : BLACK_ROOK;
                } else if (col == 1 || col == BOARD_SIZE - 2) {
                    board[row][col] = row == 0 ? WHITE_KNIGHT : BLACK_KNIGHT;
                } else if (col == 2 || col == BOARD_SIZE - 3) {
                    board[row][col] = row == 0 ? WHITE_BISHOP : BLACK_BISHOP;
                } else if (col == 3) {
                    board[row][col] = row == 0 ? WHITE_QUEEN : BLACK_QUEEN;
                } else {
                    board[row][col] = row == 0 ? WHITE_KING : BLACK_KING;
                }
            } else if (row == 1 || row == BOARD_SIZE - 2) {
                board[row][col] = row == 1 ? WHITE_PAWN : BLACK_PAWN;
            } else {
                board[row][col] = EMPTY_SPACE;
            }
        }
    }
}

// Print out the board
void print_board() {
    printf("\n  A B C D E F G H\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%d ", BOARD_SIZE - row);
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("%c ", board[row][col]);
        }
        printf("%d\n", BOARD_SIZE - row);
    }
    printf("  A B C D E F G H\n\n");
}

int main() {
    initialize_board();
    print_board();
    return 0;
}