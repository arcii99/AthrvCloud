//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20
#define MAX_ROOMS 10

typedef struct {
    int x;
    int y;
} Point;

int map[MAP_HEIGHT][MAP_WIDTH];

void fillMap(int val) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map[y][x] = val;
        }
    }
}

void printMap() {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            switch (map[y][x]) {
                case 0:
                    printf("#");
                    break;
                case 1:
                    printf(".");
                    break;
                case 2:
                    printf("!");
                    break;
                default:
                    printf("?");
                    break;
            }
        }
        printf("\n");
    }
}

int randomRange(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int collidesWithRoom(Point point, Point size, Point* rooms, int numRooms) {
    for (int i = 0; i < numRooms; i++) {
        Point otherRoom = rooms[i];
        if ((point.x < otherRoom.x + size.x && point.x + size.x > otherRoom.x) &&
            (point.y < otherRoom.y + size.y && point.y + size.y > otherRoom.y)) {
            return 1;
        }
    }
    return 0;
}

void generateRooms(Point* rooms, int numRooms) {
    for (int i = 0; i < numRooms; i++) {
        Point size = { randomRange(3, 6), randomRange(3, 6) };
        Point point = { randomRange(1, MAP_WIDTH - size.x - 1), randomRange(1, MAP_HEIGHT - size.y - 1) };
        while (collidesWithRoom(point, size, rooms, i)) {
            size = (Point) { randomRange(3, 6), randomRange(3, 6) };
            point = (Point) { randomRange(1, MAP_WIDTH - size.x - 1), randomRange(1, MAP_HEIGHT - size.y - 1) };
        }
        rooms[i] = point;
        for (int y = point.y; y < point.y + size.y; y++) {
            for (int x = point.x; x < point.x + size.x; x++) {
                map[y][x] = 1;
            }
        }
    }
}

void generateCorridors(Point* rooms, int numRooms) {
    for (int i = 0; i < numRooms - 1; i++) {
        Point a = rooms[i];
        Point b = rooms[i + 1];
        Point midpoint = {
            randomRange(a.x, a.x + (b.x - a.x)),
            randomRange(a.y, a.y + (b.y - a.y))
        };
        while (midpoint.x != a.x && midpoint.y != a.y) {
            int direction = randomRange(0, 1);
            if (direction) {
                if (midpoint.x < a.x) {
                    midpoint.x++;
                } else {
                    midpoint.x--;
                }
            } else {
                if (midpoint.y < a.y) {
                    midpoint.y++;
                } else {
                    midpoint.y--;
                }
            }
            map[midpoint.y][midpoint.x] = 2;
        }
        while (midpoint.x != b.x && midpoint.y != b.y) {
            int direction = randomRange(0, 1);
            if (direction) {
                if (midpoint.x < b.x) {
                    midpoint.x++;
                } else {
                    midpoint.x--;
                }
            } else {
                if (midpoint.y < b.y) {
                    midpoint.y++;
                } else {
                    midpoint.y--;
                }
            }
            map[midpoint.y][midpoint.x] = 2;
        }
    }
}

int main() {
    srand(time(NULL));
    
    fillMap(0);

    Point rooms[MAX_ROOMS];
    int numRooms = randomRange(3, MAX_ROOMS);
    generateRooms(rooms, numRooms);
    generateCorridors(rooms, numRooms);

    printMap();

    return 0;
}