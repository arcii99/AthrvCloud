//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 10

char map[MAP_HEIGHT][MAP_WIDTH];

void generate_map() {
    // initialize random seed
    srand(time(NULL));

    // generate random map tiles
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (rand() % 2 == 0) {
                map[y][x] = '.';
            } else {
                map[y][x] = '#';
            }
        }
    }

    // add player to map
    int player_x = rand() % MAP_WIDTH;
    int player_y = rand() % MAP_HEIGHT;
    map[player_y][player_x] = '@';
}

void print_map() {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
}

int main() {
    generate_map();
    print_map();
    return 0;
}