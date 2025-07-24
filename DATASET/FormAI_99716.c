//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 60
#define MAP_HEIGHT 20

char map[MAP_HEIGHT][MAP_WIDTH];

void generateMap() {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            int num = rand() % 10;
            if (num < 3) {
                map[i][j] = '#';
            } else {
                map[i][j] = '.';
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