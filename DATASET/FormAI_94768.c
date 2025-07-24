//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: lively
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20

char map[MAP_HEIGHT][MAP_WIDTH];

void generateMap() {
    srand(time(NULL)); // seed random number generator

    // initialize map with walls
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = '#';
        }
    }

    // place random floor tiles
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            if (rand() % 100 < 40) { // 40% chance of a floor tile
                map[i][j] = '.';
            }
        }
    }

    // place random items and enemies
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            if (map[i][j] == '.') {
                if (rand() % 100 < 10) { // 10% chance of an item
                    map[i][j] = '+';
                } else if (rand() % 100 < 5) { // 5% chance of an enemy
                    map[i][j] = 'E';
                }
            }
        }
    }

    // place player on a random floor tile
    int player_x, player_y;
    do {
        player_x = rand() % MAP_WIDTH;
        player_y = rand() % MAP_HEIGHT;
    } while (map[player_y][player_x] != '.');
    map[player_y][player_x] = '@';
}

void printMap() {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    generateMap();
    printMap();

    return 0;
}