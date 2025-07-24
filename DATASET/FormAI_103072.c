//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 60
#define MAX_ROOMS 8

char dungeon[ROWS][COLS];
int start_x, start_y;

struct Room {
    int x, y, w, h;
};

struct Room rooms[MAX_ROOMS];

void print_dungeon() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", dungeon[i][j]);
        }
        printf("\n");
    }
}

void generate_rooms() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        int room_w = rand() % 10 + 5;
        int room_h = rand() % 10 + 5;
        int room_x = rand() % (COLS - room_w - 1) + 1;
        int room_y = rand() % (ROWS - room_h - 1) + 1;

        rooms[i].x = room_x;
        rooms[i].y = room_y;
        rooms[i].w = room_w;
        rooms[i].h = room_h;

        for (int j = room_y; j < room_y + room_h; j++) {
            for (int k = room_x; k < room_x + room_w; k++) {
                dungeon[j][k] = '.';
            }
        }
    }
}

void connect_rooms() {
    for (int i = 0; i < MAX_ROOMS - 1; i++) {
        int x1 = rooms[i].x + rand() % rooms[i].w;
        int y1 = rooms[i].y + rand() % rooms[i].h;
        int x2 = rooms[i + 1].x + rand() % rooms[i + 1].w;
        int y2 = rooms[i + 1].y + rand() % rooms[i + 1].h;

        while (x1 != x2) {
            if (x1 < x2) x1++;
            else x1--;
            if (dungeon[y1][x1] != '.') dungeon[y1][x1] = '#';
        }
        while (y1 != y2) {
            if (y1 < y2) y1++;
            else y1--;
            if (dungeon[y1][x1] != '.') dungeon[y1][x1] = '#';
        }
    }
}

void generate_player() {
    int room = rand() % MAX_ROOMS;
    start_x = rooms[room].x + rand() % rooms[room].w;
    start_y = rooms[room].y + rand() % rooms[room].h;
    dungeon[start_y][start_x] = '@';
}

void generate_items() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        int x = rooms[i].x + rand() % rooms[i].w;
        int y = rooms[i].y + rand() % rooms[i].h;
        if (dungeon[y][x] == '.') {
            dungeon[y][x] = '*';
        }
    }
}

void generate_monsters() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        int x = rooms[i].x + rand() % rooms[i].w;
        int y = rooms[i].y + rand() % rooms[i].h;
        if (dungeon[y][x] == '.') {
            dungeon[y][x] = 'M';
        }
    }
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            dungeon[i][j] = '#';
        }
    }
    generate_rooms();
    connect_rooms();
    generate_player();
    generate_items();
    generate_monsters();
    print_dungeon();
    return 0;
}