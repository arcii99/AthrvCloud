//FormAI DATASET v1.0 Category: Checkers Game ; Style: energetic
#include <stdio.h>

#define BOARD_SIZE 8 // Board size
#define EMPTY '-' // Empty square
#define BLACK 'B' // Black piece
#define WHITE 'W' // White piece

char board[BOARD_SIZE][BOARD_SIZE]; // Game board

void init_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) { // Fill odd squares
                if (i < 3) board[i][j] = WHITE;
                else if (i > 4) board[i][j] = BLACK;
                else board[i][j] = EMPTY;
            } else board[i][j] = EMPTY; // Fill even squares
        }
    }
}

void print_board() {
    printf(" ");
    for (int i = 0; i < BOARD_SIZE; i++) printf(" %d", i);
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) printf("%c ", board[i][j]);
        printf("\n");
    }
}

int main() {
    init_board();
    print_board();
    return 0;
}