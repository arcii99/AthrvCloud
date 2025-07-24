//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 30
#define NUM_ROOMS 6

#define EMPTY '.'
#define WALL '#'
#define ROOM '+'
#define CORRIDOR '.'

// Define a struct to represent a room
typedef struct room {
    int x, y, w, h;
} room_t;

// Define a struct to represent the game map
typedef struct map {
    char tiles[MAP_SIZE][MAP_SIZE];
    room_t rooms[NUM_ROOMS];
} map_t;

// Function to initialize map with walls and empty space
void initMap(map_t* map) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (i == 0 || i == MAP_SIZE - 1 || j == 0 || j == MAP_SIZE - 1) {
                map->tiles[i][j] = WALL;
            } else {
                map->tiles[i][j] = EMPTY;
            }
        }
    }
}

// Function to draw a room on the map
void drawRoom(map_t* map, room_t* room) {
    for (int i = room->x; i < room->x + room->w; i++) {
        for (int j = room->y; j < room->y + room->h; j++) {
            if (i == room->x || i == room->x + room->w - 1 || j == room->y || j == room->y + room->h - 1) {
                map->tiles[i][j] = WALL;
            } else {
                map->tiles[i][j] = ROOM;
            }
        }
    }
}

// Function to draw a corridor between two rooms
void drawCorridor(map_t* map, room_t* from, room_t* to) {
    // Determine the direction of the corridor
    int x_dir = (to->x + to->w / 2) - (from->x + from->w / 2);
    int y_dir = (to->y + to->h / 2) - (from->y + from->h / 2);

    // Draw the corridor
    int x = from->x + from->w / 2;
    int y = from->y + from->h / 2;
    while (x != to->x + to->w / 2 || y != to->y + to->h / 2) {
        if (x != to->x + to->w / 2 && rand() % 2 == 0) {
            if (x_dir > 0) {
                x++;
            } else {
                x--;
            }
        } else {
            if (y_dir > 0) {
                y++;
            } else {
                y--;
            }
        }
        map->tiles[x][y] = CORRIDOR;
    }
}

// Function to generate a random room with given width and height
void generateRoom(room_t* room, int min_size, int max_size) {
    room->w = rand() % (max_size - min_size) + min_size;
    room->h = rand() % (max_size - min_size) + min_size;
}

// Function to check if a newly generated room collides with existing rooms
int checkCollisions(map_t* map, room_t* room) {
    for (int i = room->x - 1; i < room->x + room->w + 1; i++) {
        for (int j = room->y - 1; j < room->y + room->h + 1; j++) {
            if (map->tiles[i][j] != EMPTY) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to randomly generate rooms and corridors on the map
void generateMap(map_t* map) {
    // Generate initial room in center of map
    room_t room;
    generateRoom(&room, 5, 10);
    room.x = MAP_SIZE / 2 - room.w / 2;
    room.y = MAP_SIZE / 2 - room.h / 2;
    drawRoom(map, &room);
    map->rooms[0] = room;

    // Generate remaining rooms and corridors
    for (int i = 1; i < NUM_ROOMS; i++) {
        // Generate a new room and check for collisions
        do {
            generateRoom(&room, 3, 8);
            room.x = rand() % (MAP_SIZE - room.w - 1) + 1;
            room.y = rand() % (MAP_SIZE - room.h - 1) + 1;
        } while (checkCollisions(map, &room));
        drawRoom(map, &room);
        map->rooms[i] = room;

        // Draw a corridor to the previous room
        drawCorridor(map, &map->rooms[i - 1], &map->rooms[i]);
    }
}

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Generate game map
    map_t map;
    initMap(&map);
    generateMap(&map);

    // Print game map
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            printf("%c", map.tiles[i][j]);
        }
        printf("\n");
    }

    return 0;
}