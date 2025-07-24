//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 30

int main() {

    // Initialize screen buffer
    char screen[SCREEN_HEIGHT][SCREEN_WIDTH];

    // Initialize variables for player and enemy positions
    int player_x = SCREEN_WIDTH / 2;
    int enemy_x = rand() % SCREEN_WIDTH;
    int enemy_y = 0;

    // Initialize score and lives
    int score = 0;
    int lives = 3;

    // Initialize game loop
    while (1) {

        // Clear screen
        system("clear");

        // Update screen buffer with player and enemy positions
        for (int i = 0; i < SCREEN_HEIGHT; i++) {
            for (int j = 0; j < SCREEN_WIDTH; j++) {
                if (i == enemy_y && j == enemy_x) {
                    screen[i][j] = 'E';
                } else if (i == SCREEN_HEIGHT - 1 && j == player_x) {
                    screen[i][j] = 'P';
                } else {
                    screen[i][j] = ' ';
                }
            }
        }

        // Print screen buffer
        for (int i = 0; i < SCREEN_HEIGHT; i++) {
            printf("%s\n", screen[i]);
        }

        // Check for player input
        char input;
        scanf("%c", &input);
        if (input == 'a') {
            player_x--;
        } else if (input == 'd') {
            player_x++;
        }

        // Move enemy down
        enemy_y++;

        // Check for collision
        if (enemy_y == SCREEN_HEIGHT - 1 && enemy_x == player_x) {
            score++;
            enemy_x = rand() % SCREEN_WIDTH;
            enemy_y = 0;
        } else if (enemy_y == SCREEN_HEIGHT - 1) {
            lives--;
            enemy_x = rand() % SCREEN_WIDTH;
            enemy_y = 0;
        }

        // Check for game over
        if (lives == 0) {
            printf("Game over! Final score: %d\n", score);
            break;
        }

        // Wait for 100 milliseconds
        usleep(100000);
    }

    return 0;
}