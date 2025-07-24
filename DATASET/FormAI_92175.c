//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 60
#define HEIGHT 30

// Player's position and movement
int playerX = WIDTH / 2;
int playerY = HEIGHT - 2;
int isMovingLeft = 0;
int isMovingRight = 0;

// Enemy's position and movement
int enemyX = WIDTH / 2;
int enemyY = 0;
int enemySpeed = 1;

// Array to store player's bullets
int bullets[HEIGHT][WIDTH] = {0};

// Function to draw the game screen
void drawScreen() {
    // Clear the screen
    system("clear");
    
    // Draw player, enemy, and bullets
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == playerX && y == playerY) {
                printf("P");
            } else if (x == enemyX && y == enemyY) {
                printf("E");
            } else if (bullets[y][x] == 1) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Main game loop
    while (1) {
        // Move player
        if (isMovingLeft && playerX > 0) {
            playerX--;
        }
        if (isMovingRight && playerX < WIDTH - 1) {
            playerX++;
        }
        
        // Move enemy
        enemyY += enemySpeed;
        
        // Check for collision
        if (enemyY == playerY && enemyX == playerX) {
            printf("Game Over\n");
            return 0;
        }
        
        // Check if enemy has reached bottom
        if (enemyY == HEIGHT - 1) {
            // Reset enemy position and speed
            enemyX = rand() % WIDTH;
            enemyY = 0;
            enemySpeed++;
        }
        
        // Move bullets and check for collision
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                if (bullets[y][x] == 1) {
                    bullets[y][x] = 0;
                    if (y == enemyY && x == enemyX) {
                        // Enemy hit, reset position and speed
                        enemyX = rand() % WIDTH;
                        enemyY = 0;
                        enemySpeed++;
                    }
                }
            }
        }
        
        // Draw the screen
        drawScreen();
        
        // Wait for a short amount of time
        struct timespec ts = {0, 100000000};
        nanosleep(&ts, NULL);
    }
    
    return 0;
}