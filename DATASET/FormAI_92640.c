//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

char map[WIDTH][HEIGHT];

void init_map() {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            map[x][y] = '#';
        }
    }
}

void print_map() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", map[x][y]);
        }
        printf("\n");
    }
}

void generate_map() {
    srand(time(NULL));

    int num_rooms = rand() % 20 + 10;

    for (int r = 0; r < num_rooms; r++) {
        int x = rand() % (WIDTH - 10) + 1;
        int y = rand() % (HEIGHT - 10) + 1;

        int w = rand() % 8 + 5;
        int h = rand() % 8 + 5;

        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                if (i == 0 || j == 0 || i == w - 1 || j == h - 1) {
                    map[x + i][y + j] = '#';
                } else {
                    map[x + i][y + j] = '.';
                }
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