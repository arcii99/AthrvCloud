//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 25

char dungeon[WIDTH][HEIGHT];

void generateDungeon() {
    srand(time(NULL));
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            if (rand() % 100 < 40) { // 40% chance of a wall
                dungeon[x][y] = '#';
            } else {
                dungeon[x][y] = '.';
            }
        }
    }
}

void printDungeon() {
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            printf("%c", dungeon[x][y]);
        }
        printf("\n");
    }
}

int main() {
    generateDungeon();
    printDungeon();
    return 0;
}