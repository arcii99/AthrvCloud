//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20
#define WALL '#'
#define FLOOR '.'
#define PLAYER '@'

void generate_map(char map[][WIDTH]) {
    // initialize map with walls and floors
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            map[y][x] = WALL;
        }
    }

    // carve out paths through the walls
    int x = rand() % (WIDTH - 2) + 1;
    int y = rand() % (HEIGHT - 2) + 1;
    map[y][x] = FLOOR;

    for (int i = 0; i < 50; ++i) {
        switch (rand() % 4) {
            case 0: // up
                if (y > 1) {
                    --y;
                    map[y][x] = FLOOR;
                    --y;
                    map[y][x] = FLOOR;
                }
                break;
            case 1: // down
                if (y < HEIGHT - 2) {
                    ++y;
                    map[y][x] = FLOOR;
                    ++y;
                    map[y][x] = FLOOR;
                }
                break;
            case 2: // left
                if (x > 1) {
                    --x;
                    map[y][x] = FLOOR;
                    --x;
                    map[y][x] = FLOOR;
                }
                break;
            case 3: // right
                if (x < WIDTH - 2) {
                    ++x;
                    map[y][x] = FLOOR;
                    ++x;
                    map[y][x] = FLOOR;
                }
                break;
        }
    }
}

void print_map(char map[][WIDTH]) {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            putchar(map[y][x]);
        }
        putchar('\n');
    }
}

int main() {
    srand(time(NULL));

    char map[HEIGHT][WIDTH];
    generate_map(map);
    print_map(map);

    return EXIT_SUCCESS;
}