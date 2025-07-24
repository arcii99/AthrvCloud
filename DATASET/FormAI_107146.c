//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DUNGEON_WIDTH 50
#define DUNGEON_HEIGHT 50

char dungeon[DUNGEON_HEIGHT][DUNGEON_WIDTH];

enum TileType {
    EMPTY,
    FLOOR,
    WALL
};

void generateDungeon() {
    // Initialize the dungeon with walls
    for (int y = 0; y < DUNGEON_HEIGHT; y++) {
        for (int x = 0; x < DUNGEON_WIDTH; x++) {
            dungeon[y][x] = WALL;
        }
    }

    // Carve out rooms and corridors
    // TODO

    // Place stairs to the next level
    // TODO
}

void printDungeon() {
    for (int y = 0; y < DUNGEON_HEIGHT; y++) {
        for (int x = 0; x < DUNGEON_WIDTH; x++) {
            switch (dungeon[y][x]) {
                case EMPTY:
                    printf(" ");
                    break;
                case FLOOR:
                    printf(".");
                    break;
                case WALL:
                    printf("#");
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));
    generateDungeon();
    printDungeon();
    return 0;
}