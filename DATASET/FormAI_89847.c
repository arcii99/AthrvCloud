//FormAI DATASET v1.0 Category: Checkers Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Represents a single piece on the board
typedef struct {
    int row, col;
    char color;
} Piece;

// Initializes the board with pieces in their starting positions
void init_board(Piece board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    // Black pieces
    for (i = 0; i < 3; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 != 0) {
                board[i][j].row = i;
                board[i][j].col = j;
                board[i][j].color = 'B';
            }
        }
    }
    // White pieces
    for (i = BOARD_SIZE - 3; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 != 0) {
                board[i][j].row = i;
                board[i][j].col = j;
                board[i][j].color = 'W';
            }
        }
    }
}

// Prints the board with all pieces
void print_board(Piece board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    printf("   ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d  ", i);
        for (j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                printf("  ");
            }
            else {
                printf("%c ", board[i][j].color);
            }
        }
        printf("\n");
    }
}

// Moves a piece from one cell to another
void move_piece(Piece board[BOARD_SIZE][BOARD_SIZE], int src_row, int src_col, int dest_row, int dest_col) {
    Piece temp = board[src_row][src_col];
    board[src_row][src_col] = board[dest_row][dest_col];
    board[dest_row][dest_col] = temp;
}

int main() {
    Piece board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);
    print_board(board);
    return 0;
}