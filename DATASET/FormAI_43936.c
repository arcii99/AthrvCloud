//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20

typedef enum {
    FLOOR,
    WALL
} Tile;

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Tile tiles[MAP_WIDTH][MAP_HEIGHT];
    Point player_pos;
} Map;

Map generate_map() {
    Map map;

    // Fill map with walls
    for (int x = 0; x < MAP_WIDTH; x++) {
        for (int y = 0; y < MAP_HEIGHT; y++) {
            map.tiles[x][y] = WALL;
        }
    }

    // Place random floors
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        Point p = {rand() % MAP_WIDTH, rand() % MAP_HEIGHT};
        map.tiles[p.x][p.y] = FLOOR;
    }

    // Place player in a random position
    Point p = {rand() % MAP_WIDTH, rand() % MAP_HEIGHT};
    while (map.tiles[p.x][p.y] != FLOOR) {
        p.x = rand() % MAP_WIDTH;
        p.y = rand() % MAP_HEIGHT;
    }
    map.player_pos = p;

    return map;
}

void draw_map(Map map) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (map.player_pos.x == x && map.player_pos.y == y) {
                printf("@");
            } else {
                switch (map.tiles[x][y]) {
                    case FLOOR:
                        printf(".");
                        break;
                    case WALL:
                        printf("#");
                        break;
                }
            }
        }
        printf("\n");
    }
}

int main() {
    Map map = generate_map();
    draw_map(map);
    return 0;
}