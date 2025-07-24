//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 30
#define COLS 60
#define MAX_ROOMS 20

char dungeon[ROWS][COLS];
int roomCount = 0;
int roomWidth[MAX_ROOMS];
int roomHeight[MAX_ROOMS];
int roomX[MAX_ROOMS];
int roomY[MAX_ROOMS];

void createRoom(int roomIdx) {
    int w = rand() % 10 + 5;
    int h = rand() % 6 + 4;
    int x = rand() % (COLS - w - 2) + 1;
    int y = rand() % (ROWS - h - 2) + 1;

    int i, j;
    for (i = y; i < y + h; i++) {
        for (j = x; j < x + w; j++) {
            dungeon[i][j] = '.';
        }
    }

    roomWidth[roomIdx] = w;
    roomHeight[roomIdx] = h;
    roomX[roomIdx] = x;
    roomY[roomIdx] = y;
}

void createCorridor(int startX, int startY, int endX, int endY) {
    int j;
    for (j = startY; j <= endY; j++) {
        dungeon[startX][j] = '#';
    }
    for (j = startX; j <= endX; j++) {
        dungeon[j][endY] = '#';
    }
}

void connectRooms() {
    int i;
    for (i = 1; i < roomCount; i++) {
        int startX = roomX[i-1] + (roomWidth[i-1] / 2);
        int startY = roomY[i-1] + (roomHeight[i-1] / 2);
        int endX = roomX[i] + (roomWidth[i] / 2);
        int endY = roomY[i] + (roomHeight[i] / 2);

        createCorridor(startX, startY, endX, endY);
    }
}

void printDungeon() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (dungeon[i][j] == '\0') {
                printf("#");
            } else {
                printf("%c", dungeon[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int i, j;

    srand(time(NULL));

    // Fill the dungeon with walls
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            dungeon[i][j] = '\0';
        }
    }

    // Create rooms
    roomCount = rand() % MAX_ROOMS + 10;
    for (i = 0; i < roomCount; i++) {
        createRoom(i);
    }

    // Connect rooms with corridors
    connectRooms();

    // Print the dungeon
    printDungeon();

    return 0;
}