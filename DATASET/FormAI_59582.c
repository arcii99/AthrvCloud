//FormAI DATASET v1.0 Category: Chess AI ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Structure to represent a piece on the board
typedef struct Piece {
    char type; // 'P' for Pawn, 'R' for Rook, 'N' for Knight, 'B' for Bishop, 'Q' for Queen, 'K' for King
    char color; // 'W' for White, 'B' for Black
    int x; // x coordinate on the board
    int y; // y coordinate on the board
} Piece;

// Function to initialize the board with pieces
void initialize_board(Piece board[BOARD_SIZE][BOARD_SIZE]) {
    // Pawns
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[1][i] = (Piece) {'P', 'W', i, 1};
        board[6][i] = (Piece) {'P', 'B', i, 6};
    }

    // Rooks
    board[0][0] = (Piece) {'R', 'W', 0, 0};
    board[0][7] = (Piece) {'R', 'W', 7, 0};
    board[7][0] = (Piece) {'R', 'B', 0, 7};
    board[7][7] = (Piece) {'R', 'B', 7, 7};

    // Knights
    board[0][1] = (Piece) {'N', 'W', 1, 0};
    board[0][6] = (Piece) {'N', 'W', 6, 0};
    board[7][1] = (Piece) {'N', 'B', 1, 7};
    board[7][6] = (Piece) {'N', 'B', 6, 7};

    // Bishops
    board[0][2] = (Piece) {'B', 'W', 2, 0};
    board[0][5] = (Piece) {'B', 'W', 5, 0};
    board[7][2] = (Piece) {'B', 'B', 2, 7};
    board[7][5] = (Piece) {'B', 'B', 5, 7};

    // Queens
    board[0][3] = (Piece) {'Q', 'W', 3, 0};
    board[7][3] = (Piece) {'Q', 'B', 3, 7};

    // Kings
    board[0][4] = (Piece) {'K', 'W', 4, 0};
    board[7][4] = (Piece) {'K', 'B', 4, 7};
}

// Function to print the board
void print_board(Piece board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].type == 0) {
                printf("- ");
            } else {
                printf("%c ", board[i][j].type);
            }
        }
        printf("\n");
    }
}

int main() {
    // Initialize the board
    Piece board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);

    // Print the board
    print_board(board);

    return 0;
}