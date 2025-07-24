//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 10
#define WIDTH 20
#define MAX_ROOMS 6
#define MAX_ROOM_SIZE 6
#define MIN_ROOM_SIZE 3

typedef struct {
    int x;
    int y;
    int w;
    int h;
} Room;

char dungeon[HEIGHT][WIDTH];
Room rooms[MAX_ROOMS];

int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void printDungeon() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", dungeon[y][x]);
        }
        printf("\n");
    }
}

void clearDungeon() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            dungeon[y][x] = ' ';
        }
    }
}

void carveHorizontal(int x1, int x2, int y) {
    for (int x = x1; x <= x2; x++) {
        dungeon[y][x] = '#';
    }
}

void carveVertical(int y1, int y2, int x) {
    for (int y = y1; y <= y2; y++) {
        dungeon[y][x] = '#';
    }
}

void generateRooms() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        int w = randInt(MIN_ROOM_SIZE, MAX_ROOM_SIZE);
        int h = randInt(MIN_ROOM_SIZE, MAX_ROOM_SIZE);
        int x = randInt(1, WIDTH - w - 1);
        int y = randInt(1, HEIGHT - h - 1);
        rooms[i] = (Room) {x, y, w, h};
        for (int ty = y; ty < y + h; ty++) {
            for (int tx = x; tx < x + w; tx++) {
                dungeon[ty][tx] = '.';
            }
        }
    }
}

void generateCorridors() {
    int prevX, prevY;
    for (int i = 0; i < MAX_ROOMS - 1; i++) {
        int x1 = rooms[i].x + randInt(0, rooms[i].w - 1);
        int y1 = rooms[i].y + randInt(0, rooms[i].h - 1);
        int x2 = rooms[i + 1].x + randInt(0, rooms[i + 1].w - 1);
        int y2 = rooms[i + 1].y + randInt(0, rooms[i + 1].h - 1);
        if (randInt(0, 1)) {
            carveHorizontal(x1, x2, y1);
            carveVertical(y1, y2, x2);
        } else {
            carveVertical(y1, y2, x1);
            carveHorizontal(x1, x2, y2);
        }
    }
}

int main() {
    srand(time(NULL));
    clearDungeon();
    generateRooms();
    generateCorridors();
    printDungeon();
    return 0;
}