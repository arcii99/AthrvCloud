//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 30
#define MAX_ENEMIES 10

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    char map[MAP_SIZE][MAP_SIZE];
    Position player;
    Position enemies[MAX_ENEMIES];
    int num_enemies;
} GameData;

void initializeGameData(GameData* gameData) {
    // set player position to center of map
    gameData->player.x = MAP_SIZE / 2;
    gameData->player.y = MAP_SIZE / 2;

    // randomly place enemies on map
    srand(time(NULL));
    gameData->num_enemies = rand() % MAX_ENEMIES;
    for (int i = 0; i < gameData->num_enemies; i++) {
        gameData->enemies[i].x = rand() % MAP_SIZE;
        gameData->enemies[i].y = rand() % MAP_SIZE;
    }

    // initialize map with walls
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (i == 0 || i == MAP_SIZE - 1 || j == 0 || j == MAP_SIZE - 1) {
                gameData->map[i][j] = '#';
            } else {
                gameData->map[i][j] = '.';
            }
        }
    }

    // place player and enemies on map
    gameData->map[gameData->player.x][gameData->player.y] = '@';
    for (int i = 0; i < gameData->num_enemies; i++) {
        gameData->map[gameData->enemies[i].x][gameData->enemies[i].y] = 'E';
    }
}

void printMap(GameData* gameData) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            printf("%c ", gameData->map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    GameData gameData;
    initializeGameData(&gameData);
    printMap(&gameData);
    return 0;
}