//FormAI DATASET v1.0 Category: Checkers Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE] = {0}; // initialize the board with all zeros

void printBoard() {
    printf("\n");
    printf("  0 1 2 3 4 5 6 7\n"); // column numbers
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i); // row number
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
                case -1: printf("x "); break;
                case 1: printf("o "); break;
                default: printf("- "); break;
            }
        }
        printf("\n");
    }
}

int main() {
    int player = 1; // player 'o' goes first

    printBoard();

    while (1) {
        int x, y;
        printf("\nPlayer %c's turn\n", player == -1 ? 'x' : 'o');
        printf("Enter the coordinates of the piece you want to move (x y): ");
        scanf("%d %d", &x, &y);

        if (board[x][y] == 0 || board[x][y]*player < 0) {
            printf("Invalid selection\n");
            continue;
        }

        printf("Enter the coordinates of the destination (x y): ");
        scanf("%d %d", &x, &y);

        if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE || board[x][y] != 0) {
            printf("Invalid move\n");
            continue;
        }

        // move piece
        board[x][y] = board[x][y] + board[x-1][y-1];
        board[x-1][y-1] = 0;

        printBoard();

        // check for win
        int win = 1;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == player) {
                    if (j-1 >= 0 && board[i+1][j-1] == 0) {
                        win = 0; // piece can still move
                    }
                    if (j+1 < BOARD_SIZE && board[i+1][j+1] == 0) {
                        win = 0; // piece can still move
                    }
                }
            }
        }

        if (win) {
            printf("\nPlayer %c wins!\n", player == -1 ? 'x' : 'o');
            break;
        }

        // switch player
        player = -player;
    }

    return 0;
}