//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEVEL 10       // Maximum depth of the dungeon
#define MAP_SIZE_X 100     // Width of the dungeon map
#define MAP_SIZE_Y 100     // Height of the dungeon map

#define WALL '#'
#define ROOM '.'
#define CORRIDOR '\''

char dungeon[MAP_SIZE_X][MAP_SIZE_Y];

void initializeDungeonMap() {
    // Fill the entire map with walls
    for (int x = 0; x < MAP_SIZE_X; x++) {
        for (int y = 0; y < MAP_SIZE_Y; y++) {
            dungeon[x][y] = WALL;
        }
    }
}

void printDungeonMap() {
    // Print the dungeon map to the console
    for (int y = 0; y < MAP_SIZE_Y; y++) {
        for (int x = 0; x < MAP_SIZE_X; x++) {
            printf("%c", dungeon[x][y]);
        }
        printf("\n");
    }
}

void createRoom(int x, int y, int width, int height) {
    // Create a rectangular room with the specified position and size
    for (int i = x; i < x + width; i++) {
        for (int j = y; j < y + height; j++) {
            dungeon[i][j] = ROOM;
        }
    }
}

void createCorridor(int x1, int y1, int x2, int y2) {
    // Create a straight horizontal or vertical corridor between two points
    if (x1 == x2) {
        for (int y = y1; y <= y2; y++) {
            dungeon[x1][y] = CORRIDOR;
        }
    } else if (y1 == y2) {
        for (int x = x1; x <= x2; x++) {
            dungeon[x][y1] = CORRIDOR;
        }
    }
}

void generateDungeon(int level) {
    // Place a random number of rooms and corridors
    int numRooms = rand() % 5 + 1;
    for (int i = 0; i < numRooms; i++) {
        int width = rand() % 10 + 5;
        int height = rand() % 10 + 5;
        int x = rand() % (MAP_SIZE_X - width - 1) + 1;
        int y = rand() % (MAP_SIZE_Y - height - 1) + 1;
        createRoom(x, y, width, height);
    }
    for (int i = 0; i < numRooms * 2; i++) {
        int x1 = rand() % (MAP_SIZE_X - 1) + 1;
        int y1 = rand() % (MAP_SIZE_Y - 1) + 1;
        int x2 = rand() % (MAP_SIZE_X - 1) + 1;
        int y2 = rand() % (MAP_SIZE_Y - 1) + 1;
        createCorridor(x1, y1, x2, y2);
    }
}

int main() {
    srand(time(NULL));
    initializeDungeonMap();
    generateDungeon(MAX_LEVEL);
    printDungeonMap();
    return 0;
}