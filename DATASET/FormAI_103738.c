//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20
#define NUM_ROOMS 8

typedef struct {
    int x, y, w, h;
} Room;

typedef struct {
    int x, y;
} Point;

int map[SIZE][SIZE];
Room rooms[NUM_ROOMS];
int num_rooms = 0;

void clear_map() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            map[i][j] = 1;
        }
    }
}

void print_map() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (map[i][j] == 0) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

void generate_rooms() {
    srand(time(NULL));

    for (int i = 0; i < NUM_ROOMS; i++) {
        Room room;

        room.w = rand() % 6 + 5;
        room.h = rand() % 6 + 5;
        room.x = rand() % (SIZE - room.w - 1) + 1;
        room.y = rand() % (SIZE - room.h - 1) + 1;

        rooms[i] = room;
    }
}

void draw_rooms() {
    for (int i = 0; i < NUM_ROOMS; i++) {
        Room room = rooms[i];

        for (int x = room.x; x < room.x + room.w; x++) {
            for (int y = room.y; y < room.y + room.h; y++) {
                map[x][y] = 0;
            }
        }
    }
}

void connect_rooms() {
    for (int i = 0; i < NUM_ROOMS - 1; i++) {
        Room room1 = rooms[i];
        Room room2 = rooms[i + 1];

        Point point1;
        point1.x = room1.x + (room1.w / 2);
        point1.y = room1.y + (room1.h / 2);

        Point point2;
        point2.x = room2.x + (room2.w / 2);
        point2.y = room2.y + (room2.h / 2);

        while (point1.x != point2.x) {
            if (point1.x < point2.x) {
                point1.x++;
            } else {
                point1.x--;
            }
            map[point1.x][point1.y] = 0;
        }

        while (point1.y != point2.y) {
            if (point1.y < point2.y) {
                point1.y++;
            } else {
                point1.y--;
            }
            map[point1.x][point1.y] = 0;
        }
    }
}

int main() {
    clear_map();

    generate_rooms();
    draw_rooms();
    connect_rooms();

    print_map();

    return 0;
}