//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define WIDTH 40
#define HEIGHT 20

int kbhit(void);
void drawMap(void);
void drawPlayer(void);
void drawBullet(void);
void drawEnemy(void);
void updateBullet(void);
void updateEnemy(void);

int map[HEIGHT][WIDTH];
int playerX, playerY, bulletX, bulletY, enemyX, enemyY;

int main(void) {
    int ch, i, j;
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                map[i][j] = 1;
            } else {
                map[i][j] = 0;
            }
        }
    }

    playerX = WIDTH / 2;
    playerY = HEIGHT - 2;
    bulletX = -1;
    bulletY = -1;
    enemyX = WIDTH / 2;
    enemyY = 1;

    while (1) {
        if (kbhit()) {
            ch = getchar();
            if (ch == 'a') {
                if (playerX > 1) {
                    playerX--;
                }
            } else if (ch == 's') {
                if (playerY < HEIGHT - 2) {
                    playerY++;
                }
            } else if (ch == 'd') {
                if (playerX < WIDTH - 2) {
                    playerX++;
                }
            } else if (ch == ' ') {
                if (bulletY == -1) {
                    bulletX = playerX;
                    bulletY = playerY - 1;
                }
            }
        }

        drawMap();
        drawPlayer();
        drawBullet();
        drawEnemy();
        updateBullet();
        updateEnemy();

        if (bulletX == enemyX && bulletY == enemyY) {
            bulletY = -1;
            enemyX = rand() % (WIDTH - 2) + 1;
            enemyY = 1;
        }

        if (playerY == enemyY && playerX >= enemyX - 1 && playerX <= enemyX + 1) {
            printf("Game Over\n");
            break;
        }

        usleep(50000);
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return 0;
}

int kbhit(void) {
    struct termios oldt, newt;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

void drawMap(void) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (map[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void drawPlayer(void) {
    map[playerY][playerX] = 2;
}

void drawBullet(void) {
    if (bulletY >= 1) {
        map[bulletY][bulletX] = 3;
    }
}

void drawEnemy(void) {
    map[enemyY][enemyX] = 4;
}

void updateBullet(void) {
    if (bulletY >= 1) {
        map[bulletY][bulletX] = 0;
        bulletY--;
        map[bulletY][bulletX] = 3;
    } else {
        bulletX = -1;
        bulletY = -1;
    }
}

void updateEnemy(void) {
    map[enemyY][enemyX] = 0;
    enemyY++;
    if (enemyY >= HEIGHT - 1) {
        enemyX = rand() % (WIDTH - 2) + 1;
        enemyY = 1;
    }
    map[enemyY][enemyX] = 4;
}