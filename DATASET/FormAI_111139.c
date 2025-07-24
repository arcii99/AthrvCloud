//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

char dungeon[HEIGHT][WIDTH];

void initialize() {
    srand(time(NULL));
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            dungeon[y][x] = '#';
        }
    }
}

void generate_dungeon() {
    int room_count = rand() % 5 + 5;
    for (int i = 0; i < room_count; i++) {
        int room_width = rand() % 7 + 5;
        int room_height = rand() % 4 + 3;
        int room_x = rand() % (WIDTH - room_width - 2) + 1;
        int room_y = rand() % (HEIGHT - room_height - 2) + 1;
        for (int y = room_y; y < room_y + room_height; y++) {
            for (int x = room_x; x < room_x + room_width; x++) {
                dungeon[y][x] = '.';
            }
        }
    }
}

void print_dungeon() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", dungeon[y][x]);
        }
        printf("\n");
    }
}

int main() {
    initialize();
    generate_dungeon();
    print_dungeon();
    return 0;
}