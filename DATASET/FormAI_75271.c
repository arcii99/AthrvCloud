//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 10
#define MAX_ROOMS 6
#define MIN_ROOM_SIZE 4
#define MAX_ROOM_SIZE 8

char map[MAP_HEIGHT][MAP_WIDTH];

typedef struct {
    int x, y;
    int width, height;
} Room;

Room rooms[MAX_ROOMS];

void fill_map() {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = '#';
        }
    }
}

void print_map() {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

Room create_room() {
    Room room;
    room.width = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
    room.height = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
    room.x = rand() % (MAP_WIDTH - room.width);
    room.y = rand() % (MAP_HEIGHT - room.height);
    return room;
}

int is_overlap(Room a, Room b) {
    int left1 = a.x;
    int right1 = a.x + a.width - 1;
    int top1 = a.y;
    int bottom1 = a.y + a.height - 1;

    int left2 = b.x;
    int right2 = b.x + b.width - 1;
    int top2 = b.y;
    int bottom2 = b.y + b.height - 1;

    if (left1 <= right2 && right1 >= left2 && top1 <= bottom2 && bottom1 >= top2) {
        return 1;
    }
    return 0;
}

void create_rooms() {
    int room_count = 0;
    while (room_count < MAX_ROOMS) {
        Room new_room = create_room();
        int overlap = 0;
        for (int i = 0; i < room_count; i++) {
            if (is_overlap(new_room, rooms[i])) {
                overlap = 1;
                break;
            }
        }
        if (!overlap) {
            rooms[room_count] = new_room;
            room_count++;
        }
    }
}

void connect_rooms() {
    for (int i = 0; i < MAX_ROOMS - 1; i++) {
        int x1 = rooms[i].x + rooms[i].width / 2;
        int y1 = rooms[i].y + rooms[i].height / 2;
        int x2 = rooms[i+1].x + rooms[i+1].width / 2;
        int y2 = rooms[i+1].y + rooms[i+1].height / 2;
        while (x1 != x2) {
            if (x1 < x2) {
                x1++;
            } else {
                x1--;
            }
            map[y1][x1] = '.';
        }
        while (y1 != y2) {
            if (y1 < y2) {
                y1++;
            } else {
                y1--;
            }
            map[y1][x1] = '.';
        }
    }
}

void generate_map() {
    fill_map();
    create_rooms();
    connect_rooms();
}

int main() {
    srand(time(NULL));
    generate_map();
    print_map();
    return 0;
}