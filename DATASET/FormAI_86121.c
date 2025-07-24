//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define ROWS 5
#define COLS 10

// Declare global variables
int playerPosition = COLS / 2;
int score = 0;
int lives = 3;
char board[ROWS][COLS];

// Initialize the board
void initBoard() {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == ROWS - 1) {
                board[i][j] = '_';
            } else {
                board[i][j] = ' ';
            }
        }
    }

    board[ROWS - 1][playerPosition] = '^';
}

// Print the board
void printBoard() {
    int i, j;

    printf("\nScore: %d Lives: %d\n", score, lives);

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < COLS; i++) {
        printf("-");
    }
    printf("\n");
}

// Move the player left
void moveLeft() {
    if (playerPosition > 0) {
        board[ROWS - 1][playerPosition] = ' ';
        playerPosition--;
        board[ROWS - 1][playerPosition] = '^';
    }
}

// Move the player right
void moveRight() {
    if (playerPosition < COLS - 1) {
        board[ROWS - 1][playerPosition] = ' ';
        playerPosition++;
        board[ROWS - 1][playerPosition] = '^';
    }
}

// Move the bullets up
void moveBullets() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == '|') {
                board[i][j] = ' ';
                if (i > 0) {
                    if (board[i - 1][j] == 'o') {
                        score++;
                    }
                    board[i - 1][j] = '|';
                }
            }
        }
    }
}

// Move the enemy ships down
void moveEnemies() {
    int i, j;
    for (i = ROWS - 2; i >= 0; i--) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == 'o') {
                board[i][j] = ' ';
                if (i < ROWS - 2) {
                    board[i + 1][j] = 'o';
                } else {
                    // Enemy ship reached player
                    lives--;
                    if (lives <= 0) {
                        printf("\nGame Over!\n");
                        exit(0);
                    }
                    initBoard();
                }
            }
        }
    }
}

// Spawn a new enemy ship randomly in each row
void spawnEnemies() {
    int i, j;
    for (i = 0; i < ROWS - 1; i++) {
        if (rand() % 5 == 0) {
            j = rand() % COLS;
            if (board[i][j] != '^' && board[i][j] != 'o') {
                board[i][j] = 'o';
            }
        }
    }
}

// Fire a bullet from the player
void fireBullet() {
    int i;
    for (i = ROWS - 2; i >= 0; i--) {
        if (board[i][playerPosition] == ' ') {
            board[i][playerPosition] = '|';
            break;
        }
    }
}

// Main game loop
void *gameLoop(void *arg) {
    while (1) {
        system("clear");

        // Move the bullets up
        moveBullets();

        // Move the enemy ships down
        moveEnemies();

        // Spawn new enemy ships
        spawnEnemies();

        // Print the board
        printBoard();

        // Sleep to slow down the game
        usleep(100000);

        // Check for user input
        char input = getchar();
        if (input == 'a' || input == 'A') {
            moveLeft();
        } else if (input == 'd' || input == 'D') {
            moveRight();
        } else if (input == ' ') {
            fireBullet();
        }
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the board
    initBoard();

    // Create a new thread for the game loop
    pthread_t tid;
    pthread_create(&tid, NULL, gameLoop, NULL);

    // Wait for the game loop to finish
    pthread_join(tid, NULL);

    return 0;
}