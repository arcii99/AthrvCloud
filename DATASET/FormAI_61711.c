//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10
#define MAX_ROOMS 5

typedef struct {
    int top;
    int left;
    int bottom;
    int right;
} Room;

typedef struct {
    int x;
    int y;
} Position;

char map[MAP_SIZE][MAP_SIZE];

void create_room(Room* room) {
    room->left = rand() % (MAP_SIZE - 5) + 1;
    room->top = rand() % (MAP_SIZE - 5) + 1;
    room->right = room->left + rand() % 4 + 4;
    room->bottom = room->top + rand() % 3 + 3;
}

int room_intersects(Room* room1, Room* room2) {
    return !(
        room1->left > room2->right ||
        room1->right < room2->left ||
        room1->top > room2->bottom ||
        room1->bottom < room2->top
    );
}

void connect_rooms(Position* pos1, Position* pos2) {
    while (pos1->x != pos2->x) {
        if (pos1->x < pos2->x) {
            pos1->x += 1;
        } else {
            pos1->x -= 1;
        }
        map[pos1->y][pos1->x] = '.';
    }
    while (pos1->y != pos2->y) {
        if (pos1->y < pos2->y) {
            pos1->y += 1;
        } else {
            pos1->y -= 1;
        }
        map[pos1->y][pos1->x] = '.';
    }
}

void create_map() {
    int num_rooms = 0;
    Room rooms[MAX_ROOMS];
    Position room_positions[MAX_ROOMS];

    // Create starting room
    create_room(&rooms[0]);
    for (int y = rooms[0].top; y <= rooms[0].bottom; y++) {
        for (int x = rooms[0].left; x <= rooms[0].right; x++) {
            map[y][x] = '.';
        }
    }
    room_positions[0].x = rand() % (rooms[0].right - rooms[0].left + 1) + rooms[0].left;
    room_positions[0].y = rand() % (rooms[0].bottom - rooms[0].top + 1) + rooms[0].top;
    num_rooms++;

    // Create additional rooms
    while (num_rooms < MAX_ROOMS) {
        int intersect = 0;
        Room room;
        create_room(&room);
        for (int i = 0; i < num_rooms; i++) {
            if (room_intersects(&room, &rooms[i])) {
                intersect = 1;
                break;
            }
        }
        if (!intersect) {
            rooms[num_rooms] = room;
            for (int y = room.top; y <= room.bottom; y++) {
                for (int x = room.left; x <= room.right; x++) {
                    map[y][x] = '.';
                }
            }
            room_positions[num_rooms].x = rand() % (room.right - room.left + 1) + room.left;
            room_positions[num_rooms].y = rand() % (room.bottom - room.top + 1) + room.top;
            connect_rooms(&room_positions[num_rooms - 1], &room_positions[num_rooms]);
            num_rooms++;
        }
    }

    // Add walls and player
    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0; x < MAP_SIZE; x++) {
            if (!map[y][x]) {
                if (y == 0 || y == MAP_SIZE - 1 || x == 0 || x == MAP_SIZE - 1) {
                    map[y][x] = '#';
                } else {
                    map[y][x] = ' ';
                }
            }
        }
    }
    map[room_positions[0].y][room_positions[0].x] = '@';
}

int main() {
    srand(time(NULL));
    create_map();
    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0; x < MAP_SIZE; x++) {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
    return 0;
}