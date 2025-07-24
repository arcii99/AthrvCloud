//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define HEIGHT 15  // Height of the game board
#define WIDTH 20   // Width of the game board

char board[HEIGHT][WIDTH];  // The game board
int player_pos;  // The player's position
int score;       // The player's score

// Recursive function to move the aliens on the game board
void move_aliens(int row, int col, int dir) {
    if (row == HEIGHT) {
        // Game over if the aliens reach the bottom of the board
        printf("\nGame Over! Final Score: %d\n", score);
        exit(0);
    }

    if (board[row][col] == '*') {
        // Alien hit, update score and move on to next alien
        score++;
        board[row][col] = ' ';
        move_aliens(row+1, 0, dir);
        return;
    }

    if (dir == 1) {
        if (col == WIDTH-1) {
            // Reached right edge, change direction and move down
            move_aliens(row+1, col, -1);
            return;
        }
        // Move right
        board[row][col] = ' ';
        board[row][col+1] = '*';
        move_aliens(row, col+1, dir);
    } else {
        if (col == 0) {
            // Reached left edge, change direction and move down
            move_aliens(row+1, col, 1);
            return;
        }
        // Move left
        board[row][col] = ' ';
        board[row][col-1] = '*';
        move_aliens(row, col-1, dir);
    }
}

// Moves the player position to the left or right
void move_player(int dir) {
    if ((dir == -1 && player_pos == 0) || (dir == 1 && player_pos == WIDTH-1)) {
        // Player cannot move off the game board
        return;
    }
    player_pos += dir;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the game board
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = ' ';
        }
    }
    board[HEIGHT-1][WIDTH/2] = 'V';  // Player starting position

    // Initialize the aliens randomly on the first row
    int alien_count = 5 + rand() % 6;
    for (int i = 0; i < alien_count; i++) {
        int pos = rand() % WIDTH;
        board[0][pos] = '*';
    }

    // Begin game loop
    while (true) {
        // Move aliens on the game board
        move_aliens(0, 0, 1);

        // Print the game board
        system("clear");  // Clear the console
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        // Move the player based on user input
        char input = getchar();
        if (input == 'a') {
            move_player(-1);
        } else if (input == 'd') {
            move_player(1);
        }

        // Update player position on the game board
        for (int i = 0; i < WIDTH; i++) {
            board[HEIGHT-1][i] = ' ';
        }
        board[HEIGHT-1][player_pos] = 'V';
    }

    return 0;
}