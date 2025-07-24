//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20
#define MIN_ROOM_WIDTH 5
#define MIN_ROOM_HEIGHT 5
#define MAX_ROOM_WIDTH 15
#define MAX_ROOM_HEIGHT 10
#define MAX_ROOMS 10

int map[MAP_WIDTH][MAP_HEIGHT];

typedef struct {
    int x;
    int y;
    int width;
    int height;
} Room;

Room rooms[MAX_ROOMS];

void generate_map() {
    int i, j, k, x, y, w, h;

    // Initialize map with all walls
    for (i = 0; i < MAP_WIDTH; i++) {
        for (j = 0; j < MAP_HEIGHT; j++) {
            map[i][j] = '#';
        }
    }

    // Generate rooms
    for (i = 0; i < MAX_ROOMS; i++) {
        x = rand() % (MAP_WIDTH - MAX_ROOM_WIDTH - 1) + 1;
        y = rand() % (MAP_HEIGHT - MAX_ROOM_HEIGHT - 1) + 1;
        w = rand() % (MAX_ROOM_WIDTH - MIN_ROOM_WIDTH + 1) + MIN_ROOM_WIDTH;
        h = rand() % (MAX_ROOM_HEIGHT - MIN_ROOM_HEIGHT + 1) + MIN_ROOM_HEIGHT;

        // Make sure the room doesn't overlap with other rooms
        for (j = x - 1; j <= x + w; j++) {
            for (k = y - 1; k <= y + h; k++) {
                if (map[j][k] != '#') {
                    break;
                }
            }
            if (k != y + h + 1) {
                break;
            }
        }
        if (j == x + w + 1) {
            // Valid room location, add it to the map
            rooms[i].x = x;
            rooms[i].y = y;
            rooms[i].width = w;
            rooms[i].height = h;
            for (j = x; j < x + w; j++) {
                for (k = y; k < y + h; k++) {
                    if (j == x || j == x + w - 1 || k == y || k == y + h - 1) {
                        map[j][k] = '#'; // Add walls
                    } else {
                        map[j][k] = '.'; // Add floor
                    }
                }
            }
        }
    }

    // Connect the rooms with corridors
    for (i = 0; i < MAX_ROOMS - 1; i++) {
        x = rooms[i].x + rooms[i].width / 2;
        y = rooms[i].y + rooms[i].height / 2;
        w = rooms[i + 1].x + rooms[i + 1].width / 2;
        h = rooms[i + 1].y + rooms[i + 1].height / 2;
        while (x != w || y != h) {
            if (x < w) {
                x++;
            } else if (x > w) {
                x--;
            }
            if (y < h) {
                y++;
            } else if (y > h) {
                y--;
            }
            if (map[x][y] == '#') {
                map[x][y] = '.';
            }
        }
    }
}

void print_map() {
    int i, j;
    for (j = 0; j < MAP_HEIGHT; j++) {
        for (i = 0; i < MAP_WIDTH; i++) {
            putchar(map[i][j]);
        }
        putchar('\n');
    }
}

int main() {
    srand(time(NULL));
    generate_map();
    print_map();
    return 0;
}