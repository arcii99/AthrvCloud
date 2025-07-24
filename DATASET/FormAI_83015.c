//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 80
#define MAP_HEIGHT 30
#define MAX_ROOMS 15

struct Room {
    int x;
    int y;
    int width;
    int height;
};

void generate_map(char map[MAP_HEIGHT][MAP_WIDTH]) {
    printf("Generating map...\n");

    // Fill map with walls
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map[y][x] = '#';
        }
    }

    // Create rooms
    struct Room rooms[MAX_ROOMS];
    int num_rooms = 0;

    srand(time(NULL));

    for (int i = 0; i < MAX_ROOMS; i++) {
        int room_width = rand() % 10 + 5;
        int room_height = rand() % 6 + 3;
        int room_x = rand() % (MAP_WIDTH - room_width - 2) + 1;
        int room_y = rand() % (MAP_HEIGHT - room_height - 2) + 1;

        struct Room new_room = { room_x, room_y, room_width, room_height };

        int failed = 0;

        for (int j = 0; j < num_rooms; j++) {
            struct Room existing_room = rooms[j];

            if ((new_room.x >= existing_room.x - new_room.width && new_room.x <= existing_room.x + existing_room.width) ||
                (new_room.x + new_room.width >= existing_room.x && new_room.x + new_room.width <= existing_room.x + existing_room.width) ||
                (new_room.y >= existing_room.y - new_room.height && new_room.y <= existing_room.y + existing_room.height) ||
                (new_room.y + new_room.height >= existing_room.y && new_room.y + new_room.height <= existing_room.y + existing_room.height)) {
                failed = 1;
                break;
            }
        }

        if (!failed) {
            for (int y = new_room.y; y < new_room.y + new_room.height; y++) {
                for (int x = new_room.x; x < new_room.x + new_room.width; x++) {
                    map[y][x] = ' ';
                }
            }

            rooms[num_rooms] = new_room;
            num_rooms++;
        }
    }

    // Create tunnels
    for (int i = 0; i < num_rooms - 1; i++) {
        struct Room room1 = rooms[i];
        struct Room room2 = rooms[i + 1];

        int x1 = room1.x + room1.width / 2;
        int y1 = room1.y + room1.height / 2;
        int x2 = room2.x + room2.width / 2;
        int y2 = room2.y + room2.height / 2;

        while (x1 != x2 || y1 != y2) {
            if (x1 < x2) {
                x1++;
            } else if (x1 > x2) {
                x1--;
            }

            if (y1 < y2) {
                y1++;
            } else if (y1 > y2) {
                y1--;
            }

            map[y1][x1] = ' ';
        }
    }

    printf("Done!\n");
}

int main() {
    char map[MAP_HEIGHT][MAP_WIDTH];

    generate_map(map);

    // Print map
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            printf("%c", map[y][x]);
        }

        printf("\n");
    }

    return 0;
}