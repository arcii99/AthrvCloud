//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24
#define MAX_ROOMS 10

typedef struct Room {
    int x;
    int y;
    int width;
    int height;
} Room;

Room rooms[MAX_ROOMS];
char dungeon[HEIGHT][WIDTH];

int getRandom(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void drawHorizontal(int x1, int x2, int y) {
    int i;
    for(i = x1; i <= x2; i++) {
        dungeon[y][i] = '#';
    }
}

void drawVertical(int y1, int y2, int x) {
    int i;
    for(i = y1; i <= y2; i++) {
        dungeon[i][x] = '#';
    }
}

void drawRoom(Room room) {
    drawHorizontal(room.x, room.x + room.width, room.y);
    drawHorizontal(room.x, room.x + room.width, room.y + room.height);
    drawVertical(room.y + 1, room.y + room.height - 1, room.x);
    drawVertical(room.y + 1, room.y + room.height - 1, room.x + room.width);
}

void generateDungeon() {
    int i, j;

    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            dungeon[i][j] = ' ';
        }
    }

    for(i = 0; i < MAX_ROOMS; i++) {
        rooms[i].width = getRandom(3, 10);
        rooms[i].height = getRandom(3, 10);
        rooms[i].x = getRandom(1, WIDTH - rooms[i].width - 1);
        rooms[i].y = getRandom(1, HEIGHT - rooms[i].height - 1);
        drawRoom(rooms[i]);
    }
}

int main() {
    srand(time(NULL));
    generateDungeon();

    int i, j;
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            printf("%c", dungeon[i][j]);
        }
        printf("\n");
    }

    return 0;
}