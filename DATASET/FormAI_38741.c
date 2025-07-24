//FormAI DATASET v1.0 Category: Chess engine ; Style: configurable
#include <stdlib.h>
#include <stdio.h>

// Define the board as a 2D 8x8 array
char board[8][8] = {
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
};

// Function to print the board
void print_board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to move a piece
void move_piece(int from_x, int from_y, int to_x, int to_y) {
    board[to_x][to_y] = board[from_x][from_y];
    board[from_x][from_y] = ' ';
}

int main() {
    // Start the game by printing the board
    print_board();
    
    // Move the pawn from (1, 0) to (2, 0)
    move_piece(1, 0, 2, 0);
    printf("\nAfter moving pawn from (1, 0) to (2, 0):\n");
    print_board();

    // Move the pawn from (6, 0) to (4, 0)
    move_piece(6, 0, 4, 0);
    printf("\nAfter moving pawn from (6, 0) to (4, 0):\n");
    print_board();

    // Move the bishop from (0, 2) to (2, 0)
    move_piece(0, 2, 2, 0);
    printf("\nAfter moving bishop from (0, 2) to (2, 0):\n");
    print_board();

    return 0;
}