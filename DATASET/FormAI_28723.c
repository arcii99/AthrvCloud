//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 30
#define COLS 80
#define MAX_ROOMS 15
#define ROOM_SIZE_MIN 4
#define ROOM_SIZE_MAX 10

typedef struct {
    int x, y;
    int width, height;
} room;

void map_init(int map[ROWS][COLS], int fill);
void carve_room(int map[ROWS][COLS], room r);
void carve_corridor(int map[ROWS][COLS], int x1, int y1, int x2, int y2);
void print_map(int map[ROWS][COLS]);

void map_init(int map[ROWS][COLS], int fill) {
    int x, y;

    for (y = 0; y < ROWS; y++) {
        for (x = 0; x < COLS; x++) {
            map[y][x] = fill;
        }
    }
}

void carve_room(int map[ROWS][COLS], room r) {
    int x, y;

    for (y = r.y; y < r.y + r.height; y++) {
        for (x = r.x; x < r.x + r.width; x++) {
            map[y][x] = 0;
        }
    }
}

void carve_corridor(int map[ROWS][COLS], int x1, int y1, int x2, int y2) {
    int x, y;

    while (x1 != x2 || y1 != y2) {
        if (x1 < x2) x1++;
        else if (x1 > x2) x1--;
        if (y1 < y2) y1++;
        else if (y1 > y2) y1--;
        map[y1][x1] = 0;
    }
}

void print_map(int map[ROWS][COLS]) {
    int x, y;

    for (y = 0; y < ROWS; y++) {
        for (x = 0; x < COLS; x++) {
            if (map[y][x])
                printf("#");
            else
                printf(".");
        }
        printf("\n");
    }
}

int main() {
    int map[ROWS][COLS];
    room rooms[MAX_ROOMS];
    int i, j, x, y, w, h;
    int x1, y1, x2, y2;
    int num_rooms = 0;
    int max_iters = 1000;
    int iter = 0;
    int overlap;

    srand(time(NULL));

    map_init(map, 1);

    /* Generate random rooms */
    while (num_rooms < MAX_ROOMS && iter < max_iters) {
        iter++;
        w = rand() % (ROOM_SIZE_MAX - ROOM_SIZE_MIN + 1) + ROOM_SIZE_MIN;
        h = rand() % (ROOM_SIZE_MAX - ROOM_SIZE_MIN + 1) + ROOM_SIZE_MIN;
        x = rand() % (COLS - w - 1) + 1;
        y = rand() % (ROWS - h - 1) + 1;

        /* Check for overlaps */
        overlap = 0;
        for (i = 0; i < num_rooms; i++) {
            if (x < rooms[i].x + rooms[i].width + 1 &&
                x + w + 1 > rooms[i].x &&
                y < rooms[i].y + rooms[i].height + 1 &&
                y + h + 1 > rooms[i].y) {
                overlap = 1;
                break;
            }
        }

        if (!overlap) {
            rooms[num_rooms].x = x;
            rooms[num_rooms].y = y;
            rooms[num_rooms].width = w;
            rooms[num_rooms].height = h;
            num_rooms++;
        }
    }

    /* Carve rooms */
    for (i = 0; i < num_rooms; i++) {
        carve_room(map, rooms[i]);
    }

    /* Carve corridors */
    for (i = 0; i < num_rooms - 1; i++) {
        x1 = rooms[i].x + rooms[i].width / 2;
        y1 = rooms[i].y + rooms[i].height / 2;
        x2 = rooms[i + 1].x + rooms[i + 1].width / 2;
        y2 = rooms[i + 1].y + rooms[i + 1].height / 2;
        carve_corridor(map, x1, y1, x2, y2);
    }

    /* Print map */
    print_map(map);

    return 0;
}