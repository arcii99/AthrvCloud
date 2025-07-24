//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20
#define MAX_ROOMS 6

struct Room {
    int x;
    int y;
    int w;
    int h;
};

char map[HEIGHT][WIDTH];

void generate_map();
void place_room(struct Room room);
void connect_rooms(struct Room room1, struct Room room2);
int random_int(int min, int max);

int main() {
    srand(time(NULL));
    generate_map();

    // Print the map
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }

    return 0;
}

void generate_map() {
    // Initialize the map with # characters
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            map[y][x] = '#';
        }
    }

    // Generate rooms
    struct Room rooms[MAX_ROOMS];
    int num_rooms = 0;
    while (num_rooms < MAX_ROOMS) {
        struct Room room = { random_int(1, WIDTH-11), random_int(1, HEIGHT-11), random_int(5, 10), random_int(5, 10) };
        int overlap = 0;
        for (int i = 0; i < num_rooms; i++) {
            struct Room r = rooms[i];
            if (room.x < r.x + r.w && room.x + room.w > r.x && room.y < r.y + r.h && room.y + room.h > r.y) {
                overlap = 1;
                break;
            }
        }
        if (!overlap) {
            place_room(room);
            rooms[num_rooms] = room;
            num_rooms++;
        }
    }

    // Connect rooms
    for (int i = 0; i < num_rooms - 1; i++) {
        connect_rooms(rooms[i], rooms[i+1]);
    }
}

void place_room(struct Room room) {
    for (int y = room.y; y < room.y + room.h; y++) {
        for (int x = room.x; x < room.x + room.w; x++) {
            map[y][x] = '.';
        }
    }
}

void connect_rooms(struct Room room1, struct Room room2) {
    int x1 = room1.x + random_int(0, room1.w-1);
    int y1 = room1.y + random_int(0, room1.h-1);
    int x2 = room2.x + random_int(0, room2.w-1);
    int y2 = room2.y + random_int(0, room2.h-1);

    int dx = x2 - x1;
    int dy = y2 - y1;
    int x = x1;
    int y = y1;

    while (x != x2) {
        map[y][x] = '.';
        if (dx > 0) {
            x++;
        } else {
            x--;
        }
    }
    while (y != y2) {
        map[y][x] = '.';
        if (dy > 0) {
            y++;
        } else {
            y--;
        }
    }
}

int random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}