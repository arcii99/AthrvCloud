//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE_X 50
#define MAP_SIZE_Y 20
#define MAX_ROOMS 6
#define MAX_ROOM_WIDTH 12
#define MAX_ROOM_HEIGHT 8

int main() {
    // Set up random seed
    srand((unsigned)time(NULL));

    // Create the game map
    char map[MAP_SIZE_Y][MAP_SIZE_X];

    // Fill the map with solid walls
    for (int y = 0; y < MAP_SIZE_Y; y++) {
        for (int x = 0; x < MAP_SIZE_X; x++) {
            map[y][x] = '#';
        }
    }

    // Place the player in the middle of the map
    int player_x = MAP_SIZE_X / 2;
    int player_y = MAP_SIZE_Y / 2;
    map[player_y][player_x] = '@';

    // Generate the rooms
    int num_rooms = (rand() % MAX_ROOMS) + 1;
    int room_starts_x[MAX_ROOMS];
    int room_starts_y[MAX_ROOMS];
    int room_ends_x[MAX_ROOMS];
    int room_ends_y[MAX_ROOMS];

    for (int i = 0; i < num_rooms; i++) {
        int room_width = (rand() % MAX_ROOM_WIDTH) + 2;
        int room_height = (rand() % MAX_ROOM_HEIGHT) + 2;
        int room_start_x = (rand() % (MAP_SIZE_X - room_width - 1)) + 1;
        int room_start_y = (rand() % (MAP_SIZE_Y - room_height - 1)) + 1;
        int room_end_x = room_start_x + room_width - 1;
        int room_end_y = room_start_y + room_height - 1;

        for (int y = room_start_y; y <= room_end_y; y++) {
            for (int x = room_start_x; x <= room_end_x; x++) {
                map[y][x] = '.';
            }
        }

        room_starts_x[i] = room_start_x;
        room_starts_y[i] = room_start_y;
        room_ends_x[i] = room_end_x;
        room_ends_y[i] = room_end_y;
    }

    // Connect the rooms with corridors
    for (int i = 0; i < num_rooms - 1; i++) {
        int x1 = (rand() % (room_ends_x[i] - room_starts_x[i] + 1)) + room_starts_x[i];
        int y1 = (rand() % (room_ends_y[i] - room_starts_y[i] + 1)) + room_starts_y[i];
        int x2 = (rand() % (room_ends_x[i+1] - room_starts_x[i+1] + 1)) + room_starts_x[i+1];
        int y2 = (rand() % (room_ends_y[i+1] - room_starts_y[i+1] + 1)) + room_starts_y[i+1];

        while (x1 != x2 || y1 != y2) {
            if (x1 != x2) {
                x1 += (x1 < x2) ? 1 : -1;
            }
            if (y1 != y2) {
                y1 += (y1 < y2) ? 1 : -1;
            }

            if (map[y1][x1] == '#') {
                map[y1][x1] = '.';
            }
        }
    }

    // Print the map
    for (int y = 0; y < MAP_SIZE_Y; y++) {
        for (int x = 0; x < MAP_SIZE_X; x++) {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }

    return 0;
}