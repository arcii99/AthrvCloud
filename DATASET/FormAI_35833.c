//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define ROWS 128
#define COLS 128

void flip_image(unsigned char image[ROWS][COLS]) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS / 2; j++) {
            unsigned char temp = image[i][j];
            image[i][j] = image[i][COLS - 1 - j];
            image[i][COLS - 1 - j] = temp;
        }
    }
}

void adjust_brightness_contrast(unsigned char image[ROWS][COLS], int brightness, int contrast) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            int pixel = image[i][j];
            pixel = pixel + brightness;
            pixel = (pixel * contrast) / 128;
            if (pixel > 255) pixel = 255;
            if (pixel < 0) pixel = 0;
            image[i][j] = pixel;
        }
    }
}

int main() {
    unsigned char image[ROWS][COLS]; // assume the image is already read from a file

    flip_image(image);
    adjust_brightness_contrast(image, 50, 128);

    // print the modified image for testing
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%3d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}