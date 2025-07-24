//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: systematic
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20

typedef enum {
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT
} Direction;

char map[MAP_HEIGHT][MAP_WIDTH];

void init_map() {
    int i, j;
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = '.';
        }
    }
}

void print_map() {
    int i, j;
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void generate_map() {
    int i, j, num_rooms;
    int min_room_size = 4;
    int max_room_size = 8;
    int max_rooms = 10;
    
    // Set up random number generator
    srand(time(NULL));
    
    // Place rooms
    num_rooms = rand() % (max_rooms - 2) + 2; // Generate 2 to max_rooms-1 rooms
    for (i = 0; i < num_rooms; i++) {
        int room_x = rand() % (MAP_WIDTH - max_room_size - 1) + 1;
        int room_y = rand() % (MAP_HEIGHT - max_room_size - 1) + 1;
        int room_width = rand() % (max_room_size - min_room_size + 1) + min_room_size;
        int room_height = rand() % (max_room_size - min_room_size + 1) + min_room_size;
        
        // Check for overlapping rooms
        int overlaps = 0;
        int x, y;
        for (x = room_x - 1; x <= room_x + room_width; x++) {
            for (y = room_y - 1; y <= room_y + room_height; y++) {
                if (map[y][x] != '.') {
                    overlaps = 1;
                    break;
                }
            }
            if (overlaps) {
                break;
            }
        }
        
        // Place room if there are no overlapping rooms
        if (!overlaps) {
            for (x = room_x; x < room_x + room_width; x++) {
                for (y = room_y; y < room_y + room_height; y++) {
                    map[y][x] = '#';
                }
            }
        }
    }
    
    // Connect rooms with corridors
    for (i = 0; i < num_rooms - 1; i++) {
        int x1, y1, x2, y2;
        int first = 1;
        do {
            if (!first) {
                Direction dir;
                if (x1 == x2) {
                    dir = (y2 > y1 ? DIR_DOWN : DIR_UP);
                } else {
                    dir = (x2 > x1 ? DIR_RIGHT : DIR_LEFT);
                }
                while (x1 != x2 || y1 != y2) {
                    map[y1][x1] = '#';
                    switch (dir) {
                        case DIR_UP:
                            y1--;
                            break;
                        case DIR_DOWN:
                            y1++;
                            break;
                        case DIR_LEFT:
                            x1--;
                            break;
                        case DIR_RIGHT:
                            x1++;
                            break;
                    }
                }
            }
            x1 = rand() % (MAP_WIDTH - 2) + 1;
            y1 = rand() % (MAP_HEIGHT - 2) + 1;
            x2 = rand() % (MAP_WIDTH - 2) + 1;
            y2 = rand() % (MAP_HEIGHT - 2) + 1;
            first = 0;
        } while (map[y1][x1] != '#' || map[y2][x2] != '#');
    }
}

int main() {
    init_map();
    generate_map();
    print_map();
    return 0;
}