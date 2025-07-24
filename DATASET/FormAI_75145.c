//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

void printMap(char map[WIDTH][HEIGHT]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", map[x][y]);
        }
        printf("\n");
    }
}

void generateMap(char map[WIDTH][HEIGHT]) {
    srand(time(NULL));

    // Initialize the map to all walls
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            map[x][y] = '#';
        }
    }

    // Dig out some areas to create rooms
    for (int i = 0; i < 5; i++) {
        int x = rand() % (WIDTH - 5) + 2;
        int y = rand() % (HEIGHT - 5) + 2;
        int width = rand() % 5 + 3;
        int height = rand() % 5 + 3;

        for (int j = x; j < x + width; j++) {
            for (int k = y; k < y + height; k++) {
                map[j][k] = '.';
            }
        }
    }
}

int main() {
    char map[WIDTH][HEIGHT];

    generateMap(map);
    printMap(map);

    return 0;
}