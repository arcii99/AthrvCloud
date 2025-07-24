//FormAI DATASET v1.0 Category: Chess engine ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

// Function to initialize the chess board
void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    char pieces[] = {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'};
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[0][i] = pieces[i];
        board[1][i] = 'P';
        board[6][i] = 'p';
        board[7][i] = pieces[i] + 32;
    }
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the chess board
void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("+---+---+---+---+---+---+---+---+\n");
        printf("| ");
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n");
    }
    printf("+---+---+---+---+---+---+---+---+\n");
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);
    print_board(board);
    return 0;
}