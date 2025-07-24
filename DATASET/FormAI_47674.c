//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20

int map[MAP_HEIGHT][MAP_WIDTH];

void generateMap() {
    srand(time(NULL));
    int i, j;
    for(i = 0; i < MAP_HEIGHT; i++) {
        for(j = 0; j < MAP_WIDTH; j++) {
            if(rand() % 5 == 0) map[i][j] = 1;
            else map[i][j] = 0;
        }
    }
}

void printMap() {
    int i, j;
    for(i = 0; i < MAP_HEIGHT; i++) {
        for(j = 0; j < MAP_WIDTH; j++) {
            if(map[i][j] == 1) printf("#");
            else printf(".");
        }
        printf("\n");
    }
}

int main() {
    generateMap();
    printMap();
    return 0;
}