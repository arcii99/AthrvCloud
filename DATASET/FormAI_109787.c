//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 60
#define HEIGHT 20

int map[WIDTH][HEIGHT];

void generate_map() {
    int x, y;
    srand(time(NULL));

    // Set all tiles to zero
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            map[x][y] = 0;
        }
    }

    // Randomly place walls
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            if ((x == 0) || (x == (WIDTH - 1)) || (y == 0) || (y == (HEIGHT - 1))) {
                map[x][y] = 1;
            } else if ((rand() % 100) < 40) {
                map[x][y] = 1;
            }
        }
    }
}

void print_map() {
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            if (map[x][y] == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main() {
    generate_map();
    print_map();
    return 0;
}