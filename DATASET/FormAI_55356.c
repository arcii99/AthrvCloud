//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

// Define the size of the game board
#define ROWS 20
#define COLS 40

// Define the game board array
char board[ROWS][COLS];

// Define the player position variables
int playerRow, playerCol;

// Define the enemy variables
int enemyRow, enemyCol;
int enemyDirection; // 1 = Right, -1 = Left

// Define the bullet variables
int bulletRow, bulletCol;
bool bulletFired;

// Define the player input function
int getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

// Define the function to move the player left
void moveLeft() {
    if (playerCol > 0) {
        board[playerRow][playerCol] = ' ';
        playerCol--;
        board[playerRow][playerCol] = 'P';
    }
}

// Define the function to move the player right
void moveRight() {
    if (playerCol < COLS - 1) {
        board[playerRow][playerCol] = ' ';
        playerCol++;
        board[playerRow][playerCol] = 'P';
    }
}

// Define the function to fire the bullet
void fireBullet() {
    bulletRow = playerRow - 1;
    bulletCol = playerCol;
    bulletFired = true;
}

// Define the function to move the bullet
void moveBullet() {
    if (bulletRow > 0) {
        // Clear the current position of the bullet
        board[bulletRow][bulletCol] = ' ';

        // Move the bullet one row up
        bulletRow--;

        // Check if the bullet hit the enemy
        if (bulletRow == enemyRow && bulletCol == enemyCol) {
            // Reset the enemy position
            enemyRow = ROWS - 2;
            enemyCol = rand() % (COLS - 1);
            enemyDirection = rand() % 2 == 0 ? 1 : -1;

            // Mark the enemy as dead
            board[bulletRow][bulletCol] = 'X';
        }
        else {
            // Mark the new position of the bullet
            board[bulletRow][bulletCol] = '|';
        }
    }
    else {
        bulletFired = false;
    }
}

// Define the function to move the enemy
void moveEnemy() {
    // Clear the current position of the enemy
    board[enemyRow][enemyCol] = ' ';

    // Move the enemy one position left or right
    enemyCol += enemyDirection;

    // Check if the enemy hit the wall
    if (enemyCol <= 0) {
        enemyDirection = 1;
    }
    else if (enemyCol >= COLS - 1) {
        enemyDirection = -1;
    }

    // Mark the new position of the enemy
    board[enemyRow][enemyCol] = 'E';
}

// Define the function to draw the game board
void drawBoard() {
    // Clear the screen
    printf("\033[2J\033[1;1H");

    // Draw the game board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }

    // Print the game instructions
    printf("\nControls:\n");
    printf("Left arrow - Move left\n");
    printf("Right arrow - Move right\n");
    printf("Space - Fire\n");
}

// Define the main function
int main() {
    // Set the board boundaries
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == ROWS - 1 || j == 0 || j == COLS - 1) {
                board[i][j] = '#';
            }
            else {
                board[i][j] = ' ';
            }
        }
    }

    // Initialize the random seed
    srand(time(NULL));

    // Set the player position
    playerRow = ROWS - 2;
    playerCol = COLS / 2;
    board[playerRow][playerCol] = 'P';

    // Set the enemy position and direction
    enemyRow = ROWS - 4;
    enemyCol = rand() % (COLS - 1);
    enemyDirection = rand() % 2 == 0 ? 1 : -1;
    board[enemyRow][enemyCol] = 'E';

    // Initialize the bullet variables
    bulletFired = false;

    // Draw the initial game board
    drawBoard();

    // Start the game loop
    while (true) {
        // Check for player input
        int input = getch();

        switch (input) {
            case 27:
                // Check for arrow keys
                input = getch();
                if (input == 91) {
                    // Check for left arrow key
                    input = getch();
                    if (input == 68) {
                        moveLeft();
                    }
                    // Check for right arrow key
                    else if (input == 67) {
                        moveRight();
                    }
                }
                break;
            case 32:
                // Fire the bullet
                if (!bulletFired) {
                    fireBullet();
                }
                break;
        }

        // Move the bullet
        if (bulletFired) {
            moveBullet();
        }

        // Move the enemy
        moveEnemy();

        // Draw the game board
        drawBoard();

        // Pause the game for a short period
        usleep(100000);
    }

    return 0;
}