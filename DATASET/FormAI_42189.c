//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20
#define ROOM_MIN_SIZE 3
#define ROOM_MAX_SIZE 10
#define MAX_ROOMS 5

typedef struct {
    int x;
    int y;
    int width;
    int height;
} Room;

int map[MAP_SIZE][MAP_SIZE];
Room rooms[MAX_ROOMS];
int num_rooms = 0;

void init_map() {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = 0;
        }
    }
}

int random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void create_room(int index) {
    int x = random_int(1, MAP_SIZE - ROOM_MAX_SIZE - 1);
    int y = random_int(1, MAP_SIZE - ROOM_MAX_SIZE - 1);
    int width = random_int(ROOM_MIN_SIZE, ROOM_MAX_SIZE);
    int height = random_int(ROOM_MIN_SIZE, ROOM_MAX_SIZE);
    rooms[index] = (Room){x, y, width, height};
    for (int i = x; i < x + width; i++) {
        for (int j = y; j < y + height; j++) {
            map[i][j] = 1;
        }
    }
}

void connect_rooms() {
    for (int i = 0; i < num_rooms - 1; i++) {
        Room a = rooms[i];
        Room b = rooms[i + 1];
        int x1 = random_int(a.x, a.x + a.width - 1);
        int y1 = random_int(a.y, a.y + a.height - 1);
        int x2 = random_int(b.x, b.x + b.width - 1);
        int y2 = random_int(b.y, b.y + b.height - 1);
        int dx = (x1 < x2) ? 1 : -1;
        int dy = (y1 < y2) ? 1 : -1;
        for (int x = x1; x != x2 + dx; x += dx) {
            map[x][y1] = 1;
        }
        for (int y = y1; y != y2 + dy; y += dy) {
            map[x2][y] = 1;
        }
    }
}

void print_map() {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (map[i][j] == 0) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    init_map();
    num_rooms = random_int(2, MAX_ROOMS);
    for (int i = 0; i < num_rooms; i++) {
        create_room(i);
    }
    connect_rooms();
    print_map();
    return 0;
}