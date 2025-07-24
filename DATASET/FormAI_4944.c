//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 30
#define MAP_HEIGHT 20

char map[MAP_HEIGHT][MAP_WIDTH];

void generate_map() {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            int map_type = rand() % 100;
            if (map_type < 25) {
                map[i][j] = '#'; // wall
            } else {
                map[i][j] = '.'; // floor
            }
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

int main() {
    generate_map();
    print_map();
    return 0;
}