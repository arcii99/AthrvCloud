//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: futuristic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 30
#define ROOM_ATTEMPTS 100

char map[MAP_HEIGHT][MAP_WIDTH];

void place_room(int x, int y, int w, int h) {
    for (int i = y; i < y + h; i++) {
        for (int j = x; j < x + w; j++) {
            map[i][j] = '.';
        }
    }
}

void generate_map() {
    // Fill map with walls
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = '#';
        }
    }

    // Seed random number generator
    srand(time(NULL));

    // Place rooms
    for (int i = 0; i < ROOM_ATTEMPTS; i++) {
        int room_width = rand() % 10 + 5;
        int room_height = rand() % 10 + 5;
        int x = rand() % (MAP_WIDTH - room_width - 1) + 1;
        int y = rand() % (MAP_HEIGHT - room_height - 1) + 1;
        place_room(x, y, room_width, room_height);
    }
}

void draw_map() {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    generate_map();
    draw_map();
    return 0;
}