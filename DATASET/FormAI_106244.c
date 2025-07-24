//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20

char map[MAP_HEIGHT][MAP_WIDTH];

void initialize() {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < MAP_HEIGHT; ++i) {
        for (j = 0; j < MAP_WIDTH; ++j) {
            map[i][j] = '.';
        }
    }
}

void generate_map() {
    int i, j, num_of_obstacles = 100;
    for (i = 0; i < num_of_obstacles; ++i) {
        int x = rand() % MAP_WIDTH;
        int y = rand() % MAP_HEIGHT;
        map[y][x] = '#';
    }

    // Generate starting and ending positions
    int start_x = rand() % MAP_WIDTH;
    int end_x;
    do {
        end_x = rand() % MAP_WIDTH;
    } while (end_x == start_x);
    map[0][start_x] = 'S';
    map[MAP_HEIGHT - 1][end_x] = 'E';
}

void print_map() {
    int i, j;
    for (i = 0; i < MAP_HEIGHT; ++i) {
        for (j = 0; j < MAP_WIDTH; ++j) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    initialize();
    generate_map();
    print_map();
    return 0;
}