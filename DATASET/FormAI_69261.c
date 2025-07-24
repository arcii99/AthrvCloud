//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

// Generate random map
void generateMap(int map[MAP_WIDTH][MAP_HEIGHT]) {
    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            map[i][j] = rand() % 2; // randomly assign tile type
        }
    }
}

int main() {
    int map[MAP_WIDTH][MAP_HEIGHT];
    generateMap(map);

    // print map
    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    return 0;
}