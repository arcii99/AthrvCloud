//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

#define PLAYER_WIDTH 3
#define PLAYER_HEIGHT 1
#define PLAYER_SPEED 1

#define BULLET_SPEED 2

#define ENEMY_WIDTH 3
#define ENEMY_HEIGHT 1
#define ENEMY_ROWS 3
#define ENEMY_COLS 10
#define ENEMY_SPACING 2
#define ENEMY_START_X 10
#define ENEMY_START_Y 2
#define ENEMY_START_DIRECTION 1

#define GAME_SPEED 500000

char screen[SCREEN_HEIGHT][SCREEN_WIDTH];

struct Player {
    int x;
    int y;
    bool firing;
} player;

struct Bullet {
    int x;
    int y;
    bool active;
} bullets[SCREEN_HEIGHT];

struct Enemy {
    int x;
    int y;
    bool active;
} enemies[ENEMY_ROWS][ENEMY_COLS];

int score = 0;
int direction = ENEMY_START_DIRECTION;

void initScreen() {
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            if (i == 0 || i == SCREEN_HEIGHT-1) {
                screen[i][j] = '-';
            } else if (j == 0 || j == SCREEN_WIDTH-1) {
                screen[i][j] = '|';
            } else {
                screen[i][j] = ' ';
            }
        }
    }
}

void drawScreen() {
    system("clear");
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            putchar(screen[i][j]);
        }
        putchar('\n');
    }
    printf("Score: %d\n", score);
}

void drawPlayer() {
    for (int i = 0; i < PLAYER_WIDTH; i++) {
        screen[player.y][player.x+i] = 'X';
    }
}

void drawBullets() {
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        if (bullets[i].active) {
            screen[bullets[i].y][bullets[i].x] = '|';
        }
    }
}

void drawEnemies() {
    for (int i = 0; i < ENEMY_ROWS; i++) {
        for (int j = 0; j < ENEMY_COLS; j++) {
            if (enemies[i][j].active) {
                screen[enemies[i][j].y][enemies[i][j].x] = 'O';
            }
        }
    }
}

void updateBullets() {
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        if (bullets[i].active) {
            bullets[i].y -= BULLET_SPEED;
            if (bullets[i].y < 1) {
                bullets[i].active = false;
            }
        }
    }
}

void updateEnemies() {
    bool moveDown = false;
    for (int i = 0; i < ENEMY_ROWS; i++) {
        for (int j = 0; j < ENEMY_COLS; j++) {
            if (enemies[i][j].active) {
                if (enemies[i][j].x <= 1 || enemies[i][j].x >= SCREEN_WIDTH-ENEMY_WIDTH-1) {
                    moveDown = true;
                    break;
                }
            }
        }
    }
    if (moveDown) {
        direction = -direction;
        for (int i = 0; i < ENEMY_ROWS; i++) {
            for (int j = 0; j < ENEMY_COLS; j++) {
                if (enemies[i][j].active) {
                    enemies[i][j].y += ENEMY_SPACING;
                }
            }
        }
    } else {
        for (int i = 0; i < ENEMY_ROWS; i++) {
            for (int j = 0; j < ENEMY_COLS; j++) {
                if (enemies[i][j].active) {
                    enemies[i][j].x += direction;
                }
            }
        }
    }
}

void fireBullet() {
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        if (!bullets[i].active) {
            bullets[i].active = true;
            bullets[i].x = player.x + PLAYER_WIDTH/2;
            bullets[i].y = player.y - 1;
            break;
        }
    }
}

void initEnemies() {
    for (int i = 0; i < ENEMY_ROWS; i++) {
        for (int j = 0; j < ENEMY_COLS; j++) {
            enemies[i][j].active = true;
            enemies[i][j].x = ENEMY_START_X + j*(ENEMY_WIDTH+ENEMY_SPACING);
            enemies[i][j].y = ENEMY_START_Y + i*(ENEMY_HEIGHT+ENEMY_SPACING);
        }
    }
}

bool checkBulletCollision(int x, int y) {
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        if (bullets[i].active && bullets[i].x == x && bullets[i].y == y) {
            bullets[i].active = false;
            return true;
        }
    }
    return false;
}

bool checkEnemyCollision(int x, int y) {
    for (int i = 0; i < ENEMY_ROWS; i++) {
        for (int j = 0; j < ENEMY_COLS; j++) {
            if (enemies[i][j].active && x >= enemies[i][j].x && x <= enemies[i][j].x + ENEMY_WIDTH-1 && y == enemies[i][j].y) {
                enemies[i][j].active = false;
                score++;
                return true;
            }
        }
    }
    return false;
}

void updatePlayer() {
    char c = getchar();
    if (c == 'a') {
        player.x = player.x > 1 ? player.x - PLAYER_SPEED : player.x;
    } else if (c == 'd') {
        player.x = player.x < SCREEN_WIDTH-PLAYER_WIDTH-1 ? player.x + PLAYER_SPEED : player.x;
    } else if (c == ' ' && !player.firing) {
        player.firing = true;
        fireBullet();
    } else if (c == '\n' && player.firing) {
        player.firing = false;
    }
}

void updateGame() {
    updatePlayer();
    updateBullets();
    updateEnemies();

    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            if (checkBulletCollision(j, i)) {
                screen[i][j] = ' ';
            } else if (checkEnemyCollision(j, i)) {
                screen[i][j] = ' ';
            }
        }
    }
}

bool checkGameOver() {
    for (int i = 0; i < ENEMY_ROWS; i++) {
        for (int j = 0; j < ENEMY_COLS; j++) {
            if (enemies[i][j].active && enemies[i][j].y >= player.y) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    srand(time(NULL));
    player.x = SCREEN_WIDTH/2 - PLAYER_WIDTH/2;
    player.y = SCREEN_HEIGHT - 3;
    initEnemies();
    while (true) {
        initScreen();
        drawPlayer();
        drawBullets();
        drawEnemies();
        drawScreen();
        updateGame();
        if (checkGameOver()) {
            printf("GAME OVER\n");
            break;
        }
        usleep(GAME_SPEED);
    }
    return 0;
}