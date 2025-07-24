//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10
#define NUM_ROOMS 5

typedef struct {
    int x;
    int y;
    int width;
    int height;
} Room;

typedef struct {
    char tiles[MAP_SIZE][MAP_SIZE];
    Room rooms[NUM_ROOMS];
} Map;

void print_map(Map* map) {
    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0; x < MAP_SIZE; x++) {
            printf("%c", map->tiles[x][y]);
        }
        printf("\n");
    }
}

void initialize_map(Map* map) {
    // Initialize all tiles to wall
    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0; x < MAP_SIZE; x++) {
            map->tiles[x][y] = '#';
        }
    }

    // Generate rooms
    srand(time(NULL));
    for (int i = 0; i < NUM_ROOMS; i++) {
        // Random room position and size
        int x = rand() % (MAP_SIZE - 3) + 1;
        int y = rand() % (MAP_SIZE - 3) + 1;
        int width = rand() % 4 + 4;
        int height = rand() % 4 + 4;

        // Check if room intersects with existing rooms
        for (int j = 0; j < i; j++) {
            Room* other_room = &map->rooms[j];
            if (x < other_room->x + other_room->width &&
                x + width > other_room->x &&
                y < other_room->y + other_room->height &&
                y + height > other_room->y) {
                // Rooms intersect, abort and try again
                i--;
                break;
            }
        }

        // Add room to map
        Room* room = &map->rooms[i];
        room->x = x;
        room->y = y;
        room->width = width;
        room->height = height;
        for (int y = room->y; y < room->y + room->height; y++) {
            for (int x = room->x; x < room->x + room->width; x++) {
                map->tiles[x][y] = '.';
            }
        }
    }
}

int main() {
    Map map;
    initialize_map(&map);
    print_map(&map);
    return 0;
}