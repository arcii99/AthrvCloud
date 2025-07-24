//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_X 50
#define MAX_Y 20
#define MAX_ROOMS 10

char dungeon[MAX_Y][MAX_X];

typedef struct Room {
    int x;
    int y;
    int width;
    int height;
} Room;

bool intersect(Room *room1, Room *room2) {
    if (room1->x + room1->width + 1 < room2->x ||
        room2->x + room2->width + 1 < room1->x ||
        room1->y + room1->height + 1 < room2->y ||
        room2->y + room2->height + 1 < room1->y) {
        return false;
    }

    return true;
}

void draw_room(Room *room) {
    for (int y = room->y; y < room->y + room->height; y++) {
        for (int x = room->x; x < room->x + room->width; x++) {
            dungeon[y][x] = '.';
        }
    }
}

void connect(Room *room1, Room *room2) {
    int x1 = room1->x + room1->width / 2;
    int y1 = room1->y + room1->height / 2;
    int x2 = room2->x + room2->width / 2;
    int y2 = room2->y + room2->height / 2;

    while (x1 != x2) {
        if (x1 < x2) {
            x1++;
        } else {
            x1--;
        }

        dungeon[y1][x1] = '#';
    }

    while (y1 != y2) {
        if (y1 < y2) {
            y1++;
        } else {
            y1--;
        }

        dungeon[y1][x1] = '#';
    }
}

void generate_room(Room *room) {
    room->width = rand() % 7 + 4;
    room->height = rand() % 4 + 3;

    room->x = rand() % (MAX_X - room->width - 1) + 1;
    room->y = rand() % (MAX_Y - room->height - 1) + 1;
}

int main() {
    srand(time(NULL));

    for (int y = 0; y < MAX_Y; y++) {
        for (int x = 0; x < MAX_X; x++) {
            dungeon[y][x] = '#';
        }
    }

    Room rooms[MAX_ROOMS];
    int num_rooms = 0;

    while (num_rooms < MAX_ROOMS) {
        Room room;
        generate_room(&room);

        bool ok = true;
        for (int i = 0; i < num_rooms; i++) {
            if (intersect(&room, &rooms[i])) {
                ok = false;
                break;
            }
        }

        if (ok) {
            rooms[num_rooms++] = room;
        }
    }

    for (int i = 0; i < num_rooms; i++) {
        draw_room(&rooms[i]);
    }

    for (int i = 0; i < num_rooms - 1; i++) {
        connect(&rooms[i], &rooms[i + 1]);
    }

    for (int y = 0; y < MAX_Y; y++) {
        for (int x = 0; x < MAX_X; x++) {
            putchar(dungeon[y][x]);
        }
        putchar('\n');
    }

    return 0;
}