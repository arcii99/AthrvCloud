//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define GHOSTS 5
#define PLAYER_ICON 'P'
#define GHOST_ICON 'G'
#define WALL_ICON '#'

// Initialize the game board with walls and player
void initBoard(char board[][COLS], int playerPosition[2]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == playerPosition[0] && j == playerPosition[1]) {
                board[i][j] = PLAYER_ICON;
            }
            else if (i == 0 || i == ROWS-1 || j == 0 || j == COLS-1) {
                board[i][j] = WALL_ICON;
            }
            else {
                board[i][j] = ' ';
            }
        }
    }
}

// Randomly place ghosts on the board
void placeGhosts(char board[][COLS]) {
    int count = 0;
    while (count < GHOSTS) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if (board[row][col] == ' ') {
            board[row][col] = GHOST_ICON;
            count++;
        }
    }
}

// Print the game board
void printBoard(char board[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

// Check if the player has collided with a ghost
bool checkCollision(char board[][COLS], int playerPosition[2]) {
    if (board[playerPosition[0]][playerPosition[1]] == GHOST_ICON) {
        printf("Game over! You were caught by a ghost!\n");
        return true;
    }
    return false;
}

// Check if the player has reached the end of the game
bool checkWin(char board[][COLS], int playerPosition[2]) {
    if (board[playerPosition[0]][playerPosition[1]] == WALL_ICON) {
        printf("Congratulations! You made it out of the haunted house!\n");
        return true;
    }
    return false;
}

int main(void) {
    srand(time(NULL)); // Seed random number generator

    char board[ROWS][COLS];
    int playerPosition[2] = {1,1}; // Starting position of player

    initBoard(board, playerPosition);
    placeGhosts(board);
    printBoard(board);

    bool gameOver = false;
    while (!gameOver) {
        char move = '\0';
        printf("Enter your move (w,a,s,d): ");
        scanf(" %c", &move);

        // Update player position based on move
        switch(move) {
            case 'w':
                playerPosition[0]--;
                break;
            case 'a':
                playerPosition[1]--;
                break;
            case 's':
                playerPosition[0]++;
                break;
            case 'd':
                playerPosition[1]++;
                break;
            default:
                printf("Invalid move!\n");
                break;
        }

        // Check for collisions and wins
        gameOver = checkCollision(board, playerPosition);
        if (!gameOver) {
            gameOver = checkWin(board, playerPosition);
        }

        // Update board with new player position and print board
        board[playerPosition[0]][playerPosition[1]] = PLAYER_ICON;
        printBoard(board);

        // Remove player icon from previous position
        board[playerPosition[0]][playerPosition[1]] = ' ';
    }

    return 0;
}