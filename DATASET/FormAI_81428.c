//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Define the size of the game board
#define BOARD_SIZE_X 80
#define BOARD_SIZE_Y 24

// Define the maximum number of enemies on the board
#define MAX_ENEMIES 10

// Define the player and enemy characters
#define PLAYER '@'
#define ENEMY 'E'

// Define the game board and player position variables
char gameBoard[BOARD_SIZE_Y][BOARD_SIZE_X];
int playerPosX, playerPosY;

// Define the enemy position and health variables
int enemyPosX[MAX_ENEMIES], enemyPosY[MAX_ENEMIES];
int enemyHealth[MAX_ENEMIES];

// Define the random number generator function
int randInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Define the function to generate the game board
void generateBoard() {
    // Fill the game board with empty spaces
    for (int y = 0; y < BOARD_SIZE_Y; y++) {
        for (int x = 0; x < BOARD_SIZE_X; x++) {
            gameBoard[y][x] = ' ';
        }
    }

    // Place the player in the center of the board
    playerPosX = BOARD_SIZE_X / 2;
    playerPosY = BOARD_SIZE_Y / 2;
    gameBoard[playerPosY][playerPosX] = PLAYER;

    // Place the enemies randomly on the board
    for (int i = 0; i < MAX_ENEMIES; i++) {
        enemyPosX[i] = randInt(0, BOARD_SIZE_X - 1);
        enemyPosY[i] = randInt(0, BOARD_SIZE_Y - 1);
        gameBoard[enemyPosY[i]][enemyPosX[i]] = ENEMY;
        enemyHealth[i] = randInt(1, 5);
    }
}

// Define the function to display the game board
void displayBoard() {
    // Clear the console screen
    system("clear");

    // Print the game board
    for (int y = 0; y < BOARD_SIZE_Y; y++) {
        for (int x = 0; x < BOARD_SIZE_X; x++) {
            printf("%c", gameBoard[y][x]);
        }
        printf("\n");
    }
}

// Define the function to move the player
void movePlayer(int dirX, int dirY) {
    // Calculate the new player position
    int newPlayerPosX = playerPosX + dirX;
    int newPlayerPosY = playerPosY + dirY;

    // Check if the new position is within the boundaries of the board
    if (newPlayerPosX >= 0 && newPlayerPosX < BOARD_SIZE_X && newPlayerPosY >= 0 && newPlayerPosY < BOARD_SIZE_Y) {
        // Check if the new position is empty or occupied by an enemy
        if (gameBoard[newPlayerPosY][newPlayerPosX] == ' ') {
            // Move the player to the new position
            gameBoard[playerPosY][playerPosX] = ' ';
            playerPosX = newPlayerPosX;
            playerPosY = newPlayerPosY;
            gameBoard[playerPosY][playerPosX] = PLAYER;
        } else if (gameBoard[newPlayerPosY][newPlayerPosX] == ENEMY) {
            // Attack the enemy and move the player to the new position
            for (int i = 0; i < MAX_ENEMIES; i++) {
                if (enemyPosX[i] == newPlayerPosX && enemyPosY[i] == newPlayerPosY && enemyHealth[i] > 0) {
                    enemyHealth[i]--;
                    if (enemyHealth[i] == 0) {
                        gameBoard[enemyPosY[i]][enemyPosX[i]] = ' ';
                    }
                    break;
                }
            }
            gameBoard[playerPosY][playerPosX] = ' ';
            playerPosX = newPlayerPosX;
            playerPosY = newPlayerPosY;
            gameBoard[playerPosY][playerPosX] = PLAYER;
        }
    }
}

// Define the main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate the game board
    generateBoard();

    // Main game loop
    while (1) {
        // Display the game board
        displayBoard();

        // Get the player input
        char input = getchar();

        // Move the player according to the input
        switch (input) {
            case 'w':
                movePlayer(0, -1);
                break;
            case 'a':
                movePlayer(-1, 0);
                break;
            case 's':
                movePlayer(0, 1);
                break;
            case 'd':
                movePlayer(1, 0);
                break;
        }
    }

    return 0;
}