//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: optimized
#include <stdio.h>

// define the pixel size and character used to represent pixel
#define PIXEL_SIZE 2
#define PIXEL_CHAR '█'

void generate_pixel_art(int width, int height, int color) {
    // calculate the total size of the pixel art canvas
    int canvas_width = width * PIXEL_SIZE;
    int canvas_height = height * PIXEL_SIZE;

    // initialize the array with the background color
    int pixels[canvas_height][canvas_width];
    for (int i = 0; i < canvas_height; i++) {
        for (int j = 0; j < canvas_width; j++) {
            pixels[i][j] = color;
        }
    }

    // generate the pixel art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // determine the top-left position of the current pixel block
            int x = j * PIXEL_SIZE;
            int y = i * PIXEL_SIZE;

            // generate the pixels for the current block
            for (int k = y; k < y + PIXEL_SIZE; k++) {
                for (int l = x; l < x + PIXEL_SIZE; l++) {
                    if (k % 2 == l % 2) {
                        pixels[k][l] = color;
                    } else {
                        pixels[k][l] = !color;
                    }
                }
            }
        }
    }

    // print the pixel art
    for (int i = 0; i < canvas_height; i++) {
        for (int j = 0; j < canvas_width; j++) {
            if (pixels[i][j] == color) {
                printf("%c%c", PIXEL_CHAR, PIXEL_CHAR);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    // generate a green and white checkered pattern
    generate_pixel_art(8, 8, 1);
    return 0;
}