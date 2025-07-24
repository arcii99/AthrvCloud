//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20

#define MAX_ROOMS 10
#define MIN_ROOM_SIZE 4
#define MAX_ROOM_SIZE 8

typedef struct {
    int x, y, w, h;
} room_t;

char map[MAP_HEIGHT][MAP_WIDTH];

/* Random number generator for generating procedural maps */
int random_int(int min, int max) {
    static int seed = 0;
    if (seed == 0) {
        seed = time(0);
        srand(seed);
    }
    return rand() % (max - min + 1) + min;
}

/* Function to create a rectangular room in the map */
void create_room(room_t room) {
    int x, y;
    for (y = room.y; y < room.y + room.h; y++) {
        for (x = room.x; x < room.x + room.w; x++) {
            map[y][x] = '.';
        }
    }
}

/* Function to create a corridor between two rooms */
void create_corridor(int x1, int y1, int x2, int y2) {
    int x, y, dx, dy, sx, sy, err, e2;

    dx = x2 - x1;
    dy = y2 - y1;

    sx = dx > 0 ? 1 : -1;
    sy = dy > 0 ? 1 : -1;

    dx = abs(dx);
    dy = abs(dy);

    err = dx > dy ? dx : -dy;

    while (x1 != x2 || y1 != y2) {
        map[y1][x1] = '.';
        e2 = err * 2;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

/* Function to create a procedural map with random rooms and corridors */
void create_map() {
    int i, j, r;
    room_t rooms[MAX_ROOMS];
    int num_rooms = 0;

    /* Fill the map with walls */
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = '#';
        }
    }

    /* Create random rooms */
    for (i = 0; i < MAX_ROOMS; i++) {
        room_t room;
        room.w = random_int(MIN_ROOM_SIZE, MAX_ROOM_SIZE);
        room.h = random_int(MIN_ROOM_SIZE, MAX_ROOM_SIZE);
        room.x = random_int(1, MAP_WIDTH - room.w - 1);
        room.y = random_int(1, MAP_HEIGHT - room.h - 1);

        /* Check if the room intersects with any previous room */
        int intersects = 0;
        for (j = 0; j < num_rooms; j++) {
            if (room.x < rooms[j].x + rooms[j].w && room.x + room.w > rooms[j].x &&
                room.y < rooms[j].y + rooms[j].h && room.y + room.h > rooms[j].y) {
                intersects = 1;
                break;
            }
        }

        /* Add the room to the map if it doesn't intersect with any previous room */
        if (!intersects) {
            create_room(room);
            rooms[num_rooms++] = room;
        }
    }

    /* Create corridors between adjacent rooms */
    for (i = 0; i < num_rooms - 1; i++) {
        create_corridor(
            rooms[i].x + rooms[i].w / 2,
            rooms[i].y + rooms[i].h / 2,
            rooms[i + 1].x + rooms[i + 1].w / 2,
            rooms[i + 1].y + rooms[i + 1].h / 2);
    }
}

int main() {
    int i, j;

    create_map();

    /* Print the map */
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}