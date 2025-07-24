//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 60
#define HEIGHT 20

int playerX, playerY, score;
int enemyX[5], enemyY[5], enemyAlive[5];
int shotX, shotY, shotAlive;

void initialize() {
    score = 0;
    playerX = WIDTH / 2;
    playerY = HEIGHT - 1;
    for (int i = 0; i < 5; i++) {
        enemyX[i] = i * (WIDTH / 5) + (WIDTH / 10);
        enemyY[i] = 1;
        enemyAlive[i] = 1;
    }
}

void clearScreen() {
    system("clear");
}

void draw() {
    char frame[HEIGHT][WIDTH];
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            char c = ' ';
            if (x == playerX && y == playerY) {
                c = '^';
            } else if (shotAlive && x == shotX && y == shotY) {
                c = '|';
            } else {
                for (int i = 0; i < 5; i++) {
                    if (enemyAlive[i] && x == enemyX[i] && y == enemyY[i]) {
                        c = 'o';
                    }
                }
            }
            frame[y][x] = c;
        }
    }
    printf("SCORE: %04d\n", score);
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", frame[y][x]);
        }
        printf("\n");
    }
}

void update() {
    // player movement
    if (getchar() == 'a' && playerX > 0) {
        playerX -= 1;
    }
    if (getchar() == 'd' && playerX < WIDTH - 1) {
        playerX += 1;
    }
    // shot movement
    if (shotAlive) {
        shotY -= 1;
        if (shotY < 0) {
            shotAlive = 0;
        }
        for (int i = 0; i < 5; i++) {
            if (enemyAlive[i] && shotX == enemyX[i] && shotY == enemyY[i]) {
                enemyAlive[i] = 0;
                shotAlive = 0;
                score += 10;
            }
        }
    }
    // enemy movement
    int move = 0;
    for (int i = 0; i < 5; i++) {
        if (enemyAlive[i]) {
            move = 1;
            if (rand() % 2 == 0) {
                enemyX[i] += 1;
            } else {
                enemyX[i] -= 1;
            }
            if (enemyY[i] == playerY) {
                printf("GAME OVER\n");
                exit(0);
            }
            if (enemyY[i] == shotY && enemyX[i] == shotX) {
                enemyAlive[i] = 0;
                shotAlive = 0;
                score += 10;
            }
        }
    }
    if (!move) {
        printf("YOU WIN\n");
        exit(0);
    }
    // spawn new enemy
    for (int i = 0; i < 5; i++) {
        if (!enemyAlive[i] && rand() % 5 == 0) {
            enemyX[i] = i * (WIDTH / 5) + (WIDTH / 10);
            enemyY[i] = 1;
            enemyAlive[i] = 1;
        }
    }
}

int main() {
    srand(time(NULL));
    initialize();
    while (1) {
        clearScreen();
        draw();
        update();
    }
    return 0;
}