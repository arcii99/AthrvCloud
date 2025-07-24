//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 50
#define ENEMY_COUNT 50
#define PLAYER_SIZE 3 
#define ENEMY_SIZE 2
#define ENEMY_SPEED 1
#define BULLET_SPEED 3

int score = 0;

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position pos;
    int speed;
    int visible;
} Enemy;

typedef struct {
    Position pos;
    int alive;
} Bullet;

Position playerPos;
Enemy enemies[ENEMY_COUNT];
Bullet bullets[HEIGHT];
int gameOver = 0;

void init() {
    // Initialize player position.
    playerPos.x = WIDTH / 2 - PLAYER_SIZE / 2;
    playerPos.y = HEIGHT - PLAYER_SIZE;

    // Initialize enemies.
    srand(time(NULL));
    for (int i = 0; i < ENEMY_COUNT; i++) {
        enemies[i].pos.x = rand() % (WIDTH - ENEMY_SIZE);
        enemies[i].pos.y = rand() % (HEIGHT / 2);
        enemies[i].speed = ENEMY_SPEED;
        enemies[i].visible = 1;
    }

    // Initialize bullets.
    for (int i = 0; i < HEIGHT; i++) {
        bullets[i].pos.x = -1;
        bullets[i].pos.y = -1;
        bullets[i].alive = 0;
    }
}

void draw() {
    // Draw player.
    for (int i = 0; i < PLAYER_SIZE; i++) {
        printf("*");
    }
    printf("\n");

    // Draw enemies.
    for (int i = 0; i < ENEMY_COUNT; i++) {
        if (enemies[i].visible) {
            for (int j = 0; j < ENEMY_SIZE; j++) {
                printf("O");
            }
            printf("\n");
        }
    }

    // Draw bullets.
    for (int i = 0; i < HEIGHT; i++) {
        if (bullets[i].alive) {
            printf("|");
        } else {
            printf(" ");
        }
    }
    printf("\n");
}

void update() {
    // Move enemies.
    for (int i = 0; i < ENEMY_COUNT; i++) {
        if (!enemies[i].visible) continue;
        enemies[i].pos.y += enemies[i].speed;
        if (enemies[i].pos.y >= HEIGHT) {
            enemies[i].visible = 0;
        }
    }

    // Move bullets.
    for (int i = 0; i < HEIGHT; i++) {
        if (!bullets[i].alive) continue;
        bullets[i].pos.y -= BULLET_SPEED;
        // Check for hit.
        for (int j = 0; j < ENEMY_COUNT; j++) {
            if (!enemies[j].visible) continue;
            if (bullets[i].pos.x >= enemies[j].pos.x 
                && bullets[i].pos.x < enemies[j].pos.x + ENEMY_SIZE
                && bullets[i].pos.y == enemies[j].pos.y) {
                enemies[j].visible = 0;
                bullets[i].alive = 0;
                score++;
                break;
            }
        }
        if (bullets[i].pos.y < 0) {
            bullets[i].alive = 0;
        }
    }

    // Check for game over.
    for (int i = 0; i < ENEMY_COUNT; i++) {
        if (!enemies[i].visible) continue;
        if (enemies[i].pos.y >= playerPos.y 
            && enemies[i].pos.x >= playerPos.x - ENEMY_SIZE 
            && enemies[i].pos.x < playerPos.x + PLAYER_SIZE) {
            gameOver = 1;
            return;
        }
    }
}

void handleInput(char c) {
    switch(c) {
        case 'a':
            playerPos.x--;
            break;
        case 'd':
            playerPos.x++;
            break;
        case ' ':
            for (int i = 0; i < HEIGHT; i++) {
                if (!bullets[i].alive) {
                    bullets[i].pos.x = playerPos.x + PLAYER_SIZE / 2;
                    bullets[i].pos.y = playerPos.y - 1;
                    bullets[i].alive = 1;
                    break;
                }
            }
            break;
        case 'q':
            gameOver = 1;
            break;
    }
}

int main() {
    init();

    while (!gameOver) {
        // Draw
        system("clear");
        draw();

        // Update
        update();

        // Handle input
        char c = getchar();
        while (getchar() != '\n');
        handleInput(c);
    }

    // Game over
    system("clear");
    printf("Game Over! Score: %d\n", score);

    return 0;
}