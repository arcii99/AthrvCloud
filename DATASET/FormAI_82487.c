//FormAI DATASET v1.0 Category: Checkers Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// function to print the game board
void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n  | A | B | C | D | E | F | G | H |\n");
    printf("---------------------------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n---------------------------------\n");
    }
}

// function to initialize the game board
void init_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            // black pieces
            if (i < 3 && (i + j) % 2 == 0) {
                board[i][j] = 'b';
            }
            // white pieces
            else if (i > 4 && (i + j) % 2 == 0) {
                board[i][j] = 'w';
            }
            // empty spaces
            else {
                board[i][j] = ' ';
            }
        }
    }
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int turn = 1;
    int game_over = 0;
    init_board(board);
    while (!game_over) {
        printf("=================================\n");
        printf("    C CHECKERS GAME - Turn %d\n", turn);
        printf("=================================\n");
        print_board(board);
        // TODO: implement game logic
        turn++;
    }
    return 0;
}