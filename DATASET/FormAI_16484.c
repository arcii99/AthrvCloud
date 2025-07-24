//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_range(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    srand(time(NULL));

    int width = 20, height = 10;
    char map[height][width];

    // Fill map with walls
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            map[y][x] = '#';
        }
    }

    // Add some rooms
    int num_rooms = rand_range(3, 5);
    for (int i = 0; i < num_rooms; i++) {
        int room_width = rand_range(3, 6);
        int room_height = rand_range(3, 6);
        int room_x = rand_range(1, width - room_width - 1);
        int room_y = rand_range(1, height - room_height - 1);

        // Check for collisions with existing rooms
        int has_collision = 0;
        for (int y = room_y - 1; y < room_y + room_height + 1; y++) {
            for (int x = room_x - 1; x < room_x + room_width + 1; x++) {
                if (map[y][x] != '#') {
                    has_collision = 1;
                    break;
                }
            }
            if (has_collision) {
                break;
            }
        }

        // If no collision, add the room to the map
        if (!has_collision) {
            for (int y = room_y; y < room_y + room_height; y++) {
                for (int x = room_x; x < room_x + room_width; x++) {
                    map[y][x] = ' ';
                }
            }
        }
    }

    // Add some corridors between rooms
    for (int i = 0; i < num_rooms - 1; i++) {
        int x1 = rand_range(1, width - 2);
        int y1 = rand_range(1, height - 2);
        int x2 = rand_range(1, width - 2);
        int y2 = rand_range(1, height - 2);

        while (x2 != x1) {
            if (map[y2][x2] == '#') {
                map[y2][x2] = '.';
            }
            if (x2 < x1) {
                x2++;
            } else {
                x2--;
            }
        }
        while (y2 != y1) {
            if (map[y2][x2] == '#') {
                map[y2][x2] = '.';
            }
            if (y2 < y1) {
                y2++;
            } else {
                y2--;
            }
        }
    }

    // Print out the map
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }

    return 0;
}