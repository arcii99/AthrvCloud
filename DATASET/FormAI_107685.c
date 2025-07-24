//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the size of the game board
#define ROWS 20
#define COLS 20

// Define the characters for the game elements
#define WALL '#'
#define EMPTY ' '
#define DOT '.'
#define POWER_PELLET 'O'
#define PACMAN 'C'
#define GHOST 'G'

// Define the initial positions for Pac-Man and the Ghost
#define PACMAN_ROW 9
#define PACMAN_COL 9
#define GHOST_ROW 10
#define GHOST_COL 10

// Define the directions
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

// Define the game board
char gameBoard[ROWS][COLS] = {
    {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
    {WALL, DOT, DOT, DOT, DOT, DOT, DOT, DOT, WALL, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, WALL},
    {WALL, DOT, WALL, WALL, DOT, WALL, WALL, DOT, WALL, DOT, WALL, WALL, DOT, WALL, WALL, DOT, WALL, WALL, DOT, WALL},
    {WALL, POWER_PELLET, WALL, WALL, DOT, WALL, WALL, DOT, WALL, DOT, WALL, WALL, DOT, WALL, WALL, DOT, WALL, WALL, POWER_PELLET, WALL},
    {WALL, DOT, WALL, WALL, DOT, WALL, WALL, DOT, WALL, DOT, WALL, WALL, DOT, WALL, WALL, DOT, WALL, WALL, DOT, WALL},
    {WALL, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, WALL},
    {WALL, DOT, WALL, WALL, DOT, WALL, DOT, WALL, WALL, WALL, WALL, DOT, WALL, WALL, WALL, DOT, WALL, WALL, DOT, WALL},
    {WALL, DOT, DOT, DOT, DOT, WALL, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, WALL, DOT, DOT, DOT, DOT, WALL},
    {WALL, WALL, WALL, WALL, DOT, WALL, WALL, WALL, WALL, EMPTY, WALL, WALL, WALL, WALL, WALL, DOT, WALL, WALL, WALL, WALL},
    {EMPTY, EMPTY, EMPTY, WALL, DOT, WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL, DOT, WALL, EMPTY, EMPTY, EMPTY, EMPTY},
    {WALL, WALL, WALL, WALL, DOT, WALL, WALL, WALL, EMPTY, WALL, EMPTY, WALL, WALL, WALL, DOT, WALL, WALL, WALL, WALL, WALL},
    {EMPTY, EMPTY, EMPTY, EMPTY, DOT, EMPTY, EMPTY, WALL, EMPTY, EMPTY, EMPTY, WALL, EMPTY, EMPTY, DOT, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {WALL, WALL, WALL, WALL, DOT, WALL, WALL, WALL, EMPTY, WALL, EMPTY, WALL, WALL, WALL, DOT, WALL, WALL, WALL, WALL, WALL},
    {EMPTY, EMPTY, EMPTY, WALL, DOT, WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL, DOT, WALL, EMPTY, EMPTY, EMPTY, EMPTY},
    {WALL, WALL, WALL, WALL, DOT, WALL, WALL, DOT, WALL, WALL, WALL, WALL, DOT, WALL, WALL, DOT, WALL, WALL, WALL, WALL},
    {WALL, DOT, DOT, DOT, DOT, DOT, WALL, DOT, WALL, DOT, EMPTY, DOT, WALL, DOT, DOT, DOT, DOT, DOT, DOT, WALL},
    {WALL, DOT, WALL, WALL, DOT, WALL, WALL, DOT, WALL, DOT, WALL, WALL, DOT, WALL, WALL, DOT, WALL, WALL, DOT, WALL},
    {WALL, POWER_PELLET, DOT, WALL, DOT, WALL, WALL, DOT, EMPTY, DOT, EMPTY, WALL, DOT, WALL, WALL, DOT, WALL, DOT, POWER_PELLET, WALL},
    {WALL, DOT, DOT, DOT, DOT, WALL, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, WALL, DOT, DOT, DOT, DOT, WALL},
    {WALL, DOT, WALL, WALL, WALL, WALL, DOT, WALL, WALL, WALL, WALL, DOT, WALL, WALL, WALL, WALL, WALL, WALL, DOT, WALL},
    {WALL, DOT, DOT, DOT, DOT, WALL, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, WALL, DOT, DOT, DOT, DOT, WALL},
    {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL}
};

// Define the initial game state
int pacmanRow = PACMAN_ROW;
int pacmanCol = PACMAN_COL;
int ghostRow = GHOST_ROW;
int ghostCol = GHOST_COL;
int pacmanDirection = EAST;
int score = 0;

// Function to move the Pac-Man
void movePacman(int direction) {
    // Clear the current position of Pac-Man
    gameBoard[pacmanRow][pacmanCol] = EMPTY;

    // Move Pac-Man in the specified direction
    if (direction == NORTH) {
        pacmanRow--;
    } else if (direction == EAST) {
        pacmanCol++;
    } else if (direction == SOUTH) {
        pacmanRow++;
    } else if (direction == WEST) {
        pacmanCol--;
    }

    // Check for collision with game elements
    if (gameBoard[pacmanRow][pacmanCol] == DOT) {
        score++;
    } else if (gameBoard[pacmanRow][pacmanCol] == POWER_PELLET) {
        score += 10;
    } else if (gameBoard[pacmanRow][pacmanCol] == GHOST) {
        printf("Game Over!\n");
        exit(0);
    }

    // Set the new position of Pac-Man and update the game board
    gameBoard[pacmanRow][pacmanCol] = PACMAN;
}

// Function to move the Ghost
void moveGhost() {
    // Clear the current position of the Ghost
    gameBoard[ghostRow][ghostCol] = EMPTY;

    // Move the Ghost in a random direction
    int direction = rand() % 4;
    if (direction == NORTH) {
        ghostRow--;
    } else if (direction == EAST) {
        ghostCol++;
    } else if (direction == SOUTH) {
        ghostRow++;
    } else if (direction == WEST) {
        ghostCol--;
    }

    // Check for collision with Pac-Man
    if (ghostRow == pacmanRow && ghostCol == pacmanCol) {
        printf("Game Over!\n");
        exit(0);
    }

    // Set the new position of the Ghost and update the game board
    gameBoard[ghostRow][ghostCol] = GHOST;
}

int main() {
    // Initialize the random seed
    srand(time(NULL));

    // Set the initial position of Pac-Man and the Ghost
    gameBoard[pacmanRow][pacmanCol] = PACMAN;
    gameBoard[ghostRow][ghostCol] = GHOST;

    // Initialize the game loop
    bool gameRunning = true;
    while (gameRunning) {
        // Print the game board
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%c", gameBoard[i][j]);
            }
            printf("\n");
        }

        // Print the score
        printf("Score: %d\n", score);

        // Wait for user input
        printf("Enter direction (0 = North, 1 = East, 2 = South, 3 = West): ");
        scanf("%d", &pacmanDirection);

        // Move Pac-Man and the Ghost
        movePacman(pacmanDirection);
        moveGhost();
    }

    return 0;
}