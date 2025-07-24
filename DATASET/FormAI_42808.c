//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 30
#define MAP_HEIGHT 20

char map[MAP_HEIGHT][MAP_WIDTH];

int rand_lim(int limit) {
    int divisor = RAND_MAX / (limit + 1);
    int retval;

    do { 
        retval = rand() / divisor;
    } while (retval > limit);

    return retval;
}

void generate_map() {
    // generate the map with procedural generation
    int x, y;

    for (y = 0; y < MAP_HEIGHT; y++) {
        for (x = 0; x < MAP_WIDTH; x++) {
            int r = rand_lim(100);

            if (r < 40) {
                map[y][x] = '#'; // wall
            } else {
                map[y][x] = ' '; // empty space
            }
        }
    }

    // add some randomness to the map
    for (y = 1; y < MAP_HEIGHT - 1; y++) {
        for (x = 1; x < MAP_WIDTH - 1; x++) {
            int n = 0;

            if (map[y - 1][x] == '#') n++;
            if (map[y + 1][x] == '#') n++;
            if (map[y][x - 1] == '#') n++;
            if (map[y][x + 1] == '#') n++;

            if (n >= 3) {
                map[y][x] = '#'; // wall
            }
        }
    }
}

void draw_map() {
    // draw the map
    int x, y;

    for (y = 0; y < MAP_HEIGHT; y++) {
        for (x = 0; x < MAP_WIDTH; x++) {
            printf("%c", map[y][x]);
        }

        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    generate_map();
    draw_map();

    return 0;
}