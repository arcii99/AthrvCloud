//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 30

enum TileType {
    WALL,
    FLOOR
};

typedef struct {
    int x, y;
} Position;

typedef struct {
    int width, height;
    enum TileType tiles[MAP_SIZE][MAP_SIZE];
} Map;

void initialize_map(Map* map) {
    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0; x < MAP_SIZE; x++) {
            map->tiles[y][x] = WALL;
        }
    }
}

void carve_room(Map* map, Position pos, int width, int height) {
    for (int y = pos.y; y < pos.y + height; y++) {
        for (int x = pos.x; x < pos.x + width; x++) {
            if (x >= 0 && x < MAP_SIZE && y >= 0 && y < MAP_SIZE) {
                map->tiles[y][x] = FLOOR;
            }
        }
    }
}

void generate_dungeon(Map* map) {
    initialize_map(map);
    srand(time(NULL));

    int num_rooms = 5 + rand() % 5;
    for (int i = 0; i < num_rooms; i++) {
        int width = 4 + rand() % 8;
        int height = 4 + rand() % 8;
        int x = rand() % (MAP_SIZE - width - 1) + 1;
        int y = rand() % (MAP_SIZE - height - 1) + 1;
        carve_room(map, (Position){x, y}, width, height);
    }
}

int main() {
    Map map;
    generate_dungeon(&map);

    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0; x < MAP_SIZE; x++) {
            printf("%c", map.tiles[y][x] == WALL ? '#' : '.');
        }
        printf("\n");
    }

    return 0;
}