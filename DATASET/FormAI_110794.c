//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 10

void generateMap(int map[MAP_WIDTH][MAP_HEIGHT]) {
    srand(time(NULL));
    int i, j;

    // Initialize the map to all 0s
    for (i = 0; i < MAP_WIDTH; i++) {
        for (j = 0; j < MAP_HEIGHT; j++) {
            map[i][j] = 0;
        }
    }

    // Add some hills to the map
    for (i = 0; i < 50; i++) {
        int x = rand() % MAP_WIDTH;
        int y = rand() % MAP_HEIGHT;
        int size = rand() % 4 + 2;
        int height = rand() % 3 + 2;

        int startX = x - size;
        int startY = y - size;
        int endX = x + size;
        int endY = y + size;

        if (startX < 0) startX = 0;
        if (startY < 0) startY = 0;
        if (endX >= MAP_WIDTH) endX = MAP_WIDTH - 1;
        if (endY >= MAP_HEIGHT) endY = MAP_HEIGHT - 1;

        for (j = startY; j <= endY; j++) {
            for (i = startX; i <= endX; i++) {
                if (i >= x - (size - 1) && i <= x + (size - 1) && j >= y - (size - 1) && j <= y + (size - 1)) {
                    map[i][j] = height;
                }
            }
        }
    }

    // Add some trees to the map
    for (i = 0; i < 30; i++) {
        int x = rand() % MAP_WIDTH;
        int y = rand() % MAP_HEIGHT;

        if (map[x][y] == 0) {
            map[x][y] = -1;
        }
    }
}

void drawMap(int map[MAP_WIDTH][MAP_HEIGHT]) {
    int i, j;
    for (j = 0; j < MAP_HEIGHT; j++) {
        for (i = 0; i < MAP_WIDTH; i++) {
            switch (map[i][j]) {
                case 0:
                    printf(".");
                    break;
                case -1:
                    printf("T");
                    break;
                default:
                    printf("^");
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    int map[MAP_WIDTH][MAP_HEIGHT];
    generateMap(map);
    drawMap(map);
    return 0;
}