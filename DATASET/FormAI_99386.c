//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20
#define SHIP_HEIGHT 3

// Function to draw the game board
void draw_board(int x, int y, int score, int lives, char board[HEIGHT][WIDTH]) {

    // Clear the terminal screen
    system("clear");

    // Draw the border
    printf("+");
    for (int i = 0; i < WIDTH; i++) {
        printf("-");
    }
    printf("+\n");

    // Draw the board
    for (int i = 0; i < HEIGHT; i++) {
        printf("|");
        for (int j = 0; j < WIDTH; j++) {
            if (i == y && j == x) {         // Draw the ship
                printf("X");
            } else {
                printf("%c", board[i][j]);  // Draw the invaders or empty space
            }
        }
        printf("|\n");
    }

    // Draw the status
    printf("+");
    for (int i = 0; i < WIDTH; i++) {
        printf("-");
    }
    printf("+\n");
    printf("Score: %d    Lives: %d\n", score, lives);
}

int main() {

    // Declare variables
    int x = WIDTH / 2;
    int y = HEIGHT - SHIP_HEIGHT;
    int score = 0;
    int lives = 3;
    char board[HEIGHT][WIDTH];
    int invader_x = 0;
    int invader_y = 0;
    char invader = 'V';

    // Seed the random generator
    srand(time(NULL));

    // Initialize the board
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = ' ';
        }
    }

    // Main game loop
    while (1) {

        // Draw the board
        draw_board(x, y, score, lives, board);

        // Move the invaders
        if (invader_y >= HEIGHT) {
            invader_x = rand() % WIDTH;
            invader_y = 0;
        }
        board[invader_y][invader_x] = ' ';
        invader_y++;
        board[invader_y][invader_x] = invader;

        // Check for game over
        if (lives == 0) {
            printf("Game over!\n");
            break;
        }

        // Check for collision with an invader
        if (invader_y == y && invader_x == x) {
            lives--;
        }

        // Get user input
        char input;
        printf("Use arrow keys to move. Press Q to quit.\n");
        input = getchar();
        if (input == 'q' || input == 'Q') {
            break;
        }
        switch (input) {
            case 'w':
            case 'W':
                if (y > 0) y--;
                break;
            case 'a':
            case 'A':
                if (x > 0) x--;
                break;
            case 's':
            case 'S':
                if (y < HEIGHT - SHIP_HEIGHT) y++;
                break;
            case 'd':
            case 'D':
                if (x < WIDTH - 1) x++;
                break;
        }

        // Increase score
        score++;
    }

    return 0;
}