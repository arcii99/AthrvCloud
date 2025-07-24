//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Game board constants
#define BOARD_HEIGHT 20
#define BOARD_WIDTH 30

// Pac-Man constants
#define PACMAN_START_X 15
#define PACMAN_START_Y 10
#define PACMAN_LIVES 3

// Pellet and power-up constants
#define NUM_PELLETS 200
#define NUM_POWERUPS 4
#define POWERUP_INTERVAL 50

// Game board data
char board[BOARD_HEIGHT][BOARD_WIDTH];

// Pac-Man data
int PacManX;
int PacManY;
int PacManLives;

// Pellet and power-up data
int PelletsRemaining;
int PowerUpCounter;
int PowerUpsRemaining;

// Display the game board
void DisplayBoard() {
    // Clear the screen
    system("clear");

    // Print the board
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }

    // Display the status
    printf("Lives: %d\tPellets: %d\tPower-Ups: %d\n", PacManLives, PelletsRemaining, PowerUpsRemaining);
}

// Place the pellets and power-ups on the board
void PlacePelletsAndPowerups() {
    // Place the pellets
    for (int i = 0; i < NUM_PELLETS; i++) {
        int x = rand() % BOARD_WIDTH;
        int y = rand() % BOARD_HEIGHT;
        if (board[y][x] == ' ') {
            board[y][x] = '.';
            PelletsRemaining++;
        }
    }

    // Place the power-ups
    PowerUpCounter = POWERUP_INTERVAL;
    PowerUpsRemaining = NUM_POWERUPS;
    for (int i = 0; i < NUM_POWERUPS; i++) {
        int x = rand() % BOARD_WIDTH;
        int y = rand() % BOARD_HEIGHT;
        if (board[y][x] == ' ') {
            board[y][x] = 'O';
        }
    }
}

// Move Pac-Man in the specified direction
void MovePacMan(int directionX, int directionY) {
    int newX = PacManX + directionX;
    int newY = PacManY + directionY;

    // Check for collisions
    if (board[newY][newX] == ' ') {
        // Move Pac-Man
        board[PacManY][PacManX] = ' ';
        PacManX = newX;
        PacManY = newY;
        board[PacManY][PacManX] = 'C';

    } else if (board[newY][newX] == '.') {
        // Eat the pellet
        board[PacManY][PacManX] = ' ';
        PacManX = newX;
        PacManY = newY;
        board[PacManY][PacManX] = 'C';
        PelletsRemaining--;

    } else if (board[newY][newX] == 'O') {
        // Eat the power-up
        board[PacManY][PacManX] = ' ';
        PacManX = newX;
        PacManY = newY;
        board[PacManY][PacManX] = 'C';
        PowerUpsRemaining--;
        PowerUpCounter = POWERUP_INTERVAL;

    } else if (board[newY][newX] == 'G') {
        // Pac-Man collides with Ghost: lose a life
        PacManLives--;
        if (PacManLives > 0) {
            PacManX = PACMAN_START_X;
            PacManY = PACMAN_START_Y;
            board[PacManY][PacManX] = 'C';
        } else {
            // Game over
            printf("GAME OVER!");
            exit(0);
        }
    }
}

// Main function
int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Initialize game board with walls
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (i == 0 || i == BOARD_HEIGHT - 1 || j == 0 || j == BOARD_WIDTH - 1) {
                board[i][j] = '#';
            } else {
                board[i][j] = ' ';
            }
        }
    }

    // Place Pac-Man on the board
    PacManX = PACMAN_START_X;
    PacManY = PACMAN_START_Y;
    board[PacManY][PacManX] = 'C';
    PacManLives = PACMAN_LIVES;

    // Place ghosts on the board
    board[7][7] = 'G';
    board[7][22] = 'G';
    board[11][7] = 'G';
    board[11][22] = 'G';

    // Place pellets and power-ups on the board
    PlacePelletsAndPowerups();

    // Game loop
    while (1) {
        // Display the game board
        DisplayBoard();

        // Get input from user
        char input = getchar();
        getchar(); // Consume the newline character

        // Move Pac-Man based on input
        switch (input) {
            case 'w': // Move up
                MovePacMan(0, -1);
                break;
            case 'a': // Move left
                MovePacMan(-1, 0);
                break;
            case 's': // Move down
                MovePacMan(0, 1);
                break;
            case 'd': // Move right
                MovePacMan(1, 0);
                break;
            default: // Invalid input
                break;
        }

        // Move ghosts randomly
        for (int i = 1; i < BOARD_HEIGHT - 1; i++) {
            for (int j = 1; j < BOARD_WIDTH - 1; j++) {
                if (board[i][j] == 'G') {
                    int direction = rand() % 4;
                    switch (direction) {
                        case 0: // Move up
                            if (board[i - 1][j] == ' ') {
                                board[i][j] = ' ';
                                board[i - 1][j] = 'G';
                            }
                            break;
                        case 1: // Move left
                            if (board[i][j - 1] == ' ') {
                                board[i][j] = ' ';
                                board[i][j - 1] = 'G';
                            }
                            break;
                        case 2: // Move down
                            if (board[i + 1][j] == ' ') {
                                board[i][j] = ' ';
                                board[i + 1][j] = 'G';
                            }
                            break;
                        case 3: // Move right
                            if (board[i][j + 1] == ' ') {
                                board[i][j] = ' ';
                                board[i][j + 1] = 'G';
                            }
                            break;
                        default:
                            break;
                    }
                }
            }
        }

        // Decrement power-up counter
        if (PowerUpCounter > 0) {
            PowerUpCounter--;
        }

        // If power-up has expired, ghosts turn back into ghosts
        if (PowerUpCounter == 0 && PowerUpsRemaining == 0) {
            for (int i = 1; i < BOARD_HEIGHT - 1; i++) {
                for (int j = 1; j < BOARD_WIDTH - 1; j++) {
                    if (board[i][j] == 'F') {
                        board[i][j] = 'G';
                    }
                }
            }
        }

        // If new power-up is available, ghosts turn into frightened ghosts
        if (PowerUpCounter == 0 && PowerUpsRemaining > 0) {
            for (int i = 1; i < BOARD_HEIGHT - 1; i++) {
                for (int j = 1; j < BOARD_WIDTH - 1; j++) {
                    if (board[i][j] == 'G') {
                        board[i][j] = 'F';
                    }
                }
            }
        }

        // Check if player has won
        if (PelletsRemaining == 0) {
            printf("You win!");
            exit(0);
        }
    }

    return 0;
}