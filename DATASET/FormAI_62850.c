//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25

char map[WIDTH][HEIGHT];

typedef struct {
    int x, y;
} Point;

Point playerPos;

void generateMap(int seed) {
    srand(seed);

    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            if (rand() % 100 < 40) {
                map[x][y] = '#';
            } else {
                map[x][y] = '.';
            }
        }
    }

    int stairs_x = rand() % WIDTH;
    int stairs_y = rand() % HEIGHT;
    map[stairs_x][stairs_y] = '>';

    int treasure_x = rand() % WIDTH;
    int treasure_y = rand() % HEIGHT;
    map[treasure_x][treasure_y] = '$';

    playerPos.x = rand() % WIDTH;
    playerPos.y = rand() % HEIGHT;
    map[playerPos.x][playerPos.y] = '@';
}

void drawMap() {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            printf("%c", map[x][y]);
        }
        printf("\n");
    }
}

int main() {
    int seed = time(NULL);
    generateMap(seed);
    drawMap();
    return 0;
}