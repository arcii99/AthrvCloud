//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 80
#define MAP_HEIGHT 25

typedef enum TileType {
    TILE_FLOOR,
    TILE_WALL
} TileType;

typedef struct Tile {
    TileType type;
} Tile;

typedef struct Map {
    Tile tiles[MAP_HEIGHT][MAP_WIDTH];
} Map;

void initialize_map(Map* map) {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            map->tiles[i][j].type = TILE_WALL;
        }
    }
}

void print_map(Map* map) {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            if (map->tiles[i][j].type == TILE_WALL) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    Map map;
    initialize_map(&map);

    // Randomly place rooms
    int num_rooms = 5 + rand() % 6;
    for (int i = 0; i < num_rooms; i++) {
        int room_width = 5 + rand() % 10;
        int room_height = 3 + rand() % 6;
        int room_x = rand() % (MAP_WIDTH - room_width - 1) + 1;
        int room_y = rand() % (MAP_HEIGHT - room_height - 1) + 1;
        for (int j = room_y; j < room_y + room_height; j++) {
            for (int k = room_x; k < room_x + room_width; k++) {
                map.tiles[j][k].type = TILE_FLOOR;
            }
        }
    }

    print_map(&map);
    return 0;
}