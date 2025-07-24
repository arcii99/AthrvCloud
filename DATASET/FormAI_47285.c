//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 9
#define ROWS 30
#define COLS 80

typedef struct _room {
    int x, y;
    int width, height;
} room;

char map[ROWS][COLS];

int num_rooms = 0;
room rooms[MAX_ROOMS];

void generate_rooms() {
    int i;
    for (i = 0; i < MAX_ROOMS; i++) {
        int w = rand() % 10 + 5;
        int h = rand() % 5 + 3;
        int x = rand() % (COLS - w - 2) + 1;
        int y = rand() % (ROWS - h - 2) + 1;
        rooms[i].x = x;
        rooms[i].y = y;
        rooms[i].width = w;
        rooms[i].height = h;
        int r, c;
        for (r = y; r < y + h; r++) {
            for (c = x; c < x + w; c++) {
                map[r][c] = '.';
            }
        }
    }
    num_rooms = MAX_ROOMS;
}

void print_map() {
    int r, c;
    for (r = 0; r < ROWS; r++) {
        for (c = 0; c < COLS; c++) {
            printf("%c", map[r][c]);
        }
        printf("\n");
    }
}

int main() {
    int r, c;
    for (r = 0; r < ROWS; r++) {
        for (c = 0; c < COLS; c++) {
            map[r][c] = '#';
        }
    }
    srand(time(NULL));
    generate_rooms();
    print_map();
    return 0;
}