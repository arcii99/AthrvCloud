//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: futuristic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 10
#define NUM_ROOMS 5

typedef struct {
    int x;
    int y;
} point;

point player_pos;
char map[MAP_HEIGHT][MAP_WIDTH];

void init_map() {
    int i, j;
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = '#';
        }
    }
}

void print_map() {
    int i, j;
    printf(" ");
    for (i = 0; i < MAP_WIDTH; i++) {
        printf("%d", i % 10);
    }
    printf("\n");
    for (i = 0; i < MAP_HEIGHT; i++) {
        printf("%d", i % 10);
        for (j = 0; j < MAP_WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void create_room(int x, int y, int w, int h) {
    int i, j;
    for (i = y; i < y + h; i++) {
        for (j = x; j < x + w; j++) {
            map[i][j] = '.';
        }
    }
}

void connect_rooms(point a, point b) {
    int i;
    if (a.x < b.x) {
        for (i = a.x; i <= b.x; i++) {
            map[a.y][i] = '.';
        }
    }
    else {
        for (i = b.x; i <= a.x; i++) {
            map[a.y][i] = '.';
        }
    }
    if (a.y < b.y) {
        for (i = a.y; i <= b.y; i++) {
            map[i][a.x] = '.';
        }
    }
    else {
        for (i = b.y; i <= a.y; i++) {
            map[i][a.x] = '.';
        }
    }
}

void generate_map() {
    int i;
    point rooms[NUM_ROOMS];

    for (i = 0; i < NUM_ROOMS; i++) {
        rooms[i].x = rand() % (MAP_WIDTH - 5);
        rooms[i].y = rand() % (MAP_HEIGHT - 5);
        create_room(rooms[i].x, rooms[i].y, 5 + rand() % 5, 5 + rand() % 5);
    }

    for (i = 0; i < NUM_ROOMS - 1; i++) {
        connect_rooms(rooms[i], rooms[i+1]);
    }

    player_pos = rooms[0];
    map[player_pos.y][player_pos.x] = '@';
}

int main() {
    srand(time(NULL));
    init_map();
    generate_map();
    print_map();

    return 0;
}