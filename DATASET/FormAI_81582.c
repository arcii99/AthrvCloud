//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20
#define MAX_ROOMS 10
#define MAX_ROOM_WIDTH 10
#define MAX_ROOM_HEIGHT 10
#define MAX_MONSTERS 5

typedef struct {
    int x, y;
} Position;

typedef struct {
    Position position;
    char symbol;
} Monster;

char map[MAP_HEIGHT][MAP_WIDTH];

void generateRooms() {
    int i, x, y, roomWidth, roomHeight;
    for (i = 0; i < MAX_ROOMS; i++) {
        roomWidth = rand() % MAX_ROOM_WIDTH + 1;
        roomHeight = rand() % MAX_ROOM_HEIGHT + 1;
        x = rand() % (MAP_WIDTH - roomWidth - 1) + 1;
        y = rand() % (MAP_HEIGHT - roomHeight - 1) + 1;
        int j, k;
        for (j = y; j < y + roomHeight; j++) {
            for (k = x; k < x + roomWidth; k++) {
                map[j][k] = '.';
            }
        }
    }
}

void placePlayer(Position* player) {
    int x = rand() % (MAP_WIDTH - 2) + 1;
    int y = rand() % (MAP_HEIGHT - 2) + 1;
    while (map[y][x] != '.') {
        x = rand() % (MAP_WIDTH - 2) + 1;
        y = rand() % (MAP_HEIGHT - 2) + 1;
    }
    player->x = x;
    player->y = y;
}

void placeMonsters(Monster* monsters, int* numMonsters) {
    int i, x, y;
    *numMonsters = rand() % MAX_MONSTERS + 1;
    for (i = 0; i < *numMonsters; i++) {
        x = rand() % (MAP_WIDTH - 2) + 1;
        y = rand() % (MAP_HEIGHT - 2) + 1;
        while (map[y][x] != '.') {
            x = rand() % (MAP_WIDTH - 2) + 1;
            y = rand() % (MAP_HEIGHT - 2) + 1;
        }
        monsters[i].position.x = x;
        monsters[i].position.y = y;
        monsters[i].symbol = 'M';
    }
}

void printMap(Position player, Monster* monsters, int numMonsters) {
    int i, j, k;
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            if (i == player.y && j == player.x) {
                printf("@");
            }
            else {
                int monsterPresent = 0;
                for (k = 0; k < numMonsters; k++) {
                    if (monsters[k].position.x == j && monsters[k].position.y == i) {
                        printf("%c", monsters[k].symbol);
                        monsterPresent = 1;
                        break;
                    }
                }
                if (!monsterPresent) {
                    printf("%c", map[i][j]);
                }
            }
        }
        printf("\n");
    }
}

int main() {
    srand((unsigned int) time(NULL));
    int i, numMonsters;
    Position player;
    Monster monsters[MAX_MONSTERS];
    for (i = 0; i < MAP_HEIGHT; i++) {
        int j;
        for (j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = '#';
        }
    }
    generateRooms();
    placePlayer(&player);
    placeMonsters(monsters, &numMonsters);
    printMap(player, monsters, numMonsters);
    return 0;
}