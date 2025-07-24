//FormAI DATASET v1.0 Category: Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLAYERS 2
#define BOARD_SIZE 10

void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("|");
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n");
    }
}

void placeShips(char board[BOARD_SIZE][BOARD_SIZE]) {
    srand(time(NULL));
    for(int i = 0; i < NUM_PLAYERS; i++) {
        int row = rand() % BOARD_SIZE;
        int col = rand() % BOARD_SIZE;
        board[row][col] = 'S';
    }
}

int main(void) {
    char board[BOARD_SIZE][BOARD_SIZE];
    initializeBoard(board);
    placeShips(board);
    printBoard(board);
    return 0;
}