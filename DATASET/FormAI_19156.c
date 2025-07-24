//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 25
#define MAX_ROOMS 10
#define ROOM_MIN_SIZE 3
#define ROOM_MAX_SIZE 10

char map[MAP_HEIGHT][MAP_WIDTH];

struct Room {
    int x, y;
    int width, height;
};

void initMap();
void printMap();
void createRooms(struct Room*);
void generateMap(struct Room*);
void placeRoom(struct Room);
int isOverlap(struct Room, struct Room);

int main() {
    struct Room rooms[MAX_ROOMS];

    srand(time(NULL));

    initMap();

    createRooms(rooms);
    generateMap(rooms);

    printMap();

    return 0;
}

void initMap() {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = '#';
        }
    }
}

void printMap() {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void createRooms(struct Room* rooms) {
    int i = 0;

    while (i < MAX_ROOMS) {
        int width = (rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1)) + ROOM_MIN_SIZE;
        int height = (rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1)) + ROOM_MIN_SIZE;
        int x = rand() % (MAP_WIDTH - width - 1) + 1;
        int y = rand() % (MAP_HEIGHT - height - 1) + 1;

        struct Room room = { x, y, width, height };

        if (!isOverlap(room, rooms[i])) {
            rooms[i++] = room;
        }
    }
}

void generateMap(struct Room* rooms) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        placeRoom(rooms[i]);
    }
}

void placeRoom(struct Room room) {
    for (int i = room.y; i < room.y + room.height; i++) {
        for (int j = room.x; j < room.x + room.width; j++) {
            map[i][j] = '.';
        }
    }
}

int isOverlap(struct Room r1, struct Room r2) {
    if (r1.x < r2.x + r2.width && r1.x + r1.width > r2.x && r1.y < r2.y + r2.height && r1.y + r1.height > r2.y) {
        return 1;
    }
    return 0;
}