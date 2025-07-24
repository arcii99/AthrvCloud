//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for game
#define WIDTH 70
#define HEIGHT 20
#define MAX_BULLETS 5
#define MAX_ALIENS 10
#define ALIEN_CHANCE 30

// Define struct for bullets
typedef struct {
    int isActive;
    int x;
    int y;
} Bullet;

// Define struct for aliens
typedef struct {
    int isActive;
    int x;
    int y;
    int health;
} Alien;

// Declare global variables
int score = 0;
int gameOver = 0;
int playerX = WIDTH / 2;
Bullet bullets[MAX_BULLETS];
Alien aliens[MAX_ALIENS];

// Function to draw game board
void drawBoard() {
    system("clear"); // Clear console
    printf("Score: %d\n", score);
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("-");
    }
    printf("\n");
    for (int i = 0; i < HEIGHT; i++) {
        printf("|");
        for (int j = 0; j < WIDTH; j++) {
            if (i == HEIGHT - 1 && j == playerX) {
                printf("V");
            } else {
                int isBullet = 0;
                for (int k = 0; k < MAX_BULLETS; k++) {
                    if (bullets[k].isActive && bullets[k].x == j && bullets[k].y == i) {
                        printf("|");
                        isBullet = 1;
                        break;
                    }
                }
                if (!isBullet) {
                    int isAlien = 0;
                    for (int k = 0; k < MAX_ALIENS; k++) {
                        if (aliens[k].isActive && aliens[k].x == j && aliens[k].y == i) {
                            printf("*");
                            isAlien = 1;
                            break;
                        }
                    }
                    if (!isAlien) {
                        printf(" ");
                    }
                }
            }
        }
        printf("|\n");
    }
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("-");
    }
    printf("\n");
}

// Function to update game state
void updateState() {
    // Move bullets
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets[i].isActive) {
            bullets[i].y--;
            if (bullets[i].y < 0) {
                bullets[i].isActive = 0;
            }
        }
    }
    // Move aliens
    for (int i = 0; i < MAX_ALIENS; i++) {
        if (aliens[i].isActive) {
            aliens[i].y++;
            if (aliens[i].y >= HEIGHT) {
                aliens[i].isActive = 0;
            }
        }
    }
    // Check collisions
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets[i].isActive) {
            for (int j = 0; j < MAX_ALIENS; j++) {
                if (aliens[j].isActive && bullets[i].x == aliens[j].x && bullets[i].y == aliens[j].y) {
                    bullets[i].isActive = 0;
                    aliens[j].health--;
                    if (aliens[j].health == 0) {
                        aliens[j].isActive = 0;
                        score++;
                    }
                }
            }
        }
    }
    // Check game over
    for (int i = 0; i < MAX_ALIENS; i++) {
        if (aliens[i].isActive && aliens[i].y == HEIGHT - 1) {
            gameOver = 1;
            break;
        }
    }
}

// Function to move player
void movePlayer(char c) {
    if (c == 'a' && playerX > 0) {
        playerX--;
    } else if (c == 'd' && playerX < WIDTH - 1) {
        playerX++;
    } else if (c == ' ') {
        // Fire bullet
        for (int i = 0; i < MAX_BULLETS; i++) {
            if (!bullets[i].isActive) {
                bullets[i].isActive = 1;
                bullets[i].x = playerX;
                bullets[i].y = HEIGHT - 2;
                break;
            }
        }
    }
}

// Function to spawn aliens
void spawnAliens() {
    srand(time(NULL)); // Set seed for random number generation
    for (int i = 0; i < MAX_ALIENS; i++) {
        if (rand() % 100 < ALIEN_CHANCE) {
            aliens[i].isActive = 1;
            aliens[i].x = rand() % WIDTH;
            aliens[i].y = 0;
            aliens[i].health = 1;
        } else {
            aliens[i].isActive = 0;
        }
    }
}

int main() {
    // Initialize game board
    for (int i = 0; i < MAX_BULLETS; i++) {
        bullets[i].isActive = 0;
    }
    for (int i = 0; i < MAX_ALIENS; i++) {
        aliens[i].isActive = 0;
    }
    // Game loop
    while (!gameOver) {
        drawBoard();
        char c = getchar();
        if (c != '\n') {
            movePlayer(c);
        }
        spawnAliens();
        updateState();
    }
    printf("Game Over! Final score: %d\n", score);
    return 0;
}