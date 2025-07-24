//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define MAX_ROOMS 10

char dungeon[WIDTH][HEIGHT];

typedef struct {
    int x;
    int y;
    int w;
    int h;
} Room;

void init_dungeon() {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            dungeon[i][j] = '#';
        }
    }
}

void gen_room(Room *room) {
    room->w = rand() % 10 + 5;
    room->h = rand() % 5 + 3;
    room->x = rand() % (WIDTH - room->w - 2) + 1;
    room->y = rand() % (HEIGHT - room->h - 2) + 1;
}

int room_overlap(Room *room1, Room *room2) {
    int i, j;

    for (i = room1->x - 1; i <= room1->x + room1->w; i++) {
        for (j = room1->y - 1; j <= room1->y + room1->h; j++) {
            if (i >= room2->x && i <= room2->x + room2->w &&
                j >= room2->y && j <= room2->y + room2->h) {
                return 1;
            }
        }
    }

    return 0;
}

void add_room(Room *room) {
    int i, j;

    for (i = room->x; i < room->x + room->w; i++) {
        for (j = room->y; j < room->y + room->h; j++) {
            dungeon[i][j] = '.';
        }
    }
}

void add_corridor(Room *room1, Room *room2) {
    int i, j;

    i = room1->x + room1->w / 2;
    j = room1->y + room1->h / 2;

    while (i != room2->x + room2->w / 2) {
        if (dungeon[i][j] != '.') {
            dungeon[i][j] = '.';
        }
        i += (i < room2->x + room2->w / 2) ? 1 : -1;
    }

    while (j != room2->y + room2->h / 2) {
        if (dungeon[i][j] != '.') {
            dungeon[i][j] = '.';
        }
        j += (j < room2->y + room2->h / 2) ? 1 : -1;
    }
}

void gen_dungeon() {
    int i, j, k, done;
    Room rooms[MAX_ROOMS];

    for (k = 0; k < MAX_ROOMS; k++) {
        done = 0;
        while (!done) {
            gen_room(&rooms[k]);
            done = 1;
            for (i = 0; i < k; i++) {
                if (room_overlap(&rooms[k], &rooms[i])) {
                    done = 0;
                    break;
                }
            }
        }
        add_room(&rooms[k]);
    }

    for (i = 0; i < MAX_ROOMS - 1; i++) {
        add_corridor(&rooms[i], &rooms[i + 1]);
    }
}

void print_dungeon() {
    int i, j;

    for (j = 0; j < HEIGHT; j++) {
        for (i = 0; i < WIDTH; i++) {
            putchar(dungeon[i][j]);
        }
        putchar('\n');
    }
}

int main() {
    srand(time(NULL));

    init_dungeon();
    gen_dungeon();
    print_dungeon();

    return 0;
}