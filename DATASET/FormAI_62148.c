//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 60
#define HEIGHT 20
#define PLAYER '*'
#define ENEMY 'X'
#define BULLET '|'

/* Function Declarations */
void setup();
void draw();
void update();
void input();
void movePlayer();
void moveBullets();
void moveEnemies();
void createEnemies();
void killEnemy(int, int);
void checkCollisions();

/* Global Variables */
char screen[HEIGHT][WIDTH];
int playerPos = WIDTH / 2;
int bulletPos = -1;
int enemyCount = 0;
int enemyPositions[10][2];

/* Main Program */
int main() {
    setup();

    while (1) {
        draw();
        input();
        update();
    }

    return 0;
}

/* Function Definitions */

void setup() {
    srand(time(NULL));
    
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == HEIGHT - 1) {
                screen[i][j] = '_';
            } else {
                screen[i][j] = ' ';
            }
        }
    }

    screen[HEIGHT - 2][playerPos] = PLAYER;

    createEnemies();
}

void draw() {
    system("clear");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", screen[i][j]);
        }
        printf("\n");
    }
}

void update() {
    moveBullets();
    moveEnemies();
    checkCollisions();
}

void input() {
    int input = getchar();

    if (input == 'q') {
        exit(0);
    } else if (input == 'a') {
        movePlayer(-1);
    } else if (input == 'd') {
        movePlayer(1);
    } else if (input == ' ') {
        if (bulletPos == -1) {
            bulletPos = HEIGHT - 3;
            screen[bulletPos][playerPos] = BULLET;
        }
    }
}

void movePlayer(int direction) {
    screen[HEIGHT - 2][playerPos] = ' ';
    playerPos += direction;
    if (playerPos < 0) {
        playerPos = 0;
    }
    if (playerPos >= WIDTH) {
        playerPos = WIDTH - 1;
    }
    screen[HEIGHT - 2][playerPos] = PLAYER;
}

void moveBullets() {
    if (bulletPos != -1) {
        screen[bulletPos][playerPos] = ' ';
        bulletPos--;
        if (bulletPos < 0) {
            bulletPos = -1;
        } else {
            screen[bulletPos][playerPos] = BULLET;
        }
    }
}

void moveEnemies() {
    for (int i = 0; i < enemyCount; i++) {
        screen[enemyPositions[i][0]][enemyPositions[i][1]] = ' ';
        enemyPositions[i][0]++;
        if (enemyPositions[i][0] >= HEIGHT - 1) {
            enemyPositions[i][0] = -1;
        } else {
            screen[enemyPositions[i][0]][enemyPositions[i][1]] = ENEMY;
        }
    }
}

void createEnemies() {
    for (int i = 0; i < 10; i++) {
        int y = rand() % 10;
        int x = rand() % WIDTH;
        enemyPositions[i][0] = y;
        enemyPositions[i][1] = x;
        screen[y][x] = ENEMY;
        enemyCount++;
    }
}

void killEnemy(int y, int x) {
    for (int i = 0; i < enemyCount; i++) {
        if (enemyPositions[i][0] == y && enemyPositions[i][1] == x) {
            enemyPositions[i][0] = -1;
            enemyPositions[i][1] = -1;
            screen[y][x] = ' ';
            enemyCount--;
            break;
        }
    }
}

void checkCollisions() {
    if (bulletPos != -1) {
        for (int i = 0; i < enemyCount; i++) {
            if (enemyPositions[i][0] == bulletPos && enemyPositions[i][1] == playerPos) {
                killEnemy(enemyPositions[i][0], enemyPositions[i][1]);
                bulletPos = -1;
                break;
            }
        }
    }

    for (int i = 0; i < enemyCount; i++) {
        if (enemyPositions[i][0] == HEIGHT - 2) {
            exit(0);
        }
    }
}