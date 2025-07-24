//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Cyberpunk
// A Cyberpunk-style Terminal Based Game

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Size of game board
#define SIZE 10

// Function to print game board
void printBoard(char board[SIZE][SIZE], bool hidden) {
    printf("\n\n");

    // Print top border
    printf("\t   ");
    for (int x = 0; x < SIZE; x++) {
        printf("+---");
    }
    printf("+\n");

    // Print each row
    for (int y = 0; y < SIZE; y++) {
        printf("\t%2d ", y+1);
        for (int x = 0; x < SIZE; x++) {
            if (hidden && board[y][x] == 'O') {
                printf("|   ");
            } else {
                printf("| %c ", board[y][x]);
            }
        }
        printf("|\n\t   ");
        for (int x = 0; x < SIZE; x++) {
            printf("+---");
        }
        printf("+\n");
    }
}

// Function to check if coordinates are valid
bool isValid(int x, int y) {
    return x >= 0 && y >= 0 && x < SIZE && y < SIZE;
}

int main() {
    // Seed random function
    srand(time(NULL));

    // Initialize game board
    char board[SIZE][SIZE];
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            board[y][x] = 'O';
        }
    }

    // Place random obstacles
    int numObstacles = (int)((SIZE*SIZE)/5);
    for (int i = 0; i < numObstacles; i++) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        board[y][x] = 'X';
    }

    // Place random player
    int playerX = rand() % SIZE;
    int playerY = rand() % SIZE;
    board[playerY][playerX] = 'P';

    // Game loop
    bool gameOver = false;
    while (!gameOver) {
        // Print game board
        printBoard(board, true);

        // Take user input
        printf("\n\nEnter move (w,a,s,d): ");
        char move;
        scanf(" %c", &move);

        // Calculate new player position
        int newPlayerX = playerX;
        int newPlayerY = playerY;
        if (move == 'w') {
            newPlayerY--;
        } else if (move == 'a') {
            newPlayerX--;
        } else if (move == 's') {
            newPlayerY++;
        } else if (move == 'd') {
            newPlayerX++;
        }

        // Check if new player position is valid
        if (!isValid(newPlayerX, newPlayerY)) {
            printf("\nInvalid move!\n");
            continue;
        }

        // Check if new player position is obstacle or player
        if (board[newPlayerY][newPlayerX] == 'X') {
            printf("\nYou hit an obstacle and died...\n");
            gameOver = true;
        } else if (board[newPlayerY][newPlayerX] == 'P') {
            printf("\nYou found another player and started a fight!\n");
            gameOver = true;
        } else {
            board[playerY][playerX] = ' ';
            board[newPlayerY][newPlayerX] = 'P';
            playerX = newPlayerX;
            playerY = newPlayerY;
        }
    }

    printf("\n\nGame Over!\n");

    return 0;
}