//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20
#define MAX_ROOMS 10
#define MIN_SIZE 4
#define MAX_SIZE 10

typedef struct room {
    int x, y;
    int width, height;
} Room;

char dungeon[HEIGHT][WIDTH];

void init() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            dungeon[i][j] = '#';
        }
    }
}

void create_room(Room r) {
    for (int i = r.y; i < r.y + r.height; i++) {
        for (int j = r.x; j < r.x + r.width; j++) {
            dungeon[i][j] = '.';
        }
    }
}

int check_overlap(Room r1, Room r2) {
    if (r1.x + r1.width <= r2.x || r1.x >= r2.x + r2.width) {
        return 0;
    }
    else if (r1.y + r1.height <= r2.y || r1.y >= r2.y + r2.height) {
        return 0;
    }
    else {
        return 1;
    }
}

void create_corridor(Room r1, Room r2) {
    int x1 = r1.x + (r1.width / 2);
    int y1 = r1.y + (r1.height / 2);
    int x2 = r2.x + (r2.width / 2);
    int y2 = r2.y + (r2.height / 2);
    while (x1 != x2) {
        if (x1 < x2) {
            x1++;
        }
        else {
            x1--;
        }
        dungeon[y1][x1] = '.';
    }
    while (y1 != y2) {
        if (y1 < y2) {
            y1++;
        }
        else {
            y1--;
        }
        dungeon[y1][x1] = '.';
    }
}

int main() {
    srand(time(NULL));
    init();
    Room rooms[MAX_ROOMS];
    int num_rooms = 0;

    while (num_rooms < MAX_ROOMS) {
        int w = rand() % (MAX_SIZE - MIN_SIZE + 1) + MIN_SIZE;
        int h = rand() % (MAX_SIZE - MIN_SIZE + 1) + MIN_SIZE;
        int x = rand() % (WIDTH - w - 1) + 1;
        int y = rand() % (HEIGHT - h - 1) + 1;
        Room r = { x, y, w, h };
        int overlap = 0;
        for (int i = 0; i < num_rooms; i++) {
            if (check_overlap(r, rooms[i])) {
                overlap = 1;
                break;
            }
        }
        if (!overlap) {
            create_room(r);
            rooms[num_rooms] = r;
            num_rooms++;
        }
    }

    for (int i = 0; i < num_rooms - 1; i++) {
        create_corridor(rooms[i], rooms[i+1]);
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", dungeon[i][j]);
        }
        printf("\n");
    }

    return 0;
}