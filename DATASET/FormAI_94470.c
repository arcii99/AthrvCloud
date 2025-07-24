//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: standalone
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_ROOMS 10
#define MAP_SIZE 30
#define WALL '#'
#define FLOOR ' '
#define PLAYER '@'

typedef struct {
    int x, y;
} position;

bool isWithinMap(int x, int y) {
    return x >= 0 && x < MAP_SIZE && y >= 0 && y < MAP_SIZE;
}

void generateRoom(char map[][MAP_SIZE], position* roomPos, position* roomSize) {
    roomPos->x = rand() % MAP_SIZE;
    roomPos->y = rand() % MAP_SIZE;
    roomSize->x = 4 + rand() % 7;
    roomSize->y = 4 + rand() % 7;

    for (int x = roomPos->x; x < roomPos->x + roomSize->x; x++) {
        for (int y = roomPos->y; y < roomPos->y + roomSize->y; y++) {
            if (!isWithinMap(x, y))
                continue;

            map[x][y] = FLOOR;
        }
    }
}

void generateCorridor(char map[][MAP_SIZE], position start, position end) {
    while (start.x != end.x || start.y != end.y) {
        if (start.x != end.x) {
            int step = (start.x < end.x) ? 1 : -1;
            start.x += step;
        }
        else if (start.y != end.y) {
            int step = (start.y < end.y) ? 1 : -1;
            start.y += step;
        }

        if (isWithinMap(start.x, start.y))
            map[start.x][start.y] = FLOOR;
    }
}

int findClosestRoom(position* rooms, int numRooms, position target) {
    int closest = -1;
    int closestDist = 100000;

    for (int i = 0; i < numRooms; i++) {
        int dx = rooms[i].x - target.x;
        int dy = rooms[i].y - target.y;
        int distSq = dx * dx + dy * dy;

        if (distSq < closestDist) {
            closestDist = distSq;
            closest = i;
        }
    }

    return closest;
}

void moveToRoom(char map[][MAP_SIZE], position* pos, position target) {
    while (pos->x != target.x || pos->y != target.y) {
        if (pos->x != target.x) {
            int step = (pos->x < target.x) ? 1 : -1;
            pos->x += step;
        }
        else if (pos->y != target.y) {
            int step = (pos->y < target.y) ? 1 : -1;
            pos->y += step;
        }

        if (map[pos->x][pos->y] == WALL) {
            pos->x -= (pos->x < target.x) ? 1 : -1;
            pos->y -= (pos->y < target.y) ? 1 : -1;
        }
    }
}

void placePlayer(char map[][MAP_SIZE], position* pos) {
    int roomIndex = rand() % MAX_ROOMS;
    moveToRoom(map, pos, (position) {map[roomIndex][roomIndex], map[roomIndex][roomIndex + 1]});
    map[pos->x][pos->y] = PLAYER;
}

void generateMap(char map[][MAP_SIZE]) {
    for (int x = 0; x < MAP_SIZE; x++) {
        for (int y = 0; y < MAP_SIZE; y++) {
            map[x][y] = WALL;
        }
    }

    position rooms[MAX_ROOMS];
    position sizes[MAX_ROOMS];

    for (int i = 0; i < MAX_ROOMS; i++) {
        generateRoom(map, &rooms[i], &sizes[i]);
    }

    for (int i = 0; i < MAX_ROOMS; i++) {
        position closestPos = rooms[findClosestRoom(rooms, MAX_ROOMS, rooms[i])];
        position midPoint = {rooms[i].x + sizes[i].x / 2, rooms[i].y + sizes[i].y / 2};
        generateCorridor(map, midPoint, (position) {closestPos.x + sizes[i].x / 2, closestPos.y + sizes[i].y / 2});
    }

    position playerPos;
    placePlayer(map, &playerPos);
}

void printMap(char map[][MAP_SIZE]) {
    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0; x < MAP_SIZE; x++) {
            printf("%c", map[x][y]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    char map[MAP_SIZE][MAP_SIZE];
    generateMap(map);
    printMap(map);

    return 0;
}