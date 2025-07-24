//FormAI DATASET v1.0 Category: Checkers Game ; Style: ultraprecise
#include <stdio.h>

#define BOARD_SIZE 8

// Initializes the board with pieces
void init_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    // black pieces
    board[0][1] = 'b';
    board[0][3] = 'b';
    board[0][5] = 'b';
    board[0][7] = 'b';
    board[1][0] = 'b';
    board[1][2] = 'b';
    board[1][4] = 'b';
    board[1][6] = 'b';
    board[2][1] = 'b';
    board[2][3] = 'b';
    board[2][5] = 'b';
    board[2][7] = 'b';
    // white pieces
    board[5][0] = 'w';
    board[5][2] = 'w';
    board[5][4] = 'w';
    board[5][6] = 'w';
    board[6][1] = 'w';
    board[6][3] = 'w';
    board[6][5] = 'w';
    board[6][7] = 'w';
    board[7][0] = 'w';
    board[7][2] = 'w';
    board[7][4] = 'w';
    board[7][6] = 'w';
}

// Prints the current board state
void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("    0   1   2   3   4   5   6   7\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("  +---+---+---+---+---+---+---+---+\n");
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("| %c ", board[i][j] == '\0' ? ' ' : board[i][j]);
        }
        printf("|\n");
    }
    printf("  +---+---+---+---+---+---+---+---+\n");
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE] = {0};
    int turn = 0; // 0 for black, 1 for white

    // initializations
    init_board(board);
    print_board(board);

    return 0;
}