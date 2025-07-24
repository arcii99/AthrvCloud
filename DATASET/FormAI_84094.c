//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constants for the map size
#define MAP_WIDTH 20
#define MAP_HEIGHT 10

// constants for the map tiles
#define TILE_EMPTY '.'
#define TILE_WALL '|'
#define TILE_PLAYER '@'

// function to randomly generate a map
void generateMap(char map[MAP_HEIGHT][MAP_WIDTH]) {
    // seed the random number generator
    srand(time(NULL));

    // fill the map with empty tiles
    for (int row = 0; row < MAP_HEIGHT; row++) {
        for (int col = 0; col < MAP_WIDTH; col++) {
            map[row][col] = TILE_EMPTY;
        }
    }

    // randomly place walls
    for (int i = 0; i < MAP_HEIGHT * MAP_WIDTH / 4; i++) {
        int row = rand() % MAP_HEIGHT;
        int col = rand() % MAP_WIDTH;
        if (map[row][col] == TILE_EMPTY) {
            map[row][col] = TILE_WALL;
        }
    }

    // randomly place the player
    int playerRow = rand() % MAP_HEIGHT;
    int playerCol = rand() % MAP_WIDTH;
    while (map[playerRow][playerCol] != TILE_EMPTY) {
        playerRow = rand() % MAP_HEIGHT;
        playerCol = rand() % MAP_WIDTH;
    }
    map[playerRow][playerCol] = TILE_PLAYER;
}

// function to print the map to the console
void printMap(char map[MAP_HEIGHT][MAP_WIDTH]) {
    for (int row = 0; row < MAP_HEIGHT; row++) {
        for (int col = 0; col < MAP_WIDTH; col++) {
            printf("%c", map[row][col]);
        }
        printf("\n");
    }
}

int main() {
    // create and generate the map
    char map[MAP_HEIGHT][MAP_WIDTH];
    generateMap(map);

    // print the map and wait for user input
    printMap(map);
    getchar();

    return 0;
}