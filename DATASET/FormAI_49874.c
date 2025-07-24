//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DUNGEON_SIZE 50
#define ROOM_MIN_SIZE 4
#define ROOM_MAX_SIZE 12
#define MAX_ROOMS 10

struct Room {
    int x, y;
    int width, height;
    int visited;
};

int dungeon[DUNGEON_SIZE][DUNGEON_SIZE];

struct Room rooms[MAX_ROOMS];
int numRooms = 0;

void initDungeon() {
    for (int i = 0; i < DUNGEON_SIZE; i++) {
        for (int j = 0; j < DUNGEON_SIZE; j++) {
            dungeon[i][j] = 1;
        }
    }
}

void generateRooms() {
    srand(time(NULL));
    for (int i = 0; i < MAX_ROOMS; i++) {
        int roomWidth = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE) + ROOM_MIN_SIZE;
        int roomHeight = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE) + ROOM_MIN_SIZE;
        int x = rand() % (DUNGEON_SIZE - roomWidth);
        int y = rand() % (DUNGEON_SIZE - roomHeight);
        
        struct Room room = { x, y, roomWidth, roomHeight, 0 };
        rooms[i] = room;
        numRooms++;
    }
}

void connectRooms() {
    for (int i = 0; i < numRooms - 1; i++) {
        int startX = rooms[i].x + rooms[i].width / 2;
        int startY = rooms[i].y + rooms[i].height / 2;
        int endX = rooms[i + 1].x + rooms[i + 1].width / 2;
        int endY = rooms[i + 1].y + rooms[i + 1].height / 2;
        
        while (startX != endX) {
            dungeon[startX][startY] = 0;
            startX += startX < endX ? 1 : -1;
        }
        
        while (startY != endY) {
            dungeon[startX][startY] = 0;
            startY += startY < endY ? 1 : -1;
        }
    }
}

void printDungeon() {
    for (int i = 0; i < DUNGEON_SIZE; i++) {
        for (int j = 0; j < DUNGEON_SIZE; j++) {
            putchar(dungeon[i][j] ? '#' : '.');
        }
        putchar('\n');
    }
}

int main() {
    initDungeon();
    generateRooms();
    connectRooms();
    printDungeon();
    return 0;
}