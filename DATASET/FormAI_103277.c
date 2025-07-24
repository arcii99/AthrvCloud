//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20
#define MAX_ROOMS 6

typedef struct Room {
    int x, y;
    int width, height;
} Room;

char map[MAP_SIZE][MAP_SIZE];

void initMap() {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = ' ';
        }
    }
}

void drawMap() {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void createRoom(Room *room) {
    room->width = generateRandomNumber(3, 6);
    room->height = generateRandomNumber(3, 6);
    room->x = generateRandomNumber(1, MAP_SIZE - room->width - 1);
    room->y = generateRandomNumber(1, MAP_SIZE - room->height - 1);
}

void connectRooms(Room r1, Room r2) {
    int x1 = r1.x + generateRandomNumber(0, r1.width - 1);
    int y1 = r1.y + generateRandomNumber(0, r1.height - 1);
    int x2 = r2.x + generateRandomNumber(0, r2.width - 1);
    int y2 = r2.y + generateRandomNumber(0, r2.height - 1);

    // connect horizontal and vertical
    while (x1 != x2) {
        if (x1 < x2) {
            x1++;
        } else {
            x1--;
        }
        map[y1][x1] = '#';
    }
    while (y1 != y2) {
        if (y1 < y2) {
            y1++;
        } else {
            y1--;
        }
        map[y1][x1] = '#';
    }
}

int main() {
    srand(time(NULL));
    initMap();

    // create rooms
    Room rooms[MAX_ROOMS];
    for (int i = 0; i < MAX_ROOMS; i++) {
        createRoom(&rooms[i]);
        for (int y = rooms[i].y; y < rooms[i].y + rooms[i].height; y++) {
            for (int x = rooms[i].x; x < rooms[i].x + rooms[i].width; x++) {
                map[y][x] = '.';
            }
        }
    }

    // connect rooms
    for (int i = 0; i < MAX_ROOMS - 1; i++) {
        connectRooms(rooms[i], rooms[i+1]);
    }

    // print the map
    drawMap();
    return 0;
}