//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20
#define MAX_ROOMS 8

typedef struct {
    int x;
    int y;
    int width;
    int height;
} Room;

void print_map(char map[MAP_SIZE][MAP_SIZE]) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

void generate_rooms(Room rooms[MAX_ROOMS]) {
    srand(time(NULL));
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].width = rand() % 6 + 4;
        rooms[i].height = rand() % 6 + 4;
        rooms[i].x = rand() % (MAP_SIZE - rooms[i].width);
        rooms[i].y = rand() % (MAP_SIZE - rooms[i].height);
    }
}

void create_map(char map[MAP_SIZE][MAP_SIZE], Room rooms[MAX_ROOMS]) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = '#';
        }
    }
    for (int i = 0; i < MAX_ROOMS; i++) {
        for (int x = rooms[i].x; x < rooms[i].x + rooms[i].width; x++) {
            for (int y = rooms[i].y; y < rooms[i].y + rooms[i].height; y++) {
                if (x == rooms[i].x || x == rooms[i].x + rooms[i].width - 1 || y == rooms[i].y || y == rooms[i].y + rooms[i].height - 1) {
                    map[x][y] = '.';
                } else {
                    map[x][y] = '.';
                }
            }
        }
    }
}

int main() {
    char map[MAP_SIZE][MAP_SIZE];
    Room rooms[MAX_ROOMS];

    generate_rooms(rooms);
    create_map(map, rooms);
    print_map(map);

    return 0;
}