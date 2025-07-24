//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 30
#define MAP_HEIGHT 20
#define MAX_ROOMS 6
#define MAX_ROOM_SIZE 8
#define MIN_ROOM_SIZE 4

char map[MAP_HEIGHT][MAP_WIDTH];

int roomCount = 0;
struct Room {
    int x1, y1, x2, y2;
};

void createRoom(struct Room room) {
    int x, y;
    for (x = room.x1; x <= room.x2; x++) {
        for (y = room.y1; y <= room.y2; y++) {
            map[y][x] = '.';
        }
    }
}

int intersectsRoom(struct Room room) {
    int x, y;
    for (x = room.x1 - 1; x <= room.x2 + 1; x++) {
        for (y = room.y1 - 1; y <= room.y2 + 1; y++) {
            if (map[y][x] == '.') {
                return 1;
            }
        }
    }
    return 0;
}

void createCorridor(int x1, int y1, int x2, int y2) {
    int x = x1, y = y1;
    while (x != x2) {
        if (x < x2) {
            x++;
        } else {
            x--;
        }
        map[y][x] = '#';
    }
    while (y != y2) {
        if (y < y2) {
            y++;
        } else {
            y--;
        }
        map[y][x] = '#';
    }
}

void createMap() {
    int i, j, x, y, w, h, x1, y1, x2, y2;
    struct Room rooms[MAX_ROOMS];

    // clear the map
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = '#';
        }
    }

    // seed random number generator
    srand(time(NULL));

    // create rooms
    for (i = 0; i < MAX_ROOMS; i++) {
        w = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
        h = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
        x = rand() % (MAP_WIDTH - w - 1) + 1;
        y = rand() % (MAP_HEIGHT - h - 1) + 1;
        x1 = x - 1;
        y1 = y - 1;
        x2 = x + w;
        y2 = y + h;
        struct Room newRoom = { x1, y1, x2, y2 };
        if (!intersectsRoom(newRoom)) {
            createRoom(newRoom);
            rooms[roomCount] = newRoom;
            roomCount++;
        }
    }

    // create corridors
    for (i = 0; i < roomCount - 1; i++) {
        x1 = rooms[i].x1 + (rooms[i].x2 - rooms[i].x1) / 2;
        y1 = rooms[i].y1 + (rooms[i].y2 - rooms[i].y1) / 2;
        x2 = rooms[i + 1].x1 + (rooms[i + 1].x2 - rooms[i + 1].x1) / 2;
        y2 = rooms[i + 1].y1 + (rooms[i + 1].y2 - rooms[i + 1].y1) / 2;
        createCorridor(x1, y1, x2, y2);
    }
}

void printMap() {
    int i, j;
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    createMap();
    printMap();
    return 0;
}