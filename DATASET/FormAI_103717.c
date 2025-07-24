//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: immersive
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20
#define MAX_ROOMS 8
#define MAX_ROOM_SIZE 10

typedef struct Point {
    int x;
    int y;
} Point;

typedef struct Rect {
    Point pos;
    int width;
    int height;
} Rect;

enum TileType {
    WALL,
    FLOOR
};

enum Direction {
    NORTH,
    SOUTH,
    EAST,
    WEST
};

typedef struct Map {
    int width;
    int height;
    enum TileType tiles[WIDTH * HEIGHT];
} Map;

Map generateMap();
void makeRoom(Map*, Rect);
void makeHCorridor(Map*, int, int, int);
void makeVCorridor(Map*, int, int, int);
void placePlayer(Map*, Point);

int main() {
    srand(time(NULL));
    Map map = generateMap();
    Point playerPosition = { map.width / 2, map.height / 2 };
    placePlayer(&map, playerPosition);

    while (1) {
        // game loop goes here
    }

    return 0;
}

Map generateMap() {
    Map map;
    map.width = WIDTH;
    map.height = HEIGHT;

    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        map.tiles[i] = WALL;
    }

    Rect rooms[MAX_ROOMS];
    int numRooms = 0;

    for (int i = 0; i < MAX_ROOMS; i++) {
        int roomWidth = rand() % (MAX_ROOM_SIZE - 3) + 3;
        int roomHeight = rand() % (MAX_ROOM_SIZE - 3) + 3;
        int x = rand() % (WIDTH - roomWidth - 1) + 1;
        int y = rand() % (HEIGHT - roomHeight - 1) + 1;

        Rect newRoom = { { x, y }, roomWidth, roomHeight };

        int failed = 0;
        for (int j = 0; j < numRooms; j++) {
            if (rectIntersects(newRoom, rooms[j])) {
                failed = 1;
                break;
            }
        }

        if (!failed) {
            makeRoom(&map, newRoom);
            Point newCenter = { x + roomWidth / 2, y + roomHeight / 2 };

            if (numRooms == 0) {
                placePlayer(&map, newCenter);
            } else {
                Point prevCenter = { rooms[numRooms - 1].pos.x + rooms[numRooms - 1].width / 2, rooms[numRooms - 1].pos.y + rooms[numRooms - 1].height / 2 };

                if (rand() % 2) {
                    makeHCorridor(&map, prevCenter.x, newCenter.x, prevCenter.y);
                    makeVCorridor(&map, prevCenter.y, newCenter.y, newCenter.x);
                } else {
                    makeVCorridor(&map, prevCenter.y, newCenter.y, prevCenter.x);
                    makeHCorridor(&map, prevCenter.x, newCenter.x, newCenter.y);
                }
            }

            rooms[numRooms] = newRoom;
            numRooms++;
        }
    }

    return map;
}

void makeRoom(Map* map, Rect room) {
    for (int x = room.pos.x; x < room.pos.x + room.width; x++) {
        for (int y = room.pos.y; y < room.pos.y + room.height; y++) {
            map->tiles[y * WIDTH + x] = FLOOR;
        }
    }
}

void makeHCorridor(Map* map, int x1, int x2, int y) {
    for (int x = x1; x <= x2; x++) {
        map->tiles[y * WIDTH + x] = FLOOR;
    }
}

void makeVCorridor(Map* map, int y1, int y2, int x) {
    for (int y = y1; y <= y2; y++) {
        map->tiles[y * WIDTH + x] = FLOOR;
    }
}

void placePlayer(Map* map, Point position) {
    map->tiles[position.y * WIDTH + position.x] = FLOOR;
    printf("Player position: (%d, %d)\n", position.x, position.y);
}

int rectIntersects(Rect r1, Rect r2) {
    return r1.pos.x <= r2.pos.x + r2.width && r1.pos.x + r1.width >= r2.pos.x && r1.pos.y <= r2.pos.y + r2.height && r1.pos.y + r1.height >= r2.pos.y;
}