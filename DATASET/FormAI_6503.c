//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAP_WIDTH 60
#define MAP_HEIGHT 20

typedef struct {
    int x;
    int y;
} Coord;

void drawMap(char map[MAP_HEIGHT][MAP_WIDTH], Coord player) {
    for(int y = 0; y < MAP_HEIGHT; y++) {
        for(int x = 0; x < MAP_WIDTH; x++) {
            if(x == player.x && y == player.y) {
                printf("@");
            } else {
                printf("%c", map[y][x]);
            }
        }
        printf("\n");
    }
}

void generateMap(char map[MAP_HEIGHT][MAP_WIDTH]) {
    for(int y = 0; y < MAP_HEIGHT; y++) {
        for(int x = 0; x < MAP_WIDTH; x++) {
            int r = rand() % 100;
            if(r < 10) {
                map[y][x] = '#';
            } else {
                map[y][x] = ' ';
            }
        }
    }
}

int main() {
    char map[MAP_HEIGHT][MAP_WIDTH];
    srand(1);
    generateMap(map);
    Coord player = { MAP_WIDTH / 2, MAP_HEIGHT / 2 };
    drawMap(map, player);

    return 0;
}