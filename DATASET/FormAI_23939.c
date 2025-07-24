//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 20

char map[SCREEN_WIDTH * SCREEN_HEIGHT];

void initializeMap();
void drawMap();
void generateMap(int seed);
void placeWalls();
void placeEnemies();
void placePlayer();
void movePlayer(int dx, int dy);
int getCellIndex(int x, int y);

int main() {
    int seed = time(NULL);
    srand(seed);

    initializeMap();
    generateMap(seed);

    char input = ' ';
    while (input != 'q') {
        drawMap();
        printf("\nEnter movement direction (wasd) or press q to quit: ");
        scanf(" %c", &input);

        switch (input) {
            case 'w':
                movePlayer(-SCREEN_WIDTH, 0);
                break;
            case 'a':
                movePlayer(-1, 0);
                break;
            case 's':
                movePlayer(SCREEN_WIDTH, 0);
                break;
            case 'd':
                movePlayer(1, 0);
                break;
        }
    }

    return 0;
}

void initializeMap() {
    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
        map[i] = ' ';
    }
}

void drawMap() {
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            printf("%c", map[getCellIndex(x, y)]);
        }
        printf("\n");
    }
}

void generateMap(int seed) {
    placeWalls();
    placeEnemies();
    placePlayer();
}

void placeWalls() {
    // code for placing randomized walls
}

void placeEnemies() {
    // code for placing randomized enemies
}

void placePlayer() {
    int playerX = SCREEN_WIDTH / 2;
    int playerY = SCREEN_HEIGHT / 2;
    map[getCellIndex(playerX, playerY)] = '@';
}

void movePlayer(int dx, int dy) {
    int playerX, playerY;
    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
        if (map[i] == '@') {
            playerX = i % SCREEN_WIDTH;
            playerY = i / SCREEN_WIDTH;
        }
    }

    int newPlayerX = playerX + dx;
    int newPlayerY = playerY + dy;
    int newPlayerIndex = getCellIndex(newPlayerX, newPlayerY);

    if (map[newPlayerIndex] == '.') {
        map[getCellIndex(playerX, playerY)] = '.';
        map[newPlayerIndex] = '@';
    }
}

int getCellIndex(int x, int y) {
    return y * SCREEN_WIDTH + x;
}