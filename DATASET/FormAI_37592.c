//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24

// The player character
char player = 'A';

// The enemy characters
char enemies[3] = {'X', 'Y', 'Z'};

// The game board
char board[SCREEN_HEIGHT][SCREEN_WIDTH];

// The player's position
int playerPos = (SCREEN_WIDTH / 2) - 1;

// The enemy positions
int enemyPos[3] = {0, SCREEN_WIDTH/4, SCREEN_WIDTH/2};

// The enemy speeds
int enemySpeed[3] = {1, 2, 3};

// Function to initialize the game board
void initBoard() {
    int i, j;

    // Initialize the board to all empty spaces
    for (i = 0; i < SCREEN_HEIGHT; i++) {
        for (j = 0; j < SCREEN_WIDTH; j++) {
            board[i][j] = ' ';
        }
    }

    // Place the player character in the center of the board
    board[SCREEN_HEIGHT-1][playerPos] = player;

    // Place the enemies at the top of the board
    for (i = 0; i < 3; i++) {
        board[0][enemyPos[i]] = enemies[i];
    }
}

// Function to print the game board
void printBoard() {
    int i, j;

    // Clear the screen
    system("clear");

    // Print each character in the board array
    for (i = 0; i < SCREEN_HEIGHT; i++) {
        for (j = 0; j < SCREEN_WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

// Function to move the player character
void movePlayer(char direction) {
    // Move the player character left or right
    if (direction == 'L' && playerPos > 0) {
        board[SCREEN_HEIGHT-1][playerPos] = ' ';
        playerPos--;
        board[SCREEN_HEIGHT-1][playerPos] = player;
    }
    else if (direction == 'R' && playerPos < SCREEN_WIDTH-1) {
        board[SCREEN_HEIGHT-1][playerPos] = ' ';
        playerPos++;
        board[SCREEN_HEIGHT-1][playerPos] = player;
    }
}

// Function to move the enemy characters
void moveEnemies() {
    int i;

    // Move each enemy character down the screen
    for (i = 0; i < 3; i++) {
        board[0][enemyPos[i]] = ' ';
        enemyPos[i] += enemySpeed[i];
        board[0][enemyPos[i]] = enemies[i];
    }
}

// Function to check for collisions between the player and enemies
int checkCollisions() {
    int i;

    // Check each enemy character for collision with player
    for (i = 0; i < 3; i++) {
        if (enemyPos[i] == SCREEN_HEIGHT - 1 && playerPos == enemyPos[i]) {
            // Collision detected
            return 1;
        }
    }

    // No collision detected
    return 0;
}

// Function to generate a random number
int randomInt(int max) {
    srand(time(NULL));
    return rand() % max;
}

// Function to handle the game loop
void playGame() {
    char input;

    // Initialize the game board
    initBoard();

    // Game loop
    while (1) {
        // Move the enemies
        moveEnemies();

        // Check for collisions
        if (checkCollisions()) {
            // Game over
            printf("Game over!\n");
            break;
        }

        // Print the game board
        printBoard();

        // Get input from the user
        printf("Move left (press L), right (press R), or quit (press Q): ");
        scanf(" %c", &input);

        // Move the player character or quit the game
        if (input == 'L' || input == 'R') {
            movePlayer(input);
        }
        else if (input == 'Q') {
            break;
        }
    }
}

// Main function
int main() {
    // Welcome message
    printf("Welcome to C Space Invaders!\n");

    // Start the game
    playGame();

    // Exit message
    printf("Thanks for playing C Space Invaders!\n");

    return 0;
}