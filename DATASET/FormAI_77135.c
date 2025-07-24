//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20
#define NUM_ROOMS 6
#define MAX_ROOM_SIZE 6
#define MIN_ROOM_SIZE 3

typedef struct {
    int x;
    int y;
    int width;
    int height;
} Room;

char map[MAP_SIZE][MAP_SIZE];

void initializeMap() {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = '#';
        }
    }
}

void printMap() {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

void createRoom(int x, int y, int width, int height) {
    for (int i = y; i < y + height; i++) {
        for (int j = x; j < x + width; j++) {
            map[i][j] = '.';
        }
    }
}

int roomOverlap(Room r1, Room r2) {
    if ((r1.x + r1.width < r2.x) || (r2.x + r2.width < r1.x) ||
        (r1.y + r1.height < r2.y) || (r2.y + r2.height < r1.y)) {
        return 0;
    }
    return 1;
}

int main() {
    srand(time(NULL));
    initializeMap();

    Room rooms[NUM_ROOMS];

    // Generate rooms
    for (int i = 0; i < NUM_ROOMS; i++) {
        int roomWidth = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
        int roomHeight = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
        int roomX = rand() % (MAP_SIZE - roomWidth - 1) + 1;
        int roomY = rand() % (MAP_SIZE - roomHeight - 1) + 1;

        Room newRoom = {roomX, roomY, roomWidth, roomHeight};

        // Check for overlap with existing rooms
        int overlap = 0;
        for (int j = 0; j < i; j++) {
            if (roomOverlap(newRoom, rooms[j])) {
                overlap = 1;
                break;
            }
        }
        if (!overlap) {
            createRoom(roomX, roomY, roomWidth, roomHeight);
            rooms[i] = newRoom;
        }
    }

    printMap();
    return 0;
}