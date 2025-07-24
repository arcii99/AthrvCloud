//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20

char map[MAP_HEIGHT][MAP_WIDTH];

void generateMap() {
    srand(time(NULL));

    for(int y=0; y<MAP_HEIGHT; y++) {
        for(int x=0; x<MAP_WIDTH; x++) {
            int randNum = rand() % 100;

            if(randNum < 20) {
                map[y][x] = '#';
            }
            else {
                map[y][x] = '.';
            }
        }
    }
}

int main() {
    generateMap();

    for(int y=0; y<MAP_HEIGHT; y++) {
        for(int x=0; x<MAP_WIDTH; x++) {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }

    return 0;
}