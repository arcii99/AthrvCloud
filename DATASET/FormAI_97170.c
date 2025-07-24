//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20
#define ROOM_MIN_SIZE 4
#define ROOM_MAX_SIZE 10
#define MAX_ROOMS 5

int map[MAP_WIDTH][MAP_HEIGHT];

typedef struct {
    int x;
    int y;
    int width;
    int height;
} Room;

void generate_map() {
    // Initialize map to all walls
    for (int x = 0; x < MAP_WIDTH; x++) {
        for (int y = 0; y < MAP_HEIGHT; y++) {
            map[x][y] = 1;
        }
    }

    // Create rooms
    int num_rooms = 0;
    Room rooms[MAX_ROOMS];
    srand(time(NULL));
    for (int i = 0; i < MAX_ROOMS; i++) {
        int room_width = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE) + ROOM_MIN_SIZE;
        int room_height = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE) + ROOM_MIN_SIZE;
        int room_x = rand() % (MAP_WIDTH - room_width - 1) + 1;
        int room_y = rand() % (MAP_HEIGHT - room_height - 1) + 1;

        Room new_room = {room_x, room_y, room_width, room_height};

        int overlap = 0;
        for (int j = 0; j < num_rooms; j++) {
            if (new_room.x < rooms[j].x + rooms[j].width + 2
                && new_room.x + new_room.width + 2 > rooms[j].x
                && new_room.y < rooms[j].y + rooms[j].height + 2
                && new_room.y + new_room.height + 2 > rooms[j].y) {
                overlap = 1;
            }
        }

        if (!overlap) {
            for (int x = new_room.x; x < new_room.x + new_room.width; x++) {
                for (int y = new_room.y; y < new_room.y + new_room.height; y++) {
                    if (x == new_room.x || x == new_room.x + new_room.width - 1
                        || y == new_room.y || y == new_room.y + new_room.height - 1) {
                        map[x][y] = 2;
                    } else {
                        map[x][y] = 0;
                    }
                }
            }

            rooms[num_rooms] = new_room;
            num_rooms++;
        }
    }

    // Connect the rooms with corridors
    for (int i = 0; i < num_rooms - 1; i++) {
        int x1 = rooms[i].x + rooms[i].width / 2;
        int y1 = rooms[i].y + rooms[i].height / 2;
        int x2 = rooms[i + 1].x + rooms[i + 1].width / 2;
        int y2 = rooms[i + 1].y + rooms[i + 1].height / 2;

        while (x1 != x2 || y1 != y2) {
            if (x1 < x2) {
                x1++;
                map[x1][y1] = 0;
            } else if (x1 > x2) {
                x1--;
                map[x1][y1] = 0;
            }

            if (y1 < y2) {
                y1++;
                map[x1][y1] = 0;
            } else if (y1 > y2) {
                y1--;
                map[x1][y1] = 0;
            }
        }
    }
}

int main() {
    generate_map();

    // Print map
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            switch (map[x][y]) {
                case 0:
                    printf(".");
                    break;
                case 1:
                    printf("#");
                    break;
                case 2:
                    printf("+");
                    break;
            }
        }
        printf("\n");
    }

    return 0;
}