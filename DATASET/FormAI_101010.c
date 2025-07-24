//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: portable
/*
* C Space Invaders Game Clone
* By: [Your Name]
*/

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24
#define ENEMY_COUNT 20
#define BULLET_COUNT 20

// Data structures
struct enemy {
    int x, y;
    int alive;
};

struct bullet {
    int x, y;
    int alive;
};

// Global variables
int score = 0;
int playerX = WIDTH / 2;
struct enemy enemies[ENEMY_COUNT];
struct bullet bullets[BULLET_COUNT];

// Function prototypes
void draw();
void update();
void spawnEnemies();
void movePlayer(char);
void shoot();
void moveBullets();
int kbhit();

// Main game loop
int main() {
    srand(time(NULL));

    // Initialize enemies
    for (int i = 0; i < ENEMY_COUNT; i++) {
        enemies[i].x = rand() % WIDTH;
        enemies[i].y = rand() % HEIGHT;
        enemies[i].alive = 1;
    }

    // Initialize bullets
    for (int i = 0; i < BULLET_COUNT; i++) {
        bullets[i].x = -1;
        bullets[i].y = -1;
        bullets[i].alive = 0;
    }

    // Game loop
    while (1) {
        // Update game state
        update();

        // Check if game is over
        int gameOver = 1;
        for (int i = 0; i < ENEMY_COUNT; i++) {
            if (enemies[i].alive) {
                gameOver = 0;
            }
        }
        if (gameOver) {
            break;
        }

        // Draw game
        draw();

        // Wait for next frame
        usleep(1000000 / 60);
    }

    // Game over screen
    system("clear");
    printf("Game Over! Final Score: %d\n", score);

    return 0;
}

// Draw the game board
void draw() {
    // Clear screen
    system("clear");

    // Draw player
    printf(" ");
    for (int i = 0; i < playerX; i++) {
        printf(" ");
    }
    printf("V");

    // Draw bullets
    for (int i = 0; i < BULLET_COUNT; i++) {
        if (bullets[i].alive) {
            printf("^");
        }
    }
    printf("\n");

    // Draw enemies
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int enemyAlive = 0;
            for (int i = 0; i < ENEMY_COUNT; i++) {
                if (enemies[i].alive && enemies[i].x == x && enemies[i].y == y) {
                    printf("M");
                    enemyAlive = 1;
                    break;
                }
            }
            if (!enemyAlive) {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Draw score
    printf("Score: %d\n", score);
}

// Update game state
void update() {
    // Spawn new enemies randomly
    spawnEnemies();

    // Move bullets
    moveBullets();

    // Handle keyboard input
    if (kbhit()) {
        char input = getchar();
        movePlayer(input);
        if (input == ' ') {
            shoot();
        }
    }

    // Move enemies
    for (int i = 0; i < ENEMY_COUNT; i++) {
        if (enemies[i].alive) {
            enemies[i].y++;
            if (enemies[i].y == HEIGHT) {
                enemies[i].alive = 0;
            }
        }
    }
}

// Spawn new enemies randomly
void spawnEnemies() {
    for (int i = 0; i < ENEMY_COUNT; i++) {
        if (!enemies[i].alive) {
            enemies[i].x = rand() % WIDTH;
            enemies[i].y = 0;
            enemies[i].alive = 1;
        }
    }
}

// Move the player left or right
void movePlayer(char input) {
    if (input == 'a' && playerX > 0) {
        playerX--;
    } else if (input == 'd' && playerX < WIDTH - 1) {
        playerX++;
    }
}

// Shoot a bullet
void shoot() {
    for (int i = 0; i < BULLET_COUNT; i++) {
        if (!bullets[i].alive) {
            bullets[i].x = playerX;
            bullets[i].y = HEIGHT - 1;
            bullets[i].alive = 1;
            break;
        }
    }
}

// Move bullets up
void moveBullets() {
    for (int i = 0; i < BULLET_COUNT; i++) {
        if (bullets[i].alive) {
            bullets[i].y--;
            if (bullets[i].y < 0) {
                bullets[i].alive = 0;
            } else {
                // Check for collision with enemies
                for (int j = 0; j < ENEMY_COUNT; j++) {
                    if (enemies[j].alive && bullets[i].x == enemies[j].x && bullets[i].y == enemies[j].y) {
                        bullets[i].alive = 0;
                        enemies[j].alive = 0;
                        score += 10;
                    }
                }
            }
        }
    }
}

// Check if there is keyboard input waiting
int kbhit() {
    struct termios oldterm, newterm;
    int oldfd;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldterm);
    newterm = oldterm;
    newterm.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newterm);
    oldfd = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldfd | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldterm);
    fcntl(STDIN_FILENO, F_SETFL, oldfd);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}