//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

int main() {
    // initialize the pixel buffer
    int pixel_buffer[10][10];
    int x, y;
    for (y = 0; y < 10; y++) {
        for (x = 0; x < 10; x++) {
            pixel_buffer[y][x] = 0;
        }
    }

    // create a pattern
    int pattern[3][3] = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    // add the pattern to the pixel buffer
    int px, py;
    int buffer_x = 3;
    int buffer_y = 3;
    for (py = 0; py < 3; py++) {
        for (px = 0; px < 3; px++) {
            pixel_buffer[buffer_y + py][buffer_x + px] = pattern[py][px];
        }
    }

    // output the pixel art
    for (y = 0; y < 10; y++) {
        for (x = 0; x < 10; x++) {
            if (pixel_buffer[y][x] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}