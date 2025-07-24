//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 10

char map[MAP_HEIGHT][MAP_WIDTH];

void generate_map() {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            int r = rand() % 5;
            if (r == 0) map[i][j] = '#';
            else map[i][j] = '.';
        }
    }
}

void print_map() {
    int i, j;
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    generate_map();
    print_map();
    return 0;
}