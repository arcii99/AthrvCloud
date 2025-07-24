//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// Board size
#define ROWS 10
#define COLUMNS 10

// Player struct
typedef struct {
    int row;
    int column;
    bool alive;
} Player; 

// Global variables
Player playerOne;
Player playerTwo;
char gameBoard[ROWS][COLUMNS];

// Function prototypes
void initializeBoard();
void initializePlayers();
int randomInt(int max);
bool isValidMove(int row, int column);
void makeMove(Player *player);
void printBoard();
void playGame();

int main() {
    initializeBoard();
    initializePlayers();
    playGame();

    return 0;
}

// Initializes the game board with dots
void initializeBoard() {
    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLUMNS; column++) {
            gameBoard[row][column] = '.';
        }
    }
}

// Initializes the players at opposite corners of the board
void initializePlayers() {
    playerOne.row = 0;
    playerOne.column = 0;
    playerOne.alive = true;

    playerTwo.row = ROWS - 1;
    playerTwo.column = COLUMNS - 1;
    playerTwo.alive = true;

    gameBoard[playerOne.row][playerOne.column] = 'P';
    gameBoard[playerTwo.row][playerTwo.column] = 'P';
}

// Returns a random integer from 0 to max (inclusive)
int randomInt(int max) {
    srand(time(NULL));
    return rand() % (max + 1);
}

// Checks if a move is valid (within the bounds of the board and not occupied by another player)
bool isValidMove(int row, int column) {
    if (row < 0 || row >= ROWS || column < 0 || column >= COLUMNS) {
        return false;
    }

    if (gameBoard[row][column] != '.') {
        return false;
    }

    return true;
}

// Makes a move for the player
void makeMove(Player *player) {
    int moveRow, moveColumn;

    // Prompt the player for their move
    printf("Player %d, enter your move (row column): ", (player == &playerOne ? 1 : 2));
    scanf("%d %d", &moveRow, &moveColumn);

    // Keep prompting the player until they enter a valid move
    while (!isValidMove(moveRow, moveColumn)) {
        printf("Invalid move. Try again: ");
        scanf("%d %d", &moveRow, &moveColumn);
    }

    // Update the game board
    gameBoard[player->row][player->column] = '.';
    player->row = moveRow;
    player->column = moveColumn;
    gameBoard[player->row][player->column] = 'P';
}

// Prints the current state of the game board
void printBoard() {
    printf("  ");
    for (int column = 0; column < COLUMNS; column++) {
        printf("%d ", column);
    }
    printf("\n");

    for (int row = 0; row < ROWS; row++) {
        printf("%d ", row);

        for (int column = 0; column < COLUMNS; column++) {
            printf("%c ", gameBoard[row][column]);

            if (column == COLUMNS - 1) {
                printf("\n");
            }
        }
    }
    printf("\n");
}

// Plays the game until one of the players wins
void playGame() {
    bool gameOver = false;

    while (!gameOver) {
        printf("\n");
        printBoard();

        makeMove(&playerOne);
        printf("\n");
        if (playerTwo.alive) {
            makeMove(&playerTwo);
        }

        // Check if either player has won
        if (playerOne.row == ROWS - 1 && playerOne.column == COLUMNS - 1) {
            printf("Player 1 wins!");
            gameOver = true;
        } else if (playerTwo.row == 0 && playerTwo.column == 0) {
            printf("Player 2 wins!");
            gameOver = true;
        }
    }
}