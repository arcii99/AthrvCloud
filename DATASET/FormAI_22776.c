//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 50

char dungeon[ROWS][COLS];

void init_dungeon() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            dungeon[i][j] = '#';
        }
    }
}

void print_dungeon() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", dungeon[i][j]);
        }
        printf("\n");
    }
}

void generate_dungeon() {
    srand(time(NULL));
    int i, j;
    for (i = 1; i < ROWS - 1; i++) {
        for (j = 1; j < COLS - 1; j++) {
            if (rand() % 100 < 45) {
                dungeon[i][j] = '.';
            } else {
                dungeon[i][j] = '#';
            }
        }
    }
}

int main() {
    init_dungeon();
    generate_dungeon();
    print_dungeon();
    return 0;
}