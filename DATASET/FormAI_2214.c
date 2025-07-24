//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20
#define ROOM_MIN_SIZE 3
#define ROOM_MAX_SIZE 6
#define MAX_ROOMS 5

#define WALL 0
#define FLOOR 1

typedef struct {
    int x;
    int y;
    int width;
    int height;
} Room;

int map[MAP_SIZE][MAP_SIZE] = {0};
Room rooms[MAX_ROOMS];

void print_map() {
    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0; x < MAP_SIZE; x++) {
            printf("%c", (map[x][y] == WALL) ? '#' : '.');
        }
        printf("\n");
    }
}

void generate_map() {
    // Initialize map with walls
    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0; x < MAP_SIZE; x++) {
            map[x][y] = WALL;
        }
    }

    // Generate rooms
    srand(time(0));
    for (int i = 0; i < MAX_ROOMS; i++) {
        // Randomize room location and size
        int x = rand() % (MAP_SIZE - ROOM_MAX_SIZE - 1) + 1;
        int y = rand() % (MAP_SIZE - ROOM_MAX_SIZE - 1) + 1;
        int width = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
        int height = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;

        // Create room
        Room room = {x, y, width, height};

        // Check if the room overlaps with any previous rooms
        int overlap = 0;
        for (int j = 0; j < i; j++) {
            if (room.x < rooms[j].x + rooms[j].width &&
                room.x + room.width > rooms[j].x &&
                room.y < rooms[j].y + rooms[j].height &&
                room.y + room.height > rooms[j].y) {
                overlap = 1;
                break;
            }
        }

        // If no overlap, add the room to the map
        if (!overlap) {
            for (int y = room.y; y < room.y + room.height; y++) {
                for (int x = room.x; x < room.x + room.width; x++) {
                    map[x][y] = FLOOR;
                }
            }
            rooms[i] = room;
        }
    }
}

int main() {
    generate_map();
    print_map();
    return 0;
}