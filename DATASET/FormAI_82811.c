//FormAI DATASET v1.0 Category: Chess engine ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

// Struct to represent a chess piece
typedef struct {
    char type; // 'P' for Pawn, 'K' for King, 'Q' for Queen, 'R' for Rook, 'B' for Bishop, 'N' for Knight
    bool is_white; // true if the piece is white, false if black
} Piece;

// Struct to represent a chess board
typedef struct {
    Piece board[BOARD_SIZE][BOARD_SIZE];
} Board;

// Function to initialize a new chess board
void initialize_board(Board *board) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (row == 1 || row == 6) {
                // Add pawns
                board->board[row][col] = (Piece) { .type = 'P', .is_white = (row == 6) };
            } else if (row == 0 || row == 7) {
                // Add other pieces
                bool is_white = (row == 0);
                switch (col) {
                    case 0:
                    case 7:
                        board->board[row][col] = (Piece) { .type = 'R', .is_white = is_white };
                        break;
                    case 1:
                    case 6:
                        board->board[row][col] = (Piece) { .type = 'N', .is_white = is_white };
                        break;
                    case 2:
                    case 5:
                        board->board[row][col] = (Piece) { .type = 'B', .is_white = is_white };
                        break;
                    case 3:
                        board->board[row][col] = (Piece) { .type = 'Q', .is_white = is_white };
                        break;
                    case 4:
                        board->board[row][col] = (Piece) { .type = 'K', .is_white = is_white };
                        break;
                }
            }
        }
    }
}

// Function to print the chess board
void print_board(Board *board) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board->board[row][col].type != '\0') {
                printf("%c%c ", board->board[row][col].is_white ? 'W' : 'B', board->board[row][col].type);
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
}

int main() {
    Board board;
    initialize_board(&board);
    print_board(&board);
    return 0;
}