//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: ephemeral
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Define constants for the game board dimensions and characters
#define ROWS 25
#define COLS 50
#define PELLET '.'
#define PACMAN 'C'
#define GHOST 'G'
#define WALL '#'
#define BLANK ' '

// Define struct to hold the game objects' coordinates
typedef struct {
    int x, y;
} coord;

// Define function to check if two coordinates are equal
bool equal_coords(coord c1, coord c2) {
    return c1.x == c2.x && c1.y == c2.y;
}

int main() {
    // Seed random number generator to randomize ghost starting position
    srand(time(NULL));

    // Initialize game board as a 2D array of blank spaces
    char board[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = BLANK;
        }
    }

    // Draw walls on the top and bottom of the board
    for (int j = 0; j < COLS; j++) {
        board[0][j] = WALL;
        board[ROWS - 1][j] = WALL;
    }

    // Draw walls on the left and right sides of the board
    for (int i = 0; i < ROWS; i++) {
        board[i][0] = WALL;
        board[i][COLS - 1] = WALL;
    }

    // Draw pellets randomly throughout the board
    for (int i = 1; i < ROWS - 1; i++) {
        for (int j = 1; j < COLS - 1; j++) {
            if (board[i][j] != WALL && rand() % 10 == 0) {
                board[i][j] = PELLET;
            }
        }
    }

    // Set Pac-Man's starting position in the center of the board
    coord pacman_pos = { ROWS / 2, COLS / 2 };
    board[pacman_pos.x][pacman_pos.y] = PACMAN;

    // Set ghost's starting position in a random spot on the board
    coord ghost_pos = { rand() % (ROWS - 2) + 1, rand() % (COLS - 2) + 1 };
    board[ghost_pos.x][ghost_pos.y] = GHOST;

    // Initialize score and game over variables
    int score = 0;
    bool game_over = false;

    // Main game loop
    while (!game_over) {
        // Print the game board and the score
        system("clear"); // Clear the console screen in Unix/Linux environments
        printf("Score: %d\n\n", score);
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%c", board[i][j]);
            }
            printf("\n");
        }

        // Get user input to move Pac-Man
        char direction;
        printf("\nUse the arrow keys to move Pac-Man. ");
        scanf(" %c", &direction);

        // Determine new position for Pac-Man based on user input
        coord new_pos = pacman_pos;
        if (direction == 'up') {
            new_pos.x--;
        } else if (direction == 'down') {
            new_pos.x++;
        } else if (direction == 'left') {
            new_pos.y--;
        } else if (direction == 'right') {
            new_pos.y++;
        }

        // Move Pac-Man to the new position if it is not a wall
        if (board[new_pos.x][new_pos.y] != WALL) {
            // Remove pellet if Pac-Man moves to a pellet
            if (board[new_pos.x][new_pos.y] == PELLET) {
                score++;
            }
            board[pacman_pos.x][pacman_pos.y] = BLANK;
            pacman_pos = new_pos;
            board[pacman_pos.x][pacman_pos.y] = PACMAN;
        }

        // Move ghost randomly
        coord ghost_new_pos = ghost_pos;
        switch(rand() % 4) {
            case 0:
                ghost_new_pos.x--;
                break;
            case 1:
                ghost_new_pos.x++;
                break;
            case 2:
                ghost_new_pos.y--;
                break;
            case 3:
                ghost_new_pos.y++;
                break;
        }
        // Move ghost to the new position if it is not a wall
        if (board[ghost_new_pos.x][ghost_new_pos.y] != WALL) {
            board[ghost_pos.x][ghost_pos.y] = BLANK;
            ghost_pos = ghost_new_pos;
            board[ghost_pos.x][ghost_pos.y] = GHOST;
        }

        // Check if Pac-Man collides with ghost
        if (equal_coords(pacman_pos, ghost_pos)) {
            printf("\nGame Over! Score: %d\n", score);
            game_over = true;
        }

        // Check if Pac-Man has eaten all the pellets
        bool all_pellets_eaten = true;
        for (int i = 1; i < ROWS - 1; i++) {
            for (int j = 1; j < COLS - 1; j++) {
                if (board[i][j] == PELLET) {
                    all_pellets_eaten = false;
                }
            }
        }
        if (all_pellets_eaten) {
            printf("\nYou Win! Score: %d\n", score);
            game_over = true;
        }
    }

    return 0;
}