//FormAI DATASET v1.0 Category: Chess engine ; Style: beginner-friendly
#include <stdio.h>
#define BOARD_SIZE 8

// Struct to represent each piece on the board
typedef struct Piece {
    char symbol; // Character symbol of the piece
    int color; // 0 for white, 1 for black
} Piece;

// Function to initialize the board with starting pieces
void initializeBoard(Piece board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    // Initialize white pieces on the board
    for (i = 0; i < BOARD_SIZE; i++) {
        board[1][i].symbol = 'P';
        board[1][i].color = 0;
    }
    board[0][0].symbol = 'R';
    board[0][1].symbol = 'N';
    board[0][2].symbol = 'B';
    board[0][3].symbol = 'Q';
    board[0][4].symbol = 'K';
    board[0][5].symbol = 'B';
    board[0][6].symbol = 'N';
    board[0][7].symbol = 'R';
    for (i = 0; i < BOARD_SIZE; i++) {
        board[0][i].color = 0;
    }
    // Initialize black pieces on the board
    for (i = 0; i < BOARD_SIZE; i++) {
        board[6][i].symbol = 'P';
        board[6][i].color = 1;
    }
    board[7][0].symbol = 'R';
    board[7][1].symbol = 'N';
    board[7][2].symbol = 'B';
    board[7][3].symbol = 'Q';
    board[7][4].symbol = 'K';
    board[7][5].symbol = 'B';
    board[7][6].symbol = 'N';
    board[7][7].symbol = 'R';
    for (i = 0; i < BOARD_SIZE; i++) {
        board[7][i].color = 1;
    }
}

// Function to print out the current state of the board
void printBoard(Piece board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    printf("  a b c d e f g h\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", BOARD_SIZE - i);
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j].symbol);
        }
        printf("%d\n", BOARD_SIZE - i);
    }
    printf("  a b c d e f g h\n");
}

int main() {
    Piece board[BOARD_SIZE][BOARD_SIZE];
    initializeBoard(board);
    printBoard(board);
    return 0;
}