//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24

typedef enum {EMPTY, WALL, FLOOR} CellType;

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    CellType type;
    char displayChar;
} Cell;

typedef struct {
    Cell cells[WIDTH][HEIGHT];
} Map;

const int ROOM_MAX_SIZE = 10;
const int ROOM_MIN_SIZE = 6;
const int MAX_ROOMS = 15;

void initMap(Map* map) {
    int x, y;
    for (x = 0; x < WIDTH; ++x) {
        for (y = 0; y < HEIGHT; ++y) {
            map->cells[x][y].type = WALL;
            map->cells[x][y].displayChar = '#';
        }
    }
}

void createRoom(Map* map, int x, int y, int w, int h) {
    int px, py;
    for (px = x; px < x + w; ++px) {
        for (py = y; py < y + h; ++py) {
            map->cells[px][py].type = FLOOR;
            map->cells[px][py].displayChar = '.';
        }
    }
}

void createHorizontalTunnel(Map* map, int x1, int x2, int y) {
    int x;
    for (x = (x1 < x2 ? x1 : x2); x < (x1 < x2 ? x2 + 1 : x1 + 1); ++x) {
        map->cells[x][y].type = FLOOR;
        map->cells[x][y].displayChar = '.';
    }
}

void createVerticalTunnel(Map* map, int y1, int y2, int x) {
    int y;
    for (y = (y1 < y2 ? y1 : y2); y < (y1 < y2 ? y2 + 1 : y1 + 1); ++y) {
        map->cells[x][y].type = FLOOR;
        map->cells[x][y].displayChar = '.';
    }
}

void connectRooms(Map* map, Position room1Center, Position room2Center) {
    if (rand() % 2) {
        createHorizontalTunnel(map, room1Center.x, room2Center.x, room1Center.y);
        createVerticalTunnel(map, room1Center.y, room2Center.y, room2Center.x);
    }
    else {
        createVerticalTunnel(map, room1Center.y, room2Center.y, room1Center.x);
        createHorizontalTunnel(map, room1Center.x, room2Center.x, room2Center.y);
    }
}

int getRandomInt(int min, int max) {
    return rand() % (max - min) + min;
}

void placeRooms(Map* map) {
    int roomCount = 0;
    int i;
    for (i = 0; i < MAX_ROOMS; ++i) {
        int roomWidth = getRandomInt(ROOM_MIN_SIZE, ROOM_MAX_SIZE);
        int roomHeight = getRandomInt(ROOM_MIN_SIZE, ROOM_MAX_SIZE);
        int x = getRandomInt(0, WIDTH - roomWidth - 1);
        int y = getRandomInt(0, HEIGHT - roomHeight - 1);

        createRoom(map, x, y, roomWidth, roomHeight);
        ++roomCount;

        if (roomCount == 1) {
            continue;
        }

        Position room1Center;
        room1Center.x = x + roomWidth / 2;
        room1Center.y = y + roomHeight / 2;

        Position room2Center;
        room2Center.x = map->cells[room1Center.x][room1Center.y-1].type != EMPTY ? getRandomInt(x + 1, x + roomWidth - 2) : room1Center.x;
        room2Center.y = map->cells[room1Center.x-1][room1Center.y].type != EMPTY ? getRandomInt(y + 1, y + roomHeight - 2) : room1Center.y;

        connectRooms(map, room1Center, room2Center);
    }
}

void printMap(Map* map) {
    int x, y;
    for (y = 0; y < HEIGHT; ++y) {
        for (x = 0; x < WIDTH; ++x) {
            putchar(map->cells[x][y].displayChar);
        }
        putchar('\n');
    }
}

int main() {
    srand(time(NULL));

    Map map;
    initMap(&map);
    placeRooms(&map);
    printMap(&map);

    return 0;
}