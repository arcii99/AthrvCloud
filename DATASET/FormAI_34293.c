//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

char map[WIDTH][HEIGHT];

void generate_map()
{
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (rand() % 10 == 0) {
                map[i][j] = '#';
            } else {
                map[i][j] = '.';
            }
        }
    }
}

void draw_map()
{
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    srand((unsigned)time(NULL));

    generate_map();
    draw_map();

    return 0;
}