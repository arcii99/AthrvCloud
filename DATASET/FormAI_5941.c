//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 5
#define COLUMNS 10

int main() {
    // Initializing variables for game
    int playerX = ((COLUMNS - 1) / 2); // Starting position of player
    int score = 0; // Initializing score to 0
    bool gameWon = false; // Initializing gameWon to false
    bool gameOver = false; // Initializing gameOver to false
    char gameGrid[ROWS][COLUMNS]; // Initializing gameGrid to ROWS x COLUMNS

    // Setting up initial gameGrid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            gameGrid[i][j] = ' ';
        }
    }
    // Setting the player in the initial position
    gameGrid[ROWS - 1][playerX] = '*';

    // Setting up initial invaders in random columns
    srand(time(NULL)); // Initializing random seed
    for (int i = 0; i < ROWS-2; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (rand() % 4 == 0) {
                gameGrid[i][j] = 'X';
            }
        }
    }

    // Game loop
    while (!gameWon && !gameOver) {
        // Printing gameGrid
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                printf("%c", gameGrid[i][j]);
            }
            printf("\n");
        }

        // Player moves left or right
        char direction;
        printf("Enter 'l' to move left or 'r' to move right: ");
        scanf(" %c", &direction);
        if (direction == 'l' && playerX > 0) {
            gameGrid[ROWS - 1][playerX] = ' '; // Remove player from previous position
            playerX--;
            gameGrid[ROWS - 1][playerX] = '*';
        }
        else if (direction == 'r' && playerX < COLUMNS - 1) {
            gameGrid[ROWS - 1][playerX] = ' '; // Remove player from previous position
            playerX++;
            gameGrid[ROWS - 1][playerX] = '*';
        }

        // Invaders move down
        for (int i = ROWS - 3; i >= 0; i--) {
            for (int j = 0; j < COLUMNS; j++) {
                if (gameGrid[i][j] == 'X') {
                    gameGrid[i][j] = ' '; // Remove invader from previous position
                    gameGrid[i+1][j] = 'X'; // Move invader down
                }
            }
        }
        // Invaders shoot randomly
        for (int i = 0; i < COLUMNS; i++) {
            if (gameGrid[0][i] == 'X' && rand() % 4 == 0) {
                gameGrid[1][i] = '-'; // Invader shoots
            }
        }

        // Player shoots
        int bulletX = playerX;
        int bulletY = ROWS - 2; // Starting position of bullet
        char bulletMoved = ' '; // Initializing bulletMoved to blank
        char bulletKill = ' '; // Initializing bulletKill to blank
        printf("Enter 's' to shoot: ");
        scanf(" %c", &direction);
        if (direction == 's') {
            while (bulletMoved != 'X' && bulletY >= 0) {
                gameGrid[bulletY][bulletX] = bulletKill;
                bulletY--;
                bulletMoved = gameGrid[bulletY][bulletX];
                gameGrid[bulletY][bulletX] = '|';
                bulletKill = ' ';
                if (bulletMoved == 'X') {
                    score += 10; // Increase score by 10
                    break;
                }
            }
        }

        // Checking end game conditions
        int invaderCount = 0;
        for (int i = ROWS - 3; i >= 0; i--) {
            for (int j = 0; j < COLUMNS; j++) {
                if (gameGrid[i][j] == 'X') {
                    invaderCount++;
                }
                if (gameGrid[i][j] == '|') {
                    gameGrid[i][j] = ' '; // Remove bullet from previous position
                }
                if (gameGrid[i][j] == '-' && i < ROWS - 2) {
                    gameGrid[i][j] = ' '; // Remove invader bullet from previous position
                    if (gameGrid[i+1][j] == '*') {
                        // Player hit, end game
                        gameOver = true;
                        break;
                    }
                }
            }
            if (gameOver) {
                break;
            }
        }
        if (invaderCount == 0) {
            // All invaders have been defeated, game won
            gameWon = true;
        }
    }

    // End Game
    if (gameWon) {
        printf("Congratulations, you won!\n");
        printf("Score: %d\n", score);
    }
    else {
        printf("Game Over\n");
        printf("Score: %d\n", score);
    }

    return 0;
}