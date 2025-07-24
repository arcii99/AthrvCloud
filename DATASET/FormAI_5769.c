//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

char dungeon[HEIGHT][WIDTH];

void print_dungeon() {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", dungeon[i][j]);
        }
        printf("\n");
    }
}

void generate_dungeon() {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int r = rand() % 100;
            if (r < 40) {
                dungeon[i][j] = '#';
            } else if (r < 70) {
                dungeon[i][j] = '.';
            } else {
                dungeon[i][j] = ' ';
            }
        }
    }
}

void shift_dungeon() {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int r = rand() % 100;
            if (r < 5) {
                dungeon[i][j] = '#';
            } else if (r < 15) {
                dungeon[i][j] = '.';
            } else if (r < 20) {
                dungeon[i][j] = ' ';
            }
        }
    }
}

int main() {
    generate_dungeon();

    int i;
    for (i = 0; i < 10; i++) {
        shift_dungeon();
        print_dungeon();
        printf("\n");
    }

    return 0;
}