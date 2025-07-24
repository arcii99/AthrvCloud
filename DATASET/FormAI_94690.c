//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20

char map[MAP_HEIGHT][MAP_WIDTH];

void generate_map()
{
    int i, j;
    srand(time(NULL));
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            if (rand() % 100 < 30) {
                map[i][j] = '#';
            } else {
                map[i][j] = '.';
            }
        }
    }

    // Carve out some rooms
    int num_rooms = rand() % 5 + 5;
    for (i = 0; i < num_rooms; i++) {
        int x = rand() % (MAP_WIDTH - 5) + 2;
        int y = rand() % (MAP_HEIGHT - 5) + 2;
        int w = rand() % 5 + 3;
        int h = rand() % 5 + 3;

        // Check if there's already something in the way
        int overlap = 0;
        int xi, yi;
        for (xi = x - 1; xi < x + w + 1; xi++) {
            for (yi = y - 1; yi < y + h + 1; yi++) {
                if (map[yi][xi] == '#') {
                    overlap = 1;
                }
            }
        }
        if (!overlap) {
            for (xi = x; xi < x + w; xi++) {
                for (yi = y; yi < y + h; yi++) {
                    map[yi][xi] = '.';
                }
            }
        }
    }
}

void print_map()
{
    int i, j;
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    generate_map();
    print_map();
    return 0;
}