//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MAP_WIDTH 50
#define MAX_MAP_HEIGHT 50

char map[MAX_MAP_HEIGHT][MAX_MAP_WIDTH];

void generateMap() {
    // Initialize random seed
    srand(time(NULL));

    // Generate map
    for (int y = 0; y < MAX_MAP_HEIGHT; y++) {
        for (int x = 0; x < MAX_MAP_WIDTH; x++) {
            int randNum = rand() % 100;
            if (randNum < 5) {
                map[y][x] = '#'; // Wall
            } else {
                map[y][x] = '.'; // Floor
            }
        }
    }
}

void printMap() {
    for (int y = 0; y < MAX_MAP_HEIGHT; y++) {
        for (int x = 0; x < MAX_MAP_WIDTH; x++) {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
}

int main() {
    generateMap();
    printMap();

    return 0;
}