//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 10
#define MAX_ROOMS 6
#define ROOM_MIN_WIDTH 3
#define ROOM_MIN_HEIGHT 3
#define ROOM_MAX_WIDTH 6
#define ROOM_MAX_HEIGHT 6

void generateMap(char map[MAP_HEIGHT][MAP_WIDTH]);
void printMap(char map[MAP_HEIGHT][MAP_WIDTH]);

int main() {
    char map[MAP_HEIGHT][MAP_WIDTH];
    srand(time(NULL));
    generateMap(map);
    printMap(map);
    return 0;
}

void generateMap(char map[MAP_HEIGHT][MAP_WIDTH]) {
    int i, j, k, l;
    int roomCount = 0;
    int roomTries = 0;
    int x, y, width, height;
    int roomOverlap;
    int roomLeft, roomRight, roomTop, roomBottom;
    char roomSymbol = '.';
    char corridorSymbol = '#';
    char wallSymbol = '@';
    while (roomCount < MAX_ROOMS && roomTries < 100) {
        width = rand() % (ROOM_MAX_WIDTH - ROOM_MIN_WIDTH + 1) + ROOM_MIN_WIDTH;
        height = rand() % (ROOM_MAX_HEIGHT - ROOM_MIN_HEIGHT + 1) + ROOM_MIN_HEIGHT;
        x = rand() % (MAP_WIDTH - width - 2) + 1;
        y = rand() % (MAP_HEIGHT - height - 2) + 1;
        roomLeft = x - 1;
        roomRight = x + width;
        roomTop = y - 1;
        roomBottom = y + height;
        roomOverlap = 0;
        for (i = roomTop; i <= roomBottom; i++) {
            for (j = roomLeft; j <= roomRight; j++) {
                if (map[i][j] == roomSymbol) {
                    roomOverlap = 1;
                    break;
                }
            }
            if (roomOverlap) {
                break;
            }
        }
        if (!roomOverlap) {
            for (i = roomTop; i <= roomBottom; i++) {
                for (j = roomLeft; j <= roomRight; j++) {
                    if (i == roomTop || i == roomBottom || j == roomLeft || j == roomRight) {
                        map[i][j] = wallSymbol;
                    } else {
                        map[i][j] = roomSymbol;
                    }
                }
            }
            roomCount++;
        }
        roomTries++;
    }
    for (i = 1; i < MAP_HEIGHT - 1; i++) {
        for (j = 1; j < MAP_WIDTH - 1; j++) {
            if (map[i][j] == wallSymbol && (map[i-1][j] == roomSymbol || map[i+1][j] == roomSymbol || map[i][j-1] == roomSymbol || map[i][j+1] == roomSymbol)) {
                map[i][j] = corridorSymbol;
            }
        }
    }
}

void printMap(char map[MAP_HEIGHT][MAP_WIDTH]) {
    int i, j;
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}