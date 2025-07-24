//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 70
#define HEIGHT 25

char world[WIDTH][HEIGHT];

void clear_world() {
    int i, j;
    for (i = 0; i < WIDTH; ++i) {
        for (j = 0; j < HEIGHT; ++j) {
            world[i][j] = '.';
        }
    }
}

void generate_world() {
    int i, j;
    int num_floors = (WIDTH * HEIGHT) * 0.3;
    for (i = 0; i < num_floors; ++i) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        world[x][y] = ' ';
    }
}

void print_world() {
    int i, j;
    for (i = 0; i < WIDTH; ++i) {
        for (j = 0; j < HEIGHT; ++j) {
            printf("%c", world[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    clear_world();
    generate_world();
    print_world();
    return 0;
}