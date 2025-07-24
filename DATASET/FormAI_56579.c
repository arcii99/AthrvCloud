//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 50
#define MIN_ROOM_WIDTH 4
#define MIN_ROOM_HEIGHT 3
#define MAX_ROOM_WIDTH 15
#define MAX_ROOM_HEIGHT 10

typedef struct Room {
    int x;
    int y;
    int width;
    int height;
} Room;

void generate_dungeon(char dungeon[21][80], Room rooms[MAX_ROOMS], int num_rooms) {
    // Set all tiles to wall
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 80; j++) {
            dungeon[i][j] = '#';
        }
    }

    // Create rooms
    srand(time(0)); // Seed random number generator
    for (int i = 0; i < num_rooms; i++) {
        int room_width = rand() % (MAX_ROOM_WIDTH - MIN_ROOM_WIDTH + 1) + MIN_ROOM_WIDTH;
        int room_height = rand() % (MAX_ROOM_HEIGHT - MIN_ROOM_HEIGHT + 1) + MIN_ROOM_HEIGHT;
        int x = rand() % (80 - room_width - 1) + 1;
        int y = rand() % (21 - room_height - 1) + 1;

        Room room = { x, y, room_width, room_height };
        rooms[i] = room;

        // Fill room with floor
        for (int j = x; j < x + room_width; j++) {
            for (int k = y; k < y + room_height; k++) {
                dungeon[k][j] = '.';
            }
        }
    }

    // Connect rooms with corridors
    for (int i = 0; i < num_rooms - 1; i++) {
        int x1 = rooms[i].x + rand() % rooms[i].width;
        int y1 = rooms[i].y + rand() % rooms[i].height;
        int x2 = rooms[i + 1].x + rand() % rooms[i + 1].width;
        int y2 = rooms[i + 1].y + rand() % rooms[i + 1].height;

        while (x1 != x2) {
            if (x1 < x2) {
                x1++;
            } else {
                x1--;
            }

            if (dungeon[y1][x1] == '#') {
                dungeon[y1][x1] = '.';
            }
        }

        while (y1 != y2) {
            if (y1 < y2) {
                y1++;
            } else {
                y1--;
            }

            if (dungeon[y1][x1] == '#') {
                dungeon[y1][x1] = '.';
            }
        }
    }
}

int main() {
    char dungeon[21][80];
    Room rooms[MAX_ROOMS];

    generate_dungeon(dungeon, rooms, MAX_ROOMS);

    // Print dungeon
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 80; j++) {
            printf("%c", dungeon[i][j]);
        }
        printf("\n");
    }

    return 0;
}