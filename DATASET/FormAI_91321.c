//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: protected
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct tile {
    int x;
    int y;
    char symbol;
};

int main() {
    srand(time(NULL)); // seed the random number generator

    int width = 80;
    int height = 24;

    struct tile map[height][width];

    // generate the map using procedural generation
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r = rand() % 3;
            if (r == 0) {
                map[y][x].symbol = '.';
            } else if (r == 1) {
                map[y][x].symbol = '#';
            } else {
                map[y][x].symbol = '+';
            }
            map[y][x].x = x;
            map[y][x].y = y;
        }
    }

    // print out the map
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", map[y][x].symbol);
        }
        printf("\n");
    }

    return 0;
}