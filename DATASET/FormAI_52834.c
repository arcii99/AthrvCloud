//FormAI DATASET v1.0 Category: Checkers Game ; Style: retro
#include <stdio.h>
#define BOARD_SIZE 8

// function to display the board on the console
void display_board(int board[][BOARD_SIZE])
{
    for (int i=0; i<BOARD_SIZE; i++) {
        for (int j=0; j<BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // initialize the board with 0s and 1s for pieces
    int board[BOARD_SIZE][BOARD_SIZE] = {
        {0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {2, 0, 2, 0, 2, 0, 2, 0},
        {0, 2, 0, 2, 0, 2, 0, 2},
        {2, 0, 2, 0, 2, 0, 2, 0}
    };

    // display the board
    display_board(board);

    return 0;
}