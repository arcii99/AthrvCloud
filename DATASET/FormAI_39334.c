//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20

char map[MAP_HEIGHT][MAP_WIDTH];

void generateMap() {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            if (rand() % 5 == 0) {
                map[i][j] = '#';
            } else {
                map[i][j] = '.';
            }
        }
    }
}

void displayMap() {
    int i, j;
    printf("+");
    for (i = 0; i < MAP_WIDTH; i++) {
        printf("-");
    }
    printf("+\n");
    for (i = 0; i < MAP_HEIGHT; i++) {
        printf("|");
        for (j = 0; j < MAP_WIDTH; j++) {
            if (map[i][j] == '#') {
                printf("\033[1;33m#\033[0m");
            } else {
                printf(".");
            }
        }
        printf("|\n");
    }
    printf("+");
    for (i = 0; i < MAP_WIDTH; i++) {
        printf("-");
    }
    printf("+\n");
}

int main() {
    generateMap();
    displayMap();
    return 0;
}