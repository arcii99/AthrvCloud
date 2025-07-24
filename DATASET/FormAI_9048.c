//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 40
#define MAP_HEIGHT 20

char map[MAP_HEIGHT][MAP_WIDTH];

void generateMap() {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            int r = rand() % 100;
            if (r < 30) {
                map[i][j] = '#';
            } else if (r < 50) {
                map[i][j] = '.';
            } else {
                map[i][j] = '+';
            }
        }
    }
}

void printMap() {
    int i, j;
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    generateMap();
    printMap();
    return 0;
}