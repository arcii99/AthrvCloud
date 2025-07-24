//FormAI DATASET v1.0 Category: Checkers Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE] = {
    {'_', 'b', '_', 'b', '_', 'b', '_', 'b'},
    {'b', '_', 'b', '_', 'b', '_', 'b', '_'},
    {'_', 'b', '_', 'b', '_', 'b', '_', 'b'},
    {'_', '_', '_', '_', '_', '_', '_', '_'},
    {'_', '_', '_', '_', '_', '_', '_', '_'},
    {'w', '_', 'w', '_', 'w', '_', 'w', '_'},
    {'_', 'w', '_', 'w', '_', 'w', '_', 'w'},
    {'w', '_', 'w', '_', 'w', '_', 'w', '_'}
};

void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Welcome to Checkers!\n");
    printf("To move a piece, enter the row and column of the piece you want to move and the row and column to move it to\n");

    bool game_over = false;
    int turn = 1;

    while (!game_over) {
        printf("Player %d's turn\n", turn);

        print_board();

        // TO DO: Implement move validation and game logic

        turn = turn == 1 ? 2 : 1;
    }

    printf("Game over!\n");

    return 0;
}