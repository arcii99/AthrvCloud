//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 10
#define MAX_MONSTERS 5

typedef struct {
    int x, y;
    char symbol;
} Entity;

typedef struct {
    int x, y;
} Point;

Entity player = {0, 0, '@'};
Entity monsters[MAX_MONSTERS];
char map[MAP_WIDTH][MAP_HEIGHT];
Point playerPos;
int monsterCount;

void mapInit() {
    int i, j;
    for (i = 0; i < MAP_WIDTH; i++) {
        for (j = 0; j < MAP_HEIGHT; j++) {
            map[i][j] = '#';
        }
    }
}

void placePlayer() {
    srand(time(NULL));
    playerPos.x = rand() % MAP_WIDTH;
    playerPos.y = rand() % MAP_HEIGHT;
    player.x = playerPos.x;
    player.y = playerPos.y;
    map[playerPos.x][playerPos.y] = player.symbol;
}

void placeMonsters() {
    srand(time(NULL));
    int i;
    for (i = 0; i < MAX_MONSTERS; i++) {
        monsters[i].x = rand() % MAP_WIDTH;
        monsters[i].y = rand() % MAP_HEIGHT;
        monsters[i].symbol = 'M';
        monsterCount += 1;
        map[monsters[i].x][monsters[i].y] = monsters[i].symbol;
    }
}

void displayMap() {
    int i, j;
    for (i = 0; i < MAP_WIDTH; i++) {
        for (j = 0; j < MAP_HEIGHT; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void handleInput(char input) {
    switch (input) {
        case 'w':
            if (playerPos.y > 0) {
                map[playerPos.x][playerPos.y] = '#';
                playerPos.y--;
                player.y = playerPos.y;
                map[playerPos.x][playerPos.y] = player.symbol;
            }
            break;
        
        case 's':
            if (playerPos.y < MAP_HEIGHT - 1) {
                map[playerPos.x][playerPos.y] = '#';
                playerPos.y++;
                player.y = playerPos.y;
                map[playerPos.x][playerPos.y] = player.symbol;
            }
            break;
        
        case 'a':
            if (playerPos.x > 0) {
                map[playerPos.x][playerPos.y] = '#';
                playerPos.x--;
                player.x = playerPos.x;
                map[playerPos.x][playerPos.y] = player.symbol;
            }
            break;
        
        case 'd':
            if (playerPos.x < MAP_WIDTH - 1) {
                map[playerPos.x][playerPos.y] = '#';
                playerPos.x++;
                player.x = playerPos.x;
                map[playerPos.x][playerPos.y] = player.symbol;
            }
            break;
    }
}

int main() {
    mapInit();
    placePlayer();
    placeMonsters();
    displayMap();
    char input;
    while (monsterCount > 0) {
        scanf(" %c", &input);
        handleInput(input);

        int i;
        for (i = 0; i < MAX_MONSTERS; i++) {
            if (monsters[i].x == playerPos.x && monsters[i].y == playerPos.y) {
                monsterCount--;
                monsters[i].symbol = '#';
                map[playerPos.x][playerPos.y] = player.symbol;
                printf("You have killed a monster!\n");
            }
        }

        displayMap();
    }

    printf("You have defeated all the monsters and won the game!\n");
    return 0;
}