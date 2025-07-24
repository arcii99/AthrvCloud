//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 20
#define MAX_COLS 50

int dungeon[MAX_ROWS][MAX_COLS];

int rand_num(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    srand(time(NULL));

    // generate dungeon with randomized walls and corridors
    for (int row = 0; row < MAX_ROWS; row++) {
        for (int col = 0; col < MAX_COLS; col++) {
            if (row == 0 || col == 0 || row == MAX_ROWS - 1 || col == MAX_COLS - 1) {
                dungeon[row][col] = 1;
            } else {
                dungeon[row][col] = rand_num(0, 1);
            }
        }
    }

    // print dungeon to console
    for (int row = 0; row < MAX_ROWS; row++) {
        for (int col = 0; col < MAX_COLS; col++) {
            if (dungeon[row][col] == 1) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }

    return 0;
}