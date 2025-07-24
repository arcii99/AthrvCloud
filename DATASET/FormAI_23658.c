//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_ROWS 10
#define MAP_COLS 20
#define MAX_ROOMS 6

typedef struct {
    int x, y, width, height;
} Room;

void generate_map(char map[MAP_ROWS][MAP_COLS], Room rooms[MAX_ROOMS]) {
    // Fill map with walls
    for (int i = 0; i < MAP_ROWS; i++) {
        for (int j = 0; j < MAP_COLS; j++) {
            map[i][j] = '#';
        }
    }

    // Generate rooms
    srand(time(NULL));
    for (int i = 0; i < MAX_ROOMS; i++) {
        int room_width = rand() % 8 + 4;
        int room_height = rand() % 6 + 4;
        int x = rand() % (MAP_COLS - room_width - 2) + 1;
        int y = rand() % (MAP_ROWS - room_height - 2) + 1;
        Room new_room = {x, y, room_width, room_height};

        // Make sure rooms don't overlap
        int overlaps = 0;
        for (int j = 0; j < i; j++) {
            if (new_room.x < rooms[j].x + rooms[j].width + 1 &&
                new_room.x + new_room.width + 1 > rooms[j].x &&
                new_room.y < rooms[j].y + rooms[j].height + 1 &&
                new_room.y + new_room.height + 1 > rooms[j].y) {
                overlaps = 1;
                break;
            }
        }
        if (overlaps) {
            i--;
            continue;
        }

        // Carve out room
        for (int j = y; j < y + room_height; j++) {
            for (int k = x; k < x + room_width; k++) {
                map[j][k] = '.';
            }
        }
        rooms[i] = new_room;
    }

    // Generate corridors
    for (int i = 0; i < MAX_ROOMS - 1; i++) {
        int x1 = rooms[i].x + rooms[i].width / 2;
        int y1 = rooms[i].y + rooms[i].height / 2;
        int x2 = rooms[i+1].x + rooms[i+1].width / 2;
        int y2 = rooms[i+1].y + rooms[i+1].height / 2;

        while (x1 != x2) {
            if (x1 < x2) {
                x1++;
            } else {
                x1--;
            }
            map[y1][x1] = '.';
        }
        while (y1 != y2) {
            if (y1 < y2) {
                y1++;
            } else {
                y1--;
            }
            map[y1][x1] = '.';
        }
    }
}

void print_map(char map[MAP_ROWS][MAP_COLS]) {
    for (int i = 0; i < MAP_ROWS; i++) {
        for (int j = 0; j < MAP_COLS; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char map[MAP_ROWS][MAP_COLS];
    Room rooms[MAX_ROOMS];
    generate_map(map, rooms);
    print_map(map);
    return 0;
}