//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 60
#define HEIGHT 20

char map[HEIGHT][WIDTH + 1];

void generateMap() {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (i == 0 || j == 0 || i == HEIGHT - 1 || j == WIDTH - 1) {
                map[i][j] = '#';
            } else {
                map[i][j] = '.';
            }
        }
        map[i][WIDTH] = '\0';
    }

    srand(time(NULL));
    int x = rand() % (WIDTH - 2) + 1;
    int y = rand() % (HEIGHT - 2) + 1;
    map[y][x] = '@';
}

void displayMap() {
    int i;
    for (i = 0; i < HEIGHT; i++) {
        printf("%s\n", map[i]);
    }
}

int main() {
    generateMap();
    displayMap();
    return 0;
}