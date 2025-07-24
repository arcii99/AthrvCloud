//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: portable
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25

char map[WIDTH][HEIGHT];

void generateMap() {
    srand(time(NULL));
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (rand() % 2 == 0) {
                map[x][y] = '#';
            } else {
                map[x][y] = '.';
            }
        }
    }
}

void printMap() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", map[x][y]);
        }
        printf("\n");
    }
}

int main() {
    generateMap();
    printMap();
    return 0;
}