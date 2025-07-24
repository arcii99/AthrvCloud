//FormAI DATASET v1.0 Category: Checkers Game ; Style: configurable
#include <stdio.h>

#define ROWS 8
#define COLUMNS 8

// Configurable values
char BLACK_PIECE = 'B';
char WHITE_PIECE = 'W';

// Board struct
typedef struct {
    char board[ROWS][COLUMNS];
} Board;

// Print the current state of the board
void printBoard(Board *board) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%c ", board->board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Board board;
    // Initialize the board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if ((i + j) % 2 == 0) {
                if (i < 3) {
                    board.board[i][j] = BLACK_PIECE;
                } else if (i > 4) {
                    board.board[i][j] = WHITE_PIECE;
                } else {
                    board.board[i][j] = ' ';
                }
            } else {
                board.board[i][j] = ' ';
            }
        }
    }

    // Print the initial state of the board
    printBoard(&board);

    return 0;
}