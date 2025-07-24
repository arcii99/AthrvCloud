//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20

char map[MAP_HEIGHT][MAP_WIDTH];

void init_map() {
    // Fill the map with "#" to represent walls
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = '#';
        }
    }
}

void print_map() {
    // Print the map to the screen
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void generate_map() {
    // Randomly generate the map using procedural generation
    srand(time(NULL));
    int num_rooms = rand() % 6 + 5; // Generate between 5 and 10 rooms

    for (int i = 0; i < num_rooms; i++) {
        int room_width = rand() % 10 + 5;
        int room_height = rand() % 5 + 3;
        int x = rand() % (MAP_WIDTH - room_width - 1) + 1;
        int y = rand() % (MAP_HEIGHT - room_height - 1) + 1;

        // Place the room
        for (int j = y; j < y + room_height; j++) {
            for (int k = x; k < x + room_width; k++) {
                map[j][k] = '.';
            }
        }

        // Connect the rooms with corridors
        if (i > 0) {
            int prev_x = rand() % (room_width - 2) + x + 1;
            int prev_y = rand() % (room_height - 2) + y + 1;
            int curr_x = rand() % (room_width - 2) + prev_x - room_width;
            int curr_y = rand() % (room_height - 2) + prev_y - room_height;

            while (curr_x != prev_x || curr_y != prev_y) {
                if (curr_x != prev_x) {
                    if (curr_x < prev_x) {
                        curr_x++;
                    } else {
                        curr_x--;
                    }
                } else if (curr_y != prev_y) {
                    if (curr_y < prev_y) {
                        curr_y++;
                    } else {
                        curr_y--;
                    }
                }
                map[curr_y][curr_x] = '.';
            }
        }
    }
}

int main() {
    init_map();
    generate_map();
    print_map();
    return 0;
}