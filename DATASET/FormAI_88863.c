//FormAI DATASET v1.0 Category: Chess AI ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Define the chess board structure
typedef struct {
    char piece; // the type of piece occupying a square
    int color;  // the color of the piece (0 for white, 1 for black)
} Square;

// Define the chess board structure
typedef struct {
    Square squares[BOARD_SIZE][BOARD_SIZE]; // the array of squares that make up the board
    int turn;                                // the current player's turn (0 for white, 1 for black)
} Board;

// Initialize the board with starting positions for both players
void init_board(Board *board) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; ++i) {
        for (j = 0; j < BOARD_SIZE; ++j) {
            // Place pawns on the second (for white) and seventh (for black) ranks
            if (i == 1) {
                board->squares[i][j].piece = 'P';
                board->squares[i][j].color = 0;
            } else if (i == BOARD_SIZE - 2) {
                board->squares[i][j].piece = 'P';
                board->squares[i][j].color = 1;
            } else {
                board->squares[i][j].piece = ' ';
            }
        }
    }

    // Place rooks, knights and bishops on the first (for white) and eighth (for black) ranks
    board->squares[0][0].piece = 'R';
    board->squares[0][0].color = 0;
    board->squares[0][7].piece = 'R';
    board->squares[0][7].color = 0;
    board->squares[7][0].piece = 'R';
    board->squares[7][0].color = 1;
    board->squares[7][7].piece = 'R';
    board->squares[7][7].color = 1;

    board->squares[0][1].piece = 'N';
    board->squares[0][1].color = 0;
    board->squares[0][6].piece = 'N';
    board->squares[0][6].color = 0;
    board->squares[7][1].piece = 'N';
    board->squares[7][1].color = 1;
    board->squares[7][6].piece = 'N';
    board->squares[7][6].color = 1;

    board->squares[0][2].piece = 'B';
    board->squares[0][2].color = 0;
    board->squares[0][5].piece = 'B';
    board->squares[0][5].color = 0;
    board->squares[7][2].piece = 'B';
    board->squares[7][2].color = 1;
    board->squares[7][5].piece = 'B';
    board->squares[7][5].color = 1;

    // Place queens and kings on the fourth and fifth ranks (for both colors)
    board->squares[0][3].piece = 'Q';
    board->squares[0][3].color = 0;
    board->squares[0][4].piece = 'K';
    board->squares[0][4].color = 0;
    board->squares[7][3].piece = 'Q';
    board->squares[7][3].color = 1;
    board->squares[7][4].piece = 'K';
    board->squares[7][4].color = 1;

    // White goes first
    board->turn = 0;
}

// Print the board to the console
void print_board(Board *board) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; ++i) {
        for (j = 0; j < BOARD_SIZE; ++j) {
            printf("+---");
        }
        printf("+\n");

        for (j = 0; j < BOARD_SIZE; ++j) {
            printf("| %c ", board->squares[i][j].piece);
        }
        printf("|\n");
    }
    for (j = 0; j < BOARD_SIZE; ++j) {
        printf("+---");
    }
    printf("+\n");
}

int main() {
    // Initialize the board
    Board board;
    init_board(&board);

    // Print the board
    print_board(&board);

    return 0;
}