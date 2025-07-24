//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 30
#define NUM_ROOMS 8

void generate_map(char map[MAP_SIZE][MAP_SIZE])
{
    // Initialize map with walls
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = '#';
        }
    }

    // Generate rooms
    for (int room = 0; room < NUM_ROOMS; room++) {
        int room_x = rand() % (MAP_SIZE - 10) + 1;
        int room_y = rand() % (MAP_SIZE - 10) + 1;
        int room_width = rand() % 8 + 4;
        int room_height = rand() % 8 + 4;

        // Check for collisions with other rooms
        char collision = 0;
        for (int i = room_x - 1; i <= room_x + room_width; i++) {
            for (int j = room_y - 1; j <= room_y + room_height; j++) {
                if (i >= 0 && i < MAP_SIZE && j >= 0 && j < MAP_SIZE) {
                    if (map[i][j] != '#') {
                        collision = 1;
                        break;
                    }
                }
            }
            if (collision) {
                break;
            }
        }

        // If no collisions, create room
        if (!collision) {
            for (int i = room_x; i < room_x + room_width; i++) {
                for (int j = room_y; j < room_y + room_height; j++) {
                    if (i == room_x || i == room_x + room_width - 1) {
                        map[i][j] = '-';
                    } else if (j == room_y || j == room_y + room_height - 1) {
                        map[i][j] = '|';
                    } else {
                        map[i][j] = '.';
                    }
                }
            }
        }
    }

    // Add player avatar
    map[MAP_SIZE / 2][MAP_SIZE / 2] = '@';
}

void print_map(char map[MAP_SIZE][MAP_SIZE])
{
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char map[MAP_SIZE][MAP_SIZE];
    srand(time(NULL));

    generate_map(map);
    print_map(map);

    return 0;
}