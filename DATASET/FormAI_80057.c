//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20
#define PIXEL_SIZE 10

int main() {
    srand(time(NULL));

    // create pixel art canvas
    char canvas[HEIGHT][WIDTH];

    // initialize canvas with random colors
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            int color = rand() % 2;
            if(color == 0) {
                canvas[i][j] = ' ';
            } else {
                canvas[i][j] = '#';
            }
        }
    }

    // print pixel art to console
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            for(int i = 0; i < PIXEL_SIZE; i++) {
                for(int j = 0; j < PIXEL_SIZE; j++) {
                    printf("%c", canvas[y][x]);
                }
            }
        }
        printf("\n");
    }

    return 0;
}