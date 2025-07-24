//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE_X 30
#define MAP_SIZE_Y 20
#define MAX_ROOMS 10

int map[MAP_SIZE_X][MAP_SIZE_Y];

struct Room {
    int x, y, w, h;
};

struct Room rooms[MAX_ROOMS];

void carve_room(int x, int y, int w, int h) {
    for (int i = x; i < x + w; i++) {
        for (int j = y; j < y + h; j++) {
            map[i][j] = 1;
        }
    }
}

void connect_rooms(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int x = x1;
    int y = y1;

    if (dx < 0) {
        while (x != x2) {
            map[x][y] = 1;
            x--;
        }
    } else {
        while (x != x2) {
            map[x][y] = 1;
            x++;
        }
    }

    if (dy < 0) {
        while (y != y2) {
            map[x][y] = 1;
            y--;
        }
    } else {
        while (y != y2) {
            map[x][y] = 1;
            y++;
        }
    }
}

void generate_map() {
    /* Initialize map with walls */
    for (int i = 0; i < MAP_SIZE_X; i++) {
        for (int j = 0; j < MAP_SIZE_Y; j++) {
            map[i][j] = 0;
        }
    }

    /* Generate rooms */
    srand(time(NULL));
    int num_rooms = rand() % MAX_ROOMS + 1;
    for (int i = 0; i < num_rooms; i++) {
        int x = rand() % (MAP_SIZE_X - 10) + 5;
        int y = rand() % (MAP_SIZE_Y - 10) + 5;
        int w = rand() % 8 + 4;
        int h = rand() % 8 + 4;
        carve_room(x, y, w, h);
        rooms[i] = (struct Room) { x, y, w, h };
    }

    /* Connect rooms */
    for (int i = 0; i < num_rooms - 1; i++) {
        int x1 = rooms[i].x + rooms[i].w / 2;
        int y1 = rooms[i].y + rooms[i].h / 2;
        int x2 = rooms[i + 1].x + rooms[i + 1].w / 2;
        int y2 = rooms[i + 1].y + rooms[i + 1].h / 2;
        connect_rooms(x1, y1, x2, y2);
    }
}

int main() {
    generate_map();

    /* Print map */
    for (int j = 0; j < MAP_SIZE_Y; j++) {
        for (int i = 0; i < MAP_SIZE_X; i++) {
            if (map[i][j] == 1) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }

    return 0;
}