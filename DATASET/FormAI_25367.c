//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEIGHT 20
#define MAX_WIDTH 30
#define MAX_ROOMS 6

typedef struct Room {
    int x;
    int y;
    int width;
    int height;
} Room;

typedef struct Map {
    char cells[MAX_HEIGHT][MAX_WIDTH];
    Room rooms[MAX_ROOMS];
    int roomCount;
} Map;

/**
 * Initializes the map with all cells set to wall ('#').
 */
void initMap(Map *map) {
    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            map->cells[i][j] = '#';
        }
    }
}

/**
 * Adds a room to the map.
 */
void addRoom(Map *map, Room room) {
    for (int i = room.y; i < room.y + room.height; i++) {
        for (int j = room.x; j < room.x + room.width; j++) {
            map->cells[i][j] = '.';
        }
    }
    map->rooms[map->roomCount++] = room;
}

/**
 * Generates random room dimensions within the given bounds.
 */
int getRandomDimension(int min, int max) {
    return (rand() % (max - min)) + min;
}

/**
 * Generates a random room with a given width and height.
 */
Room generateRoom(int widthBounds[2], int heightBounds[2]) {
    int width = getRandomDimension(widthBounds[0], widthBounds[1]);
    int height = getRandomDimension(heightBounds[0], heightBounds[1]);
    int x = getRandomDimension(1, MAX_WIDTH - width - 1);
    int y = getRandomDimension(1, MAX_HEIGHT - height - 1);
    Room room = {x, y, width, height};
    return room;
}

/**
 * Generates the map with a given number of rooms.
 */
void generateMap(Map *map, int roomCount) {
    initMap(map);
    for (int i = 0; i < roomCount; i++) {
        Room room = generateRoom((int[2]){4, 10}, (int[2]){3, 7});
        int overlap = 0;
        for (int j = 0; j < i; j++) {
            if (room.x < map->rooms[j].x + map->rooms[j].width + 2 &&
                    room.x + room.width + 2 > map->rooms[j].x &&
                    room.y < map->rooms[j].y + map->rooms[j].height + 2 &&
                    room.height + 2 + room.y > map->rooms[j].y) {
                overlap = 1;
                break;
            }
        }
        if (!overlap) {
            addRoom(map, room);
        }
    }
}

int main() {
    srand(time(NULL));

    Map map;
    generateMap(&map, MAX_ROOMS);

    printf("Generated map:\n");
    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            printf("%c", map.cells[i][j]);
        }
        printf("\n");
    }

    return 0;
}