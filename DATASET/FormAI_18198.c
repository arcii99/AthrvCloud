//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 20
#define HEIGHT 10

char map[WIDTH][HEIGHT];

void generate_map()
{
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            map[i][j] = '.';
        }
    }
    int rooms = 5 + rand() % 5;
    for (i = 0; i < rooms; i++) {
        int x = 2 + rand() % (WIDTH - 4);
        int y = 2 + rand() % (HEIGHT - 4);
        int w = 4 + rand() % 5;
        int h = 4 + rand() % 3;
        int j, k;
        for (j = x; j < x + w; j++) {
            for (k = y; k < y + h; k++) {
                if (j == x || j == x + w - 1 ||
                    k == y || k == y + h - 1) {
                    map[j][k] = '#';
                } else {
                    map[j][k] = '.';
                }
            }
        }
    }
}

void print_map()
{
    int i, j;
    for (j = 0; j < HEIGHT; j++) {
        for (i = 0; i < WIDTH; i++) {
            putchar(map[i][j]);
        }
        putchar('\n');
    }
}

int main()
{
    srand(time(NULL));
    generate_map();
    print_map();
    return 0;
}