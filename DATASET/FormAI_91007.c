//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_ROWS 10
#define MAP_COLS 20
#define MAX_ROOMS 5

char map[MAP_ROWS][MAP_COLS];

typedef struct {
    int row, col, width, height;
} Room;

void init_map() {
    int i, j;
    for (i = 0; i < MAP_ROWS; i++) {
        for (j = 0; j < MAP_COLS; j++) {
            map[i][j] = '#';
        }
    }
}

Room generate_room() {
    Room room;
    room.row = rand() % (MAP_ROWS - 5) + 2;
    room.col = rand() % (MAP_COLS - 10) + 5;
    room.width = rand() % 6 + 4;
    room.height = rand() % 6 + 4;
    return room;
}

void draw_room(Room room) {
    int i, j;
    for (i = room.row; i < room.row + room.height; i++) {
        for (j = room.col; j < room.col + room.width; j++) {
            if (i == room.row || i == room.row + room.height - 1 ||
                j == room.col || j == room.col + room.width - 1) {
                map[i][j] = '+';
            } else {
                map[i][j] = '.';
            }
        }
    }
}

void connect_rooms(Room room1, Room room2) {
    int row, col;
    row = room1.row + room1.height / 2;
    col = room1.col + room1.width / 2;
    while (col != room2.col + room2.width / 2) {
        if (col < room2.col + room2.width / 2) {
            col++;
        } else {
            col--;
        }
        map[row][col] = '.';
    }
    while (row != room2.row + room2.height / 2) {
        if (row < room2.row + room2.height / 2) {
            row++;
        } else {
            row--;
        }
        map[row][col] = '.';
    }
}

void generate_map() {
    int i, num_rooms;
    Room rooms[MAX_ROOMS];
    srand(time(NULL));
    init_map();
    num_rooms = rand() % MAX_ROOMS + 1;
    for (i = 0; i < num_rooms; i++) {
        rooms[i] = generate_room();
        draw_room(rooms[i]);
    }
    for (i = 0; i < num_rooms - 1; i++) {
        connect_rooms(rooms[i], rooms[i+1]);
    }
}

int main() {
    int i, j;
    generate_map();
    for (i = 0; i < MAP_ROWS; i++) {
        for (j = 0; j < MAP_COLS; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    return 0;
}