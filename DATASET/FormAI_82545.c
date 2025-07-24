//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20

char map[MAP_SIZE][MAP_SIZE];
int playerX, playerY;

void initMap() {
    // Fill the map with walls
    for(int i = 0; i < MAP_SIZE; i++) {
        for(int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = '#';
        }
    }

    // Create a random room in the center of the map
    int roomSize = rand() % 5 + 5;
    int roomStartX = MAP_SIZE / 2 - roomSize / 2;
    int roomStartY = MAP_SIZE / 2 - roomSize / 2;
    for(int i = roomStartX; i < roomStartX + roomSize; i++) {
        for(int j = roomStartY; j < roomStartY + roomSize; j++) {
            map[i][j] = '.';
        }
    }

    // Place the player in the center of the room
    playerX = MAP_SIZE / 2;
    playerY = MAP_SIZE / 2;
    map[playerX][playerY] = '@';
}

void printMap() {
    for(int i = 0; i < MAP_SIZE; i++) {
        for(int j = 0; j < MAP_SIZE; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

void movePlayer(int dx, int dy) {
    char nextTile = map[playerX + dx][playerY + dy];
    if(nextTile == '.') {
        map[playerX][playerY] = '.';
        playerX += dx;
        playerY += dy;
        map[playerX][playerY] = '@';
    }
}

int main() {
    srand(time(NULL));
    initMap();
    printMap();

    while(1) {
        char input = getchar();
        if(input == 'q') {
            break;
        }
        else if(input == 'w') {
            movePlayer(-1, 0);
        }
        else if(input == 'a') {
            movePlayer(0, -1);
        }
        else if(input == 's') {
            movePlayer(1, 0);
        }
        else if(input == 'd') {
            movePlayer(0, 1);
        }

        printMap();
    }

    return 0;
}