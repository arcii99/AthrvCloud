//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 10
#define MAX_ROOMS 5

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position position;
    int width;
    int height;
} Room;

char map[MAP_WIDTH][MAP_HEIGHT];

void initializeMap() {
    for (int x = 0; x < MAP_WIDTH; x++) {
        for (int y = 0; y < MAP_HEIGHT; y++) {
            map[x][y] = '#';
        }
    }
}

void printMap() {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            printf("%c", map[x][y]);
        }
        printf("\n");
    }
}

void createRoom(Room room) {
    for (int x = room.position.x; x < room.position.x + room.width; x++) {
        for (int y = room.position.y; y < room.position.y + room.height; y++) {
            map[x][y] = ' ';
        }
    }
}

int isOverlapping(Room room1, Room room2) {
    if (room1.position.x + room1.width <= room2.position.x) return 0;
    if (room1.position.x >= room2.position.x + room2.width) return 0;
    if (room1.position.y + room1.height <= room2.position.y) return 0;
    if (room1.position.y >= room2.position.y + room2.height) return 0;
    return 1;
}

void generateMap() {
    Room rooms[MAX_ROOMS];
    int numRooms = 0;

    srand(time(NULL));

    initializeMap();

    while (numRooms < MAX_ROOMS) {
        Room room;
        room.width = rand() % 6 + 5;
        room.height = rand() % 6 + 5;
        room.position.x = rand() % (MAP_WIDTH - room.width - 1) + 1;
        room.position.y = rand() % (MAP_HEIGHT - room.height - 1) + 1;

        int overlapping = 0;
        for (int i = 0; i < numRooms; i++) {
            if (isOverlapping(room, rooms[i])) {
                overlapping = 1;
                break;
            }
        }

        if (!overlapping) {
            rooms[numRooms] = room;
            createRoom(room);
            numRooms++;
        }
    }
}

int main() {
    generateMap();
    printMap();
    return 0;
}