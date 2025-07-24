//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 40

enum Tile {
    WALL,
    FLOOR,
};

void generateMap(enum Tile map[HEIGHT][WIDTH]);
void printMap(enum Tile map[HEIGHT][WIDTH]);

int main() {
    enum Tile map[HEIGHT][WIDTH];

    srand(time(NULL));
    generateMap(map);
    printMap(map);

    return 0;
}

void generateMap(enum Tile map[HEIGHT][WIDTH]) {
    int r;

    // Set all tiles to walls
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            map[y][x] = WALL;
        }
    }

    // Add floors randomly
    for (int y = 1; y < HEIGHT - 1; y++) {
        for (int x = 1; x < WIDTH - 1; x++) {
            r = rand() % 100;
            if (r < 40) {
                map[y][x] = FLOOR;
            }
        }
    }
}

void printMap(enum Tile map[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (map[y][x] == WALL) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}