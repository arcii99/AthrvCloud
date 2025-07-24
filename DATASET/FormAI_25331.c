//FormAI DATASET v1.0 Category: Checkers Game ; Style: creative
#include <stdio.h>

// Define the size of the board
#define BOARD_SIZE 8

// Define the pieces that can be on the board
#define EMPTY 0
#define BLACK 1
#define RED 2

int board[BOARD_SIZE][BOARD_SIZE] = {
    {0, 2, 0, 2, 0, 2, 0, 2},
    {2, 0, 2, 0, 2, 0, 2, 0},
    {0, 2, 0, 2, 0, 2, 0, 2},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {3, 0, 3, 0, 3, 0, 3, 0},
    {0, 3, 0, 3, 0, 3, 0, 3},
    {3, 0, 3, 0, 3, 0, 3, 0},
};

// Function to display the board
void display_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                printf(" ");
            } else if (board[i][j] == BLACK) {
                printf("B");
            } else if (board[i][j] == RED) {
                printf("R");
            }
            printf("|");
        }
        printf("\n");
    }
}

int main() {
    display_board();
    return 0;
}