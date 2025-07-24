//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20

void generateMap(char map[MAP_HEIGHT][MAP_WIDTH]) {
    srand(time(NULL));
    int row, col;
    for (row = 0; row < MAP_HEIGHT; row++) {
        for (col = 0; col < MAP_WIDTH; col++) {
            if (rand() % 100 < 40) {
                map[row][col] = '#';
            } else {
                map[row][col] = '.';
            }
        }
    }
}

void printMap(char map[MAP_HEIGHT][MAP_WIDTH]) {
    int row, col;
    for (row = 0; row < MAP_HEIGHT; row++) {
        for (col = 0; col < MAP_WIDTH; col++) {
            printf("%c", map[row][col]);
        }
        printf("\n");
    }
}

int main() {
    char map[MAP_HEIGHT][MAP_WIDTH];
    generateMap(map);
    printMap(map);
    return 0;
}