//FormAI DATASET v1.0 Category: Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define BOARD_SIZE 10
#define MAX_ATTEMPTS 30
#define SHIP_SIZE 5

// Define global variables
int board[BOARD_SIZE][BOARD_SIZE] = {0};
int attempts = 0;

// Declare functions
void initializeBoard();
void printBoard(int showShips);
void placeShip();
void play();

int main() {
    // seed the random number generator
    srand(time(NULL));

    // initialize the board
    initializeBoard();

    // place the ship
    placeShip();

    // play the game
    play();

    return 0;
}

// Function to initialize the board
void initializeBoard() {
    for (int x = 0; x < BOARD_SIZE; x++) {
        for (int y = 0; y < BOARD_SIZE; y++) {
            board[x][y] = 0;
        }
    }
}

// Function to print the board
void printBoard(int showShips) {
    printf("\n\n\n     0  1  2  3  4  5  6  7  8  9\n");
    printf("   +-------------------------------+\n");
    for (int x = 0; x < BOARD_SIZE; x++) {
        printf(" %d |", x);
        for (int y = 0; y < BOARD_SIZE; y++) {
            if (board[x][y] == 0 || (!showShips && board[x][y] == 1)) {
                printf("  ");
            } else {
                printf("%c ", board[x][y] == 2 ? '*' : board[x][y]);
            }
        }
        printf("|\n");
    }
    printf("   +-------------------------------+\n");
}

// Function to randomly place the ship on the board
void placeShip() {
    int x = rand() % BOARD_SIZE;
    int y = rand() % BOARD_SIZE;
    board[x][y] = 1;

    for (int i = 0; i < SHIP_SIZE - 1; i++) {
        int direction = rand() % 4;
        switch (direction) {
            case 0: // up
                if (x-i-1 >= 0 && board[x-i-1][y] == 0) {
                    board[x-i-1][y] = 1;
                } else {
                    i--;
                }
                break;
            case 1: // right
                if (y+i+1 < BOARD_SIZE && board[x][y+i+1] == 0) {
                    board[x][y+i+1] = 1;
                } else {
                    i--;
                }
                break;
            case 2: // down
                if (x+i+1 < BOARD_SIZE && board[x+i+1][y] == 0) {
                    board[x+i+1][y] = 1;
                } else {
                    i--;
                }
                break;
            case 3: // left
                if (y-i-1 >= 0 && board[x][y-i-1] == 0) {
                    board[x][y-i-1] = 1;
                } else {
                    i--;
                }
                break;
        }
    }
}

// Function to play the game
void play() {
    int x, y;
    int hit = 0;

    do {
        printf("\n\n\n");
        printBoard(0);
        printf("\nAttempts: %d/%d", attempts, MAX_ATTEMPTS);
        printf("\n\nEnter coordinates (x, y): ");
        scanf("%d %d", &x, &y);
        attempts++;

        switch (board[x][y]) {
            case 0:
                printf("\n\n\nMiss!");
                break;
            case 1:
                printf("\n\n\nHit!");
                board[x][y] = 2;
                hit++;
                break;
            case 2:
                printf("\n\n\nYou already hit that spot!");
                attempts--;
                break;
        }

    } while (hit < SHIP_SIZE && attempts < MAX_ATTEMPTS);

    if (hit == SHIP_SIZE) {
        printf("\n\n\nCongratulations, you sunk the enemy ship!");
    } else {
        printf("\n\n\nGame over, you ran out of attempts!");
    }

    printBoard(1);
}