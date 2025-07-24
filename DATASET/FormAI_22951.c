//FormAI DATASET v1.0 Category: Checkers Game ; Style: relaxed
#include <stdio.h>

// Constants for the board size and pieces
#define BOARD_SIZE 8
#define RED 'R'
#define BLACK 'B'
#define KING 'K'
#define EMPTY ' '

// Struct to represent a piece on the board
typedef struct Piece {
    char color; // R for red, B for black
    char type; // K for king, empty for normal piece
} Piece;

// Function to initialize the board with pieces in their initial positions
void initialize_board(Piece board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;

    // Set up the black pieces on the top three rows
    for (i = 0; i < 3; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j].color = BLACK;
                board[i][j].type = EMPTY;
            }
            else {
                board[i][j].color = EMPTY;
                board[i][j].type = EMPTY;
            }
        }
    }

    // Set up the red pieces on the bottom three rows
    for (i = BOARD_SIZE - 1; i > BOARD_SIZE - 4; i--) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j].color = RED;
                board[i][j].type = EMPTY;
            }
            else {
                board[i][j].color = EMPTY;
                board[i][j].type = EMPTY;
            }
        }
    }
}

// Function to print the board to the console
void print_board(Piece board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;

    printf("  ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                printf("%c ", EMPTY);
            }
            else {
                if (board[i][j].type == EMPTY) {
                    printf("%c ", board[i][j].color);
                }
                else {
                    printf("%c%c", board[i][j].color, board[i][j].type);
                }
            }
        }
        printf("%d\n", i);
    }

    printf("  ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

int main() {
    Piece board[BOARD_SIZE][BOARD_SIZE];

    // Initialize the board
    initialize_board(board);

    // Print the board to the console
    print_board(board);

    return 0;
}