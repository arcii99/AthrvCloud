//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24

char map[WIDTH][HEIGHT];

void init_map() {
    int x, y;
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            map[x][y] = ' ';
        }
    }

    int n;
    for (n = 0; n < 10; n++) {
        x = rand() % WIDTH;
        y = rand() % HEIGHT;
        map[x][y] = '#';
    }
}

void print_map() {
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            printf("%c", map[x][y]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));
    init_map();
    print_map();
    return 0;
}