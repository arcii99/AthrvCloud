//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10
#define MAX_ROOMS 5
#define MIN_ROOM_SIZE 3
#define MAX_ROOM_SIZE 6

typedef struct {
    int x, y, width, height;
} Room;

void print_map(char map[MAP_SIZE][MAP_SIZE]) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

void generate_map(char map[MAP_SIZE][MAP_SIZE]) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = '#';
        }
    }

    srand(time(NULL));
    int num_rooms = rand() % MAX_ROOMS + 1;
    Room rooms[num_rooms];

    for (int i = 0; i < num_rooms; i++) {
        int x = rand() % (MAP_SIZE - MAX_ROOM_SIZE - 1) + 1;
        int y = rand() % (MAP_SIZE - MAX_ROOM_SIZE - 1) + 1;
        int width = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
        int height = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;

        Room room = {x, y, width, height};
        rooms[i] = room;

        for (int j = y; j < y + height; j++) {
            for (int k = x; k < x + width; k++) {
                if (map[j][k] == '.') {
                    continue;
                }
                
                if ((k == x || k == x + width - 1) || (j == y || j == y + height - 1)) {
                    map[j][k] = '#';
                } else {
                    map[j][k] = '.';
                }
            }
        }
    }

    for (int i = 0; i < num_rooms - 1; i++) {
        int x1 = rooms[i].x + rooms[i].width / 2;
        int y1 = rooms[i].y + rooms[i].height / 2;

        int x2 = rooms[i + 1].x + rooms[i + 1].width / 2;
        int y2 = rooms[i + 1].y + rooms[i + 1].height / 2;

        while (x1 != x2) {
            if (x1 < x2) {
                x1++;
            } else {
                x1--;
            }

            if (map[y1][x1] == '#') {
                map[y1][x1] = '.';
            }
        }

        while (y1 != y2) {
            if (y1 < y2) {
                y1++;
            } else {
                y1--;
            }

            if (map[y1][x1] == '#') {
                map[y1][x1] = '.';
            }
        }
    }
}

int main() {
    char map[MAP_SIZE][MAP_SIZE];

    generate_map(map);
    print_map(map);

    return 0;
}