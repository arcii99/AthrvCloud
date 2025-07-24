//FormAI DATASET v1.0 Category: Chess engine ; Style: configurable
#include <stdio.h>

#define BOARD_SIZE 10

int board[BOARD_SIZE][BOARD_SIZE];

// Initialize the board
void init_board() {
    int i, j;
    // Rows 0 and 9 are for border purposes (cannot move outside board)
    for (i = 1; i < BOARD_SIZE-1; i++) {
        for (j = 1; j < BOARD_SIZE-1; j++) {
            board[i][j] = 0;
        }
    }
}

// Print the board to console
void print_board() {
    int i, j;
    printf("\n");
    for (i = 1; i < BOARD_SIZE-1; i++) {
        for (j = 1; j < BOARD_SIZE-1; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Move a piece on the board
int move(int x1, int y1, int x2, int y2) {
    if (x1 < 1 || x1 > 8 || y1 < 1 || y1 > 8 || x2 < 1 || x2 > 8 || y2 < 1 || y2 > 8) {
        // Move is out of bounds
        return -1;
    }
    if (board[x1][y1] == 0) {
        // No piece at starting position
        return -2;
    }
    if (board[x2][y2] != 0) {
        // Destination (x2, y2) is not empty
        return -3;
    }
    // Move the piece
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = 0;
    return 0;
}

// Example program demonstrating the chess engine
int main() {
    init_board();
    board[1][1] = 1; // Place a piece at starting position (1, 1)
    print_board(); // Print the board to console
    move(1, 1, 2, 2); // Move the piece to (2, 2)
    print_board(); // Print the board to console after the move
    return 0;
}