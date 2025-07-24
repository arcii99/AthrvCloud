//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 80 
#define MAX_HEIGHT 24
#define MAX_ROOMS 10

typedef struct Room {
    int x, y, width, height;
} Room;

typedef struct Map {
    char tiles[MAX_HEIGHT][MAX_WIDTH];
    int width, height;
    Room rooms[MAX_ROOMS];
    int num_rooms;
} Map;

void init_map(Map *map) {
    int i, j;

    // Fill map with walls
    for (i = 0; i < MAX_HEIGHT; i++) {
        for (j = 0; j < MAX_WIDTH; j++) {
            map->tiles[i][j] = '#';
        }
    }

    // Add rooms to map
    for (i = 0; i < MAX_ROOMS; i++) {
        // Generate random room dimensions
        int width = rand() % 10 + 5;
        int height = rand() % 6 + 3;

        // Generate random room position
        int x = rand() % (MAX_WIDTH - width - 2) + 1;
        int y = rand() % (MAX_HEIGHT - height - 2) + 1;

        // Create room
        Room room = { x, y, width, height };
        map->rooms[i] = room;
        map->num_rooms++;

        // Fill room with floor tiles
        int r, c;
        for (r = y; r < y + height; r++) {
            for (c = x; c < x + width; c++) {
                map->tiles[r][c] = '.';
            }
        }
    }
}

void print_map(Map map) {
    int i, j;

    // Print map
    for (i = 0; i < map.height; i++) {
        for (j = 0; j < map.width; j++) {
            printf("%c", map.tiles[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Initialize map
    srand(time(NULL));
    Map map = { { {'\0'} }, MAX_WIDTH, MAX_HEIGHT, { {0} }, 0 };
    init_map(&map);

    // Print map
    print_map(map);

    return 0;
}