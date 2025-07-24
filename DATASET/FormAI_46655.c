//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 30
#define MAP_HEIGHT 20
#define MAX_ROOMS 5
#define MAX_ROOM_SIZE 8
#define MIN_ROOM_SIZE 4

typedef struct {
    int x, y, w, h;
} Room;

typedef struct {
    int x, y;
} Point;

typedef enum {
    EMPTY,
    WALL,
    ROOM,
    CORRIDOR
} Tile;

Tile map[MAP_HEIGHT][MAP_WIDTH];

void initMap() {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = WALL;
        }
    }
}

void printMap() {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            switch (map[i][j]) {
                case EMPTY: printf("."); break;
                case WALL: printf("#"); break;
                case ROOM: printf("R"); break;
                case CORRIDOR: printf("C"); break;
            }
        }
        printf("\n");
    }
}

int getRandomIntInRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}

Point getRandomPointInRoom(Room room) {
    return (Point) { 
        getRandomIntInRange(room.x, room.x + room.w - 1),
        getRandomIntInRange(room.y, room.y + room.h - 1)
    };
}

void connectRooms(Room room1, Room room2) {
    Point p1 = getRandomPointInRoom(room1);
    Point p2 = getRandomPointInRoom(room2);

    while (p1.x != p2.x || p1.y != p2.y) {
        if (p1.x != p2.x) {
            int deltaX = (p1.x < p2.x) ? 1 : -1;
            p1.x += deltaX;
            map[p1.y][p1.x] = CORRIDOR;
        }
        if (p1.y != p2.y) {
            int deltaY = (p1.y < p2.y) ? 1 : -1;
            p1.y += deltaY;
            map[p1.y][p1.x] = CORRIDOR;
        }
    }
}

void generateRooms() {
    Room rooms[MAX_ROOMS];

    for (int i = 0; i < MAX_ROOMS; i++) {
        Room room;
        room.w = getRandomIntInRange(MIN_ROOM_SIZE, MAX_ROOM_SIZE);
        room.h = getRandomIntInRange(MIN_ROOM_SIZE, MAX_ROOM_SIZE);
        room.x = getRandomIntInRange(1, MAP_WIDTH - room.w - 1);
        room.y = getRandomIntInRange(1, MAP_HEIGHT - room.h - 1);

        for (int j = 0; j < i; j++) {
            if (room.x < rooms[j].x + rooms[j].w &&
                room.x + room.w > rooms[j].x &&
                room.y < rooms[j].y + rooms[j].h &&
                room.y + room.h > rooms[j].y) {
                i--;
                goto roomOverlap;
            }
        }

        rooms[i] = room;

        for (int y = room.y; y < room.y + room.h; y++) {
            for (int x = room.x; x < room.x + room.w; x++) {
                map[y][x] = ROOM;
            }
        }

        roomOverlap:;
    }

    for (int i = 0; i < MAX_ROOMS - 1; i++) {
        connectRooms(rooms[i], rooms[i + 1]);
    }
}

int main() {
    srand(time(NULL));
    initMap();
    generateRooms();
    printMap();
    return 0;
}