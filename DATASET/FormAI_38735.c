//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize variables
    int width = 10, height = 10;
    char canvas[height][width];
    srand(time(NULL));

    // generate random pixels
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r = rand() % 2;
            canvas[y][x] = r ? '#' : ' ';
        }
    }

    // print canvas
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", canvas[y][x]);
        }
        printf("\n");
    }

    return 0;
}