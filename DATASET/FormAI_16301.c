//FormAI DATASET v1.0 Category: Chess engine ; Style: interoperable
// This is a basic example of a Chess engine written in C.
// It can currently only make random moves and does not check for check or checkmate.
// To interface with other programs, simply parse the input and output the chosen move in algebraic notation.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the Chess board as a 2D array of integers.
int board[8][8] = {
    {2, 3, 4, 5, 6, 4, 3, 2},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {-2,-3,-4,-5,-6,-4,-3,-2}
};

// Define a function to print the current Chess board.
void print_board() {
    printf("\n  a b c d e f g h\n");
    for (int i = 0; i < 8; ++i) {
        printf("%d ", 8 - i);
        for (int j = 0; j < 8; ++j) {
            printf("%c ", board[i][j] ? abs(board[i][j])+'a'-1 : '.');
        }
        printf("%d\n", 8 - i);
    }
    printf("  a b c d e f g h\n\n");
}

// Define a function to generate a random move.
// For now, we simply move a random piece to a random empty square.
void random_move() {
    int from_x, from_y, to_x, to_y;
    do {
        from_x = rand() % 8;
        from_y = rand() % 8;
    } while (!board[from_x][from_y]);

    do {
        to_x = rand() % 8;
        to_y = rand() % 8;
    } while (board[to_x][to_y]);

    int piece = board[from_x][from_y];
    board[from_x][from_y] = 0;
    board[to_x][to_y] = piece;
}

int main() {
    // Seed the random number generator.
    srand(time(NULL));

    // Print the initial board and make random moves until the game ends (for now, infinite loop).
    print_board();
    while (1) {
        random_move();
        print_board();
    }

    return 0;
}