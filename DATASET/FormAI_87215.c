//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constants for game board dimensions
#define ROWS 5
#define COLS 10

// function declarations
void print_board(char gameBoard[ROWS][COLS]);
void shift_board(char gameBoard[ROWS][COLS]);
void init_board(char gameBoard[ROWS][COLS]);
void create_invaders(char gameBoard[ROWS][COLS]);

// main function
int main(void) {
    // seed random number generator
    srand(time(NULL));

    // create game board
    char gameBoard[ROWS][COLS];
    init_board(gameBoard);

    // create invaders
    create_invaders(gameBoard);

    // print initial game board
    print_board(gameBoard);

    // game loop
    while (1) {
        // shift the board
        shift_board(gameBoard);

        // create new invaders
        create_invaders(gameBoard);

        // print the board
        print_board(gameBoard);

        // wait a bit to slow down game
        usleep(500000); // 0.5 seconds
    }

    return 0;
}

// function to initialize game board
void init_board(char gameBoard[ROWS][COLS]) {
    // set all elements to '-'
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            gameBoard[i][j] = '-';
        }
    }
}

// function to create invaders
void create_invaders(char gameBoard[ROWS][COLS]) {
    // randomly add invaders to top row of board
    for (int i = 0; i < COLS; i++) {
        if (rand() % 10 < 3) { // 30% chance of adding invader
            gameBoard[0][i] = 'I';
        }
    }
}

// function to shift board down and to the right
void shift_board(char gameBoard[ROWS][COLS]) {
    // shift all rows down by one except for last row
    for (int i = ROWS - 2; i >= 0; i--) {
        for (int j = 0; j < COLS; j++) {
            gameBoard[i + 1][j] = gameBoard[i][j];
            gameBoard[i][j] = '-';
        }
    }

    // shift all columns to the right by one
    for (int j = COLS - 1; j > 0; j--) {
        for (int i = 0; i < ROWS; i++) {
            gameBoard[i][j] = gameBoard[i][j - 1];
        }
    }

    // set leftmost column to '-'
    for (int i = 0; i < ROWS; i++) {
        gameBoard[i][0] = '-';
    }
}

// function to print the game board
void print_board(char gameBoard[ROWS][COLS]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", gameBoard[i][j]);
        }
        printf("\n");
    }
}